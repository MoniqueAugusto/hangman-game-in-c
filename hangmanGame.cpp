#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Categorias
    char categorias[5][20] = {
        "Animal",
        "Fruta",
        "Eletronico",
        "Vestuario",
        "Objeto"
    };

    // Palavras
    char palavras[5][10][20] = {

        // Animais
        {
            "cachorro", "gato", "elefante", "tigre", "leao",
            "girafa", "macaco", "coelho", "zebra", "cavalo"
        },

        // Frutas
        {
            "banana", "maca", "uva", "morango", "abacaxi",
            "pera", "laranja", "melancia", "kiwi", "manga"
        },

        // Eletronicos
        {
            "teclado", "monitor", "celular", "notebook", "mouse",
            "tablet", "fone", "televisao", "camera", "impressora"
        },

        // Vestuario
        {
            "camiseta", "calca", "jaqueta", "vestido", "bermuda",
            "sapato", "tenis", "meia", "gravata", "casaco"
        },

        // Objetos
        {
            "cadeira", "mesa", "garrafa", "janela", "espelho",
            "mochila", "caneta", "livro", "relogio", "travesseiro"
        }
    };

    char palavra[20];
    char exibicao[20];

    // Entrada do usuario
    char entrada[10];
    char letra;

    // Guarda letras digitadas
    char letrasUsadas[26];

    int quantidadeLetras = 0;

    int categoriaSorteada;
    int palavraSorteada;

    int tamanho;
    int acertos = 0;
    int erros = 0;

    int i;

    srand(time(NULL));

    // Sorteia categoria
    categoriaSorteada = rand() % 5;

    // Sorteia palavra
    palavraSorteada = rand() % 10;

    // Copia palavra sorteada
    strcpy(palavra, palavras[categoriaSorteada][palavraSorteada]);

    tamanho = strlen(palavra);

    // Preenche com _
    for(i = 0; i < tamanho; i++) {
        exibicao[i] = '_';
    }

    exibicao[tamanho] = '\0';

    printf("===== JOGO DA FORCA =====\n\n");

    printf("REGRAS:\n");
    printf("- Digite uma letra minuscula por vez.\n");
    printf("- Voce pode errar ate 6 vezes.\n");
    printf("- Descubra a palavra antes dos erros acabarem.\n");
    printf("- A dica mostra a categoria da palavra.\n\n");

    while(acertos < tamanho && erros < 6) {

        // DESENHO DA FORCA

        if(erros == 0) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
        }

        if(erros == 1) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
        }

        if(erros == 2) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf(" |   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
        }

        if(erros == 3) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|   |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
        }

        if(erros == 4) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|\\  |\n");
            printf("     |\n");
            printf("     |\n");
            printf("=========\n");
        }

        if(erros == 5) {
            printf("\n +---+\n");
            printf(" |   |\n");
            printf(" O   |\n");
            printf("/|\\  |\n");
            printf("/    |\n");
            printf("     |\n");
            printf("=========\n");
        }

        printf("\nDica: %s\n", categorias[categoriaSorteada]);

        printf("Palavra: ");

        for(i = 0; i < tamanho; i++) {
            printf("%c ", exibicao[i]);
        }

        printf("\n");

        // Mostra letras usadas
        printf("Letras usadas: ");

        for(i = 0; i < quantidadeLetras; i++) {
            printf("%c ", letrasUsadas[i]);
        }

        printf("\n");

        printf("Erros: %d/6\n", erros);

        printf("Digite uma letra minuscula: ");
        scanf("%s", entrada);

        // Verifica se digitou mais de uma letra
        if(strlen(entrada) > 1) {
            printf("\nDigite apenas UMA letra!\n");
            continue;
        }

        letra = entrada[0];

        // Verifica letra maiuscula
        if(letra >= 'A' && letra <= 'Z') {
            printf("\nDigite apenas letras minusculas!\n");
            continue;
        }

        // Verifica numeros e simbolos
        if(letra < 'a' || letra > 'z') {
            printf("\nDigite apenas letras do alfabeto!\n");
            continue;
        }

        // Verifica letra repetida
        int repetida = 0;

        for(i = 0; i < quantidadeLetras; i++) {

            if(letrasUsadas[i] == letra) {
                repetida = 1;
            }
        }

        if(repetida == 1) {
            printf("\nEssa letra ja foi digitada!\n");
            continue;
        }

        // Guarda letra digitada
        letrasUsadas[quantidadeLetras] = letra;
        quantidadeLetras++;

        int encontrou = 0;

        for(i = 0; i < tamanho; i++) {

            if(palavra[i] == letra && exibicao[i] == '_') {
                exibicao[i] = letra;
                acertos++;
                encontrou = 1;
            }
        }

        if(encontrou == 1) {
            printf("Voce acertou!\n");
        } else {
            printf("Letra errada!\n");
            erros++;
        }
    }

    // Resultado final
    if(acertos == tamanho) {

        printf("\n");

        printf("       *  *  *  *\n");
        printf("    *              *\n");
        printf("  *    PARABENS!    *\n");
        printf("    *              *\n");
        printf("       *  *  *  *\n");

        printf("\n +---+\n");
        printf(" |   |\n");
        printf("     |\n");
        printf(" \\o/ |\n");
        printf("  |  |\n");
        printf(" / \\ |\n");
        printf("=========\n");

        printf("\nVOCE GANHOU!\n");
    }

    else {

        printf("\n +---+\n");
        printf(" |   |\n");
        printf(" x   |\n");
        printf("/|\\  |\n");
        printf("/ \\  |\n");
        printf("     |\n");
        printf("=========\n");

        printf("\nVOCE PERDEU!\n");
    }

    printf("A palavra era: %s\n", palavra);

    printf("\nDesenvolvido por:\n");
    printf("Monique Augusto, Rayssa dos Santos e Wilson Bittencourt\n");

    return 0;
}
