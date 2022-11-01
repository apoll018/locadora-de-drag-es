#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "guerreiro.h"
#include "elementos.h"
#include "dragao.h"
#include "locacao.h"


void MostraMenu(){
    
   printf ("\n----------MENU---------\n");
   
    printf ("\n");
    printf ("0. Sair\n");
    printf ("1. Guerreiros\n");
    printf ("2. Elementos de dragoes\n");
    printf ("3. Dragoes\n");
    printf ("4. Locacoes\n");
}

void MostrarSubMenu(){
    
    printf ("\n----------SUBMENU----------\n");
    
    printf("0. Sair\n");
    printf ("1. Listar\n");
    printf("2. Cadastrar\n");
    printf("3. Pesquisar\n");
    printf("4. Excluir\n");
 
}

void MostrarSubMenuAluguel(){
    
    printf ("\n----------SUBMENU----------\n");
    
    printf("0. Sair\n");
    printf ("1. Listar\n");
    printf("2. Alugar\n");
    printf("3. Pesquisar\n");
    printf("4. Devolucao\n");
 
}

void ListarGuerreiros(){

	printf("\n ");
    	int i;
    	for(i = 0; i < QuantidadeGuerreiros(); i++)
    	{
    		Guerreiro g = obterGuerreiroPeloIndice(i);
    		if (g.codGuerreiro > 0)
    			printf("Codigo Guerreiro: %d - Nome Guerreiro: %s - Titulo: %s - Reino: %s \n",
    				g.codGuerreiro,
    				g.nome,
    				g.titulo,
    				g.reino);
    	}
    	if (QuantidadeGuerreiros()==0)
    		printf("Nenhum guerreiro cadastrado\n");
    	
	printf("\n");
}

void CadastrarGuerreiro()
{ //RETOQUES FINAIS: COLOCAR SCANF PARA LER
    Guerreiro g; 
    printf ("Informe o nome do guerreiro: "); 
    scanf ("%s", g.nome);
    
    printf ("Informe o reino do guerreiro: ");
    scanf ("%s", g.titulo);
    
    printf ("Informe o titulo do guerreiro: ");
    scanf ("%s", g.reino);
    
    if (salvarGuerreiro(g)==1)
		printf("Guerreiro cadastrado \n");
	else
		printf("Falha ao cadastrar \n");
    
}

void PesquisarGuerreiroPeloNome(){
    
    Guerreiro g;
    char nomeBusca[50];
    
    printf ("Nome do Guerreiro: ");
    scanf ("%s", nomeBusca);
    
    g = obterGuerreiroPeloNome(nomeBusca);
    
    if (g.codGuerreiro != -1){
        
        printf("Codigo Guerreiro: %d - Nome Guerreiro: %s - Titulo: %s - Reino: %s \n",
    				g.codGuerreiro,
    				g.nome,
    				g.titulo,
    				g.reino);
        
    }
    
    else{
        
        printf ("Guerreiro nao encontrado\n");
    }
}

void ExcluirGuerreiro(){
    
    ListarGuerreiros();
    int codigo;

    printf ("Informe o codigo do guerreiro a ser apagado: ");
    scanf ("%d", &codigo);

    if (ApagarGuerreiroPeloCodigo(codigo)==1)
        printf ("Guerreiro apagado\n");
    else
        printf ("Algo de errado não está certo, guerreiro nao apagou\n");
}

void ListarElementos(){

    printf ("\n");
        int i;
        for (i = 0; i < QuantidadeElementos(); i++){

            Elementos e = obterElementoPeloIndice(i);
            if (e.codElemento > 0)
                printf ("Codigo Elemento: %d - Nome: %s - Vulnerabilidade: %s\n",
                e.codElemento, 
                e.nome, 
                e.vulnerabilidade);
        }
        if (QuantidadeElementos()==0)
            printf ("Nenhum elemento cadastrado\n");
    printf ("\n");
}

void CadastrarElemento(){

    Elementos e;

    printf ("Informe o nome do Elemento\n");
    scanf ("%s", e.nome);

    printf ("Informe a vulnerabilidade\n");
    scanf ("%s", e.vulnerabilidade);


    if (salvarElementos(e) == 1){

        printf ("Elemento Cadastrado\n");
    }
    else{
        printf ("Falha ao cadastrar\n");
    }
}

void PesquisarElementoPeloNome(){

    Elementos e;
    char nomeBusca[50];

    printf ("Informe o nome do elemento\n");
    scanf ("%s", nomeBusca);

    e = obterElementosPeloNome (nomeBusca);
    if (e.codElemento != -1){

        printf ("Codigo Elemento: %d - Nome: %s - Vulnerabilidade: %s\n",
                e.codElemento, 
                e.nome, 
                e.vulnerabilidade);
    }
    else{
        printf ("Elemento nao encontrado ou nao cadastrado\n");
    }
}

