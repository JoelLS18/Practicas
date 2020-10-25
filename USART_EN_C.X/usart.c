
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
int entrada;
int entrada1;
int envio=0;
int cont=0;
void main(void) {
    OSCCONbits.IRCF=0b111;
    OSCCONbits.SCS=0b00;
    
    ANSEL=0B00000000;
    ANSELH=0B00000000;
    TRISB=0b11111111;
    TRISD=0b00000000;
    TRISA=0b00000000;
    PORTB=0b00000000;
    PORTD=0b00000000;
    OPTION_REGbits.nRBPU=0;
    WPUBbits.WPUB=1;
    OPTION_REGbits.INTEDG=1;
    
    TRISCbits.TRISC6=0;
    TRISCbits.TRISC7=1;
    INTCON=0B00000000;
    PIE1=0b00000000;
    TXSTA=0b00100010;
    BAUDCTL=0b00000000;
    RCSTA=0b10010000;
    SPBRG=12;
    while(1){
        while(cont==1){
      if(envio==1){
  entrada1=66;
  while(TXSTAbits.TRMT==0);
    TXREG=entrada1;
    envio=0;
      }
 // PORTDbits.RD1=1;
  if(PORTBbits.RB6==0){
      envio=0;
      cont=0;
  }
  }
    while(cont==0){
   if(envio==0){
    entrada=65;
    while(TXSTAbits.TRMT==0);
    TXREG=entrada;
    envio=1;
    }
   // PORTDbits.RD1=0;
    if(PORTBbits.RB7==0){
        envio=1;
        cont=1;
    }
    }
    }
    return;
}
