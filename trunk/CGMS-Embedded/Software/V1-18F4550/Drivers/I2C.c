


#include <p18f4550.h>
#include "I2C.h"

void bit_in(unsigned char *bdata);   // Bit input function
void bit_out(unsigned char bdata);   // Bit output function

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Functions definitions for I2C protocol

//............................................................................
// This function generates an I2C Start condition.
void bstart(void)
{
    SDA_TRIS = 1;                   // Ensure SDA is high
    SCL = 1;                        // Ensure SCL is high
    SDA_TRIS = 0;                   // Configure SDA as an output
    SDA = 0;                        // Pull SDA low
    SCL = 0;                        // Pull SCL low
    
} 

//............................................................................
// This function generates an I2C Stop condition.
void bstop(void)
{
    SCL = 0;                        // Ensure SCL is low
    SDA_TRIS = 0;                   // Configure SDA as an output
    SDA = 0;                        // Ensure SDA low
    SCL = 1;                        // Pull SCL high
    SDA_TRIS = 1;                   // Allow SDA to be pulled high
}

//............................................................................
// This function outputs a bit to the I2C bus.
void bit_out(unsigned char bdata)
{
    SCL = 0;                        // Ensure SCL is low
    if (bdata & 0x80)               // Check if next bit is high
    {
        SDA_TRIS = 1;               // Release SDA to be pulled high
    }
    else
    {
        SDA_TRIS = 0;               // Configure SDA as an output
        SDA = 0;                    // Pull SDA low
    }
    SCL = 1;                        // Pull SCL high to clock bit
    SCL = 0;                        // Pull SCL low for next bit
} 

//............................................................................
// This function inputs a bit from the I2C bus.
void bit_in(unsigned char *bdata)
{
    SCL = 0;                        // Ensure SCL is low
    SDA_TRIS = 1;                   // Configure SDA as an input
    SCL = 1;                        // Bring SCL high to begin transfer
    *bdata &= 0xFE;                 // Assume next bit is low
    if (SDA)                        // Check if SDA is high
    {
        *bdata |= 0x01;             // If high, set next bit
    }
    SCL = 0;                        // Bring SCL low again
} 

//............................................................................
// This function outputs a byte to the I2C bus.
// It also receives the ACK bit and returns 0 if
// successfully received, or 1 if not.
unsigned char byte_out(unsigned char bdata)
{
    unsigned char i;                // Loop counter
    unsigned char ack;              // ACK bit
    ack = 0;
    for (i = 0; i < 8; i++)         // Loop through each bit
    {
        bit_out(bdata);             // Output bit
        bdata = bdata << 1;         // Shift left for next bit
    }
    bit_in(&ack);                   // Input ACK bit
    return ack;
}

//............................................................................
// This function inputs a byte from the I2C bus.
// Depending on the value of ack, it will also
// transmit either an ACK or a NAK bit.
unsigned char byte_in(unsigned char ack)
{
    unsigned char i;                // Loop counter
    unsigned char retval;           // Return value
    retval = 0;
    for (i = 0; i < 8; i++)         // Loop through each bit
    {
        retval = retval << 1;       // Shift left for next bit
        bit_in(&retval);            // Input bit
    }
    bit_out(ack);                   // Output ACK/NAK bit
    return retval;
} 

//............................................................................
//. This function implements Acknowledge polling.
void ACK_Poll(unsigned char controlbyte)
{
    unsigned char result;           	// Polling result
    result = 1;                     	// Initialize result
    do
    {
        bstart();                   	// Generate Start condition
        result = byte_out(controlbyte); // Output control byte
    } while (result == 1);
    bstop();                        	// Generate Stop condition
} 


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Functions definitions for low density memory

#if ( EEPROM_SIZE <= 2048 )

//............................................................................
// This function writes a single byte to a
// low-density (<= 16 Kb) serial EEPROM device.
void LD_ByteWrite(unsigned char controlbyte,unsigned int badd,unsigned char bdata)
{
    unsigned char temp_control;     	// Temp. variable for control byte
    // Merge block bits with control byte
    temp_control = (controlbyte & 0xF1) | ((badd >> 7) & 0x0E);
    bstart();                       	// Generate Start condition
    byte_out(temp_control);         	// Output control byte
    byte_out((unsigned char)badd);		// Output address LSB
    byte_out(bdata);                 	// Output data byte
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);          	// Begin ACK polling
}

//............................................................................
// This function writes multiple bytes to a
// low-density (<= 16 Kb) serial EEPROM device.
void LD_PageWrite(unsigned char controlbyte,unsigned int badd,unsigned char *bdata, unsigned char numbytes)
{
    unsigned char i;                	// Loop counter
    unsigned char temp_control;     	// Temp. variable for control byte

    // Merge block bits with control byte
    temp_control = (controlbyte & 0xF1) | ((badd >> 7) & 0x0E);

    bstart();                       	// Generate Start condition
    byte_out(temp_control);         	// Output control byte
    byte_out((unsigned char)badd);		// Output address LSB
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        byte_out(bdata[i]);          	// Output next data byte
    }
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);              // Begin ACK polling
}

