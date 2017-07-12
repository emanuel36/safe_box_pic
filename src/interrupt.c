#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>
#include "../inc/main.h"

void reset_interrupt(){
    INTCON = 0x0;
}

void config_tmr0(){
    INTCONbits.PEIE_GIEL = 1;
    T0CON = 0x00;
    T0CONbits.TMR0ON = 1;
    T0CONbits.T0PS = 3;
    INTCON2bits.TMR0IP = 1;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE_GIEH = 1;
}

void config_int0(){
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB0 = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    INTCONbits.GIE_GIEH = 1;
}

void config_int1(){
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB1 = 1;
    INTCON2bits.INTEDG2 = 0;
    INTCON3bits.INT2IF = 0;
    INTCONbits.GIE_GIEH = 1;
    INTCON3bits.INT1IE = 1;
}

void config_int2(){
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB2 = 1;
    INTCON2bits.INTEDG2 = 0;
    INTCON3bits.INT2IF = 0;
    INTCON3bits.INT2E = 1;
    INTCONbits.GIE_GIEH = 1;
}

void interrupt ISR(){
    if(INTCONbits.INT0IF){
        INTCONbits.GIE_GIEH = 0;  //Botão 1 pressionado
        INTCONbits.INT0IF = 0;
        interrupt_flag = interrupt_flag | INT0;
    }
    
    if(INTCON3bits.INT1IF){     //Botão 2 pressionado    
        INTCONbits.GIE_GIEH = 0;
        INTCON3bits.INT1IF = 0;
        interrupt_flag = interrupt_flag | INT1;
    }
    
    if(INTCON3bits.INT2IF){     //Botão 3 pressionado
        INTCONbits.GIE_GIEH = 0;
        INTCON3bits.INT2F = 0; 
        interrupt_flag = interrupt_flag | INT2;
    }
}