void ExcluirElemento(){

    Elementos e;
    ListarElementos();
    int codigo;
    
    printf ("Informe o codigo do elemento que deseja apagar\n");
    scanf ("%d", &codigo);

    if (ApagarElementosPeloCodigo(codigo) == 1){
        printf ("Elemento apagado \n");
    }
    else{
        printf ("Algo de errado nao esta certo, elemento nao apagado");
    }
}

void ListarDragaos(){

	printf("\n ");
    	int i;
    	for(i = 0; i < QuantidadeDragaos(); i++)
    	{
    		Dragao d = obterDragaoPeloIndice(i);
            Elementos e;
    		if (d.codDragao > 0)
    			printf("Codigo Dragao: %d - Nome Dragao: %s - Idade: %d - Valor Diario: %.2f - Quantidade em estoque: %d - Codigo Elemento: %d\n",
    				d.codDragao,
    				d.nome,
                    d.idade,
                    d.valorDiario,
                    d.uniEmEstoque,
                    d.codElemento);
    	}
    	if (QuantidadeDragaos()==0)
    		printf("Nenhum dragao cadastrado\n");
    	
	printf("\n");
}

void CadastrarDragao(){ //RETOQUES FINAIS: COLOCAR SCANF PARA LER
    Dragao d; 
    printf ("Informe o nome do Dragao: "); 
    scanf ("%s", d.nome);

    printf ("Informe a idade do dragao: ");
    scanf ("%d", &d.idade);

    printf ("Informe o valor diario do dragao: ");
    scanf ("%f", &d.valorDiario);

    printf ("Informe a quantidade em estoque: ");
    scanf ("%d", &d.uniEmEstoque);   

    ListarElementos();

    printf ("Informe o elemento do dragao\n");
    scanf ("%d", &d.codElemento);
    
    if (salvarDragao(d)== 1 && VerificaElemento(d)== 1)
		printf("Dragao cadastrado \n");
	else
		printf("Falha ao cadastrar \n");
    
}

void PesquisarDragaoPeloNome(){

    Dragao d;
    char nomeBusca[50];

    printf ("Nome do Guerreiro: ");
    scanf ("%s", nomeBusca);

    d = obterDragaoPeloNome(nomeBusca);

    if (d.codDragao != -1){

        printf("Codigo Dragao: %d - Nome Dragao: %s - Idade: %d - Valor Diario: %.2f - Quantidade em estoque: %d\n",
    				d.codDragao,
    				d.nome,
                    d.idade,
                    d.valorDiario,
                    d.uniEmEstoque);
    }
    else{
        printf ("Dragao nao encontrado\n");
    }
}

void ExcluirDragao(){

    Dragao g;
    ListarDragaos();
    int codigo;

    printf ("Informe o codigo do dragao a ser excluido: ");
    scanf ("%d", &codigo);

    if (ApagarDragaoPeloCodigo(codigo) == 1){
        printf ("Dragao apagado \n");
    }
    else{
        printf ("Algo de errado nao esta certo, guerreiro nao apagou\n");

    }

}

void ListarLocacao(){

    int i;
    for(i = 0; i < QuantidadeLocacao(); i++){

        Locacao l = obterLocacaoPeloIndice(i);
        if (l.codLocacao > 0)
            printf ("Codigo Locacao: %d - Data Inicio Locacao: %s - Data Fim Locacao: %s \n",
            l.codLocacao,
            l.dataInicioLocacao,
            l.dataFimLocacao);
    }
    if (QuantidadeLocacao()==0)
    printf ("Nenhuma locacao foi feita\n");

}

void EfetuarLocacao(){

    Locacao l;
    
    ListarGuerreiros();
    printf ("Informe o codigo do guerreiro:\n");
    scanf ("%d", &l.codGuerreiro);
    
    ListarDragaos();
    printf ("Informe o codigo do dragao:\n");
    scanf ("%d", &l.codDragao);

    printf ("Informe a data de inicio da locacao:\n");
    scanf ("%s", l.dataInicioLocacao);

    printf ("Informe quantos dragaos serao locados:\n");
    scanf ("%d", &l.qtdDragaoLocados);
    
    verificarCodigos(l.codGuerreiro, l.codDragao);
    
    int verific = Aluguel(l);
    if (verific == 1){
        printf ("Aluguel realizado\n");
    }
    else if (verific == 0){
        printf ("Aluguel nao realizado\n");
    }
    /*if (verific == 2);
        printf ("falha ao alugar\n");*/


}

