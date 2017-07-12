#include <stdio.h>
#include <string.h>
#include <pic18f4550.h>
#include <xc.h>
#include "../inc/lcd16x2.h"
#include "../inc/main.h"

void enableLCD(){
    PORTEbits.RE1 = 0;//ENABLE
    __delay_ms(1);
    PORTEbits.RE1 = 1;
    __delay_ms(1);
    PORTEbits.RE1 = 0;
    __delay_ms(1);
}

void sendASCII(char letra){
    PORTBbits.RB3 = 1;//RS
    PORTD = letra;
    __delay_ms(1);
    enableLCD();
    __delay_ms(1);
    PORTBbits.RB3 = 0;
}

void sendCMD(int value){
    PORTBbits.RB3 = 0; //RS
    PORTD = value;
    __delay_ms(1);
    enableLCD();
    __delay_ms(1);
}

void writeLCD(char *frase){
    int i;
    for(i = 0; frase[i] != '\0'; i++){
        sendASCII(frase[i]);
    }
}

void shiftRight(){
    sendCMD(0x1C);
}

void shiftLeft(){
    sendCMD(0x18);
}

void selectLine(int line, int position){
    if(line == 1)   sendCMD(0x80 + position);
    if(line == 2)   sendCMD(0xC0 + position);
}

void clear_lcd(){
    sendCMD(0x1);
}

void initLCD(){
    TRISD = 0x0;
    TRISEbits.RE1 = 0;
    TRISBbits.RB3 = 0;
    sendCMD(0x1); 
    __delay_ms(1); 
    sendCMD(0x80);  
    __delay_ms(1); 
    sendCMD(0x30); 
    __delay_ms(1); 
    sendCMD(0x38);
    __delay_ms(1); 
   	sendCMD(0xf); 
    __delay_ms(1); 
}

void waitPassLCD(){
    clear_lcd();
    selectLine(1, 1);
    writeLCD("COFRE FECHADO");
    selectLine(2, 0);
    writeLCD("AGUARDANDO SENHA");
    sendCMD(0xC);
}

void cofreLigado(){
    clear_lcd();
    selectLine(1, 1);
    writeLCD("COFRE INICIADO");
    selectLine(2, 1);
    writeLCD("FECHE A PORTA");
}

void passLCD(){
    clear_lcd();
    writeLCD("DIGITANDO SENHA");
    selectLine(2,0);
    writeLCD("SENHA:");
    sendCMD(0xF);
}

void digitoLCD(){
    writeLCD("*");
}

void wrongPassLCD(int tentativas){
    char msg_tentativas[16];
    clear_lcd();
    writeLCD(" SENHA INCORRETA");
    sprintf(msg_tentativas, " TENTATIVAS = %d", tentativas);
    selectLine(2, 0);
    writeLCD(msg_tentativas);
    sendCMD(0xC);
}

void correctPassLCD(){
    clear_lcd();
    writeLCD("  SENHA CORRETA");
    selectLine(2,0);
    writeLCD("  COFRE ABERTO");
    sendCMD(0xC);
}