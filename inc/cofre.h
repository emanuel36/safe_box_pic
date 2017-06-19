#ifndef COFRE_H_H
#define	COFRE_H_H
    
#include <xc.h>
#include <pic18f4550.h>

void atualiza_senha_digitada(int button, int tentativas, int senha);
void senha_incorreta(int tentativas);
void senha_correta();

#endif	/* COFRE_H */