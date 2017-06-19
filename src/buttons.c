#include <stdio.h>
#include <string.h>
#include <pic18f4550.h>
#include <xc.h>
#include "../inc/buttons.h"

#define _XTAL_FREQ  16000000

void initButons(){
    TRISD = TRISD | 0b00001111;
}

int buttons(){
    int press = UNPRESS;
    if(!BUTTON_1){
        if(press != UNPRESS){
            return ERROR;
        }
        press = B1;
    }
    if(!BUTTON_2){
        if(press != UNPRESS){
            return ERROR;
        }
        press = B2;
    }
    if(!BUTTON_3){
        if(press != UNPRESS){
            return ERROR;
        }
        press = B3;
    }
    return press;
}

