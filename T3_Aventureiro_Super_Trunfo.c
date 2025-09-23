#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    long int populacao; 
    float area;
    double pib;
    int pontos_turisticos;
    float densidade; // populacao / area
} Carta;

int main(){
    Carta carta1, carta2;
    int opcao;

    // Cadastro das cartas
    printf("### Cadastro da carta 1 ###\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta1.nome);
    printf("População: ");
    scanf("%ld", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos); 
    carta1.densidade = carta1.populacao / carta1.area; // Cálculo da densidade demográfica
    printf("\n");
    printf("### Cadastro da carta 2 ###\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", carta2.nome);
    printf("População: ");
    scanf("%ld", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%lf", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);
    carta2.densidade = carta2.populacao / carta2.area; // Cálculo da densidade demográfica
    printf("\n");

    // Menu interativo de escolha
    printf("### Escolha um atributo para comparar ###\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    printf("\n");

    // Comparação e exibição do resultado
    printf("\nComparando %s e %s\n", carta1.nome, carta2.nome); 

    switch(opcao){
        case 1: // População
            if(carta1.populacao > carta2.populacao) // Maior população vence
                printf("%s vence com %ld habitantes contra %ld de %s\n", carta1.nome, carta1.populacao, carta2.populacao, carta2.nome);
            else if(carta2.populacao > carta1.populacao)
                printf("%s vence com %ld habitantes contra %ld de %s\n", carta2.nome, carta2.populacao, carta1.populacao, carta1.nome);
            else
                printf("Empate! Ambos os países têm %ld habitantes.\n", carta1.populacao);
            break;
        case 2: // Área
            if(carta1.area > carta2.area) // Maior área vence
                printf("%s vence com %.2f km² contra %.2f km² de %s\n", carta1.nome, carta1.area, carta2.area, carta2.nome);
            else if(carta2.area > carta1.area)
                printf("%s vence com %.2f km² contra %.2f km² de %s\n", carta2.nome, carta2.area, carta1.area, carta1.nome);
            else
                printf("Empate! Ambos os países têm %.2f km².\n", carta1.area);
            break;
        case 3: // PIB
            if(carta1.pib > carta2.pib) // Maior PIB vence
                printf("%s vence com PIB de R$ %.2f bilhões contra R$ %.2f bilhões de %s\n", carta1.nome, carta1.pib, carta2.pib, carta2.nome);
            else if(carta2.pib > carta1.pib)
                printf("%s vence com PIB de R$ %.2f bilhões contra R$ %.2f bilhões de %s\n", carta2.nome, carta2.pib, carta1.pib, carta1.nome);
            else
                printf("Empate! Ambos os países têm PIB de R$ %.2f bilhões.\n", carta1.pib);
            break;
        case 4: // Pontos turísticos
            if(carta1.pontos_turisticos > carta2.pontos_turisticos) // Maior número de pontos turísticos vence
                printf("%s vence com %d pontos turísticos contra %d de %s\n", carta1.nome, carta1.pontos_turisticos, carta2.pontos_turisticos, carta2.nome);
            else if(carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("%s vence com %d pontos turísticos contra %d de %s\n", carta2.nome, carta2.pontos_turisticos, carta1.pontos_turisticos, carta1.nome);
            else
                printf("Empate! Ambos os países têm %d pontos turísticos.\n", carta1.pontos_turisticos);
            break;
        case 5: // Densidade demográfica
            if(carta1.densidade < carta2.densidade) // Menor densidade vence
                printf("%s vence com densidade de %.2f hab/km² contra %.2f hab/km² de %s\n", carta1.nome, carta1.densidade, carta2.densidade, carta2.nome);
            else if(carta2.densidade < carta1.densidade)
                printf("%s vence com densidade de %.2f hab/km² contra %.2f hab/km² de %s\n", carta2.nome, carta2.densidade, carta1.densidade, carta1.nome);
            else
                printf("Empate! Ambos os países têm densidade de %.2f hab/km².\n", carta1.densidade);
            break;
        default:
            printf("Opção inválida!\n");
    }
    return 0;
}