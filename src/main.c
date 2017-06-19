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
    int button, tentativas, senha, senha_gravada = 123;
    TRISB = 0;
    initButons();
    while(1){
        waitPassLCD();
        tentativas = 3;
        senha = 0;
        
        while(senha < 100){
            //lê teclado
            button = buttons();
            __delay_ms(200);

            //verifica se digitou
            if(button == UNPRESS){
                continue;
            }

            //digitou
            passLCD();
            atualiza_senha_digitada(button, tentativas, senha);
        }
        
        if(senha == senha_gravada){
            senha_correta();
        }else{
            senha_incorreta(tentativas);
        }        
    }    
    return (EXIT_SUCCESS);
}
