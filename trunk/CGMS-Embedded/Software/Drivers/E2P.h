
#ifndef __EEP_H
#define __EEP_H

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+ Data space is designed to save 7200 measurements of glucose.
+ One measurement every minute for 5 days.
+ Algorithm save data of Isig, Gx, GxCal, VolCNT-REF and TimeMeas.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define EEPROM_SIZE		128000		//1Mbit Memory
#define ADDR_OFFSET		14402
/*
#define ISIG_ADDR		0x0000
#define GLU_ADDR		0x3843
#define GLU_cal_ADDR	0x7085
#define VSEN_ADDR		0xA8C7
#define TIME_ADDR		0xE109
*/
#define ISIG_ADDR_1 	0x00		//address values that stores the address of the last data stored
#define ISIG_ADDR_2 	0x00		//Isig, GO, GxCal and VolCNT-REF need 14402 Bytes
#define GLU_ADDR_1		0x43		//14403 address
#define GLU_ADDR_2		0x38
#define GLU_cal_ADDR_1	0x85		//28805 address
#define GLU_cal_ADDR_2	0x70
#define VSEN_ADDR_1		0xC7		//43207 address
#define VSEN_ADDR_2		0xA8
#define TIME_ADDR_1		0x09		//57609 address
#define TIME_ADDR_2		0xE1

#define CONTROLBYTE_E2P 0B10100000
	
#endif

