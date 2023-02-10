#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ficha /* estrutura de armazenamento de informações de conta*/
    {
        int numeroDaConta, saldoConta;
        char nomeCliente[50];
        struct ficha *prox;
    } fichaClientes;

void boas_vindas(void);
fichaClientes* cadastrarConta(fichaClientes *conta);
void mostrar_conta(fichaClientes *contaNova);
void busca_usuario(fichaClientes *contas);

int main()
{
    int menuPrincipal, indiceDaConta = 0;
    fichaClientes *contas;
    contas=NULL;

    boas_vindas();
    do
    {

        printf("Seja Bem-Vindo ao Banco Osíris!\n\n Qual operação você deseja realizar?:\n\n1. Cadastrar contas. \n2. Visualizar todas as contas de determinado cliente. \n3. Buscar Usuário \n4. Sair.\n");
        scanf("%d", &menuPrincipal);
        switch (menuPrincipal)
        {
            case 1:
                contas = cadastrarConta(contas);
                break;
            case 2:
                mostrar_conta(contas);

                break;

            case 3:
                busca_usuario(contas);

                break;

            case 4:

                break;

            default:
                printf("A Opção digitada é inválida!!!");
                break;
        }
    } while (menuPrincipal != 4);
    
    return 0;
}


void boas_vindas(void) /* função para gerar o cabeçalho de apresentação do sistema */
{
  printf("************************************\n");   
  printf("*           Banco Osíris           *\n");
  printf("************************************\n");   

};

fichaClientes* cadastrarConta(fichaClientes *conta)
{
    fichaClientes *aux;
    fichaClientes *novo_reg= malloc(sizeof(fichaClientes));
    boas_vindas();
    printf("Digite seu nome: \n");
    scanf(" %s[^\n]",&novo_reg->nomeCliente); 
    printf("\nDigite o número da conta: \n");
    scanf(" %d", &novo_reg->numeroDaConta);
    printf("\nDigite o saldo da conta: \n");
    scanf(" %d", &novo_reg->saldoConta);
    novo_reg->prox= NULL;
    if (conta == NULL)
    {
        conta=novo_reg;
    }
    else
    {
        aux= conta;
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo_reg;
    }
    return conta;

}

void mostrar_conta(fichaClientes *conta)
{
    fichaClientes *aux;
    aux=conta;
    while (aux!=NULL)
    {
        printf("Nome do Cliente: %s\n", aux->nomeCliente);
        printf("Número da conta: %d\n", aux->numeroDaConta);
        printf("Saldo da conta: R$ %d\n\n", aux->saldoConta);
        aux=aux->prox;
    }
    
   
    
}

void busca_usuario(fichaClientes *contas)
{
    fichaClientes *aux;
    aux=contas;
    int menu,numeroDaConta, achou = 0;
    char nome[50];
    printf("Por qual critério você gostaria de realizar a sua pesquisa?\n1- Nome de usuário\n2-Número de conta\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("Digite o nome do cliente que deseja buscar: ");
        scanf(" %s[^\n]", &nome);
        while (aux!=NULL)
        {
            if (strcmp(aux->nomeCliente,nome)==0)
            {
                achou=1;
                break;
            }
            else
            {
            aux=aux->prox;   
            }
        }
        if (achou == 0)
        {
            printf("nome de usuário não localizado\n\n");
        }
        else
        {
            printf("Conta localizada!!\n\nNome do Cliente: %s\nNúmero da conta: %d\nSaldo da conta: %d\n\n", aux->nomeCliente,aux->numeroDaConta,aux->saldoConta);
        }
        
        break;
    
    case 2:
        printf("Digite o número da conta que deseja buscar: ");
        scanf("%d", &numeroDaConta);
        while (aux!= NULL)
        {
            if (aux->numeroDaConta==numeroDaConta)
            {
                achou=1;
                break;
            }
            else
            {
                aux=aux->prox;
            }
        }
        if (achou==0)
        {
            printf("Número da conta não localizado\n\n");
        }
        else
        {
            printf("Conta encontrada! \nNome do cliente: %s\nNúmero da conta: %d \n Saldo da conta: %d\n\n\n", aux->nomeCliente,aux->numeroDaConta,aux->saldoConta);
        }
       break;
    default:
        printf("Opção inválida!!!");
        break;
    }

    
}