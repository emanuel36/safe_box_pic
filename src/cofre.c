#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>
#include "../inc/buttons.h"

void senha_incorreta(int tentativas){
    tentativas--;
    if(tentativas <= 0){
        //Atualiza Senha
        //Alarma
        //Aguarda Senha
    }
}

void senha_correta(){
    //Desliga Alarme
    //Atualiza Display
    //Acende Lâmpada
    //Destrava Porta
    //Verifica se a porta foi fechada
}

void atualiza_senha_digitada(int button, int tentativas, int senha){
    switch(button){
        case B1:
            digitoLCD();
            senha = (senha * 10) + 1;
            break;
        case B2:
            digitoLCD();
            senha = (senha * 10) + 2;
            break;
        case B3:
            digitoLCD();
            senha = (senha * 10) + 3;
            break;   
        default:
           senha_incorreta(tentativas);
           break;
    }
}
