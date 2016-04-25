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
count       ds.b 1
RTIcount    ds.b 1

; code section
MyCode:     SECTION
main:
_Startup:
Entry:
            LDS  #__SEG_END_SSTACK     ; initialize the stack pointer

            CLR   count
            movb  #$5B, RTIcount       ; RTIcount = 91
            movb  #$FF, DDRB           ; configure Port B for output
            movb  count, PORTB         ; clear LEDs
            movb  #$80, CRGINT
            movb  #$73, RTICTL
            CLI                        ; enable interrupts
wLoop       bra   wLoop;

timer_isr:
            bset  CRGFLG, #$80
            TST   RTIcount             ; compare RTIcount with 0
            BNE   decRTIcount          ; if(RTIcount != 0)
            movb  #$5B, RTIcount       ; RTIcount = 91
            inc   count                ; count++
            movb  count, PORTB         ; PORTB = count
            bra   finish
decRTIcount:       
            dec   RTIcount             ; RTIcount--            
finish:     rti
            
            org   $FFF0
            dc.w  timer_isr
            end