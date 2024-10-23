 #include <stdio.h>


#define N 50  // Tamanho do vetor

// Função para reorganizar o heap (Sift)
void sift(int heap[], int i, int n) {
    int maior = i; // Inicialmente, assumimos que o nó pai é o maior
    int esquerda = 2 * i;     // Filho da esquerda
    int direita = 2 * i + 1;  // Filho da direita

    // Verifica se o filho da esquerda é maior que o pai
    if (esquerda <= n && heap[esquerda] > heap[maior])
        maior = esquerda;

    // Verifica se o filho da direita é maior que o pai
    if (direita <= n && heap[direita] > heap[maior])
        maior = direita;

    // Se o maior valor não for o pai, troca os valores
    if (maior != i) {
        int temp = heap[i];
        heap[i] = heap[maior];
        heap[maior] = temp;

        // Chama a função sift recursivamente para garantir que a subárvore continue sendo um heap
        sift(heap, maior, n);
    }
}

// Função para construir o heap (Build)
void buildHeap(int heap[], int n) {
    // Chama o sift para os nós não folhas
    for (int i = n / 2; i >= 1; i--) {
        sift(heap, i, n);
    }
}

int main() {
    int heap[N + 1];  // Vetor para armazenar os 50 elementos inteiros (índice 1 a 50)

    // Preenchendo o vetor com valores inteiros (exemplo)
    for (int i = 1; i <= N; i++) {
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &heap[i]);
    }

    // Construir o heap
    buildHeap(heap, N);

    // Exibir o heap resultante
    printf("\nHeap construído:\n");
    for (int i = 1; i <= N; i++) {
        printf("%d ", heap[i]);
    }

    return 0;
}