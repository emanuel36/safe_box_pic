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