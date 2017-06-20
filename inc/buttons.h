#ifndef TECLADO_H
#define	TECLADO_H
    
#include <xc.h>
#include <pic18f4550.h>

#define CLEAR_BUTTON    PORTDbits.RD0
#define BUTTON_1        PORTDbits.RD1
#define BUTTON_2        PORTDbits.RD2
#define BUTTON_3        PORTDbits.RD3
#define ERROR           -1
#define UNPRESS         10
#define CLR             0
#define B1              1
#define B2              2
#define B3              3

void initButons();
int buttons();
void button_1();
void button_2();
void button_3();

#endif	/* TECLADO_H */