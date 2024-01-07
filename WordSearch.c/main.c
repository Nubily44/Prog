/* 
    -- = Busca de uma palavra por um texto indexado em duas estruturas de dados (O Famoso Ctrl-F)                               = --

    -- = 1. Lista ligada (LinkList) e 2. Arvore binaria (BinTree)                                                               = --
    -- = O programa foi feito para ser executado no Windows, com o terminal do PowerShell                                       = --

    -- = O programa foi estruturado para ler o texto apenas uma vez, após a primeira busca ser inserida                         = -- 
    -- = Portanto é impossível medir o tempo de leitura do texto, apenas o tempo de busca (foram tentados diversos métodos)     = --

    -- = Os arquivos main.c, LinkList.c, LinkList.h, BinTree.c e BinTree.h e o .txt a ser analisado devem estar na mesma pasta  = --
    -- = Os arquivos extras (headers) foram comentados nos arquivos .h (para facilitar a leitura)                               = --

    -- ~ Code by Lily ~ --

*/
// Bibliotecas usadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Headers utulizados para indexar o texto
#include "LinkList.h"
#include "BinTree.h"

// Macros usados para o programa
#define MAX_WORD_SIZE 50
#define MAX_LINE_SIZE 1000
#define MAX_LINES 1000



// Função que conta o numero de linhas do arquivo
int countLines(const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1; 
    }

    int lineCount = 0;
    char buffer[MAX_LINE_SIZE];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lineCount++;
    }

    fclose(file);

    return lineCount;
}

