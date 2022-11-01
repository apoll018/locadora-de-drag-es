#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locacao.h"
#include "guerreiro.h"
#include "dragao.h"

#define MAX_PADRAO 5


Locacao locacao[MAX_PADRAO];
Guerreiro guerreiro[MAX_PADRAO];
Dragao dragao[MAX_PADRAO];

int qtdLocacao = 0;
int codLocacaoAtual = 1;

int QuantidadeLocacao(){
    return qtdLocacao;
}

Locacao obterLocacaoPeloIndice(int indice){
    return locacao[indice];
}

/*int VerificaPagamento(int pago){

    int i;
    for (i = 0; i < qtdLocacao; i++){

        if (pago == 1){

            strcpy(locacao[i].pago, "Pago");
            return 1;
        }
            
        else{

            strcpy(locacao[i].pago, "Nao pagou");
            return 2;
        }
    }
    
}*/

int verificarCodigos(int codGuerreiro, int codDragao){
	
	int i;
	for (i = 0; i < MAX_PADRAO; i++){
		
			if (codGuerreiro == guerreiro[i].codGuerreiro){
            
            	if(codDragao == dragao[i].codDragao){
            	
            		return 0;
    			}
    	
		    	else{
		    		
		    		return 1;
				}
		
			}
	
		}
}

int Aluguel(Locacao l){
    
    int i;
    for (i = 0; i < MAX_PADRAO; i++){

                if (dragao[i].uniEmEstoque >= locacao[i].qtdDragaoLocados){
    
                    l.codLocacao = codLocacaoAtual++;
                    locacao[qtdLocacao] = l;
                    dragao[i].uniEmEstoque -= locacao[i].qtdDragaoLocados;
                    locacao[i].pago = 0; 
                    qtdLocacao++;
                    return 1;
                }
            
                    else{
                        return 0;
                    }
        
        
    }
}

/*Locacao obterLocacaoPeloNome (char* nome){

    int i;
    for (i = 0; i < MAX_PADRAO; i++){

        if (strcmp(guerreiro[i].nome, nome) == 0){
                
                return locacao[i];
        }
    }
    
    Locacao locacaoNaoEncontrada;
    locacaoNaoEncontrada.codLocacao = -1;
    return locacaoNaoEncontrada;
}*/

Locacao obterLocacaoPeloCodigo(int codigo){

    int i;
    for (i = 0; i < MAX_PADRAO; i++){

        if (codigo == guerreiro[i].codGuerreiro){
            return locacao[i];
        }
    }

    Locacao locacaoNaoEncontrada;
    locacaoNaoEncontrada.codLocacao = -1;
    return locacaoNaoEncontrada;
}


int VerificaDevolucao(Locacao l){

    int i; 
    for (i = 0; i < MAX_PADRAO; i++){
        
        if (l.codLocacao == locacao[i].codLocacao){
            if (locacao[i].pago == 0){
                
                strcpy(locacao[i].dataFimLocacao, l.dataFimLocacao);
                locacao[i].pago = 1;
                dragao[i].uniEmEstoque += locacao[i].qtdDragaoLocados;
                return 0;
		}
            else{
                
                return 1;
            }
      
        }    
    }
    
}

