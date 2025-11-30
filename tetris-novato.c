#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMO 5

typedef struct{
    char tipo[30];
    int id;
}Peca;

typedef struct{
    Peca pecas[MAXIMO];
    unsigned int inicio;
    unsigned int final;
    unsigned int total;
}Fila;

const char *Formatos[] = {
    "I",
    "O",
    "T",
    "L"
};

char pecaremovida[30] = {"Z"};

void mostrarFila(Fila *f){
    printf("Como a fila está no momento:\n");
    int pos = 0;

    for(int i = 0; i < f->total; i++){
        pos = (f->inicio + i) % MAXIMO;
        printf("Tipo: %s\nID: %d\n", f->pecas[pos].tipo, f->pecas[pos].id);
        printf("--------\n");
    }

    printf("Total: %d\n\n", f->total);
}

int filaCheia(Fila *f){
    return f->total == MAXIMO;
}

int filaVazia(Fila *f){
    return f->total == 0;
}

void initFila(Fila *f){
    f->inicio = 0;
    f->final = 0;
    f->total = 0;

    for(int i = 0; i < MAXIMO; i++){
        int randformato = rand() % 4;
        strcpy(f->pecas[f->final].tipo, Formatos[randformato]);
        f->pecas[f->final].id = i;
        f->final = (f->final + 1) % MAXIMO;
        f->total++;
    }
}

void enqueue(Fila *f){

    if(filaCheia(f)){
        printf("Fila cheia!\n");
        return; 
    }

    strcpy(f->pecas[f->final].tipo, Formatos[rand() % 4]);
    f->pecas[f->final].id = rand() % 10;

    f->final = (f->final + 1) % MAXIMO;
    f->total++;
}

Peca dequeue(Fila *f){
    Peca Vazia = {
        "",
        -1
    };

    if(filaVazia(f)){
        printf("Não tem peça na fila");
        return Vazia;
    }

    strcpy(pecaremovida, f->pecas[f->inicio].tipo);
    Peca Removida = f->pecas[f->inicio];
    f->inicio = (f->inicio + 1) % MAXIMO;
    f->total--;

    return Removida;
}

int main() {
    int opcao = 999;
    Fila fila;
    initFila(&fila);

    do{
        mostrarFila(&fila);
        printf("Bem vindo ao backend de Tetris Stack! Programado por JSF2006.\n");
        printf("1: Jogar peça (remover da frente)\n0: Sair.\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                dequeue(&fila);
                printf("Peça %s lançada.\n", pecaremovida);
                enqueue(&fila);
                break;

            case 0:
                opcao = -1;
                break;
        }
    }while(opcao != -1);


    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

