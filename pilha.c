#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int *proximo;
}no;

typedef struct pilha{
    no *top;
    int tam;
}pilha;

 no empilhar (pilha *monte, int valor){
    no *novo = (no*)malloc(sizeof(no));

    novo -> valor = valor;
    novo -> proximo = monte -> top;
    monte -> top = novo;
    monte -> tam++;
 }

no desempilhar (pilha *monte){
    no *backup = (no*)malloc(sizeof(no));

    backup -> valor = monte -> top;
    monte -> top = monte -> top -> proximo;
    monte -> tam --;
    free (backup);
}


 void imprimir (pilha *monte){
     no *top = monte -> top;
        while( top != NULL){
        printf("%8d", top -> valor);
        top = top -> proximo;
        }
 }



int main (){
    int valor;
    pilha monte;
    monte.top = NULL;
    monte.tam = 0;
   
    scanf ("%d", &valor);
    

    empilhar(&monte, 10);
    empilhar(&monte, 20);
    empilhar(&monte, 30);
    empilhar(&monte, 40);
    empilhar(&monte, 50);
    desempilhar(&monte);
    empilhar(&monte, 10);
    empilhar(&monte, 20);

    imprimir(&monte);
    printf("ok");



    int selecionador;


 
    /*scanf ("%d", selecionador);
    switch (selecionador){
    case 0:
    free(monte);
    break;

    case 1:

    empilhar(&monte, valor);

    case 2:
    imprimir(&monte);
    printf("ok");
    break;

    
    default:
    printf ("comando invalido");


    
    }
 //} while (monte.top != NULL);*/
    return 0;
}

