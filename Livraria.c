//
//  main.c
//  Projeto Livraria
//
//  Created by Henrique Farias on 25/05/16.
//  Copyright © 2016 FPS. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int items_no_estoque;
    int qtd_items_vendidos;
}Estoque;

typedef struct{
    int valor_total;
    Estoque total;
}Vendas;

typedef struct{
    char nome[30];
    int salario_base;
    float salario_final;
    int cod_funcionario;
    Vendas total;
}Funcionario;

typedef struct{
    char titulo[30];
    char autor[30];
    int preco;
    int cod_produto;
    Vendas produto;
}Livro;

typedef struct {
    char nome_disco[30];
    char artista[30];
    int cod_cd;
    int preco;
    Vendas produto;
}CD_Musica;

typedef struct {
    char modelo[30];
    int preco;
    int cod_celular;
    Vendas produto;
}Celular;

typedef struct {
    char nome_vendedor[30];
    char nome_produto[30];
    int unidades_vendidas;
    int cod_venda;
    int tipo_de_produto;
    int cod_produto;
    int cod_funcionario;
}Vendas_Armazenada;

void Info_Venda(Vendas_Armazenada a) {
    printf("Vendedor: %s\nProduto: %s\nTipo de Produto: %d\nUnidades vendidas: %d\nCodigo de Venda: %d\nCodigo do produto vendido: %d\nCodigo do funcionario que vendeu: %d\n", a.nome_vendedor, a.nome_produto, a.tipo_de_produto, a.unidades_vendidas, a.cod_venda, a.cod_produto, a.cod_funcionario);
}

void Info_Livro(Livro a) {
    printf("Titulo: %s\nAutor: %s\nPreco: %d\nID: %d\nItems vendidos: %d\nItems no estoque: %d\n",a.titulo, a.autor, a.preco, a.cod_produto, a.produto.total.qtd_items_vendidos, a.produto.total.items_no_estoque);
}

void Info_Celular(Celular a) {
    printf("Modelo do Celular: %s\nPreco: %d\nID: %d\nItems vendidos: %d\nItems no estoque: %d\n", a.modelo, a.preco, a.cod_celular, a.produto.total.qtd_items_vendidos, a.produto.total.items_no_estoque);
}

void Info_CD(CD_Musica a) {
    printf("Nome do disco: %s\nNome do artista: %s\nPreco: %d\nID: %d\nItems vendidos: %d\nItems no estoque: %d\n", a.nome_disco, a.artista, a.preco, a.cod_cd, a.produto.total.qtd_items_vendidos, a.produto.total.items_no_estoque);
}

void Info_Funcionario(Funcionario a) {
    printf("Nome do Funcionario: %s\nID: %d\nValor das vendas: %d\nSalario base: %d\n", a.nome, a.cod_funcionario, a.total.valor_total, a.salario_base);
}

Livro Add_Livro(Livro a, int id)
{
    getchar();
    char txt[30];
    a.produto.total.qtd_items_vendidos = 0;
    a.cod_produto = id;
    printf("Digite o nome do Livro: \n");
    gets(txt);
    strcpy(a.titulo, txt);
    fflush(stdin);
    printf("Digite o nome do autor: \n");
    gets(txt);
    strcpy(a.autor, txt);
    fflush(stdin);
    printf("Digite o preço padrao do livro: \n");
    scanf("%d", &a.preco);
    printf("Quantos itens desse livro tem nos estoque: \n");
    scanf("%d", &a.produto.total.items_no_estoque);
    Info_Livro(a);
    return a;
}

Celular Add_Celular(Celular a, int id) {
    getchar();
    char txt[30];
    a.produto.total.qtd_items_vendidos = 0;
    a.cod_celular = id;
    printf("Digite o Modelo do celular: \n");
    gets(txt);
    strcpy(a.modelo, txt);
    fflush(stdin);
    printf("Digite o preço padrao do celular: \n");
    scanf("%d", &a.preco);
    printf("Quantos celulares desse tipo voce tem nos estoque: \n");
    scanf("%d", &a.produto.total.items_no_estoque);
    Info_Celular(a);
    return a;
}

Funcionario Add_Funcionario(Funcionario a, int id) {
    getchar();
    char txt[30];
    a.cod_funcionario = id;
    a.total.valor_total = 0;
    printf("Digite o nome do Funcionario: ");
    gets(txt);
    strcpy(a.nome, txt);
    fflush(stdin);
    printf("Qual sera o salario base desse funcionario: ");
    scanf("%d", &a.salario_base);
    Info_Funcionario(a);
    return a;
    
}

CD_Musica Add_CD(CD_Musica a, int id) {
    getchar();
    char txt[30];
    a.cod_cd = id;
    a.produto.total.qtd_items_vendidos = 0;
    printf("Digite o nome do Disco: \n");
    fflush(stdin);
    gets(txt);
    strcpy(a.nome_disco, txt);
    fflush(stdin);
    printf("Digite o nome do Artista: \n");
    gets(txt);
    strcpy(a.artista, txt);
    fflush(stdin);
    printf("Digite o preço padrao do disco: \n");
    scanf("%d", &a.preco);
    printf("Quantos discos desse voce tem nos estoque: \n");
    scanf("%d", &a.produto.total.items_no_estoque);
    Info_CD(a);
    return a;
}

void Edit_Funcionario(Funcionario* a) {
    getchar();
    char txt[30];
    fflush(stdin);
    printf("Novo nome do funcionario: ");
    gets(txt);
    fflush(stdin);
    strcpy((*a).nome, txt);
    printf("Novo salario do funcionario: ");
    scanf("%d", &(*a).salario_base);
    fflush(stdin);
    Info_Funcionario(*a);
}

void Remover_Funcionario(Funcionario* a) {
    char txt[30];
    strcpy(txt, (*a).nome);
    (*a).salario_base = 0;
    strcpy((*a).nome, "");
    (*a).total.valor_total = 0;
    //printf("O Funcionário %s foi removido com sucesso, A identificaxao de numero %d que pertecia a ele esta agora disponivel para outro.\n", txt, (*a).cod_funcionario);
}

