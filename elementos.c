#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "elementos.h"
#include "dragao.h"

#define MAX_PADRAO 5

Elementos elementos[MAX_PADRAO];

int qtdElemento = 0;
int codElementoAtual = 1;

int QuantidadeElementos(){

    return qtdElemento;
}

Elementos obterElementoPeloIndice(int indice){

    return elementos[indice];
}

int salvarElementos(Elementos e){

    if (qtdElemento < MAX_PADRAO){

        e.codElemento = codElementoAtual++;
        elementos[qtdElemento] = e;
        qtdElemento++;
        return 1;
    }
    else{
        return 0;
    }
}

Elementos obterElementosPeloNome (char* nome){

    int i;
    for (i = 0; i < MAX_PADRAO; i++){

        if(strcmp(elementos[i].nome, nome) == 0){
            return elementos[i];
        }
    }

    Elementos elementoNaoEncontrado;
    elementoNaoEncontrado.codElemento = - 1;
    return elementoNaoEncontrado;
}

int ApagarElementosPeloCodigo(int codigo){

    int i;
    
    for (i = 0; i < qtdElemento; i++){
	
        if (elementos[i].codElemento == codigo){
            elementos[i] = elementos[qtdElemento -1];
            qtdElemento--;
            return 1;
        }
    }//return precisa estar fora do for para apagar
	return 0;
}
