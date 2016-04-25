;**************************************************************
;* This stationery serves as the framework for a              *
;* user application. For a more comprehensive program that    *
;* demonstrates the more advanced functionality of this       *
;* processor, please see the demonstration applications       *
;* located in the examples subdirectory of the                *
;* Freescale CodeWarrior for the HC12 Program directory       *
;**************************************************************
; Include derivative-specific definitions
            INCLUDE 'derivative.inc'

; export symbols
            XDEF Entry, _Startup, main
            ; we use export 'Entry' as symbol. This allows us to
            ; reference 'Entry' either in the linker .prm file
            ; or from C/C++ later on

            XREF __SEG_END_SSTACK      ; symbol defined by the linker for the end of the stack




; variable/data section
MY_EXTENDED_RAM: SECTION
; Insert here your data definition.
count       ds.b 1                      ; reserve 1 byte in RAM for count


; code section
MyCode:     SECTION
main:
_Startup:
Entry:
            LDS   #__SEG_END_SSTACK     ; initialize the stack pointer
            CLR   count
            movb  #$FF,DDRB             ; configure Port B for output
            movb  count,PORTB           ; clear LEDs
            movb  #$C0,INTCR            ; enable IRQ and select edge triggering
            CLI                         ; enable interrupts

EndlessLoop:BRA   EndlessLoop           ; infinite loop





; This is the IRQ service routine.
ISR:        inc   count                 ; increment count
            movb  count, PORTB          ; and display count on LEDs
            rti
            
            org   $FFF2
            dc.w  ISR