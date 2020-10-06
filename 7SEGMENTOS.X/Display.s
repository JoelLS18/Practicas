PROCESSOR 16F887
#include <xc.inc>
;CONFIG word1
CONFIG FOSC = INTRC_NOCLKOUT
CONFIG WDTE = OFF
CONFIG PWRTE = ON
CONFIG MCLRE = OFF
CONFIG CP = OFF
CONFIG CPD = OFF
CONFIG BOREN = OFF
CONFIG IESO = OFF
CONFIG FCMEN = ON
CONFIG DEBUG = ON
;CONFIG word2
CONFIG BOR4V=BOR40V
CONFIG WRT = OFF
PSECT udata
var1:
    DS 1
var2:
    DS 1
var3:
    DS 1
PSECT resetVec,class=CODE,delta=2
resetVec:
PAGESEL main
goto main
    
PSECT code
N0:
BANKSEL PORTB
movlw 0b00111111
movwf PORTB
PAGESEL main
return

PSECT code
N1:
BANKSEL PORTB
movlw 0b00000110
movwf PORTB
PAGESEL main
return

PSECT code
N2:
BANKSEL PORTB
movlw 0b01011011
movwf PORTB
PAGESEL main
return
    
PSECT code
N3:
BANKSEL PORTB
movlw 0b01001111
movwf PORTB
PAGESEL main
return    

PSECT code
N4:
BANKSEL PORTB
movlw 0b01100110
movwf PORTB
PAGESEL main
return

PSECT code
N5:
BANKSEL PORTB
movlw 0b01101101
movwf PORTB
PAGESEL main
return
   
PSECT code
N6:
BANKSEL PORTB
movlw 0b01111101
movwf PORTB
PAGESEL main
return

PSECT code
N7:
BANKSEL PORTB
movlw 0b00000111
movwf PORTB
PAGESEL main
return

PSECT code
N8:
BANKSEL PORTB
movlw 0b01111111
movwf PORTB
PAGESEL main
return

PSECT code
N9:
BANKSEL PORTB
movlw 0b01101111
movwf PORTB
PAGESEL main
return

PSECT code
delay_255us:
movlw   255
movwf   var3
decfsz var3
goto $-1
return

PSECT code
delay_65ms:
movlw   255
movwf   var2
call delay_255us
decfsz var2
goto $-2
return
 
PSECT code
delay_500ms:
movlw   0x08
movwf var1
call delay_65ms
decfsz  var1
goto $-2
return
   
PSECT code
main:
bcf STATUS,0
bcf STATUS,5
bcf STATUS,6
BANKSEL ANSELH
CLRF ANSELH
BANKSEL TRISB
MOVLW 0b00000000
MOVWF TRISB
BANKSEL PORTB
CLRF PORTB
BANKSEL OSCCON
MOVLW  0b01110000
MOVWF  OSCCON
INICIO:
call N0
call delay_500ms
call N1
call delay_500ms
call N2
call delay_500ms   
call N3
call delay_500ms
call N4
call delay_500ms
call N5
call delay_500ms
call N6
call delay_500ms
call N7
call delay_500ms
call N8
call delay_500ms
call N9
call delay_500ms
GOTO INICIO
END


