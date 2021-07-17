#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int *proximo;
}no;

typedef struct fila{
    no *top;
    no *bot;
    int tam;
}fila;

 no acrescentar (fila *monte, int valor){
    no *novo = (no*)malloc(sizeof(no));
    if (novo == NULL){
        printf ("deu ruim");
        return;
    }
    else{
        novo -> valor = valor;
        novo -> proximo = NULL;
        if (monte -> top == NULL){
            monte -> top = novo;
        } else{
            monte -> bot -> proximo = novo;
        }
        monte -> bot = novo;

    }
 }

    int desacrescentar (fila *monte){
    no *backup = monte -> top;
    int valor;
    if (backup != NULL){
        monte -> top = backup -> proximo;
        backup -> proximo = NULL;
        valor = backup -> valor;
        free (backup);
        if (monte -> top == NULL){
            monte -> bot == NULL;
        }
        return backup;
    }
    
     else {
        printf ("vazio");
        return 0;
    }


}


 void imprimir (fila *monte){
     no *ptr = monte -> top;
     if (ptr != NULL){
         while (ptr != NULL){
             printf ("%8d", ptr -> valor);
             ptr = ptr -> proximo;
         }

     }
     else{
         printf("deu ruinzao");
     }
 }



int main (){
    int valor;
    fila monte;
    monte.top = NULL;
    monte.bot = NULL;
    monte.tam = 0;
   
   
    scanf ("%d", &valor);
    

    //acrescentar(&monte, 10);
    //acrescentar(&monte, 20);
    acrescentar(&monte, 30);
    acrescentar(&monte, 40);
    acrescentar(&monte, 50);
    desacrescentar(&monte);
    acrescentar(&monte, 10);
    acrescentar(&monte, 20);

    imprimir(&monte);
    printf("\nok");



    //int selecionador;


 
    /*scanf ("%d", selecionador);
    switch (selecionador){
    case 0:
    free(monte);
    break;

    case 1:

    acrescentar(&monte, valor);

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

