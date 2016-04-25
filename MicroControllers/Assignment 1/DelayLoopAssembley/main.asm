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
i     dc.w 2000
j     dc.w 2000


; code section
MyCode:     SECTION
main:
_Startup:
Entry:
            LDS  #__SEG_END_SSTACK     ; initialize the stack pointer
            
            BSET DDRB, $FF             ; set PortB pins as output
            BCLR PORTB, $FF            ; clear PortB output bits
            LDAA #0

EndlessLoop:    
            BSR   Delay                          
            INCA                       ; count++
            STAA  PORTB
            BRA   EndlessLoop          ; restart.

; Delay Function
Delay:
            PSHX
            PSHY
            
            LDY j              ; y = 2000
OuterLoop:
            LDX i              ; x = 2000
InnerLoop:  DBNE X, InnerLoop         ; loop while x > 0          
            DBNE Y, OuterLoop         ; loop while y > 0       \
            
            PULY
            PULX
            RTS
