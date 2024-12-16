#include <stdio.h>

typedef struct {
    char estado;
    int cidade;
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("Informe o estado (A a H): ");
    scanf(" %c", &carta->estado);
    printf("Informe a cidade (1 a 4): ");
    scanf("%d", &carta->cidade);
    printf("Informe o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("Informe a população: ");
    scanf("%d", &carta->populacao);
    printf("Informe a área (em km²): ");
    scanf("%f", &carta->area);
    printf("Informe o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    printf("Informe o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

void exibirCarta(Carta carta) {
    printf("Estado: %c\n", carta.estado);
    printf("Cidade: %d\n", carta.cidade);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

Carta compararCartas(Carta carta1, Carta carta2, int criterio) {
    Carta vencedora;

    if (criterio == 1) { // População
        vencedora = (carta1.populacao > carta2.populacao) ? carta1 : carta2;
    } else if (criterio == 2) { // Área
        vencedora = (carta1.area > carta2.area) ? carta1 : carta2;
    } else if (criterio == 3) { // PIB
        vencedora = (carta1.pib > carta2.pib) ? carta1 : carta2;
    } else if (criterio == 4) { // Pontos Turísticos
        vencedora = (carta1.pontosTuristicos > carta2.pontosTuristicos) ? carta1 : carta2;
    } else if (criterio == 5) { // Densidade populacional
        vencedora = (carta1.populacao / carta1.area < carta2.populacao / carta2.area) ? carta1 : carta2;
    }

    return vencedora;
}

int main() {
    Carta cartas[2]; // Duas cartas para comparação
    int criterio;

    // Cadastrando cartas
    for (int i = 0; i < 2; i++) {
        printf("\nCadastrando Carta %d\n", i + 1);
        cadastrarCarta(&cartas[i]);
    }

    // Escolhendo o critério de comparação
    printf("\nEscolha o critério de comparação:\n");
    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n");
    scanf("%d", &criterio);

    // Comparando cartas
    Carta vencedora = compararCartas(cartas[0], cartas[1], criterio);

    // Exibindo o vencedor
    printf("\nCarta vencedora:\n");
    exibirCarta(vencedora);

    return 0;
}
