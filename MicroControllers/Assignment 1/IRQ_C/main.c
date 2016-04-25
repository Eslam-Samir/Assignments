#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

unsigned int count;

#pragma CODE_SEG __NEAR_SEG NON_BANKED

interrupt void ISR( void )
{   
  count = (count+1)%256;
  PORTB = count;
}

void main(void) {
  DDRB = 0xFF;
  PORTB = 0x00;
  count = 0;
	INTCR = 0xC0;
  EnableInterrupts;


  for(;;) {
  } /* loop forever */
  
}
