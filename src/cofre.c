#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>
#include "../inc/buttons.h"
#include "../inc/main.h"
#include "../inc/lcd16x2.h"
#include "../inc/cofre.h"

void senha_incorreta(){
    tentativas--;
    wrongPassLCD(tentativas);
    if(tentativas <= 0){
        alarme(1);    //Alarma
    }
    __delay_ms(800);
}

void senha_correta(){
    alarme(0);  //Desliga Alarme
    correctPassLCD();   //Atualiza Display
    lampada(1);     //Acende L�mpada
    abre_servo();   //Destrava Porta
    tentativas = 3;
    __delay_ms(5000);
    while(porta_aberta());
    trava_cofre();
}

void init_alarme(){
    TRISBbits.RB4 = 0;
}

void init_sensor_magnetico(){
    TRISBbits.RB5 = 1;
}

int porta_aberta(){
    return !(SENSOR_MAGNETICO);
}

void alarme(int valor){
    if(valor){
        ALARME = 1;
    }else{
        ALARME = 0;
    }
}

void init_lampada(){
    TRISBbits.RB6 = 0;
    PORTBbits.RB6 = 0;
}

void lampada(int valor){
    if(valor){
        LAMPADA = 1;
    }else{
        LAMPADA = 0;
    }
}