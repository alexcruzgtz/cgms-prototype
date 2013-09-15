
#include <p18f4550.h>
//#include <i2c.h>
#include "I2CHandler.h"

/*-----------------------------------------------------------------------------------------*/
void ACK_Poll(unsigned char);        // Acknowledge polling
void bstart(void);                   // Start condition
void bstop(void);                    // Stop condition
void bit_in(unsigned char*);   // Bit input function
void bit_out(unsigned char);   // Bit output function

unsigned char byte_out(unsigned char);  // Byte output
unsigned char byte_in(unsigned char);   // Byte input

void LDByteWriteI2C(unsigned char, unsigned char, unsigned char);  
void LDPageWriteI2C(unsigned char, unsigned char, unsigned char*, unsigned char);
void LDByteReadI2C(unsigned char, unsigned char, unsigned char*);
void LDSequentialReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);

void HDByteWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char);
void HDPageWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
void HDByteReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*,unsigned char);
void HDSequentialReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);


/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
void bstart(void)
{
    SDA_TRIS = 1;                   // Ensure SDA is high
    SCL = 1;                        // Ensure SCL is high
    SDA_TRIS = 0;                   // Configure SDA as an output
    SDA = 0;                        // Pull SDA low
    SCL = 0;                        // Pull SCL low
} 

/*-----------------------------------------------------------------------------------------*/
void bstop(void)
{
    SCL = 0;                        // Ensure SCL is low
    SDA_TRIS = 0;                   // Configure SDA as an output
    SDA = 0;                        // Ensure SDA low
    SCL = 1;                        // Pull SCL high
    SDA_TRIS = 1;                   // Allow SDA to be pulled high
}

/*-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------*/
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

/*-----------------------------------------------------------------------------------------*/
void LDByteWriteI2C(unsigned char controlbyte,unsigned char badd, unsigned char bdata)
{
    controlbyte = (controlbyte & 0xFE);
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);         		// Output control byte
    byte_out(badd);						// Output address LSB
    byte_out(bdata);                 	// Output data byte
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);          	// Begin ACK polling
}

/*-----------------------------------------------------------------------------------------*/
void LDPageWriteI2C(unsigned char controlbyte, unsigned char badd,unsigned char *bdata, unsigned char numbytes)
{
    unsigned char i;                	// Loop counter
    controlbyte = (controlbyte & 0xFE);
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);      	   	// Output control byte
    byte_out(badd);						// Output address LSB
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        byte_out(bdata[i]);          	// Output next data byte
    }
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);              // Begin ACK polling
}

/*-----------------------------------------------------------------------------------------*/
void LDByteReadI2C(unsigned char controlbyte, unsigned char badd,unsigned char *bdata)
{
    controlbyte = (controlbyte & 0xFE);
    bstart();                       // Generate Start condition
    byte_out(controlbyte);         	// Output control byte
    byte_out(badd);					// Output address LSB
    bstart();                       // Generate Start condition
    byte_out(controlbyte | 0x01);   // Output control byte
    *bdata = byte_in(NAKBIT);       // Input data byte
    bstop();                       	// Generate Stop condition
}

/*-----------------------------------------------------------------------------------------*/
void LDSequentialReadI2C(unsigned char controlbyte, unsigned char badd,unsigned char *bdata, unsigned char numbytes)
{
    unsigned int i;                 	// Loop counter
    controlbyte = (controlbyte & 0xFE);
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);      	   	// Output control byte
    byte_out(badd);						// Output address LSB
    bstart();                       	// Generate Start condition
    byte_out(controlbyte | 0x01);  	// Output control byte
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


/*-----------------------------------------------------------------------------------------*/
void HDByteWriteI2C(unsigned char controlbyte, unsigned char Hadd, unsigned char Ladd, unsigned char bdata)
{	
	unsigned int tempAddr=0;
	tempAddr=((unsigned int)Hadd)<<8;
	tempAddr|=((unsigned int)Ladd);
	if(tempAddr>=64000)
	{
		controlbyte=controlbyte|0x02;
	}
    bstart();                   // Generate Start condition
    byte_out(controlbyte);      // Output control byte
    byte_out(Hadd);				// Output address MSB
    byte_out(Ladd);			// Output address LSB
    byte_out(bdata);            // Output data byte
    bstop();                    // Generate Stop condition
    ACK_Poll(controlbyte);      // Begin ACK polling
} 

