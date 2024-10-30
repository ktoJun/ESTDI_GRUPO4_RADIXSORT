#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior número no array
int encontrarMaior(int array[], int n) {
    int maior = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para fazer a ordenação por contagem para cada dígito
void countingSort(int array[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Armazena a contagem de ocorrências
    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Altera count[i] para que contenha a posição atual do dígito
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

// Função principal do Radix Sort
void radixSort(int array[], int n) {
    // Encontra o maior número para saber o número de dígitos
    int maior = encontrarMaior(array, n);

    // Faz o counting sort para cada dígito
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingSort(array, n, exp);
    }
}

// Função para imprimir o array
void imprimirArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
}

// Função main para teste
int main() {
    //O C já converte o caracter para o código equivalente na tabela ASCII
    int array[] = {'b', 'a', 'c'};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array original: ");
    imprimirArray(array, n);

    radixSort(array, n);

    printf("Array ordenado: ");
    imprimirArray(array, n);

    return 0;
}