//............................................................................
// This function reads a single byte from a
// low-density (<= 16 Kb) serial EEPROM device.
void LD_ByteRead(unsigned char controlbyte,unsigned int badd,unsigned char *bdata)
{
    unsigned char temp_control;     // Temp. variable for control byte
    // Merge block bits with control byte
    temp_control = (controlbyte & 0xF1) | ((badd >> 7) & 0x0E);
    bstart();                       // Generate Start condition
    byte_out(temp_control);         // Output control byte
    byte_out((unsigned char)badd);	// Output address LSB
    bstart();                       // Generate Start condition
    byte_out(temp_control | 0x01);  // Output control byte
    *bdata = byte_in(NAKBIT);       // Input data byte
    bstop();                       	// Generate Stop condition
}

//............................................................................
// This function reads multiple bytes from a
// low-density (<= 16 Kb) serial EEPROM device.
void LD_SequentialRead(unsigned char controlbyte,unsigned int badd,unsigned char *bdata, unsigned int numbytes)
{
    unsigned int i;                 // Loop counter
    unsigned char temp_control;     // Temp. variable for control byte
    // Merge block bits with control byte
    temp_control = (controlbyte & 0xF1) | ((badd >> 7) & 0x0E);
    bstart();                       	// Generate Start condition
    byte_out(temp_control);         	// Output control byte
    byte_out((unsigned char)badd);		// Output address LSB
    bstart();                       	// Generate Start condition
    byte_out(temp_control | 0x01);  	// Output control byte
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        if (i < (numbytes - 1))     	// Check if more data will be read
        {
            bdata[i] = byte_in(ACKBIT); // If not last, input byte & send ACK
        }
        else
        {
            bdata[i] = byte_in(NAKBIT); // If last byte, input byte & send NAK
        }
    }
    bstop();                        	// Generate Stop condition
} 

#endif


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Functions definitions for high density memory

#if ( EEPROM_SIZE <= 16384 )

//............................................................................
// This function writes a single byte to a
// high-density (>= 32 Kb) serial EEPROM device.
void HD_ByteWrite(unsigned char controlbyte,unsigned int badd,unsigned char bdata)
{
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);              // Output control byte
    byte_out((unsigned char)(badd>>8));	// Output address MSB
    byte_out((unsigned char)badd);		// Output address LSB
    byte_out(bdata);                 	// Output data byte
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);          	// Begin ACK polling
} 

//............................................................................
// This function writes multiple bytes to a
// high-density (>= 32 Kb) serial EEPROM device.
void HD_PageWrite(unsigned char controlbyte,unsigned int badd,unsigned char *bdata, unsigned char numbytes)
{
    unsigned char i;                	// Loop counter
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);              // Output control byte
    byte_out((unsigned char)(badd>>8));	// Output address MSB
    byte_out((unsigned char)badd);		// Output address LSB
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        byte_out(bdata[i]);          	// Output next data byte
    }
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);              // Begin ACK polling
}

//............................................................................
// This function reads a single byte from a
// high-density (>= 32 Kb) serial EEPROM device.
void HD_ByteRead(unsigned char controlbyte,unsigned int badd,unsigned char *bdata)
{
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);              // Output control byte
    byte_out((unsigned char)(badd>>8));	// Output address MSB
    byte_out((unsigned char)badd);		// Output address LSB
    bstart();                       	// Generate Start condition
    byte_out(controlbyte | 0x01);       // Output control byte
    *bdata = byte_in(NAKBIT);        	// Input data byte
    bstop();                        	// Generate Stop condition
}

//............................................................................
// This function reads multiple bytes from a
// high-density (>= 32 Kb) serial EEPROM device.
void HD_SequentialRead(unsigned char controlbyte,unsigned int badd,unsigned char *bdata, unsigned int numbytes)
{
    unsigned int i;                 	// Loop counter
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);              // Output control byte
    byte_out((unsigned char)(badd>>8));	// Output address MSB
    byte_out((unsigned char)badd);		// Output address LSB
    bstart();                       	// Generate Start condition
    byte_out(controlbyte | 0x01);       // Output control byte
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        if (i < (numbytes - 1))    	 	// Check if more data will be read
        {
            bdata[i] = byte_in(ACKBIT); // If not last, input byte & send ACK
        }
        else
        {
            bdata[i] = byte_in(NAKBIT); // If last byte, input byte & send NAK
        }
    }
    bstop();                        	// Generate Stop condition
}

