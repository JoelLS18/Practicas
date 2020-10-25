
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
int cont=0;
void __interrupt() usart(void){
    if(PIR1bits.RCIF==1){
    entrada=RCREG;
    if(entrada=='A'){
    cont=1;
  }
    if(entrada=='B'){
    cont=0;
  }
    }
          
}
void main(void) {
    OSCCONbits.IRCF=0b111;
    OSCCONbits.SCS=0b00;
    
    ANSEL=0B00000000;
    ANSELH=0B00000000;
    TRISB=0b11111111;
    TRISD=0b00000000;
    TRISC=0b00000000;
    TRISA=0b00000011;
    PORTB=0b00000000;
    PORTD=0b00000000;
    PORTC=0b00000000;
    OPTION_REGbits.nRBPU=0;
    WPUBbits.WPUB=1;
    OPTION_REGbits.INTEDG=1;
    
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    INTCON=0B11000000;
    PIE1=0b00100000;
    TXSTA=0b00100010;
    BAUDCTL=0b00000000;
    RCSTA=0b10010000;
    SPBRG=12;
    while(1){
        while(cont==1){
  PORTCbits.RC1=1;
  }
    while(cont==0){
    PORTCbits.RC1=0; 
    }
    }
    return;
}
