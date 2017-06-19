#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>

#define _XTAL_FREQ  16000000

void trava_cofre(){
    PORTCbits.RC2 = 1;
    __delay_us(3500);
    PORTCbits.RC2 = 0;
    __delay_us(16500);
}

void abre_cofre(){
    PORTCbits.RC2 = 1;
    __delay_us(1000);
    PORTCbits.RC2 = 0;
    __delay_us(19000);
}