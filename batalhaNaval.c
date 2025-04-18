#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Exibe o tabuleiro com letras nas colunas e números nas linhas
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n     TABULEIRO BATALHA NAVAL\n\n");

    // Cabeçalho com letras A até J
    printf("   ");  // Espaço para alinhar com números das linhas
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c ", letra);
    }
    printf("\n");

    // Corpo do tabuleiro com números nas linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i + 1);  // Números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Verifica se o navio pode ser posicionado
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;

        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        if (tabuleiro[l][c] == VALOR_NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Posiciona o navio
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;
        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios
    int linha3 = 2, colunaD = 3; // Coluna 3 equivale à letra D
    int linha5 = 5, colunaG = 6; // Coluna 6 equivale à letra G

    if (podePosicionar(tabuleiro, linha3, colunaD, 0)) {
        posicionarNavio(tabuleiro, linha3, colunaD, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionar(tabuleiro, linha5, colunaG, 1)) {
        posicionarNavio(tabuleiro, linha5, colunaG, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}