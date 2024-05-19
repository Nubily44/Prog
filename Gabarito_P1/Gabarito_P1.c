#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

/* Code by Lily */

/* Gabarito (Não Oficial) P1 ACH2001 2024 / Prof Marcelo Morandini */

void separa(){
    printf("\n\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\n\n");

}
void Hud(){
    printf("Gabarito (Não Oficial) P1 ACH2001 2024 / Prof Marcelo Morandini\n\nCode by Lily\n\n\n");
}



/* Questão 1 */

double fahrenheit(double celsius) {

    return (celsius * 1.8) + 32; //Retorna a conta de conversão de celsius para fahrenheit

}

/* Questão 1 */



/* Questão 2 */

/* Opção sem recursão*/

void bin1(int n){

    int aux = n, i = 0;

    int bin[100];

    while (aux > 0) {
        bin[i] = aux % 2;              // Calcula o digito binário
        aux = aux / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", bin[j]);         // Imprime o vetor binário ao contrário
    }
    printf("\n");
}

/* Opção Recursiva */

int auxbin2(int n){
    if (n == 0){
        return 0;
    }
    else{
        return(n % 2 + 10 * auxbin2(n / 2));
    }
}
void bin2(int n){

    printf("%d\n", auxbin2(n));

}

/* Questão 2 */



/* Questão 3 */
void questao3(){

    int n;
    double soma = 0, maior, menor;

    printf("Digite a quantidade de numeros: \n");
    scanf("%d", &n);

    double resultados[3]; // Vetor resultados, para organizar. Poderia ser util caso a função retornasse esse vetor com ponteiros
    double a[n];
    
    // int *a = (int *) malloc(n * sizeof(int)); Easter egg ;)

    for (int i = 0; i < n; i++){
        printf("Digite o %dº numero: \n", i+1);
        scanf("%lf", &a[i]);
        if (i == 0){
            maior = a[i];
            menor = a[i];
        }
        else{
            if (a[i] > maior){
                maior = a[i];
            }
            if (a[i] < menor){
                menor = a[i];
            }
        }
        soma += a[i];
    }

    resultados[0] = (double) soma/n; // Conversão só por good measure
    resultados[1] = maior;
    resultados[2] = menor;

    printf("Media: %.2lf\n", resultados[0]);
    printf("Maior: %.2lf\n", resultados[1]);
    printf("Menor: %.2lf\n", resultados[2]);

    // free(a); // Liberar a memória alocada
}

/* Questão 3 */



/* Questão 4 */

void questao4(){

    double a[10]; // Primeiro Vetor
    double b[10]; // Segundo Vetor

    double menores[10]; // Vetor com os menores valores
    double maiores[10]; // Vetor com os maiores valores

    for (int i = 0; i < 10; i++){
        printf("Digite o %dº numero do vetor 1: \n", i+1);
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i < 10; i++){
        printf("Digite o %dº numero do vetor 2: \n", i+1);
        scanf("%lf", &b[i]);
    }

    for(int i = 0; i < 10; i++){
        if (a[i] < b[i]){
            menores[i] = a[i];
            maiores[i] = b[i];
        }
        else{
            menores[i] = b[i];
            maiores[i] = a[i];
        }
    }

    printf(" Vetor 1      Vetor 2        Menor         Maior\n");
    for (int i = 0; i < 10; i++){
        printf("  %.2lf         %.2lf          %.2lf          %.2lf\n", a[i], b[i], menores[i], maiores[i]);
    }
    // free(a);
    // free(b);
    // free(menores);
    // free(maiores);
}
/* Questão 4 */



/* Questão 5 */

/* Versão Barebones (Esperado na prova) */ 

void questao5(double n1, double n2, double n3, double n4, double n5, double n6){

    double aux = 0; // Auxiliar para o Bubble Sort

    double a[6] = {n1, n2, n3, n4, n5, n6};
    double b[4] = {0, 0, 0, 0};

    //Bubble Sort
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            if (a[i] < a[j]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
    b[0] = a[1];
    b[1] = a[2];
    b[2] = a[3];
    b[3] = a[4];
    
    double soma = 0;

    for (int i = 0; i < 4; i++){
        soma += b[i];
    }
    printf("Media: %.2lf\n", soma/4 );
}

/* Versão Lily <3 (Muitos spoilers do próximo semestre :) )*/

//Melhor algoritmo de ordenação :) (morte aos heaps)
double* quickSort(double *a, int inicio, int fim){
    if (inicio < fim){
        int p = a[fim];
        int i = inicio;
        for (int j = inicio; j < fim; j++){
            if (a[j] < p){
                double aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                i++;
            }
        }
        double aux = a[i];
        a[i] = a[fim];
        a[fim] = aux;

        quickSort(a, inicio, i-1);
        quickSort(a, i+1, fim);
    }
    return a;
}

void questao5Lily(double n1, double n2, double n3, double n4, double n5, double n6){

    double a[6] = {n1, n2, n3, n4, n5, n6};

    double *b = quickSort(a, 0, 5);
    b[0] = 0;
    b[5] = 0;

    double soma = 0;

    for (int i = 1; i < 5; i++){
        soma += b[i];
    }
    printf("Media: %.2lf\n", soma/4 );
}

/* Questão 5 */



/* Main */

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    // Se a locale bugar, só comentar a linha acima e remover os acentos

    Hud();

    /* Questão 1 */
    printf("Questão 1\n");

    printf("Fahrenheit: %.2f\n", fahrenheit(0));
    printf("Fahrenheit: %.2f\n", fahrenheit(100));

    separa();

    /* Questão 2 */
    printf("Questão 2\n");

    bin1(10);
    bin1(37);
    bin2(10);
    bin2(37);

    separa();

    /* Questão 3 */
    printf("Questão 3\n");

    questao3();

    separa();

    /* Questão 4 */
    printf("Questão 4\n");

    questao4();

    separa();

    /* Questão 5 */
    printf("Questão 5\n");

    questao5(1, 2, 3, 4, 5, 6);
    questao5Lily(1, 2, 3, 4, 5, 6);

    questao5(6, 5, 9.5, 8, 7, 6);
    questao5Lily(6, 5, 9.5, 8, 7, 6);

    return 0;
}

/* Main */

/* Acabou :) Orgulho de vcs, jovens programadores! */