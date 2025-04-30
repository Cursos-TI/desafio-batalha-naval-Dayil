
/* Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    1 Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval. Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    2 Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
    Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    3 Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console. Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios. A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios.
    Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.

Requisitos funcionais


O programa deve receber as coordenadas iniciais (linha e coluna) de cada navio como entrada (pode ser definido diretamente no código).
 
O programa deve validar se as coordenadas e o tamanho dos navios são válidos dentro dos limites do tabuleiro.
 
O programa deve garantir que os navios não se sobreponham.
 
O programa deve exibir o tabuleiro no console com os navios posicionados corretamente.

Requisitos não funcionais


Performance: O programa deve executar de forma eficiente, sem causar atrasos perceptíveis.
 
Documentação: O código deve ser bem documentado, com comentários claros explicando a lógica e o propósito de cada parte do programa. Utilize comentários para explicar a função de cada variável, loop e bloco de código.
 
Legibilidade: O código deve ser escrito de forma clara, organizada e fácil de entender, com nomes de variáveis descritivos e indentação consistente.

Simplificações para o nível básico


O tamanho do tabuleiro e dos navios é fixo (10x10).
 
Os navios têm tamanho fixo igual a 3.
 
As coordenadas dos navios são definidas diretamente no código, sem input do usuário.
 
Não é necessário implementar a lógica do jogo (ataques, acertos, etc.) neste nível.
 
A validação de sobreposição de navios pode ser simplificada.
*/
#include <stdio.h>
#include <stdbool.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se um navio pode ser posicionado sem sair dos limites
bool posicaoValida(int linha, int coluna, bool horizontal) {
    if (horizontal) {
        return (coluna + TAM_NAVIO <= TAM_TABULEIRO);
    } else {
        return (linha + TAM_NAVIO <= TAM_TABULEIRO);
    }
}

// Função para verificar se há sobreposição de navios
bool sobreposicao(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        if (tabuleiro[l][c] != AGUA) {
            return true;
        }
    }
    return false;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, bool horizontal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = horizontal ? linha : linha + i;
        int c = horizontal ? coluna + i : coluna;
        tabuleiro[l][c] = NAVIO;
        printf("Parte do navio posicionada em (%d, %d)\n", l, c);
    }
}

// Função para exibir o tabuleiro no console
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
        // Menu inicial
        printf("\n=== BATALHA NAVAL ===\n");
        printf("1 - Jogar\n");
        printf("2 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

            // Inicializa o tabuleiro
            inicializarTabuleiro(tabuleiro);

            // Coordenadas dos navios (fixas para este desafio)
            int linhaNavio1 = 2, colunaNavio1 = 4; // Horizontal
            int linhaNavio2 = 5, colunaNavio2 = 1; // Vertical

            // Posiciona o primeiro navio (horizontal)
            if (posicaoValida(linhaNavio1, colunaNavio1, true) &&
                !sobreposicao(tabuleiro, linhaNavio1, colunaNavio1, true)) {
                posicionarNavio(tabuleiro, linhaNavio1, colunaNavio1, true);
            } else {
                printf("Erro ao posicionar o navio 1 (horizontal).\n");
            }

            // Posiciona o segundo navio (vertical)
            if (posicaoValida(linhaNavio2, colunaNavio2, false) &&
                !sobreposicao(tabuleiro, linhaNavio2, colunaNavio2, false)) {
                posicionarNavio(tabuleiro, linhaNavio2, colunaNavio2, false);
            } else {
                printf("Erro ao posicionar o navio 2 (vertical).\n");
            }

            // Exibe o tabuleiro final
            exibirTabuleiro(tabuleiro);
        }
        else if (opcao == 2) {
            printf("Saindo do jogo...\n");
        }
        else {
            printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 2);

    return 0;
}
