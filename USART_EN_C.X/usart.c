/*
 * File:   primerintento.c
 * Author: ferma
 *
 * Created on 29 de septiembre de 2020, 12:10 AM
 */
#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 8000000
// CONFIG1
#pragma config FOSC = INTRC_CLKOUT// Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
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
