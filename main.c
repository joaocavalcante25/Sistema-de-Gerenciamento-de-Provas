#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carregaArquivos(){

}

void print(char string[100]){
    int count = 0;
    for (int i = 0; i < strlen(string)-1; i++){
        if (string[i] != ','){
            printf("%c",string[i]);
        }     
    }
    printf("\n\n");
}

void gerarInfoCandidatos(){

}

void pesquisarCandidatos(){
    FILE *arquivo;
    char linha[100], *id, result[100];
    int i, input, output, achou;
    input = -1;
    printf("VOCÊ ENTROU NO MENU DE PESQUISA...\n\n\n");
    while (input != 0){
        printf("INFORME A MATRICULA DO CANDIDATO OU 0 PARA ENCERRAR A PESQUISA: ");
        scanf("%d", &input);
        arquivo = fopen("dados.txt", "r");
        if (arquivo == NULL){
            printf("Problema na abertura do arquivo\n");    
            return;
        }
        achou = -1;
        i = 0;
        while(!feof(arquivo) && achou != 0){
            fgets(linha, 100, arquivo);
            strcpy(result, linha);
            id  = strtok(linha, ",");
            output = strtol(id, NULL, 10);
            if(output == input && i > 0){
                print(result);
                achou = 0;
            }
            i++;
        } 
        fclose(arquivo);
    }
    fclose(arquivo);
}

void geraraInfoCandidatosReprovados(){

}

void alterarNotaRedacao(){

}

int main(){
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
                carregaArquivos();
                break;
            case 1:
                gerarInfoCandidatos();
                break;
            case 2:
                pesquisarCandidatos();
                break;
            case 3:
                geraraInfoCandidatosReprovados();
                break;
            case 4:
                alterarNotaRedacao();
                break;
            default:
                break;
        }  

    }


    return 0;
}