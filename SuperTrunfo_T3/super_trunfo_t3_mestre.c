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
    int opcao1, opcao2;
    double valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    double soma1, soma2;

     const char* nomes_atributos[] = {
        "População",
        "Área",
        "PIB",
        "Pontos turísticos",
        "Densidade demográfica"
    };

    // Cadastro das cartas
    printf("### Cadastro da primeira carta ###\n");
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
    carta1.densidade = carta1.populacao / carta1.area;
    printf("\n");

    printf("### Cadastro da segunda carta ###\n");
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
    carta2.densidade = carta2.populacao / carta2.area;
    printf("\n");

    // Menu interativo de escolha
    printf("### Escolha o primeiro atributo para comparar ###\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    printf("\n### Escolha o segundo atributo para comparar ###\n");

    if (opcao1 != 1) printf("1 - Populacao\n");
    if (opcao1 != 2) printf("2 - Area\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Pontos Turisticos\n");
    if (opcao1 != 5) printf("5 - Densidade Demografica\n");
    printf("Opção: ");
    scanf("%d", &opcao2);

    switch (opcao1){
        case 1:
            valor1_c1 = carta1.populacao;
            valor1_c2 = carta2.populacao;
            break;
        case 2:
            valor1_c1 = carta1.area;
            valor1_c2 = carta2.area;
            break;
        case 3:
            valor1_c1 = carta1.pib;
            valor1_c2 = carta2.pib;
            break;
        case 4:
            valor1_c1 = carta1.pontos_turisticos;
            valor1_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor1_c1 = carta1.densidade;
            valor1_c2 = carta2.densidade;
            break;  
        default:
            printf("Opção inválida!\n");
            return 1;   
    }
    switch (opcao2){
        case 1:
            valor2_c1 = carta1.populacao;
            valor2_c2 = carta2.populacao;
            break;
        case 2:
            valor2_c1 = carta1.area;
            valor2_c2 = carta2.area;
            break;
        case 3:
            valor2_c1 = carta1.pib;
            valor2_c2 = carta2.pib;
            break;
        case 4:
            valor2_c1 = carta1.pontos_turisticos;
            valor2_c2 = carta2.pontos_turisticos;
            break;
        case 5:
            valor2_c1 = carta1.densidade;
            valor2_c2 = carta2.densidade;
            break;  
        default:
            printf("Opção inválida!\n");
            return 1;   
    }   

    //Caso a densidade seja escolhida, o valor deve ser invertido para que menor densidade seja melhor
    soma1 = (opcao1 == 5 ? valor1_c1 : valor1_c1) + (opcao2 == 5 ? valor2_c1 : valor2_c1);
    soma2 = (opcao1 == 5 ? valor1_c2 : valor1_c2) + (opcao2 == 5 ? valor2_c2 : valor2_c2); 

     // Exibir comparações
    printf("\n### Comparação entre %s e %s ###\n", carta1.nome, carta2.nome);
    printf("%s de %s e %s (respectivamente): %.2f x %.2f\n", 
        nomes_atributos[opcao1 - 1], carta1.nome, carta2.nome, valor1_c1, valor1_c2);
    printf("%s de %s e %s (respectivamente): %.2f x %.2f\n", 
        nomes_atributos[opcao2 - 1], carta1.nome, carta2.nome, valor2_c1, valor2_c2);
    printf("Soma ajustada: %.2f x %.2f\n", soma1, soma2);

    // Resultado Final
    if (soma1 > soma2)
        printf("%s venceu!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("%s venceu!\n", carta2.nome);
    else
        printf("Empate!\n");
    return 0;
}