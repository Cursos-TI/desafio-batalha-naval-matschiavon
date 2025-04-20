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
    printf("\nTABULEIRO BATALHA NAVAL\n\n");

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
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    // direcao: 0 = horizontal, 1 = vertical, 2 = diagonal, 3 = diagonal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (direcao == 0) c += i;          // horizontal
        else if (direcao == 1) l += i;     // vertical
        else if (direcao == 2) { l += i; c += i; } // diagonal 
        else if (direcao == 3) { l += i; c -= i; } // diagonal 

        // Verificação de limites
        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica sobreposição
        if (tabuleiro[l][c] == VALOR_NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (direcao == 0) c += i;                  // horizontal
        else if (direcao == 1) l += i;             // vertical
        else if (direcao == 2) { l += i; c += i; } // diagonal 
        else if (direcao == 3) { l += i; c -= i; } // diagonal 

        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas e direções dos 4 navios
    // Dois navios tradicionais (horizontal e vertical)
    int linha1 = 2, coluna1 = 3; // navio horizontal
    int linha2 = 5, coluna2 = 6; // navio vertical

    // Dois navios diagonais
    int linha3 = 7, coluna3 = 0; // diagonal 
    int linha4 = 0, coluna4 = 9; // diagonal 

    if (podePosicionar(tabuleiro, linha1, coluna1, 0)) {
        posicionarNavio(tabuleiro, linha1, coluna1, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    if (podePosicionar(tabuleiro, linha2, coluna2, 1)) {
        posicionarNavio(tabuleiro, linha2, coluna2, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    if (podePosicionar(tabuleiro, linha3, coluna3, 2)) {
        posicionarNavio(tabuleiro, linha3, coluna3, 2);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal.\n");
    }

    if (podePosicionar(tabuleiro, linha4, coluna4, 3)) {
        posicionarNavio(tabuleiro, linha4, coluna4, 3);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}