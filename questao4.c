#include <stdio.h>
    #include <locale.h>

    #define MAX_SIZE 100

    // Função para verificar se um elemento está presente em um conjunto
    int Elementopresente(int arr[], int tam, int elemento) {
        for (int i = 0; i < tam; i++) {
            if (arr[i] == elemento) {
                return 1; // O elemento está presente no conjunto
            }
        }
        return 0; // O elemento não está presente no conjunto
    }

    // Função para realizar a intersecção entre dois conjuntos
    void interseccao(int setA[], int tamA, int setB[], int tamB) {
        int interseccaoSet[MAX_SIZE];
        int interseccaoTam = 0;

        for (int i = 0; i < tamA; i++) {
            if (Elementopresente(setB, tamB, setA[i])) {
                interseccaoSet[interseccaoTam] = setA[i];
                interseccaoTam++;
            }
        }

        if (interseccaoTam == 0) {
            printf("Não há intersecção entre os conjuntos.\n");
        } else {
            printf("Intersecção: { ");
            for (int i = 0; i < interseccaoTam; i++) {
                printf("%d ", interseccaoSet[i]);
            }
            printf("}\n");
        }
    }

    // Função para calcular a cardinalidade de um conjunto
    int cardinalidade(int set[], int tam) {
        return tam;
    }

    // Função para realizar a união entre dois conjuntos
    void uniaoSet(int setA[], int tamA, int setB[], int tamB) {
        int uniaoSet[MAX_SIZE];
        int uniaoTam = 0;

        // Copia os elementos do conjunto A para o conjunto união
        for (int i = 0; i < tamA; i++) {
            uniaoSet[uniaoTam] = setA[i];
            uniaoTam++;
        }

        // Adiciona os elementos do conjunto B que não estão presentes no conjunto união
        for (int i = 0; i < tamB; i++) {
            if (!Elementopresente(uniaoSet, uniaoTam, setB[i])) {
                uniaoSet[uniaoTam] = setB[i];
                uniaoTam++;
            }
        }

        printf("Conjunto União: { ");
        for (int i = 0; i < uniaoTam; i++) {
            printf("%d ", uniaoSet[i]);
        }
        printf("}\n");
    }

    int main() {
        setlocale(LC_ALL, "Portuguese");
        int setA[MAX_SIZE], setB[MAX_SIZE];
        int tamA, tamB;

        printf("Digite o tamanho do conjunto A: ");
        scanf("%d", &tamA);

        printf("Digite os elementos do conjunto A separados por espaço: ");
        for (int i = 0; i < tamA; i++) {
            scanf("%d", &setA[i]);
        }

        printf("Digite o tamanho do conjunto B: ");
        scanf("%d", &tamB);

        printf("Digite os elementos do conjunto B separados por espaço: ");
        for (int i = 0; i < tamB; i++) {
            scanf("%d", &setB[i]);
        }

        // Calcula e exibe a intersecção dos conjuntos A e B
        interseccao(setA, tamA, setB, tamB);
    //
        // Calcula e exibe as cardinalidades dos conjuntos A e B
        printf("Cardinalidade de A: %d e B: %d \n", tamA, tamB);
        printf("União dos conjuntos A e B: { ");
    for (int i = 0; i < tamA; i++) {
        printf("%d ", setA[i]);
    }
    for (int i = 0; i < tamB; i++) {
        if (!Elementopresente(setA, tamA, setB[i])) {
            printf("%d ", setB[i]);
        }
    }
    printf("}\n");
}