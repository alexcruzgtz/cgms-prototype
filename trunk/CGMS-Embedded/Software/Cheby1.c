/******************************* SOURCE LICENSE *********************************
Copyright (c) 2013 MicroModeler.

A non-exclusive, nontransferable, perpetual, royalty-free license is granted to the Licensee to 
use the following Information for academic, non-profit, or government-sponsored research purposes.
Use of the following Information under this License is restricted to NON-COMMERCIAL PURPOSES ONLY.
Commercial use of the following Information requires a separately executed written license agreement.

This Information is distributed WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

******************************* END OF LICENSE *********************************/

// A commercial license for MicroModeler DSP can be obtained at http://www.micromodeler.com/launch.jsp

#include "filter1.h"

#include <stdlib.h> // For malloc/free
#include <string.h> // For memset

short filter1_coefficients[10] = 
{
// Scaled for a 16x16:32 Direct form 1 IIR filter with: 
// Feedback shift = 14
// Output shift = 14
// Input  has a maximum value of 1, scaled by 2^15
// Output has a maximum value of 3.2508389277707788, scaled by 2^13

    5101, 10202, 5101, -21482, -7954,// b0 Q12(1.25), b1 Q12(2.49), b2 Q12(1.25), a1 Q14(-1.31), a2 Q14(-0.485)
    4096, 8192, 4096, -29713, -14704// b0 Q13(0.500), b1 Q13(1.00), b2 Q13(0.500), a1 Q14(-1.81), a2 Q14(-0.897)

};


filter1Type *filter1_create( void )
{
	filter1Type *result = (filter1Type *)malloc( sizeof( filter1Type ) );	// Allocate memory for the object
	filter1_init( result );											// Initialize it
	return result;																// Return the result
}

void filter1_destroy( filter1Type *pObject )
{
	free( pObject );
}

 void filter1_init( filter1Type * pThis )
{
	filter1_reset( pThis );

}

 void filter1_reset( filter1Type * pThis )
{
	memset( &pThis->state, 0, sizeof( pThis->state ) ); // Reset state to 0
	pThis->output = 0;									// Reset output

}

 int filter1_filterBlock( filter1Type * pThis, short * pInput, short * pOutput, unsigned int count )
{
	filter1_executionState executionState;          // The executionState structure holds call data, minimizing stack reads and writes 
	if( ! count ) return 0;                         // If there are no input samples, return immediately
	executionState.pInput = pInput;                 // Pointers to the input and output buffers that each call to filterBiquad() will use
	executionState.pOutput = pOutput;               // - pInput and pOutput can be equal, allowing reuse of the same memory.
	executionState.count = count;                   // The number of samples to be processed
	executionState.pState = pThis->state;                   // Pointer to the biquad's internal state and coefficients. 
	executionState.pCoefficients = filter1_coefficients;    // Each call to filterBiquad() will advance pState and pCoefficients to the next biquad

	// The 1st call to filter1_filterBiquad() reads from the caller supplied input buffer and writes to the output buffer.
	// The remaining calls to filterBiquad() recycle the same output buffer, so that multiple intermediate buffers are not required.

	filter1_filterBiquad_14_14( &executionState );		// Run biquad #0
	executionState.pInput = executionState.pOutput;         // The remaining biquads will now re-use the same output buffer.

	filter1_filterBiquad_14_14( &executionState );		// Run biquad #1

	// At this point, the caller-supplied output buffer will contain the filtered samples and the input buffer will contain the unmodified input samples.  
	return count;		// Return the number of samples processed, the same as the number of input samples

}

 void filter1_filterBiquad_14_14( filter1_executionState * pExecState )
{

	// Read state variables
	short x0;
	short x1 = pExecState->pState[0];
	short x2 = pExecState->pState[1];
	short y1 = pExecState->pState[2];
	short y2 = pExecState->pState[3];

	// Read coefficients into work registers
	short b0 = *(pExecState->pCoefficients++);
	short b1 = *(pExecState->pCoefficients++);
	short b2 = *(pExecState->pCoefficients++);
	short a1 = *(pExecState->pCoefficients++);
	short a2 = *(pExecState->pCoefficients++);

	// Read source and target pointers
	short *pInput  = pExecState->pInput;
	short *pOutput = pExecState->pOutput;
	short count = pExecState->count;
	long accumulator;

	while( count-- )
	{
		x0 = *(pInput++);
	
		accumulator  = x2 * b2;
		accumulator += x1 * b1;
		accumulator += x0 * b0;
	
		x2 = x1;		// Shuffle left history buffer
		x1 = x0;
	
		accumulator += y2 * a2;
		accumulator += y1 * a1;
	
		y2 = y1;		// Shuffle right history buffer
		y1 = accumulator  >> 14;
	
		*(pOutput++) = accumulator  >> 14;
	}

	*(pExecState->pState++) = x1;
	*(pExecState->pState++) = x2;
	*(pExecState->pState++) = y1;
	*(pExecState->pState++) = y2;


}