/*-----------------------------------------------------------------------------------------*/
void HDPageWriteI2C(unsigned char controlbyte,unsigned char Hadd, unsigned char Ladd, unsigned char *bdata, unsigned char numbytes)
{	
    unsigned char i;                	// Loop counter
	unsigned int tempAddr=0;
	tempAddr=((unsigned int)Hadd)<<8;
	tempAddr|=((unsigned int)Ladd);
	if(tempAddr>=64000)
	{
		controlbyte=controlbyte|0x02;
	}
	bstart();                       	// Generate Start condition
    byte_out(controlbyte);          	// Output control byte
    byte_out(Hadd);						// Output address MSB
    byte_out(Ladd);						// Output address LSB
    for (i = 0; i < numbytes; i++)  	// Loop through data bytes
    {
        byte_out(bdata[i]);          	// Output next data byte
    }
    bstop();                        	// Generate Stop condition
    ACK_Poll(controlbyte);          	// Begin ACK polling
}

/*-----------------------------------------------------------------------------------------*/
void HDByteReadI2C(unsigned char controlbyte,unsigned char Hadd, unsigned char Ladd, unsigned char *bdata,unsigned char num)
{
	unsigned int tempAddr=0;
	tempAddr=(((unsigned int)Hadd)<<8);
	tempAddr|=((unsigned int)Ladd);
	if(tempAddr>=64000)
	{
		controlbyte=controlbyte|0x02;
	}
    bstart();                       	// Generate Start condition
    byte_out(controlbyte);          	// Output control byte
    byte_out(Hadd);						// Output address MSB
    byte_out(Ladd);						// Output address LSB
    bstart();                       	// Generate Start condition
    byte_out(controlbyte | 0x01);   	// Output control byte
    *bdata = byte_in(NAKBIT);        	// Input data byte
    bstop();                        	// Generate Stop condition
}

