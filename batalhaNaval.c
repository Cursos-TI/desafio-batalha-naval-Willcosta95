#include <stdio.h>

int main() {
    // Tamanho do tabuleiro
    int tabuleiro[10][10];
    int i, j;

    // Inicializando o tabuleiro com água (que é representada pelo 0 )
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }

    // Tamanho dos navios (que é representado pelo número 3)
    int tamanhoNavio = 3;
    
    //Temos dois navios, um horizontal e outro vertical

    // Inserindo os navios no mapa (Aqui colocamos os valores)
    
    int linhaNavioH = 0;   // linha onde começa o navio horizontal (0-9)
    int colunaNavioH = 0;  // coluna inicial do navio horizontal (0-9)
    
    int linhaNavioV = 7;   // linha inicial do navio vertical (0-9)
    int colunaNavioV = 9;  // coluna onde fica o navio vertical (0-9)

   
    // Validar se os navios estão dentro dos limites do tabuleiro
    int navioH_valido = (colunaNavioH + tamanhoNavio <= 10);
    int navioV_valido = (linhaNavioV + tamanhoNavio <= 10);

    // Validar a sobreposição (Para  que um navio não fique em cima do outro)
    int sobreposicao = 0; // 0 = não sobrepõe, 1 = sobrepõe
    for (i = 0; i < tamanhoNavio; i++) {
        for (j = 0; j < tamanhoNavio; j++) {
            // Verifica se a posição do navio vertical está na mesma linha do horizontal
            if (linhaNavioH == linhaNavioV + j && colunaNavioH + i == colunaNavioV) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao) {
            break;
        }
    }

    // Se todas as validações passarem, posiciona e exibe
    if (navioH_valido && navioV_valido && !sobreposicao) {
        // Posicionando o navio horizontal
        for (j = 0; j < tamanhoNavio; j++) {
            tabuleiro[linhaNavioH][colunaNavioH + j] = 3;
        }

        // Posicionando o navio vertical
        for (i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaNavioV + i][colunaNavioV] = 3;
        }
        
        // Exibindo o tabuleiro
        printf("\nTabuleiro de Batalha Naval (0 representa água e 3 representa os navios):\n\n");
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        // Exibindo a mensagem de erro específica
        printf("Erro: Nao foi possivel posicionar os navios.\n");
        if (!navioH_valido) {
            printf("- O navio horizontal ficou fora do tabuleiro.\n");
        }
        if (!navioV_valido) {
            printf("- O navio vertical ficou fora do tabuleiro.\n");
        }
        if (sobreposicao) {
            printf("- Os navios se sobrepoem.\n");
        }
        printf("Por favor, tente novamente com outras coordenadas.\n");
    }

    return 0;
}