// Função que lê o arquivo e separa as linhas em um array de ponteiros
void readText(char text[MAX_LINES][MAX_LINE_SIZE], char *fileName) {
    FILE *file = fopen(fileName, "r");
    int i = 0;

    if (file != NULL) {
        while (i < MAX_LINES && fgets(text[i], MAX_LINE_SIZE, file) != NULL) {
            // Remove the newline character at the end of the line
            text[i][strcspn(text[i], "\n")] = '\0';
            if (text[i][0] == '\0') {
            continue;
            }
            i++;
        }

        fclose(file);
    } else {
        fprintf(stderr, "Error opening file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
}

// Função que separa as palavras de cada linha em um array de strings
void tokenizeLine(char *line, char ***words, int *numWords) {
    *numWords = 0;
    char *token = strtok(line, " ");

    *words = (char **)malloc(sizeof(char *));
    
    while (token != NULL) {
        
        (*words)[*numWords] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if ((*words)[*numWords] == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }

        strcpy((*words)[*numWords], token);

        (*numWords)++; 

        *words = realloc(*words, (*numWords + 1) * sizeof(char *));
        if (*words == NULL) {
            perror("Memory reallocation error");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " ");
    }
    (*words)[*numWords] = NULL; 
}

// Função que libera a memória alocada para as palavras da linha
void freeWords(char **words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
}

//Menu básico de uso do programa
void printMenu(){

    printf("Uso correto do programa:\ncd <filePATH>\ngcc -o <saida.exe> main.c BinTree.c LinkList.c\nStart-Process -FilePath \"<saida>\" -ArgumentList \"<texto.txt>\", \"<tipo_de_estrutura>\"\n\n");
    printf("Tipos de estrutura de dados:\n\"lista\" // \"arvore\"\n");
    printf("Para sair do programa, digite: \"sair_do_programa\" como palavra buscada\n\n");
    printf("Exemplo de uso:\nStart-Process -FilePath \"test.exe\" -ArgumentList \"texto.txt\", \"lista\"\n\n");
    printf("Code by Lily\n\n\n");

}
// Main
int main(int argc, char ** argv){

    if(argc == 3  &&  (!(strcasecmp(argv[2], "lista")) || !(strcasecmp(argv[2], "arvore")))) {printMenu();}
    printf("------------------------------------------------------------------------------\n\n\n");

    char aux_teste[50];     // Placeholder para sair do programa e debug
    abool aux_lido = false; // Auxiliar para evitar de o arquivo ser lido duas vezes
    int times_loop = 0;     //Auxiliar em debugs, para garantir quantas vezes o loop de while foi executado (foi util para resolver problemas de vazamento de memoria) 

    list *LinkList = createLinkList(); // Lista ligada para indexar o texto
    tree *BinTree = createBinTree();  // Arvore binaria para indexar o texto

    char texto[MAX_LINES][MAX_LINE_SIZE];       // O texto em si que será lido e transcrito
    char texto_copy[MAX_LINES][MAX_LINE_SIZE]; // Uma copia do texto para ser usado na impressão das linhas

    list *target_1; // A palavra que será procurada foi armazenada em uma estrutura semelhante a qual o texto foi armazenado, por conveniência
    tree *target_2; // todas as variáveis temporária com o sufixo _1 são referentes a lista ligada, e as com o sufixo _2 são referentes a arvore binaria

    printf("Tipo de indice: '%s'\n", argv[2]);
    printf("Arquivo texto: '%s'\n", argv[1]);                           // Informações do arquivo e tipo de indice
    printf("Numero de linhas no arquivo: %d\n", countLines(argv[1]));


    while(argc == 3  &&  (!(strcasecmp(argv[2], "lista")) || !(strcasecmp(argv[2], "arvore")))) {

        //Leitura do input, e verificação da validade dele
        char linha[MAX_LINE_SIZE];
        char busca[MAX_WORD_SIZE];
        char palavra[MAX_WORD_SIZE];

        printf("> ");
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';    
        sscanf(linha, "%s %s", busca, palavra);

        //Palavra inválida
        if ((strcasecmp(busca, "busca") != 0) && (strcasecmp(busca, "fim") != 0)){
            printf("Opcao invalida!\n");
            busca[0] = '\0';
        }
        
        // Sair do programa
        if (!strcasecmp(busca, "fim")){
            return 1;
        }

        // Palavra vazia (não estava no enunciado, mas achei que seria bom ter)
        if(!strcasecmp(palavra, "")){
            printf("insira uma palavra para buscar!\n");
        }


        // Se o programa foi executado de maneira correta, ele começa a funcionar
        if (!strcasecmp(busca, "busca") && strcasecmp(busca, "fim") != 0 ){

            clock_t start, end;

            readText(texto, argv[1]);

            for (int l=0; l < MAX_LINES; l++){
                strcpy(texto_copy[l], texto[l]);
            }

            // Se o texto não foi lido (indexado nas estruturas de dados), ele é lido agora, apenas uma vez
            if (aux_lido == false){
                for (int i = 0; i < MAX_LINES && texto[i][0] != '\0'; i++) {
                    char **words;
                    int numWords;

                    tokenizeLine(texto[i], &words, &numWords);

                    for (int j = 0; j < numWords; j++) { 

                        // Caso seja utilizada uma Lista ligada:
                        if(!(strcasecmp(argv[2], "lista"))){ 

                            // Inserção de uma palavra que não foi encontrada na estrutura (nova)
                            if(LinkList_searchNode(LinkList, words[j]) == NULL){ 

                                LinkList_insertNode(LinkList, words[j]); // Novo nó
                                LinkList_Node *new_1 = LinkList_searchNode(LinkList, words[j]); // achar o nó que foi criado

                                // Mudança de seus parâmetros
                                new_1->address[new_1->count] = i;
                                new_1->count++;
                            }
                            // Inserção de uma palavra que já foi encontrada na estrutura (recorrente)
                            else if (LinkList_searchNode(LinkList, words[j]) != NULL){

                                LinkList_Node *found_1 = LinkList_searchNode(LinkList, words[j]); // achar o nó que já existe

                                // Mudança de seus parâmetros
                                found_1->address[found_1->count] = i;
                                found_1->count++;

                            }
                        }
                        // Caso seja utilizada uma arvore binaria:
                        else if(!(strcasecmp(argv[2], "arvore"))){

                            // Inserção de uma palavra que não foi encontrada na estrutura (nova)
                            if(BinTree_searchNode(BinTree, words[j]) == NULL){ 

                                BinTree_insertNode(BinTree, words[j]); // Novo nó
                                BinTree_Node *new_2 = BinTree_searchNode(BinTree, words[j]); // achar o nó que foi criado

                                // Mudança de seus parâmetros
                                new_2->address[new_2->count] = i;
                                new_2->count++;
                            }
                            // Inserção de uma palavra que já foi encontrada na estrutura (recorrente)
                            else if (BinTree_searchTimes(BinTree, words[j]) != 0){
                                
                                BinTree_Node *found_2 = BinTree_searchNode(BinTree, words[j]); // achar o nó que já existe

                                // Mudança de seus parâmetros
                                found_2->address[found_2->count] = i;
                                found_2->count++;
                            }
                        }
                    }
                    freeWords(words, numWords); // Liberação da memória alocada da linha, para 
                }
                aux_lido++; // Para evitar que o texto seja lido duas vezes (aux_lido = true, texto foi lido)
            }

            start = clock(); //medição do tempo de busca

            target_1 = createLinkList(); // Lista ligada para indexar o nó com a palavra buscada
            target_2 = createBinTree(); // Arvore binaria para indexar o nó com a palavra buscada

            abool inside = false; // Auxiliar para verificar se a palavra buscada está no texto

            // Verificação se a palavra buscada está no texto para ambos os casos
            if (LinkList_searchNode(LinkList, palavra) != NULL && !(strcasecmp(argv[2], "lista"))){
                inside = true; 
            }
            if (BinTree_searchNode(BinTree, palavra) != NULL && !(strcasecmp(argv[2], "arvore"))){
                inside = true;
            }

            // Caso a palavra buscada esteja no texto, ela é inserida na estrutura de dados temporária (target_1 ou target_2)
            if(!(strcasecmp(argv[2], "lista")) && inside == true) {

                // Basicamente cria um nó (head) no target com as informações sobre a palavra buscada
                LinkList_insertNode(target_1, palavra);
                target_1->head->count = LinkList_searchNode(LinkList, palavra)->count;
                for (int k = 0; k < target_1->head->count; k++){
                    target_1->head->address[k] = LinkList_searchNode(LinkList, palavra)->address[k];
                }

            }else

            if(!(strcasecmp(argv[2], "arvore")) && inside == true){

                // Basicamente cria um nó (root) no target com as informações sobre a palavra buscada
                BinTree_insertNode(target_2, palavra);
                target_2->root->count = BinTree_searchNode(BinTree, palavra)->count;
                for (int k = 0; k < target_2->root->count; k++){
                    target_2->root->address[k] = BinTree_searchNode(BinTree, palavra)->address[k];
                }
            }

            // Caso a palavra buscada não esteja no texto
            if (inside == false){
                printf("Palavra '%s' nao encontrada.\n", palavra);
            }
            else{

            // Impressão dos resultados da busca
            if(!(strcasecmp(argv[2], "lista"))){printf("Existem %d ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", target_1->head->count, palavra);}
            else
            if(!(strcasecmp(argv[2], "arvore"))){printf("Existem %d ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", target_2->root->count, palavra);}

            // Impressão das linhas que contém a palavra buscada
            if(!(strcasecmp(argv[2], "lista"))) {
                for (int k = 0; k < target_1->head->count; k++){
                    printf("%05d %.*s\n", target_1->head->address[k]+1,MAX_LINE_SIZE, texto_copy[target_1->head->address[k]]);
                }
            }else
            if(!(strcasecmp(argv[2], "arvore"))) {
                for (int k = 0; k < target_2->root->count; k++){
                    printf("%05d %.*s\n", target_2->root->address[k]+1,MAX_LINE_SIZE, texto_copy[target_2->root->address[k]]);
                }
            }
            }

            end = clock(); //medição do tempo de busca
            double time = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC; //medição do tempo de busca

            printf("Tempo de busca: %.2f ms\n", time);

            // Liberação da memória alocada para as estruturas temporárias (target_1 e target_2)
            if(!(strcasecmp(argv[2], "lista"))){
                LinkList_free(target_1);
            }
            else
            if(!(strcasecmp(argv[2], "arvore"))){
                BinTree_free(target_2);
            }
        }
        // Atualização do número de vezes que o loop foi executado (útil para o debug)
        times_loop++;
    }

    // Caso o programa não tenha sido executado corretamente, ele imprime o menu de uso correto e uma entrada antes de fechar
    if(argc != 3 || (strcasecmp(argv[2], "lista") || strcasecmp(argv[2], "arvore"))){
        printMenu();
        printf("\n");
        printf("Escreva algo para sair do programa: \n");
        scanf("%s", aux_teste);
        return 1;
    }

    return 1; // End
}
