#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pic18f4550.h>
#include "../inc/main.h"
#include "../inc/lcd16x2.h"
#include "../inc/buttons.h"

#define LED1 PORTBbits.RB0
#define LED2 PORTBbits.RB1
#define LED3 PORTBbits.RB2
#define LED4 PORTBbits.RB3

#define _XTAL_FREQ  8000000

int main(){
    int button;
    TRISB = 0;
    initButons();
    while(1){
        button = buttons();
        switch(button){
            case CLR:
                LED1 = 1;
                break;
            case B1:
                LED2 = 1;
                break;
            case B2:
                LED3 = 1;
                break;
            case B3:
                LED4 = 1;
                break;
            default:
                LED1 = 0;
                LED2 = 0;
                LED3 = 0;
                LED4 = 0;
        }
    }
    return (EXIT_SUCCESS);
}
