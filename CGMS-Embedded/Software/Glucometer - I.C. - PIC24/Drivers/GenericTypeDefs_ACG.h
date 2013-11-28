/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*																	 */
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef __GENERIC_TYPE_DEFS_H_
#define __GENERIC_TYPE_DEFS_H_
/*-------------------------------------------------------------------*/

typedef enum _BOOL { FALSE = 0, TRUE } BOOL;    /* Undefined size */
typedef enum _BIT { CLEAR = 0, SET } BIT;

typedef signed char         int8_t;
typedef signed int          int16_t;
typedef signed long 	    int32_t;
typedef signed long long    int64_t;

typedef unsigned char       uint8_t;
typedef unsigned int        uint16_t;
typedef unsigned long	  	uint32_t;
typedef unsigned long long  uint64_t;

typedef char                char_t;
typedef unsigned char       uchar_t;

typedef unsigned char		byte_t;            
typedef unsigned int	    word_t;            
typedef unsigned long       dword_t;           

/*-------------------------------------------------------------------*/
#endif
