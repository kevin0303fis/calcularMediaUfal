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

float calcularMedia(int aB) {
    int quant;
    printf("Quantas provas foram realizadas na AB%d? ", aB);
    scanf("%d", &quant);
    float *notas = (float *)malloc(quant * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memória!\n");
        return -1;
    }
    for (int i = 0;i < quant;i++) {
        printf("Digite a nota da prova %d (AB%d): ", i+1, aB);
        scanf("%f", &notas[i]);
    }
    float media;
    media = mediaAritmetica(&quant, &notas);
    free(notas);
    return media;
}

void simNao() {
    printf("Sim - Digite 1\nNão - Digite 0\nSua opção: ");
}

int main() {
    float mediaAB1, mediaAB2;
    float notaReav = 0, notaFinal = 0;
    float mediaTemp;
    printf("Salve!\n");
    printf("Todas as provas da AB1 foram concluídas?\n");
    simNao();
    int opcao = 1;
    scanf("%d", &opcao);
    if (opcao == 0) {
        printf("Entendido, tenha um ótimo dia.\n");
        return 0;
    }
    printf("Todas as provas da AB2 foram concluídas?\n");
    simNao();
    scanf("%d", &opcao);
    mediaAB1 = calcularMedia(1);
    printf("Sua média da AB1: %f\n", mediaAB1);
    if (opcao == 0) {
        return 0;
    }
    mediaAB2 = calcularMedia(2);
    printf("Sua média da AB2: %f\n", mediaAB2);

    mediaTemp = (mediaAB1 + mediaAB2) / 2;

    printf("Sua média da AB1 e AB2: %f\n", mediaTemp);

    if (mediaTemp >= 7) {
        printf("Parabéns! Você passou direto por média.\n");
        if (mediaAB1 < 7) {
            printf("Porém, você ainda poderia tentar fazer reav na AB1.\n");
        } else if (mediaAB2 < 7) {
            printf("Porém, você ainda poderia tentar fazer reav na AB2.\n");
        }
    }
    printf("Você fez a reavaliação?\n");
    simNao();
    scanf("%d", &opcao);
    if (opcao == 0) {
        if (mediaTemp < 5) {
            printf("Uma pena. Como sua média da AB1 e AB2 foi menor que 5, você não pode fazer a prova final.\n");
            return 0;
        } else if (mediaTemp >7) {
            printf("Suave.\n");
            return 0;
        }
    } else {
        if (mediaAB1 == mediaAB2) {
            int qual;
            printf("Você fez reav pra a AB1 ou AB2?\nAB1 - Digite 1\nAB2 - Digite 2\nSua opção: ");
            scanf("%d", &qual);
            printf("Qual foi a nota que você tirou na reav? ");
            scanf("%f", &notaReav);
            if (qual == 1 && notaReav >= mediaAB1) {
                mediaAB1 = 0;
                mediaTemp = (mediaAB2 + notaReav) / 2;
            } else if (qual == 2 && notaReav >= mediaAB2) {
                mediaAB2 = 0;
                mediaTemp = (mediaAB1 + notaReav) / 2;
            }
        } else {
            printf("Qual foi a nota que você tirou na reav? ");
            scanf("%f", &notaReav);
            if (mediaAB1 > mediaAB2 && notaReav >= mediaAB2) {
                mediaAB2 = 0;
                mediaTemp = (mediaAB1 + notaReav) / 2;
            } else if (mediaAB2 > mediaAB1 && notaReav >= mediaAB1) {
                mediaAB1 = 0;
                mediaTemp = (mediaAB2 + notaReav) / 2;
            }
        }
        printf("Sua média após a reav: %f\n", mediaTemp);
        if (mediaTemp<5) {
            printf("Infelizmente, mesmo após a reavaliação, sua nota não alcançou a nota mínima para fazer a final.\n");
            return 0;
        } else if (mediaTemp < 7) {
            printf("Você não passou direto, mas tem a chance de fazer a prova final.\n");
        } else {
            printf("Você passou direto! Parabéns! Não precisa fazer a final.\n");
            return 0;
        }
    }
    printf("Você fez a prova final?\n");
    simNao();
    scanf("%d", &opcao);
    if (opcao == 0) {
        printf("Situação complicada. Se puder, faça.\n");
        return 0;
    }
    printf("Qual foi a nota que você tirou na final?\n");
    scanf("%f", &notaFinal);
    mediaTemp = (6*mediaAB1 + 6*mediaAB2 + 4*notaFinal) / 16;
    printf("Sua média após a final: %f", mediaTemp);
    if (mediaTemp > 5) {
        printf("Parabéns! Foi por pouco, mas você passou!\n");
    } else {
        printf("Tenso. Você não passou, mas quem sabe na próxima.\n");
    }
    return 0;
}
