#define MAX_PADRAO 5

typedef struct 
{   
    int codLocacao;
    int codDragao;
    int codGuerreiro;
    char dataInicioLocacao[10];
    char dataFimLocacao[10];
    int qtdDragaoLocados; 
    float ValorLocacao;
    int pago;
} Locacao;

//int inicializarLocacoes();
//int encerraLocacoes();
int CriarLocacao(Locacao l);
int QuantidadeLocacao();
Locacao obterLocacaoPeloIndice(int indice);
Locacao obterLocacaoPeloCodigo(int codigo);
Locacao obterLocacaoPeloNome (char* nome);
int ApagarLocacaoPeloCodigo(int codigo);
int Aluguel(Locacao l);
int verificarCodigos(int codGuerreiro, int codDragao);
int VerificaDevolucao(Locacao l);
