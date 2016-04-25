#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

unsigned int count, RTIcount;

#pragma CODE_SEG __NEAR_SEG NON_BANKED

interrupt void timer_irq( void )
{ /* At interrupt, clear interrupt request */
  *( unsigned char *) 0x0037 |= 0x80;
  if(RTIcount == 90) 
  {    
    RTIcount = 0;
    count = (count+1)%256;
    PORTB = count;
  } 
  else 
  {
    RTIcount++;
  }
}

void timer_init(void) 
{
  //*(unsigned short *) 0xFFF0 = (unsigned short) timer_irq; /* defined in Project.prm file */
  /* Enable RTI interrupts */
  *(unsigned char *) 0x0038 = 0x80;
  /* Time base for interrupts */
  *(unsigned char *) 0x003B = 0x73;
  /* Clear CPU I-flag to enable interrupts */
  EnableInterrupts;
}


void main(void) {
  DDRB = 0xFF;
  PORTB = 0;
  count = 0;
  RTIcount = 0;
  timer_init();
  for(;;){
  }
  /* please make sure that you never leave main */
}
