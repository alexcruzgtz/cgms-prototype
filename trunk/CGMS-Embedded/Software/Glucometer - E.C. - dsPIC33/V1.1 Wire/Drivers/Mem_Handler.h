

/*-----------------------------------------------------------------------------------------*/
/*#ifndef E2PHANDLER_H
#define E2PHANDLER_H
/*
/*-----------------------------------------------------------------------------------------*/
/*#define INTERNAL_E2P 0
#define EXTERNAL_E2P 1

#define EEPROM_VALID 	1
#define EEPROM_INVALID 	0

#define E2P_TYPE 	EXTERNAL_E2P
*/
/*-----------------------------------------------------------------------------------------*/
/*#define AMOUNT_OF_MEASURES_TO_SAVE	7200

extern void Update_E2P(void);
extern void Initialize_EEPROM(void);

extern unsigned char MeasuresDone;
extern unsigned char FlagMeasuresComplete;

extern unsigned int Actual_ISIG_Addr;
extern unsigned int Actual_GO_Addr;
extern unsigned int Actual_GOCAL_Addr;
extern unsigned int Actual_VSEN_Addr;
extern unsigned int Actual_TIMEMEAS_Addr;

typedef enum
{
	E_READ_ISIG_ADDR,
	E_READ_GLU_ADDR,
	E_READ_GLU_cal_ADDR,
	E_READ_VSEN_ADDR,
	E_READ_TIME_ADDR,
	E_VALIDATE_ADDR,
	E_UPDATE_ISIG,
	E_UPDATE_GLU,
	E_UPDATE_GLU_cal,
	E_UPDATE_VSEN,
	E_UPDATE_TIME,
	E_UPDATE_ISIG_ADDR,
	E_UPDATE_GLU_ADDR,
	E_UPDATE_GLU_cal_ADDR,
	E_UPDATE_VSEN_ADDR,
	E_UPDATE_TIME_ADDR,
	E_EEPROM_OK,
	E_EEPROM_CORRUPTED,
	E_EEPROM_FULL,
	E_EEPROM_RESTORE
}EEPROM_STATUS;
extern EEPROM_STATUS EEPROM_Status;	

*/
/*-----------------------------------------------------------------------------------------*/
/* Functions definitions for EEPROM memory */
/*-----------------------------------------------------------------------------------------*/

/* Functions definitions for internal Memory *
#if ( E2P_TYPE == INTERNAL_E2P )
	#define E2P_WRITE(A,B)	Write_b_eep(A,B)	
	#define E2P_READ(A)  Read_b_eep(A)
	#define E2P_BUSY()  Busy_eep()
#endif

/ Functions definitions for external Memory *
#if ( E2P_TYPE == EXTERNAL_E2P )
	/ Funtions for Low Density I2C devices *
	#if ( EEPROM_SIZE <= 2048 )
		#define E2P_BYTE_WRITE( A, B, C )		LDByteWriteI2C( A, B, C );
		#define E2P_PAGE_WRITE( A, B, C, D ) 	LDPageWriteI2C( A, B, C );
		#define E2P_BYTE_READ( A, B, C, D ) 		LDByteReadI2C( A, B, C, D);
		#define E2P_SEQ_READ( A, B, C, D )		LDSequentialReadI2C( A, B, C, D );
	#endif
	/ Funtions for High Density I2C devices *
#if ( EEPROM_SIZE > 2048 )
		#define E2P_BYTE_WRITE( A, B, C )		HDByteWriteI2C( A, B, C, D);
		#define E2P_PAGE_WRITE( A, B, C, D ) 	HDPageWriteI2C( a, B, C, D);
		#define E2P_BYTE_READ( A, B, C, D, E ) 		HDByteReadI2C( A, B, C, D, E);
		#define E2P_SEQ_READ( A, B, C, D )		HDSequentialReadI2C( A, B, C, D, E
	#endif
#endif
*/

//#endif