void Edit_Livro(Livro* a) {
    getchar();
    char txt[30];
    printf("Digite o novo nome do livro(atual: %s): ", (*a).titulo);
    fflush(stdin);
    gets(txt);
    strcpy((*a).titulo, txt);
    printf("Digite o novo nome do autor(atual: %s): ", (*a).autor);
    fflush(stdin);
    gets(txt);
    strcpy((*a).autor, txt);
    fflush(stdin);
    printf("Digite o novo preco do livro(atual %d): ", (*a).preco);
    scanf("%d", &(*a).preco);
    Info_Livro(*a);
}

void Estoque_Livro(Livro* a){
    int qtd_do_produto;
    int oq;
    printf("O que voce que fazer no estoque(atual: %d).\n1 - Adicionar produtos\n2 - Remover produtos\nSelecionou: ", (*a).produto.total.items_no_estoque);
    scanf("%d", &oq);
    switch (oq) {
        case 1:
        {
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque += qtd_do_produto;
            Info_Livro(*a);
            break;
        }
        case 2:
        {
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque -= qtd_do_produto;
            Info_Livro(*a);
            break;
        }

        default:
            printf("Opcao Invalida");
            break;
    }
}

void Remover_Livro(Livro* a) {
    char txt[30];
    strcpy(txt, (*a).titulo);
    strcpy((*a).titulo, "");
    strcpy((*a).autor, "");
    (*a).preco = 0;
    (*a).produto.total.items_no_estoque = 0;
    (*a).produto.total.qtd_items_vendidos = 0;
    printf("O livro %s foi removido com sucesso, a ID, esta agora dispponível para outro.\n", txt);
}

void Edit_Celular(Celular* a) {
    getchar();
    char txt[30];
    printf("Novo nome do celular(atual: %s): ", (*a).modelo);
    gets(txt);
    strcpy((*a).modelo, txt);
    fflush(stdin);
    printf("Novo preco do celular(atual: %d): ", (*a).preco);
    scanf("%d", & (*a).preco);
    fflush(stdin);
    Info_Celular(*a);
}

void Estoque_Celular(Celular *a) {
    int qtd_do_produto;
    int oq;
    printf("O que voce que fazer no estoque(atual: %d).\n1 - Adicionar produtos\n2 - Remover produtos\nSelecionou: ", (*a).produto.total.items_no_estoque);
    scanf("%d", &oq);
    switch (oq) {
        case 1:
        {
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque += qtd_do_produto;
            Info_Celular(*a);
            break;
        }
        case 2:
        {
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque -= qtd_do_produto;
            Info_Celular(*a);
            break;
        }
            
        default:
            printf("Opcao Invalida");
            break;
    }
}

void Remover_Celular(Celular* a){
    char txt[30];
    strcpy(txt, (*a).modelo);
    strcpy((*a).modelo, "");
    (*a).preco = 0;
    (*a).produto.total.items_no_estoque = 0;
    (*a).produto.total.qtd_items_vendidos = 0;
    printf("O celular de modelo %s foi removido com sucesso, o codigo de id %d agora esta disponivel para outro.\n", txt, (*a).cod_celular);
}

void Edit_CD(CD_Musica* a) {
    getchar();
    printf("Digite o novo nome do disco(atual: %s): ", (*a).nome_disco);
    gets((*a).nome_disco);
    fflush(stdin);
    printf("Digite o novo nome do artista(atual: %s): ", (*a).artista);
    gets((*a).artista);
    fflush(stdin);
    printf("Digite o novo preco do CD(atual: %d): ", (*a).preco);
    scanf("%d", &(*a).preco);
    Info_CD(*a);
}

void Estoque_CD(CD_Musica* a) {
    int qtd_do_produto;
    int oq;
    printf("O que voce que fazer no estoque(atual: %d).\n1 - Adicionar produtos\n2 - Remover produtos\nSelecionou: ", (*a).produto.total.items_no_estoque);
    scanf("%d", &oq);
    switch (oq) {
        case 1:
        {
            printf("Quantos produtos serao adicionados no estoque: ");
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque += qtd_do_produto;
            Info_CD(*a);
            break;
        }
        case 2:
        {
            printf("Quantos produtos serao removidos no estoque: ");
            scanf("%d", &qtd_do_produto);
            (*a).produto.total.items_no_estoque -= qtd_do_produto;
            Info_CD(*a);
            break;
        }
            
        default:
            printf("Opcao Invalida");
            break;
    }

}
void Remover_CD(CD_Musica* a) {
    char txt[30];
    strcpy(txt, (*a).nome_disco);
    strcpy((*a).nome_disco, "");
    strcpy((*a).artista, "");
    (*a).preco = 0;
    (*a).produto.total.items_no_estoque = 0;
    (*a).produto.total.qtd_items_vendidos = 0;
    printf("O CD %s foi removido com sucesso, o codigo de ID %d agora esta disponivel para outro.", txt, (*a).cod_cd);
}

void Salario_Funcionario(Funcionario* a) {
    (*a).salario_final = (*a).salario_base + 0.08 * (*a).total.valor_total;
    printf("O funcionario %s recebera %.2f reais.\n", (*a).nome, (*a).salario_final);
}

// antes deve ter um scanf perguntado pelo cod do vendedor e do livro, recebe vendedor[n] e obra[n]

void Cadastrar_Venda_Livro(Funcionario* a, Livro* b, Vendas_Armazenada* c, int id) {
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).titulo);
    (*c).cod_venda = id;
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 1;
    (*c).cod_funcionario = (*a).cod_funcionario;
    (*c).cod_produto = (*b).cod_produto;
    Info_Venda((*c));
}

void Cadastrar_Venda_Celular(Funcionario* a, Celular* b, Vendas_Armazenada* c, int id) {
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).modelo);
    (*c).cod_venda = id;
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 2;
    (*c).cod_funcionario = (*a).cod_funcionario;
    (*c).cod_produto = (*b).cod_celular;
    Info_Venda((*c));
}

