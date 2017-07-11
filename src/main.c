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

int main(){
    OSCCON = 0x72;
    int tentativas = 3, senha_gravada = 123;
    initLCD();
    initButons();
    init_alarme();
    init_sensor_magnetico();
    init_lampada();
    //trava_cofre();
    waitPassLCD();
    while(1){
        waitPassLCD();
        senha = 0; 
        while(senha < 1000){
            if(porta_aberta()){
                alarme(1);
            }
            scanButtons();
        }
        
        if(senha == senha_gravada){
            senha_correta(tentativas);
        }else{
            senha_incorreta(tentativas);
        }       
        flag = 0;
    }
}