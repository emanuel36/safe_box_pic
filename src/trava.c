#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>
#include "../inc/main.h"
#include "../inc/pwm.h"
#include "../inc/cofre.h"

void trava_servo(){
    SetDutyCycleTo(16.0, Period);//3
    __delay_ms(800);
    SetDutyCycleTo(0.0, Period);//3
}

void abre_servo(){
    SetDutyCycleTo(3.0, Period);
}

void trava_cofre(){
    trava_servo();
    /*while(1){
        if(!porta_aberta()){
            trava_servo();
        }
        __delay_ms(700);
        if(!porta_aberta()){
            break;
        }
        abre_servo();
        __delay_ms(700);
    }*/
    lampada(0);
}