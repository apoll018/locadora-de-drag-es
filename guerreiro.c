#include <string.h>
#include "guerreiro.h"

#define MAX_PADRAO 5

Guerreiro guerreiros[MAX_PADRAO];

int qtdGuerreiros = 0;
int codGuerreiroAtual = 1; 

int inicializarGuerreiros(){
    
    int i;
    for (i = 0; i < MAX_PADRAO; i++){
        
        strcpy (guerreiros[i].nome, "");
        strcpy (guerreiros[i].titulo, "");
        strcpy (guerreiros[i].reino, "");
    }
    
    //strcpy (guerreiros[0].nome, "Shyriu");
    //strcpy (guerreiros[0].titulo, "Agua");
    //strcpy (guerreiros[0].reino, "Cinco Picos Antigos de Rozan");
    qtdGuerreiros++;
}

int QuantidadeGuerreiros(){
    
    return qtdGuerreiros;
}

Guerreiro obterGuerreiroPeloIndice(int indice){

    return guerreiros[indice];
}

int salvarGuerreiro(Guerreiro g){
    
    if (qtdGuerreiros < MAX_PADRAO){
        
        g.codGuerreiro = codGuerreiroAtual++;
        guerreiros[qtdGuerreiros] = g;
        qtdGuerreiros++;
       	return 1;
	}	
	else
		return 0; 
    
}

Guerreiro obterGuerreiroPeloNome (char* nome){
    
    int i;
        for (i = 0; i < MAX_PADRAO; i++){
            
            if (strcmp(guerreiros[i].nome, nome) == 0){
                
                return guerreiros[i];
            }
        }
    
    Guerreiro guerreiroNaoEncontrado;
    guerreiroNaoEncontrado.codGuerreiro = -1;
    return guerreiroNaoEncontrado;
}

int ApagarGuerreiroPeloCodigo(int codigo){

    int i;
    for (i = 0; i < qtdGuerreiros; i++){
        if (guerreiros[i].codGuerreiro == codigo){

            guerreiros[i] = guerreiros[qtdGuerreiros - 1];
            guerreiros[qtdGuerreiros - 1].codGuerreiro = 0;
            qtdGuerreiros--;
            return 1;
        }
       
    }
        return 0;
}
