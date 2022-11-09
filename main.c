#include <stdio.h>
#include <stdlib.h>


int main() {
    int input = -1;
    int arquivos_carregados = 0;
    while (input != 5)
    {
        /* code */
        printf(".+*****+.MENU.+*****+.\n");
        if(arquivos_carregados == 0)
        {
            printf("0 - Carregar os arquivos de entrada\n");
        }
        printf("1 - Gerar arquivo de saída .txt\n");
        printf("2 - Pesquisar candidatos .txt\n");
        printf("3 - Gerar arquivo dos candidatos não aprovados\n");
        printf("4 - Alterar nota de redação dos candidatos que entraram com recurso\n");
        printf("5 - Encerrar programa\n"); 
        scanf("%d", &input);
        switch (input)
        {
            case 0:
                /* code */
                arquivos_carregados = 1;
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                break;
        }
        
    }
    
    
    return 0;
}