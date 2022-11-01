#define MAX_PADRAO 5

typedef struct{
    
    int codDragao;
    char nome[50];
    int idade;
    float valorDiario;
    int uniEmEstoque;
    int codElemento;

} Dragao;


//int inicializarDragaos();
//int encerraDragaos();
int salvarDragao(Dragao d);
int VerificaElemento(Dragao d);
int QuantidadeDragaos();
Dragao obterDragaoPeloIndice(int indice);
//Dragao obterDragaoPeloCodigo(int codigo);
Dragao obterDragaoPeloNome (char* nome);
int ApagarDragaoPeloCodigo(int codigo);
