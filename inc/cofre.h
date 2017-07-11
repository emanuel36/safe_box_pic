#ifndef COFRE_H_H
#define	COFRE_H_H
    
#include <xc.h>
#include <pic18f4550.h>

void senha_incorreta(int tentativas);
void senha_correta(int tentativas);
void init_alarme();
void init_sensor_magnetico();
int porta_aberta();
void alarme(int valor);
void init_lampada();
void lampada(int valor);

#endif	/* COFRE_H */