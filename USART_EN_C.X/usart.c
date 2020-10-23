
#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 8000000
// CONFIG1
#pragma config FOSC = INTRC_CLKOUT
#pragma config WDTE = OFF       
#pragma config PWRTE = ON       
#pragma config MCLRE = ON       
#pragma config CP = OFF         
#pragma config CPD = OFF       
#pragma config BOREN = ON      
#pragma config IESO = ON        
#pragma config FCMEN = ON       
#pragma config LVP = OFF       

// CONFIG2
#pragma config BOR4V = BOR40V   
#pragma config WRT = OFF        
unsigned char entrada;
void __interrupt() usart(void){
      if(PIR1bits.RCIF==1){
            entrada=RCREG;
            while(TXSTAbits.TRMT==0);
            TXREG=entrada;
            __delay_ms(10);
        }  
          
}
void main(void) {
    OSCCONbits.IRCF=0b1110;
    OSCCONbits.SCS=0b00;
    ANSEL=0B00000000;
    ANSELH=0B00000000;
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    INTCON=0B11000000;
    PIE1=0b00100000;
    TXSTA=0b00100110;
    BAUDCTL=0b00000000;
    RCSTA=0b10010000;
    SPBRG=12;
    while(1){
        
    }
    return;
}