/*-----------------------------------------------------------------------------------------*/
void HDSequentialReadI2C(unsigned char controlbyte,unsigned char Hadd, unsigned char Ladd, unsigned char *bdata, unsigned char numbytes)
{
    unsigned int i;             	// Loop counter
	unsigned int tempAddr=0;
	tempAddr=(((unsigned int)Hadd)<<8);
	tempAddr|=((unsigned int)Ladd);
	if(tempAddr>=64000)
	{
		controlbyte=controlbyte|0x02;
	}
	bstart();                       	// Generate Start condition
    byte_out(controlbyte);              // Output control byte
    byte_out(Hadd);						// Output address MSB
    byte_out(Ladd);						// Output address LSB
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



/*-----------------------------------------------------------------------------------------*/
/*unsigned char LDByteWriteI2C( unsigned char ControlByte, unsigned char LowAdd, unsigned char data );
unsigned char LDByteReadI2C( unsigned char ControlByte, unsigned char address, unsigned char *data, unsigned char length );
unsigned char LDPageWriteI2C( unsigned char ControlByte, unsigned char LowAdd, unsigned char *wrptr );
unsigned char LDSequentialReadI2C( unsigned char ControlByte, unsigned char address, unsigned char *rdptr, unsigned char length );

unsigned char HDByteWriteI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char data );
unsigned char HDByteReadI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *data, unsigned char length );
unsigned char HDPageWriteI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *wrptr );
unsigned char HDSequentialReadI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *rdptr, unsigned char length );
unsigned char putstringI2C( unsigned char *wrptr );

void Initialize_I2C ( void );
*/
/*-----------------------------------------------------------------------------------------*/
/*unsigned char ControlByte;                //Control Byte
unsigned char HighAdd;                    //High Order Address Byte
unsigned char LowAdd;                     //Low Order Address Byte
unsigned char Data;                       //Data Byte
unsigned char Length;*/                     //Length of bytes to read
//unsigned int  PageSize;                   //Page size in bytes
//unsigned char PageString[64];             // Holds the device page data to/from EEPROM


/*-----------------------------------------------------------------------------------------*/
/*void Initialize_I2C ( void )
{
  DDRBbits.RB1 = 0; //Configure SCL
                    //as Output
  DDRBbits.RB0 = 0; //Configure SDA
                    //as Input
  SSPSTAT = 0x80;   //Disable SMBus &
                    //Slew Rate Control
  SSPCON1 = 0x28;   //Enable MSSP Master
  SSPADD = 0x18;    //Should be 0x18
                    //for 100kHz
  SSPCON2 = 0x00;   //Clear MSSP Conrol Bits
}
*/

/************************************************************************
*     Function Name:    LDByteWriteI2C                                  *
*     Parameters:       EE memory ControlByte, address and data         *
*     Description:      Writes data one byte at a time to I2C EE        *
*                       device. 
************************************************************************/
/*unsigned char LDByteWriteI2C( unsigned char ControlByte, unsigned char LowAdd, unsigned char data )
{
  IdleI2C();                          // ensure module is idle
  StartI2C();                         // initiate START condition
  while ( SSPCON2bits.SEN );          // wait until start condition is over 
  WriteI2C( ControlByte );            // write 1 byte - R/W bit should be 0
  IdleI2C();                          // ensure module is idle
  WriteI2C( LowAdd );                 // write address byte to EEPROM
  IdleI2C();                          // ensure module is idle
  WriteI2C ( data );                  // Write data byte to EEPROM
  IdleI2C();                          // ensure module is idle
  StopI2C();                          // send STOP condition
  while ( SSPCON2bits.PEN );          // wait until stop condition is over 
  while (EEAckPolling(ControlByte));  //Wait for write cycle to complete
  return ( 0 );                       // return with no error
}
*/
/********************************************************************
*     Function Name:    LDByteReadI2C                               *
*     Parameters:       EE memory ControlByte, address, pointer and *
*                       length bytes.                               *
*     Description:      Reads data string from I2C EE memory        *
*                       device.  
********************************************************************/
/*unsigned char LDByteReadI2C( unsigned char ControlByte, unsigned char address, unsigned char *data, unsigned char length )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte 
  IdleI2C();                      // ensure module is idle
  WriteI2C( address );            // WRITE word address to EEPROM
  IdleI2C();                      // ensure module is idle
  RestartI2C();                   // generate I2C bus restart condition
  while ( SSPCON2bits.RSEN );     // wait until re-start condition is over 
  WriteI2C( ControlByte | 0x01 ); // WRITE 1 byte - R/W bit should be 1 for read
  IdleI2C();                      // ensure module is idle
  getsI2C( data, length );       // read in multiple bytes
  NotAckI2C();                    // send not ACK condition
  while ( SSPCON2bits.ACKEN );    // wait until ACK sequence is over 
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    LDPageWriteI2C                              *
*     Parameters:       EE memory ControlByte, address and pointer  *
*     Description:      Writes data string to I2C EE memory         *
*                       device. 
********************************************************************/
/*unsigned char LDPageWriteI2C( unsigned char ControlByte, unsigned char LowAdd, unsigned char *wrptr )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte - R/W bit should be 0
  IdleI2C();                      // ensure module is idle
  WriteI2C( LowAdd );             // write LowAdd byte to EEPROM
  IdleI2C();                      // ensure module is idle
  putstringI2C ( wrptr );         // pointer to data for page write
  IdleI2C();                      // ensure module is idle
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    LDSequentialReadI2C                         *
*     Parameters:       EE memory ControlByte, address, pointer and *
*                       length bytes.                               *
*     Description:      Reads data string from I2C EE memory        *
*                       device. 
********************************************************************/
/*unsigned char LDSequentialReadI2C( unsigned char ControlByte, unsigned char address, unsigned char *rdptr, unsigned char length )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte 
  IdleI2C();                      // ensure module is idle
  WriteI2C( address );            // WRITE word address to EEPROM
  IdleI2C();                      // ensure module is idle
  RestartI2C();                   // generate I2C bus restart condition
  while ( SSPCON2bits.RSEN );     // wait until re-start condition is over 
  WriteI2C( ControlByte | 0x01 ); // WRITE 1 byte - R/W bit should be 1 for read
  IdleI2C();                      // ensure module is idle
  getsI2C( rdptr, length );       // read in multiple bytes
  NotAckI2C();                    // send not ACK condition
  while ( SSPCON2bits.ACKEN );    // wait until ACK sequence is over 
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/************************************************************************
*     Function Name:    HDByteWriteI2C                                  *   
*     Parameters:       EE memory ControlByte, address and data         *
*     Description:      Writes data one byte at a time to I2C EE        *
*                       device.     
************************************************************************/
/*unsigned char HDByteWriteI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char data )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte - R/W bit should be 0
  IdleI2C();                      // ensure module is idle
  WriteI2C( HighAdd );            // write address byte to EEPROM
  IdleI2C();                      // ensure module is idle
  WriteI2C( LowAdd );             // write address byte to EEPROM
  IdleI2C();                      // ensure module is idle
  WriteI2C ( data );              // Write data byte to EEPROM
  IdleI2C();                      // ensure module is idle
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  while (EEAckPolling(ControlByte));  //Wait for write cycle to complete
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    HDByteReadI2C                               *
*     Parameters:       EE memory ControlByte, address, pointer and *
*                       length bytes.                               *
*     Description:      Reads data string from I2C EE memory        *
*                       device. 
********************************************************************/
/*unsigned char HDByteReadI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *data, unsigned char length )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte 
  IdleI2C();                      // ensure module is idle
  WriteI2C( HighAdd );            // WRITE word address to EEPROM
  IdleI2C();                      // ensure module is idle
  while ( SSPCON2bits.RSEN );     // wait until re-start condition is over 
  WriteI2C( LowAdd );             // WRITE word address to EEPROM
  IdleI2C();                      // ensure module is idle
  RestartI2C();                   // generate I2C bus restart condition
  while ( SSPCON2bits.RSEN );     // wait until re-start condition is over 
  WriteI2C( ControlByte | 0x01 ); // WRITE 1 byte - R/W bit should be 1 for read
  IdleI2C();                      // ensure module is idle
  getsI2C( data, length );       // read in multiple bytes
  NotAckI2C();                    // send not ACK condition
  while ( SSPCON2bits.ACKEN );    // wait until ACK sequence is over 
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    HDPageWriteI2C                              *
*     Parameters:       EE memory ControlByte, address and pointer  *
*     Description:      Writes data string to I2C EE memory         *
*                       device. 
********************************************************************/
/*unsigned char HDPageWriteI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *wrptr )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte - R/W bit should be 0
  IdleI2C();                      // ensure module is idle
  WriteI2C( HighAdd );            // write HighAdd byte to EEPROM 
  IdleI2C();                      // ensure module is idle
  WriteI2C( LowAdd );             // write LowAdd byte to EEPROM
  IdleI2C();                      // ensure module is idle
  putstringI2C ( wrptr );         // pointer to data for page write
  IdleI2C();                      // ensure module is idle
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    HDSequentialReadI2C                         *
*     Parameters:       EE memory ControlByte, address, pointer and *
*                       length bytes.                               *
*     Description:      Reads data string from I2C EE memory        *
*                       device. 
********************************************************************/
/*unsigned char HDSequentialReadI2C( unsigned char ControlByte, unsigned char HighAdd, unsigned char LowAdd, unsigned char *rdptr, unsigned char length )
{
  IdleI2C();                      // ensure module is idle
  StartI2C();                     // initiate START condition
  while ( SSPCON2bits.SEN );      // wait until start condition is over 
  WriteI2C( ControlByte );        // write 1 byte 
  IdleI2C();                      // ensure module is idle
  WriteI2C( HighAdd );            // WRITE word address to EEPROM
  IdleI2C();                      // ensure module is idle
  WriteI2C( LowAdd );             // write HighAdd byte to EEPROM
  IdleI2C();                      // ensure module is idle
  RestartI2C();                   // generate I2C bus restart condition
  while ( SSPCON2bits.RSEN );     // wait until re-start condition is over 
  WriteI2C( ControlByte | 0x01 ); // WRITE 1 byte - R/W bit should be 1 for read
  IdleI2C();                      // ensure module is idle
  getsI2C( rdptr, length );       // read in multiple bytes
  NotAckI2C();                    // send not ACK condition
  while ( SSPCON2bits.ACKEN );    // wait until ACK sequence is over 
  StopI2C();                      // send STOP condition
  while ( SSPCON2bits.PEN );      // wait until stop condition is over 
  return ( 0 );                   // return with no error
}
*/
/********************************************************************
*     Function Name:    putstringI2C                                *
*     Return Value:     error condition status                      *
*     Parameters:       address of write string storage location    *
*     Description:      This routine writes a string to the I2C bus,*
*                       until a null character is reached. If Master*
*                       function putcI2C is called. When trans-     *
*                       mission is complete then test for ack-      *
*                       nowledge bit. If Slave transmitter wait for *
*                       null character or not ACK received from bus *
*                       device.                                     *
********************************************************************/
/*unsigned char putstringI2C( unsigned char *wrptr )
{

unsigned char x;
  for (x = 0; x < PageSize; x++ ) // transmit data until PageSize  
  {
    if ( SSPCON1bits.SSPM3 )      // if Master transmitter then execute the following
    {
      if ( putcI2C ( *wrptr ) )   // write 1 byte
      {
        return ( -3 );            // return with write collision error
      }
      IdleI2C();                  // test for idle condition
      if ( SSPCON2bits.ACKSTAT )  // test received ack bit state
      {
        return ( -2 );            // bus device responded with  NOT ACK
      }                           // terminateputstringI2C() function
    }
    else                          // else Slave transmitter
    {
      PIR1bits.SSPIF = 0;         // reset SSPIF bit
      SSPBUF = *wrptr;            // load SSPBUF with new data
      SSPCON1bits.CKP = 1;        // release clock line 
      while ( !PIR1bits.SSPIF );  // wait until ninth clock pulse received

      if ( ( !SSPSTATbits.R_W ) && ( !SSPSTATbits.BF ) )// if R/W=0 and BF=0, NOT ACK was received
      {
        return ( -2 );            // terminateputstringI2C() function
      }
    }
  wrptr ++;                       // increment pointer
  }                               // continue data writes until null character
  return ( 0 );
}
*/