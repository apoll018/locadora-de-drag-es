#define MAX_PADRAO 5

typedef struct 
{
    int codElemento;
    char nome[50];
    char vulnerabilidade[50];

} Elementos;


//int inicializarElementos();
//int encerraElementos();
int salvarElementos(Elementos e);
int QuantidadeElementos();
Elementos obterElementoPeloIndice(int indice);
//Elementos obterElementosPeloCodigo(int codigo);
Elementos obterElementosPeloNome (char* nome);
int ApagarElementosPeloCodigo(int codigo);
