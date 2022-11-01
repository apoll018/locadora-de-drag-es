#define MAX_PADRAO 5

typedef struct{
    
    int codGuerreiro;
    char nome[50];
    char titulo[50];
    char reino[50];
} Guerreiro;

int inicializarGuerreiros();
//int encerraGuerreiros();
int salvarGuerreiro(Guerreiro g);
int QuantidadeGuerreiros();
Guerreiro obterGuerreiroPeloIndice(int indice);
//Guerreiro obterGuerreiroPeloCodigo(int codigo);
Guerreiro obterGuerreiroPeloNome (char* nome);
int ApagarGuerreiroPeloCodigo(int codigo);
