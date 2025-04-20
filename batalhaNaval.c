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
    printf("    ");  // Espaço para alinhar com números das linhas
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c  ", letra);
    }
    printf("\n");

    // Corpo do tabuleiro com números nas linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i + 1);  // Números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// Função para verificar se é possível posicionar o navio
int podePosicionar(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;

        // Verifica se está dentro do limite do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica se já tem um navio na posição
        if (tabuleiro[l][c] == VALOR_NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Função para verificar se é possível posicionar o navio na diagonal crescente (tabuleiro[i][i])
int podePosicionarDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = coluna + i;

        // Verifica se está dentro do limite do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c >= TAMANHO_TABULEIRO) {
            return 0;
        }

        // Verifica se já tem um navio na posição
        if (tabuleiro[l][c] == VALOR_NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Função para verificar se é possível posicionar o navio na diagonal decrescente (tabuleiro[i][9-i])
int podePosicionarDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = coluna - i;

        // Verifica se está dentro do limite do tabuleiro
        if (l >= TAMANHO_TABULEIRO || c < 0) {
            return 0;
        }

        // Verifica se já tem um navio na posição
        if (tabuleiro[l][c] == VALOR_NAVIO) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio horizontal ou vertical
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int vertical) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = vertical ? linha + i : linha;
        int c = vertical ? coluna : coluna + i;
        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

// Função para posicionar o navio na diagonal crescente
void posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = coluna + i;
        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

// Função para posicionar o navio na diagonal decrescente
void posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha + i;
        int c = coluna - i;
        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (fixas no código)
    int linhaH1 = 2, colunaH1 = 4; // Navio horizontal 1
    int linhaV1 = 5, colunaV1 = 6; // Navio vertical 1
    int linhaD1 = 1, colunaD1 = 1; // Navio diagonal crescente
    int linhaD2 = 7, colunaD2 = 9; // Navio diagonal decrescente

    // Verifica e posiciona o navio horizontal
    if (podePosicionar(tabuleiro, linhaH1, colunaH1, 0)) {
        posicionarNavio(tabuleiro, linhaH1, colunaH1, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal 1.\n");
    }

    // Verifica e posiciona o navio vertical
    if (podePosicionar(tabuleiro, linhaV1, colunaV1, 1)) {
        posicionarNavio(tabuleiro, linhaV1, colunaV1, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical 1.\n");
    }

    // Verifica e posiciona o navio diagonal crescente
    if (podePosicionarDiagonalCrescente(tabuleiro, linhaD1, colunaD1)) {
        posicionarNavioDiagonalCrescente(tabuleiro, linhaD1, colunaD1);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal crescente.\n");
    }

    // Verifica e posiciona o navio diagonal decrescente
    if (podePosicionarDiagonalDecrescente(tabuleiro, linhaD2, colunaD2)) {
        posicionarNavioDiagonalDecrescente(tabuleiro, linhaD2, colunaD2);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal decrescente.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}