/*Descrição geral: Implementação de um conjunto de operações para criar, manipular e consultar vetores de 
números de ponto flutuante, fornecendo uma interface abstrata para trabalhar com esses dados.

Autores:
Antonio Wellington Damasceno Melo
Stephany Rodrigues Gonçalves
Maria Beatriz Rodrigues Martins */

#include "vetores.h"
#include <stdlib.h>
#include <stdio.h>

// Definição da estrutura Vetor
struct vetor {
    int tamanho; //Tamanho do vetor
    float *elementos; //Array com os elementos do vetor
};

//Cria um vetor de tamanho n
Vetor* criaVetor(int n) {
    if (n <= 0) {
        return NULL;
    }

    Vetor* vtr = (Vetor*)malloc(sizeof(Vetor)); // Aloca memória para a estrutura Vetor
    if (vtr == NULL) {
        printf("Falha na alocação de memória!\n"); // Imprime uma mensagem de erro se a alocação falhar
        exit(0); // Sai do programa com código de erro
    }

    vtr->tamanho = n;
    vtr->elementos = (float*)malloc(n * sizeof(float));
    if (vtr->elementos == NULL) {
        printf("Falha na alocação de memória!\n"); 
        free(vtr); // Libera a memória alocada para vtr antes de sair
        exit(0); // Sai do programa com código de erro
    }

    return vtr; // Retorna o vetor criado
}

//Libera a memoria alocada para um vetor
void liberaVetor(Vetor* v) {
            free(v->elementos); // Libera a memória alocada para o array de elementos
            free(v);
}

//Retorna o tamanho de um vetor
int tamanhoVetor(Vetor* v) {
    return v->tamanho;
}
// Verifica a validade de um índice
int verifica(Vetor* v, int i){
    return (i>=0 && i< tamanhoVetor(v)); // Retorna 1 se o índice estiver dentro dos limites do vetor, caso contrário, retorna 0
}

//Acessa o conteudo de uma determinada posiçao i do vetor
float acessa(Vetor* v, int i) {
    if (verifica(v,i)){
        return v->elementos[i]; // Retorna o elemento na posição i se o índice for válido
}   
    else{
        printf("Índice fora da faixa do vetor!\n"); // Imprime uma mensagem de erro se o índice estiver fora dos limites
        return 0.0; // Retorna 0.0 em vez de um valor inválido
    }
}

//Atribui um conteúdo c a uma determinada posição i do vetor
void atribui(Vetor* v, int i, float c){
    if (i >= 0 && i < v->tamanho){   //Verifica se o índice é maior ou igual a zero e se ele existe no vetor
        v->elementos[i] = c;  //Atribui o valor a posição i
    } else {
        printf("Posicao invalida!\n");
        return;
    }

}

//Função que retorna o maior elemento do vetor
float maior(Vetor* v){
    if (v->tamanho == 0) {
        printf("O vetor esta vazio!\n");
        return 0.0; // Retorna 0.0 se o vetor estiver vazio
    }
    float maior = 0.0;
    for (int i = 0; i < v->tamanho; i++){
        if(v->elementos[i] > maior){
            maior = v->elementos[i];
        }
    }
    return maior;
}

//Função que retorna o menor elementos do vetor.
float menor(Vetor* v){
    if (v->tamanho == 0) {
        printf("O vetor esta vazio!\n");
        return 0.0; // Retorna 0.0 se o vetor estiver vazio
    }
    float menor = 0.0;
    for (int i = 0; i < v->tamanho; i++){
        if(v->elementos[i] < menor){
            menor = v->elementos[i];
        }
    }
    return menor;
}

//Função que lista todos os elementos do vetor. A listagem deve se apresentar
//de forma organizada como uma lista na mesma linha.
void listarVetor(Vetor* v){
    if (v->tamanho == 0) {
        printf("O vetor esta vazio.\n");
    } else {
        for (int i = 0; i < v->tamanho; i++) {
            if (i == v->tamanho - 1) {
                // Último elemento
                printf("%.2f\n", v->elementos[i]);
            } else {
                // Imprime o elemento atual 
                printf("%.2f -", v->elementos[i]);
            }
        }
    }
}

float somaVetor(Vetor* v){
    float soma=0;
    for(int i=0;i<v->tamanho;i++){ //Percorre o vetor usando a variavel tamanho
        soma+=v->elementos[i]; //Soma do elemento i=0 ate i=tamanho-1 e atribui a variavel soma
    }
    return soma; 
}

float somaElementos(Vetor* v, int n){
    float soma=0;
    if(n>v->tamanho||n==0){ //Verifica se os n primeiros numeros informados é maior que o tamanho do vetor
        exit(0);
    }else{
        for(int i=0;i<n;i++){ //Percorre o vetor ate o valor de n
            soma+=v->elementos[i]; //Soma do elemento i=0 ate i=n-1
        }
        return soma;
    }
}

Vetor* somaVetores(Vetor* v1, Vetor* v2){
    if(v1->tamanho!=v2->tamanho){ //Verifica se os vetores de entrada possuem tamanhos diferentes
        return NULL;
    }
    Vetor* v3=(Vetor*)malloc(sizeof(Vetor)); //Aloca memoria para o vetor de saída
    if(v3==NULL){ //Verifica se a alocação falhou
        free(v3);
        return NULL;
    }
    v3->tamanho=v1->tamanho; //Define o tamanho do vetor de saída
    v3->elementos=(float*)malloc(v3->tamanho*sizeof(float)); //Aloca memória para os elementos do vetor de saída
    for(int i=0;i<v3->tamanho;i++){ //Laço para gerar um vetor de saída com a soma dos elementos de entrada
        v3->elementos[i]=v1->elementos[i]+v2->elementos[i]; //Atribuindo o elemento na posicão i de v3, como sendo a soma dos elementos de v1 e v2 na posição i
    }
    return v3;
}

void mostrarSomaVetores(Vetor* v1, Vetor* v2){
    if(v1->tamanho!=v2->tamanho){ //Verifica se os vetores de entrada possuem tamanhos diferentes
        printf("Vetores possuem tamanhos diferentes!"); 
        return; 
    }
    Vetor* v3=(Vetor*)malloc(sizeof(Vetor)); //Aloca memoria para o vetor v3
    if(v3==NULL){ //Verifica se a alocação teve sucesso
        printf("Erro ao alocar memória!");
        free(v3);
        return;
    }
    v3->tamanho=v1->tamanho; //Define o tamanho do vetor v3
    v3->elementos=(float*)malloc(v3->tamanho*sizeof(float)); //Aloca memória para os elementos do vetor v3
    for(int i=0;i<v3->tamanho;i++){ //Laço para gerar o vetor v3 com a soma dos elementos de entrada
        v3->elementos[i]=v1->elementos[i]+v2->elementos[i]; //Atribuindo o elemento na posicão i de v3, como sendo a soma dos elementos de v1 e v2 na posição i
        printf("%f + %f = %f\n",v1->elementos[i],v2->elementos[i],v3->elementos[i]); //Mostra no terminal a saída no formato v1 + v2 = v3
    }
    free(v3);
}
