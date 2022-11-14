#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void freeArray(char **array, int tamanho){
    for (int i = 0; i < tamanho; i++)
        free(array[i]);
    free(array);
}

void clear(char string[MAX]){
    for (int i = 0; i < strlen(string); i++){
        string[i] ='\0';
    }
    
}

char** split(char **result, char text[MAX], int tamanho){
    int quebra = 0;
    char value[50] = "";
    result = malloc( (tamanho + 1) * sizeof(char**));
    for (int i = 0; i < strlen(text) ;i++){
        if (text[i]==','){
            result[quebra] = malloc((strlen(value)+1)*sizeof(char*));
            strcpy(result[quebra], value);
            clear(value);
            quebra++;
        }
        if(text[i] != ',')
            strncat(value, &text[i], 1);
    }
    return result;
    //for (int i = 0; i < tamanho; i++)
        //free(result[i]);
    //free(result);
}

char* getCursoById(int idCurso){
    FILE *archive;
    char **array, line[MAX], curso[50];
    int idCursoAux;
    int i = 0;
    archive = fopen("cursos_e_pesos.txt", "r");
    if (archive == NULL){
        printf("Problema na abertura do arquivo\n");    
        return NULL;
    }
    while(!feof(archive)){
        fgets(line, MAX, archive);
        if (i>0){ 
            array = split(array, line, getTamanho(line)); 
            idCursoAux = strtol(array[0], NULL, 10);
            if(idCurso == idCursoAux){
                printf("%s\n", array[1]);
                strcpy(curso, array[i]);
                freeArray(array, getTamanho(line));
                return curso;
            }
        }
        i++;
    }
    return NULL;
}

int getTamanho(char text[MAX]){
    unsigned int tamanho = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i]==',') tamanho++;
    return tamanho;
}

void carregaArquivos(){

}

void print(char **array, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (array!=NULL){
            printf("%s",array[i]);
        }     
    }
}

void gerarInfoCandidatos(){

}

void pesquisarCandidatos(){
    FILE *arquivo;
    char linha[MAX], **data, **candidato;
    int input, idCurso, totalCandidatos, idCandidato, achou;
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
        while(!feof(arquivo)){
            fgets(linha, MAX, arquivo);
            data = split(data, linha, getTamanho(linha));
            idCurso = strtol(data[0], NULL, 10);
            totalCandidatos = strtol(data[1], NULL, 10);
            for (int i = 0; i < totalCandidatos; i++){
                if(!feof(arquivo)){
                    fgets(linha, MAX, arquivo);
                    candidato = split(candidato, linha, getTamanho(linha));
                    idCandidato = strtol(candidato[0], NULL, 10);
                    if(idCandidato == input){
                        print(candidato, getTamanho(linha));
                        printf("%s\n",getCursoById(idCurso));
                        freeArray(candidato, getTamanho(linha));
                    }
                }
            }
        }
        if(!feof(arquivo)){
            freeArray(data, getTamanho(linha));
        }
        
        
        //achou = 0;
        //i = 0;
        //while(!feof(arquivo) && achou != 1){
            //fgets(linha, 100, arquivo);
            //strcpy(result, linha);
            //id  = strtok(linha, ",");
            //output = strtol(id, NULL, 10);
            //if(output == input && i > 0){
                //print(result);
                //achou = 1;
            //}
            //i++;
        //} 
    }
    fclose(arquivo);
}

void geraraInfoCandidatosReprovados(){

}

void alterarNotaRedacao(){

}

int main(){
    int input = -1;
    char **data;
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