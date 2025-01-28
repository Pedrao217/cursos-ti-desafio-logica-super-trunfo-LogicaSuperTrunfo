#include <stdio.h>

typedef struct {
    char pais[30];
    int Codigo_da_carta;
    int populacao; // em milhões
    int area; // em mil km²
    int PIB; // em bilhões de dólares
    int pontos_turisticos; // número de pontos turísticos
} Carta;

int comparar_cartas(Carta c1, Carta c2) {
    int pontos_c1 = 0;
    int pontos_c2 = 0;

    if (c1.populacao > c2.populacao) pontos_c1++;
    else if (c1.populacao < c2.populacao) pontos_c2++;

    if (c1.area > c2.area) pontos_c1++;
    else if (c1.area < c2.area) pontos_c2++;

    if (c1.PIB > c2.PIB) pontos_c1++;
    else if (c1.PIB < c2.PIB) pontos_c2++;

    if (c1.pontos_turisticos > c2.pontos_turisticos) pontos_c1++;
    else if (c1.pontos_turisticos < c2.pontos_turisticos) pontos_c2++;

    if (pontos_c1 > pontos_c2) return 1;
    else if (pontos_c1 < pontos_c2) return -1;
    else return 0;
}

int main() {
    Carta cartas[20] = {
        {"Brasil", 1, 212, 8514, 2100, 50}, {"Argentina", 2, 45, 2780, 500, 30},
        {"Estados Unidos", 3, 331, 9834, 21000, 100}, {"Canadá", 4, 38, 9985, 1800, 40},
        {"México", 5, 128, 1964, 1300, 35}, {"Alemanha", 6, 83, 357, 4200, 60},
        {"França", 7, 67, 551, 3000, 70}, {"Itália", 8, 60, 301, 2000, 80},
        {"Espanha", 9, 47, 505, 1400, 75}, {"Portugal", 10, 10, 92, 300, 25},
        {"Japão", 11, 126, 377, 5000, 90}, {"China", 12, 1441, 9597, 14000, 60},
        {"Índia", 13, 1393, 3287, 2900, 40}, {"Rússia", 14, 146, 17098, 1600, 20},
        {"Austrália", 15, 25, 7692, 1400, 50}, {"Nova Zelândia", 16, 5, 268, 200, 15},
        {"África do Sul", 17, 60, 1221, 350, 20}, {"Egito", 18, 104, 1002, 300, 25},
        {"Nigéria", 19, 206, 923, 450, 10}, {"Quênia", 20, 54, 580, 100, 15}
    };

    // Exibindo as cartas
    for(int i = 0; i < 20; i++) {
        printf("Carta %d: %s, Código: %d, População: %d milhões, Área: %d mil km², PIB: %d bilhões, Pontos Turísticos: %d\n", 
               i+1, cartas[i].pais, cartas[i].Codigo_da_carta, cartas[i].populacao, cartas[i].area, cartas[i].PIB, cartas[i].pontos_turisticos);
    }

    int escolha1, escolha2;

    // Jogador 1 escolhe uma carta
    printf("Jogador 1, escolha uma carta (1-20): ");
    scanf("%d", &escolha1);
    escolha1--; // Ajustando para índice do array

    // Jogador 2 escolhe uma carta
    printf("Jogador 2, escolha uma carta (1-20): ");
    scanf("%d", &escolha2);
    escolha2--; // Ajustando para índice do array

    // Comparando as cartas escolhidas
    int resultado = comparar_cartas(cartas[escolha1], cartas[escolha2]);
    if (resultado == 1) printf("%s ganha de %s\n", cartas[escolha1].pais, cartas[escolha2].pais);
    else if (resultado == -1) printf("%s ganha de %s\n", cartas[escolha2].pais, cartas[escolha1].pais);
    else printf("Empate entre %s e %s\n", cartas[escolha1].pais, cartas[escolha2].pais);

    return 0;
}
