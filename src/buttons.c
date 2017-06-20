#include <stdio.h>
#include <string.h>
#include <pic18f4550.h>
#include <xc.h>
#include "../inc/buttons.h"
#include "../inc/main.h"
#include "../inc/lcd16x2.h"

#define _XTAL_FREQ  16000000

void initButons(){
    config_int0();
    config_int1();
    config_int2();
}

void button_1(){
    senha = (senha * 10) + 1;
    digitoLCD();
    __delay_ms(500);
}

void button_2(){
    senha = (senha * 10) + 2;
    digitoLCD();
    __delay_ms(500);
}

void button_3(){ 
    senha = (senha * 10) + 3;
    digitoLCD();
    __delay_ms(500);
}
