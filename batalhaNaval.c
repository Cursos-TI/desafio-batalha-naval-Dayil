
/* Desafio Batalha Naval - MateCheck

Desafio: nível Novato>Aventureiro
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
     // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
     // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
     // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

Tabuleiro Completo e Navios Diagonais

*/
#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Inicializa o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Valida posição para navio horizontal ou vertical
bool posicaoValida(int linha, int coluna, bool horizontal) {
    return horizontal ? (coluna + TAM_NAVIO <= TAM_TABULEIRO) : (linha + TAM_NAVIO <= TAM_TABULEIRO);
}

// Verifica sobreposição para navios horizontais ou verticais
bool sobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        if (tabuleiro[l][c] != AGUA) return true;
    }
    return false;
}

// Posiciona navio horizontal ou vertical
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        tabuleiro[l][c] = NAVIO;
    }
}

// Valida e posiciona navios na diagonal principal ou secundária
bool posicionarDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool principal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i;
        int c = principal ? coluna + i : coluna - i;
        if (l >= TAM_TABULEIRO || c < 0 || c >= TAM_TABULEIRO || tabuleiro[l][c] != AGUA)
            return false; // Fora dos limites ou sobreposição
    }
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i;
        int c = principal ? coluna + i : coluna - i;
        tabuleiro[l][c] = NAVIO;
    }
    return true;
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== BATALHA NAVAL ===\n");
        printf("1 - Jogar\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
            inicializarTabuleiro(tabuleiro);

            // Navios horizontais e verticais
            if (posicaoValida(1, 2, true) && !sobreposicao(tabuleiro, 1, 2, true))
                posicionarNavio(tabuleiro, 1, 2, true);
            else
                printf("Erro ao posicionar navio horizontal.\n");

            if (posicaoValida(4, 5, false) && !sobreposicao(tabuleiro, 4, 5, false))
                posicionarNavio(tabuleiro, 4, 5, false);
            else
                printf("Erro ao posicionar navio vertical.\n");

            // Navios diagonais
            if (!posicionarDiagonal(tabuleiro, 0, 0, true))
                printf("Erro ao posicionar navio diagonal principal.\n");

            if (!posicionarDiagonal(tabuleiro, 0, 9, false))
                printf("Erro ao posicionar navio diagonal secundária.\n");

            exibirTabuleiro(tabuleiro);
        } else if (opcao == 2) {
            printf("Saindo do jogo...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 2);

    return 0;
}