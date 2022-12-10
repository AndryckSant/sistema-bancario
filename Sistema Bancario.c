#include <stdio.h>

int main()
{
    int menuPrincipal;

    do
    {
        printf("Seja Bem-Vindo ao Banco Osíris!\n\n Qual operação você deseja realizar?:\n\n1. Cadastrar contas. \n2. Visualizar todas as contas de determinado cliente. \n3. Excluir a conta com menor saldo (supondo a não existência de saldos iguais). \n4. Sair.\n");
        scanf("%d", &menuPrincipal);
        switch (menuPrincipal)
        {
            case 1:
            
                break;
            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            default:
                printf("A Opção digitada é inválida!!!");
                break;
        }
    } while (menuPrincipal != 4);
    
    return (0);
}