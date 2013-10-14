
#ifndef __I2CHANDLER_H
#define __I2CHANDLER_H

/*-----------------------------------------------------------------------------------------*/
//Global variables 
/*extern unsigned char ControlByte;                //Control Byte
extern unsigned char HighAdd;                    //High Order Address Byte
extern unsigned char LowAdd;                     //Low Order Address Byte
extern unsigned char Data;                       //Data Byte
extern unsigned char Length;*/                     //Length of bytes to read
//extern unsigned int  PageSize;                   //Page size in bytes
//extern unsigned char PageString[64];             // Holds the device page data to/from EEPROM

/*-----------------------------------------------------------------------------------------*/
/*//Function Prototypes
unsigned char putstringI2C( unsigned char *);

extern unsigned char LDByteWriteI2C( unsigned char, unsigned char, unsigned char );
extern unsigned char LDByteReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);
extern unsigned char LDPageWriteI2C(unsigned char, unsigned char, unsigned char *);
extern unsigned char LDSequentialReadI2C(unsigned char, unsigned char, unsigned char *, unsigned char);

extern unsigned char HDByteWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned char HDByteReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
extern unsigned char HDPageWriteI2C( unsigned char, unsigned char, unsigned char, unsigned char *);
extern unsigned char HDSequentialReadI2C(unsigned char, unsigned char, unsigned char, unsigned char *, unsigned char );

extern void Initialize_I2C ( void );
*/

/*-----------------------------------------------------------------------------------------*/
#define     SCL         PORTBbits.RB1   // I2C clock, PORTC pin 1
#define     SDA         PORTBbits.RB0   // I2C data, PORTC pin 0
#define     SDA_TRIS    TRISBbits.TRISB0// SDA tris bit, PORTC pin 0
#define     ACKBIT      0x00            // ACK bit
#define     NAKBIT      0x80            // NAK bit

/*-----------------------------------------------------------------------------------------*/
void ACK_Poll(unsigned char);           // Acknowledge polling
void bstart(void);                      // Start condition
void bstop(void);                       // Stop condition
void bit_in(unsigned char*);   			// Bit input function
void bit_out(unsigned char);   			// Bit output function

unsigned char byte_out(unsigned char);  // Byte output
unsigned char byte_in(unsigned char);   // Byte input

extern void LDByteWriteI2C(unsigned char, unsigned char, unsigned char);  
extern void LDPageWriteI2C(unsigned char, unsigned char, unsigned char*, unsigned char);
extern void LDByteReadI2C(unsigned char, unsigned char, unsigned char*);
extern void LDSequentialReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);

extern void HDByteWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char);
extern void HDPageWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
extern void HDByteReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*,unsigned char);
extern void HDSequentialReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);

/*-----------------------------------------------------------------------------------------*/

#endif

