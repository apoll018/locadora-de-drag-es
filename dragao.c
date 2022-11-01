#include <string.h>
#include "dragao.h"
#include "elementos.h"

#define MAX_PADRAO 5


Dragao dragao[MAX_PADRAO];
Elementos elementos[MAX_PADRAO];

int qtdDragao = 0;
int codDragaoAtual = 1;


int QuantidadeDragaos(){
    return qtdDragao;
}

Dragao obterDragaoPeloIndice(int indice){

    return dragao[indice];
}

int salvarDragao(Dragao d){
        
    if(qtdDragao < MAX_PADRAO){

                d.codDragao = codDragaoAtual++;
                dragao[qtdDragao] = d;
                qtdDragao++;
                return 1;
            }
    
            else{
                return 0;
            }    


}

int VerificaElemento(Dragao d){
    
    int i;
        for (i = 0; i < QuantidadeElementos(); i++){

            if (d.codElemento == elementos[i].codElemento){
                return 1;
            } 
        
            else{
                return 0;
                }
        }       
}
Dragao obterDragaoPeloNome (char* nome){

    int i;
    for (i = 0; i < MAX_PADRAO; i++){

        if(strcmp(dragao[i].nome, nome) == 0){
            return dragao[i];
        }

    }

    Dragao dragaoNaoEncontrado;
    dragaoNaoEncontrado.codDragao = -1;
    return dragaoNaoEncontrado;
}

int ApagarDragaoPeloCodigo(int codigo){

    int i;
    for (i = 0; i < MAX_PADRAO; i++){

        if (dragao[i].codDragao == codigo){
            dragao[i] = dragao[qtdDragao - 1];
            qtdDragao--;

            return 1;
        }

        
    }
        return 0;
}