void Cadastrar_Venda_CD(Funcionario* a, CD_Musica* b, Vendas_Armazenada* c, int id) {
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).nome_disco);
    (*c).cod_venda = id;
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 3;
    (*c).cod_funcionario = (*a).cod_funcionario;
    (*c).cod_produto = (*b).cod_cd;
    Info_Venda((*c));
}

void Alterar_Venda_Livro(Funcionario* a, Livro* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).titulo);
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 1;
    Info_Venda((*c));
}
void Alterar_Venda_Celular(Funcionario* a, Celular* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).modelo);
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 2;
    Info_Venda((*c));
}
void Alterar_Venda_CD(Funcionario* a, CD_Musica* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    int qtd_do_produto;
    printf("Quantas unidades do produto foram vendidas: ");
    scanf("%d", &qtd_do_produto);
    (*a).total.valor_total += qtd_do_produto * (*b).preco;
    (*b).produto.total.items_no_estoque -= qtd_do_produto;
    (*b).produto.total.qtd_items_vendidos += qtd_do_produto;
    strcpy((*c).nome_vendedor, (*a).nome);
    strcpy((*c).nome_produto, (*b).nome_disco);
    (*c).unidades_vendidas = qtd_do_produto;
    (*c).tipo_de_produto = 3;
    Info_Venda((*c));
}

void Cancelar_Venda_Livro(Funcionario* a, Livro* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    strcpy((*c).nome_produto, "");
    strcpy((*c).nome_vendedor, "Esta venda foi cancelada");
    (*c).unidades_vendidas = 0;
    (*c).tipo_de_produto = 0;
    (*c).cod_funcionario = -2;
}

void Cancelar_Venda_Celular(Funcionario* a, Celular* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    strcpy((*c).nome_produto, "");
    strcpy((*c).nome_vendedor, "Esta venda foi cancelada");
    (*c).unidades_vendidas = 0;
    (*c).tipo_de_produto = 0;
    (*c).cod_funcionario = -2;
}

void Cancelar_Venda_CD(Funcionario* a, CD_Musica* b, Vendas_Armazenada* c) {
    (*b).produto.total.qtd_items_vendidos -= (*c).unidades_vendidas;
    (*b).produto.total.items_no_estoque += (*c).unidades_vendidas;
    (*a).total.valor_total -= (*c).unidades_vendidas * (*b).preco;
    
    strcpy((*c).nome_produto, "");
    strcpy((*c).nome_vendedor, "Esta venda foi cancelada");
    (*c).unidades_vendidas = 0;
    (*c).tipo_de_produto = 0;
    (*c).cod_funcionario = -2;
}

