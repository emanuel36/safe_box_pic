#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pic18f4550.h>
#include "../inc/main.h"
#include "../inc/lcd16x2.h"
#include "../inc/buttons.h"
#include "../inc/cofre.h"
#include "../inc/pwm.h"

int main(){
    OSCCON = 0x72;
    int senha_gravada = 213;
    PWM_Init(); 
    Period = setPeriodTo(50); 
    initLCD();
    initButons();
    init_alarme();
    init_sensor_magnetico();
    init_lampada();
    cofreLigado();
    trava_cofre();
    __delay_ms(1000);

    while(1){
        waitPassLCD();
        senha = 0; 
        while(senha < 100){
            if(porta_aberta() && ALARME == 0){
                alarme(1);
            }
            scanButtons();
        }
        if(senha == senha_gravada){
            senha_correta();
        }else{
            senha_incorreta();
        }       
        flag = 0;
    }
}