void PesquisarAluguel(){


    int codBusca;

    ListarGuerreiros();

    printf ("Informe o codigo do guerreiro:\n");
    scanf ("%d", &codBusca);

    Locacao l = obterLocacaoPeloCodigo(codBusca);

    if (l.codLocacao != -1){

        printf ("Codigo Locacao: %d - Data Inicio Locacao: %s - Data Fim Locacao: %s\n",
            l.codLocacao,
            l.dataInicioLocacao,
            l.dataFimLocacao);
    }
    else{

        printf ("Locacao nao encontrada\n");
    }
}

void EfetuarDevolucao(){

    Locacao l;

    ListarLocacao();

    printf ("Informe o codigo da locacao para fazer a devolução:\n");
    scanf ("%d", &l.codLocacao);

    printf ("Informe a data de devolução:\n");
    scanf ("%s", l.dataFimLocacao);

    int verificPago = VerificaDevolucao(l);

    if (verificPago == 0)
        printf ("Devolucao feita com exito! \n");
    if (verificPago == 1)
        printf ("Problema na devolucao! \n");
    

}

int main(){
    
    int codMenu; 
    
    do{
        
        MostraMenu();
	    printf ("Informe a opcao desejada: ");
	    scanf ("%d", &codMenu);
        
        switch(codMenu)
        { 
            case 0:
                printf ("Sair\n"); 
            break;
            
            case 1:
                printf ("Guerreios\n"); 
                MostrarSubMenu();
                scanf ("%d", &codMenu);

                switch (codMenu)
                {
                    case 1: 
                        printf ("Listar Guerreiros\n");
                        ListarGuerreiros();
                    break;
                    
                    case 2: 
                        printf ("Cadastrar\n");
                        CadastrarGuerreiro(); 
                    break;
                    
                    case 3: 
                        printf ("Pesquisar\n");
                        PesquisarGuerreiroPeloNome();
                        
                    break;
                    
                    case 4: 
                        printf ("Excluir\n");
                        ExcluirGuerreiro();
                    break;
                    
                    default:
                        
                        printf ("Codigo Invalido \n");
                }
            
            break;    
                
            case 2:

                printf ("Elementos\n"); 
                
                MostrarSubMenu();
                
                scanf ("%d", &codMenu);
                
                switch (codMenu)
                {
                    
                    case 1: 
                        printf ("Listar\n");
                        ListarElementos();
                    break;
                    
                    case 2: 
                        printf ("Cadastrar\n");
                        CadastrarElemento();
                        
                    break;
                    
                    case 3:
                        printf ("Pesquisar\n");
                        PesquisarElementoPeloNome();
                        
                    break;
                    
                    case 4:
                        printf ("Excluir\n");
                        ExcluirElemento();
                    break;
                    
                    default:
                        
                        printf ("Codigo Invalido \n");
                }

            break;

            case 3:

                printf ("Dragoes\n"); 
                
                MostrarSubMenu();
                
                scanf ("%d", &codMenu);
                
                switch (codMenu)
                {
                    
                    case 1:  
                        printf ("Listar\n"); 
                        ListarDragaos();
                    break;
                    
                    case 2: 
                        printf ("Cadastrar\n");
                        CadastrarDragao();
                    break;
                    
                    case 3: 
                        printf ("Pesquisar\n");
                        PesquisarDragaoPeloNome(); 
                    break;
                    
                    case 4: 
                        printf ("Excluir\n");
                        ExcluirDragao();
                    break;
                    
                    default:
                        
                        printf ("Codigo Invalido \n");
                }
            
            break;
            
            case 4:
                 
                printf ("Aluguel\n"); 
                
                MostrarSubMenuAluguel();
                
                scanf ("%d", &codMenu);
                
                switch (codMenu)
                {
                    
                    case 1:  
                        printf ("Listar\n"); 
                        ListarLocacao();
                    break;
                    
                    case 2: 
                        printf ("Alugar\n");
                        EfetuarLocacao();
                    break;
                    
                    case 3: 
                        printf ("Pesquisar\n");
                        PesquisarAluguel(); 
                    break;
                    
                    case 4: 
                        printf ("Devolucao\n");
                        EfetuarDevolucao();
                    break;
                    
                    default:
                        
                        printf ("Codigo Invalido \n");
                }
                
            break;
            
            
            
            
        break;//switch principal
            
            
        }
        
    }while(codMenu != 0);
    
    return 0; 

}


