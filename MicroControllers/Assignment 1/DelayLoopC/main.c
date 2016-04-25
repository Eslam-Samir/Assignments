#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

void delay(int ms) {
  unsigned int i, j;
  for(i = 0; i < ms; i++){
    for(j = 0; j < 2000; j++); // wait  
  }
  
}

void main(void) {
  /* put your own code here */
  unsigned int count = 0;  
  DDRB = 0xFF;
  PORTB = 0;

  for(;;) {
    delay(500);
    count = (count+1)%256;
    PORTB = count;
  } /* loop forever */
  /* please make sure that you never leave main */
}
