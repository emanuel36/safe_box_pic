#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>

#define PORTA_FECHADA 0


#define _XTAL_FREQ  16000000

void trava_servo(){
    PORTCbits.RC2 = 1;
    __delay_us(3500);
    PORTCbits.RC2 = 0;
    __delay_us(16500);
}

void abre_servo(){
    PORTCbits.RC2 = 1;
    __delay_us(1000);
    PORTCbits.RC2 = 0;
    __delay_us(19000);
}

void trava_cofre(){
    while(1){
        if(PORTA_FECHADA){
            trava_servo();
        }
        __delay_ms(700);
        if(PORTA_FECHADA){
            break;
        }
        abre_servo();
        __delay_ms(700);
    }
}