int main() {
    int* V_Aux_Arq = (int*) malloc(10 * sizeof(int));
    // funcionario
    V_Aux_Arq[0] = 30;
    V_Aux_Arq[1] = 0;
    // livro
    V_Aux_Arq[2] = 30;
    V_Aux_Arq[3] = 0;
    // celular
    V_Aux_Arq[4] = 30;
    V_Aux_Arq[5] = 0;
    // cd
    V_Aux_Arq[6] = 30;
    V_Aux_Arq[7] = 0;
    // venda
    V_Aux_Arq[8] = 30;
    V_Aux_Arq[9] = 0;
    
    FILE* Lista_Variaveis = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Auxiliares.txt", "r");
    for (int b = 0; b < 10; b++) {
        fscanf(Lista_Variaveis, "%d ", &V_Aux_Arq[b]);
    }
    fclose(Lista_Variaveis);
    
    int tam_funcionarios = V_Aux_Arq[0], tam_livros = V_Aux_Arq[2], tam_celular = V_Aux_Arq[4], tam_cd = V_Aux_Arq[6], tam_vendas = V_Aux_Arq[8];
    int id_livro = V_Aux_Arq[3], id_funcionario = V_Aux_Arq[1], id_CD = V_Aux_Arq[7], id_celular = V_Aux_Arq[5], id_venda = V_Aux_Arq[9];
    
    Funcionario* vendedor = (Funcionario*) malloc(tam_funcionarios * sizeof(Funcionario));
    Livro* obra = (Livro*) malloc(tam_livros * sizeof(Livro));
    Celular* modelo = (Celular*) malloc(tam_celular * sizeof(Celular));
    CD_Musica* disco = (CD_Musica*) malloc(tam_cd * sizeof(CD_Musica));
    Vendas_Armazenada* venda = (Vendas_Armazenada*) malloc(tam_vendas * sizeof(Vendas_Armazenada));
    
    FILE* Lista_Vendedores = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Funcionarios.txt", "r");
    FILE* Lista_Livros = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Livros.txt", "r");
    FILE* Lista_Celulares = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Celular.txt", "r");
    FILE* Lista_CDs = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/CDs.txt", "r");
    FILE* Lista_Vendas = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Vendas.txt", "r");
    
    fread(vendedor, sizeof(Funcionario), tam_funcionarios, Lista_Vendedores);
    fread(obra, sizeof(Livro), tam_livros, Lista_Livros);
    fread(modelo, sizeof(Celular), tam_celular, Lista_Celulares);
    fread(disco, sizeof(CD_Musica), tam_cd, Lista_CDs);
    fread(venda, sizeof(Vendas_Armazenada), tam_vendas, Lista_Vendas);
    
    fclose(Lista_Vendas);
    fclose(Lista_CDs);
    fclose(Lista_Celulares);
    fclose(Lista_Livros);
    fclose(Lista_Vendedores);
    
    system("clear");
    
    while(1)
    {
        if (id_funcionario < 0){
            id_funcionario = 0;
        }
        if (id_CD < 0) {
            id_CD = 0;
        }
        if (id_celular < 0) {
            id_celular = 0;
        }
        if (id_livro < 0) {
            id_livro = 0;
        }
        
        int aux;
        printf("\t\t\t\t\tGerenciamento Livraria\n\n1 - Funcionario\n2 - Produtos\n3 - Vendas\n4 - Salvar Alteracoes\n5 - Salvar e Sair\nSelecionou: ");
        scanf("%d",&aux);
        
        switch(aux)
        {
            
            case 1:
            {
                system("clear");
                int auxadd;
                printf("\t\t\t\t\tFuncionario\n1 - Cadastrar Funcionario \n2 - Alterar Funcionario\n3 - Remover Funcionario\n4 - Pesquisar Funcionario\n5 - Salario do Funcionario\n6 - Funcionario do mes\n7 - Todos os Funcionarios Cadastrados\nOutro numero para sair\nSelecionou: ");
                scanf("%d",&auxadd);
                
                switch(auxadd)
                {
                    case 1:
                    {
                        system("clear");
                        if (id_funcionario >= (tam_funcionarios - 2)) {
                            vendedor = realloc(vendedor, (tam_funcionarios + 30));
                            tam_funcionarios += 30;
                            printf("A capacidade de funcionarios cadastraveis foi aumentada em 30, agora o sistema suporta %d funcionarios diferentes.\n\n", tam_funcionarios);
                            vendedor[id_funcionario] = Add_Funcionario(vendedor[id_funcionario], id_funcionario);
                            id_funcionario++;
                            break;
                        } else {
                        vendedor[id_funcionario] = Add_Funcionario(vendedor[id_funcionario], id_funcionario);
                        id_funcionario++;
                        break;
                        }
                    }
                        
                    case 2:
                    {
                        system("clear");
                        int auxedit;
                        printf("Digite o codigo de identificacao do funcionario: ");
                        scanf("%d", &auxedit);
                            Edit_Funcionario(&vendedor[auxedit]);
                            break;
                        
                    }
                        
                    case 3:
                    {
                        system("clear");
                        int i;
                        int auxremov;
                        printf("Digite o codigo de identificacao do funcionario a ser removido: ");
                        scanf("%d", &auxremov);
                        for (i = 0; (i + auxremov) < (id_funcionario - 1); i++) {
                            strcpy(vendedor[auxremov + i].nome, vendedor[auxremov + i + 1].nome);
                            vendedor[auxremov + i].cod_funcionario = vendedor[auxremov + i + 1].cod_funcionario;
                            vendedor[auxremov + i].cod_funcionario -= 1;
                            vendedor[auxremov + i].salario_base  = vendedor[auxremov + i + 1].salario_base;
                            vendedor[auxremov + i].total.valor_total = vendedor[auxremov + i + 1].total.valor_total;
                        }
                            Remover_Funcionario(&vendedor[auxremov + i]);
                            id_funcionario -= 1;
                            printf("\n");
                            for (i = 0; i < id_venda; i++) {
                                if (venda[i].cod_funcionario > auxremov) {
                                    venda[i].cod_funcionario -= 1;
                                }
                                if (venda[i].cod_funcionario == auxremov) {
                                    venda[i].cod_funcionario = -1;
                                }
                                if (venda[i].cod_funcionario == -1) {
                                    strcpy(venda[i].nome_vendedor, "Demitido");
                                }
                            
                            }
                        
                            break;
                        
                        
                    }
                    
                    case 4:
                    {
                        system("clear");
                        int auxpesq;
                        printf("Digite o codigo de identificacao do funcionario: ");
                        scanf("%d", &auxpesq);
                        Info_Funcionario(vendedor[auxpesq]);
                        break;
                    }
                        
                    case 5:
                    {
                        system("clear");
                        int auxsal;
                        printf("Digite o codigo de identificacao do funcionario: ");
                        scanf("%d", &auxsal);
                        Salario_Funcionario(&vendedor[auxsal]);
                        break;
                    }
                        
                    case 6:
                    {
                        system("clear");
                        int a, auxmelhor = 0;
                        char nomemelhor[30];
                        for (a = 0; a < id_funcionario; a++) {
                            if (vendedor[a].total.valor_total > auxmelhor) {
                                auxmelhor = vendedor[a].total.valor_total;
                                strcpy(nomemelhor, vendedor[a].nome);
                            }
                        }
                        printf("O funcionario do mes eh %s, pois ele acumulou em vendas %d reais\n", nomemelhor, auxmelhor);
                        break;
                    }
                        
                    case 7:
                    {
                        system("clear");
                        for (int a = 0; a < id_funcionario; a++) {
                            Info_Funcionario(vendedor[a]);
                            printf("\n");
                        }
                        break;
                    }
                        
                        
                    default:
                    {
                        system("clear");
                        printf("Opção invalida!\n");
                        break;
                    }
                }
                break;
            }
                
                
            case 2:
            {
                system("clear");
                int aux2;
                printf("\t\t\t\t\tProdutos\n1 - Livro\n2 - Celular\n3 - CD de Musica\nOutro numero para sair\nSelecionou: ");
                scanf("%d", &aux2);
                switch (aux2) {
                    case 1:
                    {
                        system("clear");
                        int aux3;
                        printf("\t\t\t\t\tLivros\n1 - Cadastrar Livro\n2 - Remover Livro\n3 - Editar Livro\n4 - Pesquisar Livro\n5 - Modificar produto no estoque\n6 - Todos os livros cadastrados\nOutro numero para sair\nSelecionou: ");
                        scanf("%d", &aux3);
                        switch (aux3) {
                            case 1:
                            {
                                system("clear");
                                if (id_livro >= (tam_livros - 2)) {
                                    obra = realloc(obra, (tam_livros + 30));
                                    tam_livros += 30;
                                    printf("A capacidade de livros cadastraveis foi aumentada em 30, agora os sistema suporta %d livros diferentes.\n", tam_livros);
                                    obra[id_livro] = Add_Livro(obra[id_livro], id_livro);
                                    id_livro++;
                                    break;
                                } else {
                                obra[id_livro] = Add_Livro(obra[id_livro], id_livro);
                                id_livro++;
                                break;
                                }
                            }
                            case 2:
                            {
                                system("clear");
                                int auxremov;
                                printf("Digite o codigo do livro a ser removido: ");
                                scanf("%d", &auxremov);
                                int i;
                                for (i = 0; (i + auxremov) < (id_livro - 1); i++) {
                                strcpy(obra[auxremov + i].titulo, obra[auxremov + i + 1].titulo);
                                strcpy(obra[auxremov + i].autor, obra[auxremov + i + 1].autor);
                                obra[auxremov + i].cod_produto = obra[auxremov + i + 1].cod_produto;
                                obra[auxremov + i].cod_produto -= 1;
                                obra[auxremov + i].preco = obra[auxremov + i + 1].preco;
                                obra[auxremov + i].produto.total.items_no_estoque = obra[auxremov + i + 1].produto.total.items_no_estoque;
                                obra[auxremov + i].produto.total.qtd_items_vendidos = obra[auxremov + i + 1].produto.total.qtd_items_vendidos;
                                }
                                Remover_Livro(&obra[auxremov + i]);
                                id_livro -= 1;
                                printf("\n");
                                for (i = 0; i < id_livro; i++) {
                                    if (venda[i].tipo_de_produto == 1) {
                                        if (venda[i].cod_produto >= auxremov) {
                                            venda[i].cod_produto -= 1;
                                        }
                                    }
                                }
                                break;
                                
                            }
                            
                            case 3:
                            {
                                system("clear");
                                int auxedit;
                                printf("Digite o codigo de identificacao do livro: ");
                                scanf("%d", &auxedit);
                                Edit_Livro(&obra[auxedit]);
                                break;
                                
                            }
                                
                            case 4:
                            {
                                system("clear");
                                int auxpesq;
                                printf("Digite o numero de identificacao do livro: ");
                                scanf("%d", &auxpesq);
                                Info_Livro(obra[auxpesq]);
                                break;
                            }
                            
                            case 5:
                            {
                                system("clear");
                                int auxest;
                                printf("Digite o numero de identificacao do livro a ser modificado no estoque: ");
                                scanf("%d", &auxest);
                                Estoque_Livro(&obra[auxest]);
                                break;
                                
                            }
                            case 6:
                            {
                                system("clear");
                                for (int a = 0; a < id_livro; a++) {
                                    Info_Livro(obra[a]);
                                    printf("\n");
                                }
                                break;
                            }

                            default:
                                printf("Opcao invalida\n");
                                break;
                        }
                        break;
                    }
                    case 2:
                    {
                        system("clear");
                        int aux3;
                        printf("\t\t\t\t\tCelular\n1 - Cadastrar Celular\n2 - Remover Celular\n3 - Editar Celular\n4 - Pesquisar Celular\n5 - Modificar produto no estoque\n6 - Todos os Celulares Cadastrados\nOutro numero para sair\nSelecionou: ");
                        scanf("%d", &aux3);
                        switch (aux3) {
                            case 1:
                            {
                                system("clear");
                                if (id_celular >= (tam_livros - 2)) {
                                    modelo = realloc(modelo, (tam_celular + 30));
                                    tam_celular += 30;
                                    printf("A capacidade de celulares cadastraveis foi aumentada em 30, agora o sistema suporta %d modelos de cululares diferentes.\n", tam_celular);
                                    modelo[id_celular] = Add_Celular(modelo[id_celular], id_celular);
                                    id_celular++;
                                    break;
                                } else {
                                modelo[id_celular] = Add_Celular(modelo[id_celular], id_celular);
                                id_celular++;
                                break;
                                }
                            }
                            case 2:
                            {
                                system("clear");
                                int auxremov;
                                printf("Digite o codigo do celular a ser removido: ");
                                scanf("%d", &auxremov);
                                    int i;
                                    for (i = 0; (i + auxremov) < (id_celular - 1); i++) {
                                        strcpy(modelo[auxremov + i].modelo, modelo[auxremov + i + 1].modelo);
                                        modelo[auxremov + i].cod_celular = modelo[auxremov + i + 1].cod_celular;
                                        modelo[auxremov + i].cod_celular -= 1;
                                        modelo[auxremov + i].preco = modelo[auxremov + i + 1].preco;
                                        modelo[auxremov + i].produto.total.items_no_estoque = modelo[auxremov + i + 1].produto.total.items_no_estoque;
                                        modelo[auxremov + i].produto.total.qtd_items_vendidos = modelo[auxremov + i + 1].produto.total.qtd_items_vendidos;
                                        }
                                    
                                    Remover_Celular(&modelo[auxremov + i]);
                                    id_celular -= 1;
                                    printf("\n");
                                    for (i = 0; i < id_livro; i++) {
                                        if (venda[i].tipo_de_produto == 2) {
                                            if (venda[i].cod_produto >= auxremov) {
                                                venda[i].cod_produto -= 1;
                                            }
                                        }
                                    }

                                    break;
                                
                            }
                                
                            case 3:
                            {
                                system("clear");
                                int auxedit;
                                printf("Digite o codigo de identificacao do celular: ");
                                scanf("%d", &auxedit);
                                Edit_Celular(&modelo[auxedit]);
                                break;
                                
                            }
                                
                            case 4:
                            {
                                system("clear");
                                int auxpesq;
                                printf("Digite o codigo de identificacao do celular: ");
                                scanf("%d", &auxpesq);
                                Info_Celular(modelo[auxpesq]);
                                break;
                            }
                                
                            case 5:
                            {
                                system("clear");
                                int auxest;
                                printf("Digite o numero de identificacao do celular a ser modificado no estoque: ");
                                scanf("%d", &auxest);
                                Estoque_Celular(&modelo[auxest]);
                                break;
                                
                            }
                            case 6:
                            {
                                system("clear");
                                for (int a = 0; a < id_celular; a++) {
                                    Info_Celular(modelo[a]);
                                    printf("\n");
                                }
                                break;
                            }

                            default:
                            {
                                system("clear");
                                printf("Opcao invalida\n");
                                break;
                            }
                        }
                        break;

                    }
                        case 3:
                        {
                            system("clear");
                            int aux3;
                            printf("\t\t\t\t\tCDs de Musica\n1 - Cadastrar CD\n2 - Remover CD\n3 - Editar CD\n4 - Pesquisar CD\n5 - Modificar produto no estoque\n6 - Todos os CDs cadastrados\nOutro numero para sair\nSelecionou: ");
                            scanf("%d", &aux3);
                            switch (aux3) {
                                case 1:
                                {
                                    if (id_CD >= (tam_cd - 2)) {
                                    disco = realloc(disco, (tam_cd + 30));
                                    tam_cd += 30;
                                    printf("A capacidade de CDs foi aumentada em 30, agora o sistema suporta %d discos diferentes.\n", tam_cd);
                                    disco[id_CD] = Add_CD(disco[id_CD], id_CD);
                                    id_CD++;
                                    break;
                                    } else {
                                    disco[id_CD] = Add_CD(disco[id_CD], id_CD);
                                    id_CD++;
                                    break;
                                    }
                                }
                                case 2:
                                {
                                    system("clear");
                                    int auxremov;
                                    printf("Digite o codigo do CD a ser removido, 42 para sair: ");
                                    scanf("%d", &auxremov);
                                    int i;
                                    for (i = 0; (i + auxremov) < (id_CD - 1); i++) {
                                        strcpy(disco[auxremov + i].nome_disco, disco[auxremov + i +1].nome_disco);
                                        strcpy(disco[auxremov + i].artista, disco[auxremov + i + 1].artista);
                                        disco[auxremov + i].cod_cd = disco[auxremov + i + 1].cod_cd;
                                        disco[auxremov + i].cod_cd -= 1;
                                        disco[auxremov + i].preco = disco[auxremov + i + 1].preco;
                                        disco[auxremov + i].produto.total.items_no_estoque = disco[auxremov + i + 1].produto.total.items_no_estoque;
                                        disco[auxremov + i].produto.total.qtd_items_vendidos = disco[auxremov + i + 1].produto.total.qtd_items_vendidos;
                                    }
                                    Remover_CD(&disco[auxremov + i]);
                                    id_CD -= 1;
                                    printf("\n");
                                    for (i = 0; i < id_livro; i++) {
                                        if (venda[i].tipo_de_produto == 3) {
                                            if (venda[i].cod_produto >= auxremov) {
                                                venda[i].cod_produto -= 1;
                                            }
                                        }
                                    }
                                    break;
                                    
                                }
                                    
                                case 3:
                                {
                                    system("clear");
                                    int auxedit;
                                    printf("Digite o codigo de identificacao do CD: ");
                                    scanf("%d", &auxedit);
                                        Edit_CD(&disco[auxedit]);
                                        break;
                                    
                                }
                                    
                                case 4:
                                {
                                    system("clear");
                                    int auxpesq;
                                    printf("Digite o codigo de identificacao do CD: ");
                                    scanf("%d", &auxpesq);
                                    Info_CD(disco[auxpesq]);
                                    break;
                                }
                                    
                                case 5:
                                {
                                    system("clear");
                                    int auxest;
                                    printf("Digite o numero de identificacao do CD a ser modificado no estoque: ");
                                    scanf("%d", &auxest);
                                        Estoque_CD(&disco[auxest]);
                                        break;
                                    
                                }
                                    
                                case 6:
                                {
                                    system("clear");
                                    for (int a = 0; a < id_CD; a++) {
                                        Info_CD(disco[a]);
                                        printf("\n");
                                    }
                                    break;
                                }

                                default:
                                {
                                    system("clear");
                                    printf("Opcao invalida\n");
                                    break;
                                }
                            }
                            break;
                        }
                    default:
                    {
                        system("clear");
                        printf("Opcao invalida\n");
                        break;
                    }
                }
                break;
            }
                
                
            case 3:
            {
                system("clear");
                int aux2;
                printf("\t\t\t\t\tVendas\n1 - Cadastrar Venda\n2 - Alterar Venda\n3 - Cancelar Venda\n4 - Pesquisar Venda\n5 - Balanço de vendas\n6 - Produtos mais vendidos por categoria\n7 - Todas as Vendas Cadastradas\nOutro numero para sair\nSelecionou: ");
                scanf("%d", &aux2);
                
                switch(aux2)
                {
                    case 1:
                    {
                        system("clear");
                        int aux3;
                        printf("\t\t\t\t\tCadastrar Venda\n1 - Livro\n2 - Celular\n3 - CD de Musica\nOutro numero para sair\nSelecionou: ");
                        scanf("%d", &aux3);
                        switch (aux3) {
                            case 1:
                            {
                                system("clear");
                                if (id_venda >= (tam_vendas - 2)) {
                                    venda = realloc(venda, (tam_vendas + 30));
                                    tam_vendas += 30;
                                    int auxfun, auxlivro;
                                    printf("Qual o codigo do livro vendido: ");
                                    scanf("%d", &auxlivro);
                                    printf("Qual o codigo do funcionario que fez a venda: ");
                                    scanf("%d", &auxfun);
                                    Cadastrar_Venda_Livro(&vendedor[auxfun], &obra[auxlivro], &venda[id_venda], id_venda);
                                    id_venda += 1;
                                    break;

                                } else {
                                int auxfun, auxlivro;
                                printf("Qual o codigo do livro vendido: ");
                                scanf("%d", &auxlivro);
                                printf("Qual o codigo do funcionario que fez a venda: ");
                                scanf("%d", &auxfun);
                                Cadastrar_Venda_Livro(&vendedor[auxfun], &obra[auxlivro], &venda[id_venda], id_venda);
                                id_venda += 1;
                                break;
                                }
                            }
                            case 2:
                            {
                                system("clear");
                                if (id_venda >= (tam_vendas - 2)) {
                                venda = realloc(venda, (tam_vendas + 30));
                                tam_vendas += 30;
                                int auxfun, auxcelular;
                                printf("Qual o codigo do Celular vendido: ");
                                scanf("%d", &auxcelular);
                                printf("Qual o codigo do funcionario que fez a venda: ");
                                scanf("%d", &auxfun);
                                Cadastrar_Venda_Celular(&vendedor[auxfun], &modelo[auxcelular], &venda[id_venda], id_venda);
                                id_venda += 1;
                                break;
                                } else {
                                int auxfun, auxcelular;
                                printf("Qual o codigo do Celular vendido: ");
                                scanf("%d", &auxcelular);
                                printf("Qual o codigo do funcionario que fez a venda: ");
                                scanf("%d", &auxfun);
                                Cadastrar_Venda_Celular(&vendedor[auxfun], &modelo[auxcelular], &venda[id_venda], id_venda);
                                id_venda += 1;
                                break;
                                }
                            }
                            case 3:
                            {
                                system("clear");
                                if (id_venda >= (tam_vendas - 2)) {
                                venda = realloc(venda, (tam_vendas + 30));
                                tam_vendas += 30;
                                int auxfun, auxdisco;
                                printf("Qual o codigo do CD vendido: ");
                                scanf("%d", &auxdisco);
                                printf("Qual o codigo do funcionario que fez a venda: ");
                                scanf("%d", &auxfun);
                                Cadastrar_Venda_CD(&vendedor[auxfun], &disco[auxdisco], &venda[id_venda], id_venda);
                                id_venda += 1;
                                break;
                                } else {
                                int auxfun, auxdisco;
                                printf("Qual o codigo do CD vendido: ");
                                scanf("%d", &auxdisco);
                                printf("Qual o codigo do funcionario que fez a venda: ");
                                scanf("%d", &auxfun);
                                Cadastrar_Venda_CD(&vendedor[auxfun], &disco[auxdisco], &venda[id_venda], id_venda);
                                id_venda += 1;
                                break;
                                }
                            }
                            default:
                            {
                                system("clear");
                                printf("Opcao invalida\n");
                                break;
                            }
                        }
                        
                        break;	
                    }
                        
                        
                    case 2:
                    {
                        system("clear");
                        int auxvenda, auxfun, auxprod;
                        printf("Digite o Codigo De Identificacao da venda a ser modificada: ");
                        scanf("%d", &auxvenda);
                        auxfun = venda[auxvenda].cod_funcionario;
                        auxprod = venda[auxvenda].cod_produto;
                        if(venda[auxvenda].tipo_de_produto == 1){
                            Alterar_Venda_Livro(&vendedor[auxfun], &obra[auxprod], &venda[auxvenda]);
                        } else if (venda[auxvenda].tipo_de_produto == 2) {
                            Alterar_Venda_Celular(&vendedor[auxfun], &modelo[auxprod], &venda[auxvenda]);
                        } else if (venda[auxvenda].tipo_de_produto == 3) {
                            Alterar_Venda_CD(&vendedor[auxfun], &disco[auxprod], &venda[auxvenda]);
                        }
                        break;
                    }
                        
                        
                    case 3:
                    {
                        system("clear");
                        int auxcancel, auxfun, auxprod;
                        printf("Digite o codigo de identificacao da venda a ser cancelada: ");
                        scanf("%d", &auxcancel);
                        auxfun = venda[auxcancel].cod_funcionario;
                        auxprod = venda[auxcancel].cod_produto;
                        if(venda[auxcancel].tipo_de_produto == 1){
                            Cancelar_Venda_Livro(&vendedor[auxfun], &obra[auxprod], &venda[auxcancel]);
                        } else if (venda[auxcancel].tipo_de_produto == 2) {
                            Cancelar_Venda_Celular(&vendedor[auxfun], &modelo[auxprod], &venda[auxcancel]);
                        } else if (venda[auxcancel].tipo_de_produto == 3) {
                            Cancelar_Venda_CD(&vendedor[auxfun], &disco[auxprod], &venda[auxcancel]);
                        }
                        break;	
                    }
                        
                    case 4:
                    {
                        system("clear");
                        int auxpesq;
                        printf("Digite o codigo da venda a ser pesquisada: ");
                        scanf("%d", &auxpesq);
                        Info_Venda(venda[auxpesq]);
                        break;
                    }
                        
                    case 5:
                    {
                        system("clear");
                        int i, total = 0, tot_livros = 0, tot_celulares = 0, tot_discos = 0;
                        int val_total = 0, val_livro = 0, val_celular = 0, val_disco = 0;
                        for (i = 0; i < id_livro; i++) {
                            total += obra[i].produto.total.qtd_items_vendidos;
                            tot_livros += obra[i].produto.total.qtd_items_vendidos;
                            val_total += obra[i].produto.total.qtd_items_vendidos * obra[i].preco;
                            val_livro += obra[i].produto.total.qtd_items_vendidos * obra[i].preco;
                        }
                        for (i = 0; i < id_celular; i++) {
                            total += modelo[i].produto.total.qtd_items_vendidos;
                            tot_celulares += modelo[i].produto.total.qtd_items_vendidos;
                            val_total += modelo[i].preco * modelo[i].produto.total.qtd_items_vendidos;
                            val_celular += modelo[i].preco * modelo[i].produto.total.qtd_items_vendidos;
                        }
                        for (i = 0; i < id_CD; i++) {
                            total += disco[i].produto.total.qtd_items_vendidos;
                            tot_discos += disco[i].produto.total.qtd_items_vendidos;
                            val_total += disco[i].preco * disco[i].produto.total.qtd_items_vendidos;
                            val_disco += disco[i].preco * disco[i].produto.total.qtd_items_vendidos;
                        }
                        
                        printf("Nesse mes, a livraria vendeu %d produtos, acumulando %d reais em vendas.\nForam vendidos:\n%d livros, acumulando %d reais.\n%d celulares, acumulando %d reais.\n%d CDs de musica, acumulando %d reais.\n", total, val_total, tot_livros, val_livro, tot_celulares, val_celular, tot_discos, val_disco);
                        break;	
                    }
                    case 6:
                    {
                        system("clear");
                        char nome_cel[30], nome_livro[30], nome_cd[30];
                        int i, qtd_livro = 0, qtd_cel = 0, qtd_cd = 0;
                        for (i = 0; i < id_livro; i++) {
                            if (obra[i].produto.total.qtd_items_vendidos > qtd_livro) {
                                qtd_livro = obra[i].produto.total.qtd_items_vendidos;
                                strcpy(nome_livro, obra[i].titulo);
                            }
                        }
                        for (i = 0; i < id_celular; i++) {
                                if (modelo[i].produto.total.qtd_items_vendidos > qtd_cel) {
                                qtd_cel = modelo[i].produto.total.qtd_items_vendidos;
                                strcpy(nome_cel, modelo[i].modelo);
                            }
                        }
                        for (i = 0; i < id_CD; i++) {
                            if (disco[i].produto.total.qtd_items_vendidos > qtd_cd) {
                                qtd_cd = disco[i].produto.total.qtd_items_vendidos;
                                strcpy(nome_cd, disco[i].nome_disco);
                            }
                        }
                        
                        
                        printf("%s foi o produto mais vendido na categoria livros\n%s foi o produto mais vendido na categoria celulares\n%s foi o produto mais vedido na categoria CDs de musica\n", nome_livro, nome_cel, nome_cd);
                        break;
                    }
                        
                    case 7:
                    {
                        system("clear");
                        for (int a = 0; a < id_venda; a++) {
                            Info_Venda(venda[a]);
                            printf("\n");
                        }
                        break;
                    }
                        
                    default:
                    {
                        system("clear");
                        printf("Opção invalida!\n");
                        break;
                    }
                }
                break;
            }
                
            case 4:
            {
                V_Aux_Arq[0] = tam_funcionarios;
                V_Aux_Arq[2] = tam_livros;
                V_Aux_Arq[4] = tam_celular;
                V_Aux_Arq[6] = tam_cd;
                V_Aux_Arq[8] = tam_vendas;
                V_Aux_Arq[3] = id_livro;
                V_Aux_Arq[1] = id_funcionario;
                V_Aux_Arq[7] = id_CD;
                V_Aux_Arq[5] = id_celular;
                V_Aux_Arq[9] = id_venda;
                
                Lista_Variaveis = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Auxiliares.txt", "w");
                Lista_Vendedores = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Funcionarios.txt", "w");
                Lista_Livros = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Livros.txt", "w");
                Lista_Celulares = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Celular.txt", "w");
                Lista_CDs = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/CDs.txt", "w");
                Lista_Vendas = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Vendas.txt", "w");
                
                for (int i = 0; i < 10; i++) {
                    fprintf(Lista_Variaveis, "%d ", V_Aux_Arq[i]);
                }
                
                fwrite(vendedor, sizeof(Funcionario), id_funcionario, Lista_Vendedores);
                fwrite(obra, sizeof(Livro), id_livro, Lista_Livros);
                fwrite(modelo, sizeof(Celular), id_celular, Lista_Celulares);
                fwrite(disco, sizeof(CD_Musica), id_CD, Lista_CDs);
                fwrite(venda, sizeof(Vendas_Armazenada), id_venda, Lista_Vendas);
                
                fclose(Lista_Variaveis);
                fclose(Lista_Vendas);
                fclose(Lista_CDs);
                fclose(Lista_Celulares);
                fclose(Lista_Livros);
                fclose(Lista_Vendedores);
                printf("\n");
                break;
            }
                
            case 5:
            {
                V_Aux_Arq[0] = tam_funcionarios;
                V_Aux_Arq[2] = tam_livros;
                V_Aux_Arq[4] = tam_celular;
                V_Aux_Arq[6] = tam_cd;
                V_Aux_Arq[8] = tam_vendas;
                V_Aux_Arq[3] = id_livro;
                V_Aux_Arq[1] = id_funcionario;
                V_Aux_Arq[7] = id_CD;
                V_Aux_Arq[5] = id_celular;
                V_Aux_Arq[9] = id_venda;

                Lista_Variaveis = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Auxiliares.txt", "w");
                Lista_Vendedores = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Funcionarios.txt", "w");
                Lista_Livros = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Livros.txt", "w");
                Lista_Celulares = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Celular.txt", "w");
                Lista_CDs = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/CDs.txt", "w");
                Lista_Vendas = fopen("/Users/henrique/Documents/h/tu desistindo ja/tu desistindo ja/Projeto Livraria/Projeto Livraria/Vendas.txt", "w");
                
                for (int i = 0; i < 10; i++) {
                    fprintf(Lista_Variaveis, "%d ", V_Aux_Arq[i]);
                }
                
                fwrite(vendedor, sizeof(Funcionario), id_funcionario, Lista_Vendedores);
                fwrite(obra, sizeof(Livro), id_livro, Lista_Livros);
                fwrite(modelo, sizeof(Celular), id_celular, Lista_Celulares);
                fwrite(disco, sizeof(CD_Musica), id_CD, Lista_CDs);
                fwrite(venda, sizeof(Vendas_Armazenada), id_venda, Lista_Vendas);
                
                fclose(Lista_Variaveis);
                fclose(Lista_Vendas);
                fclose(Lista_CDs);
                fclose(Lista_Celulares);
                fclose(Lista_Livros);
                fclose(Lista_Vendedores);
                
                free(vendedor);
                vendedor = NULL;
                free(obra);
                obra = NULL;
                free(modelo);
                modelo = NULL;
                free(disco);
                disco = NULL;
                free(venda);
                venda = NULL;

                return 0;
                break;
            }
                
                
            default:
            {
                system("clear");
                printf("Opção invalida!\n");
                break;
            }	
        }
        printf("\n");
        
    }
    
}
