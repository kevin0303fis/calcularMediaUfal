#include <stdio.h>
#include <stdlib.h>

float mediaAritmetica(int *quant, float **notas) {
    float media;
    float soma = 0;
    for (int i = 0;i < *quant;i++) {
        soma += (*notas)[i];
    }
    media = soma / *quant;
    return media;
}

int mediaSemFinal() {
    int quantProvaAB1, quantProvaAB2;
    printf("Quantas provas foram realizadas na AB1? ");
    scanf("%d", &quantProvaAB1);
    float *notasAB1 = (float *)malloc(quantProvaAB1 * sizeof(float));
    if (notasAB1 == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    for (int i = 0;i < quantProvaAB1;i++) {
        printf("Digite a nota da prova %d (AB1): ", i+1);
        scanf("%f", &notasAB1[i]);
    }
    printf("Quantas provas foram realizadas na AB2? ");
    scanf("%d", &quantProvaAB2);
    float *notasAB2 = (float *)malloc(quantProvaAB2 * sizeof(float));
    if (notasAB2 == NULL) {
        printf("Erro ao alocar memória!\n");
        free(notasAB1);
        return 1;
    }
    for (int i = 0;i < quantProvaAB2;i++) {
        printf("Digite a nota da prova %d (AB2): ", i+1+quantProvaAB1);
        scanf("%f", &notasAB2[i]);
    }

    float mediaAB1, mediaAB2;
    mediaAB1 = mediaAritmetica(&quantProvaAB1, &notasAB1);
    mediaAB2 = mediaAritmetica(&quantProvaAB2, &notasAB2);

    float media = (mediaAB1 + mediaAB2) / 2;

    printf("Média da AB1 e AB2: %f\n", media);

    free(notasAB1);
    free(notasAB2);
    return 0;
}

int main() {
    printf("O que deseja calcular?\n");
    printf("Média da AB1 e AB2 (1)\n");
    printf("\nDigite o número que corresponde a opção que você deseja: ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 1) {
        mediaSemFinal();
    }
    return 0;
}
