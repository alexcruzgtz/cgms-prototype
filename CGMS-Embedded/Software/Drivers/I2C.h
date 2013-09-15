

#ifndef I2C_H
#define I2C_H

#define     SCL         PORTCbits.RC1   // I2C clock, PORTC pin 1
#define     SDA         PORTCbits.RC0   // I2C data, PORTC pin 0
#define     SDA_TRIS    TRISCbits.TRISC0// SDA tris bit, PORTC pin 0
#define     ACKBIT      0x00            // ACK bit
#define     NAKBIT      0x80            // NAK bit


void bstart(void);                      // Start condition
void bstop(void);                       // Stop condition
unsigned char byte_out(unsigned char);  // Byte output
unsigned char byte_in(unsigned char);   // Byte input
void ACK_Poll(unsigned char);           // Acknowledge polling

void LD_ByteWrite(unsigned char, unsigned int, unsigned char);  
void LD_PageWrite(unsigned char, unsigned int, unsigned char*, unsigned char);
void LD_ByteRead(unsigned char, unsigned int, unsigned char*);
void LD_SequentialRead(unsigned char, unsigned int, unsigned char*, unsigned int);
void HD_ByteWrite(unsigned char, unsigned int, unsigned char);
void HD_PageWrite(unsigned char, unsigned int, unsigned char*, unsigned char);
void HD_ByteRead(unsigned char, unsigned int, unsigned char*);
void HD_SequentialRead(unsigned char, unsigned int, unsigned char*, unsigned int);

#endif