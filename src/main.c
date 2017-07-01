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
    int tentativas, senha_gravada = 123;
    initLCD();
    initButons();
    while(1){
    /*  abre_servo();
        trava_cofre();
        waitPassLCD();
        tentativas = 3;
        */senha = 0; 
            waitPassLCD();
        while(senha < 10000){
            scanButtons();
        }
        
        if(senha == senha_gravada){
            senha_correta();
        }else{
            senha_incorreta(tentativas);
        }          
        flag = 0;
    }
}