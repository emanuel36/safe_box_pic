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

#define _XTAL_FREQ  16000000

int main(){
    int tentativas, senha_gravada = 123;
    
    while(1){
        abre_servo();
        trava_cofre();
        waitPassLCD();
        tentativas = 3;
        senha = 0;
        
        while(senha < 100){
            if(senha == 0){
                passLCD();
            }
        }
        
        if(senha == senha_gravada){
            senha_correta();
        }else{
            senha_incorreta(tentativas);
        }        
    }    
}