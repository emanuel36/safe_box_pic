#include <stdio.h>
#include <string.h>
#include <pic18f4550.h>
#include <xc.h>
#include "../inc/interrupt.h"
#include "../inc/buttons.h"
#include "../inc/main.h"
#include "../inc/lcd16x2.h"

void initButons(){
    config_int0();
    config_int1();
    config_int2();
}

void button_1(){
    senha = (senha * 10) + 1;
    //digitoLCD(); 
    writeLCD("1");
}

void button_2(){
    senha = (senha * 10) + 2;
    //digitoLCD();
    writeLCD("2");
}

void button_3(){ 
    senha = (senha * 10) + 3;
    //digitoLCD();
    writeLCD("3");
}

void scanButtons(){
    if(interrupt_flag & INT0){
        interrupt_flag = 0;
        if(!flag){
            passLCD();
            flag = 1;
        }
        button_1();
        __delay_ms(500);
        INTCONbits.GIE_GIEH = 1;
    }
        
    if(interrupt_flag & INT1){
        interrupt_flag = 0;
        if(!flag){
            passLCD();
            flag = 1;
        }
        button_2();
        __delay_ms(500);
        INTCONbits.GIE_GIEH = 1;
    }
        
    if(interrupt_flag & INT2){
        interrupt_flag = 0;
        if(!flag){
            passLCD();
            flag = 1;
        }
        button_3();
        __delay_ms(500);
        INTCONbits.GIE_GIEH = 1;
    }
}