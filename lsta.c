#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct no{
    int valor;
    struct no *proximo;
}no;

typedef struct lista{
    no *top;
    no *bot;
    int tam;
}lista;

lista* CriaLista (){

    lista* monte = (lista*)malloc(sizeof(lista));
    if (verificalista(monte)){
        monte -> top = NULL;
        monte -> bot = NULL;
        monte -> tam = 0;
        printf("\nlista alocada\n");
        return monte;
        
       
    }
     printf ("erro de alocacao\n\n");
     return NULL;
    

}

int verificalista (lista* monte){
    
    if (monte == NULL){
        
        printf ("erro de alocação");

        return 0;
    }
        //printf ("memoria alocada com sucesso");

    return 1;

}

no* CriaNo(int valor, no* proximo){

    
    no*novo = (no*)malloc(sizeof(no));
  
    novo -> valor = valor;
    novo -> proximo = proximo;
    
    return novo;

}

void adicionartop (int valor, lista* monte){
    if (verificalista(monte)){

    no* novo = CriaNo (valor, monte -> top);
    if (monte -> tam == 0){
        monte -> top = novo;
        monte -> bot = novo;
        monte -> tam++;
        return;
    }
    
    
   
    monte -> top = novo;

    monte -> tam++;
    
    }
    
    
    return;

}

void adicionarbot (int valor, lista* monte){
    if (verificalista(monte)){
    no* novo = CriaNo (valor, NULL);
    
    if (monte -> tam == 0){
        monte -> top = novo;
        monte -> bot = novo;
        monte -> tam++;
        return;
    }
    monte -> bot -> proximo = novo;
    monte -> bot = novo;
    monte -> tam++;

    }
    return;
}

void removerbot (lista* monte){

    if (verificalista(monte)){
    
    no *aux2;
    no *aux = monte -> top -> proximo;
    
    while (aux -> proximo != NULL){
        aux2 = aux;
        aux = aux -> proximo;
    }
    
    monte -> bot = aux2;
    aux2 -> proximo  = NULL;
    
    monte -> tam--;

    free (aux);
    
    }
    return;

}

void removertop (lista* monte){

    if (verificalista(monte) && monte -> tam != 0){
    no *backup;
    backup = monte -> top;

    
    monte -> top = monte -> top -> proximo;
    monte -> tam --;
    free (backup);
    }
    else {
        printf("a lista esta vazia");
    }
    return;
    
    }

void encontrar (int num, lista *monte){
    if (verificalista(monte)){
    
   
    no *aux = monte -> top;
    
    while (aux -> proximo != NULL){

        if (aux -> valor == num){
            
            printf ("numero encontrado");
    
            return;
        }
        aux = aux -> proximo;
    }
    
    printf ("nada encontrado");
    

    //free (aux);
    }

    
    return;


}

void tamanho (lista *monte){

    printf("\ntamanho da lista: %d\n", monte -> tam);
    return;

}

void substituir (int p, int valor, lista *monte){

int n = 0;


no* aux = monte -> top;



    while (n < p){       
        aux = aux -> proximo;
       
        n++;
     }

no* novo = CriaNo (valor, aux);
aux -> valor = novo -> valor;
monte -> tam ++;
return;

}

void inserir (int p, int valor, lista *monte){

int n = 0;


no* aux = monte -> top;

if (p == 1){
    adicionartop(valor, monte);
}


if (p > 1 && p <= monte -> tam){
    p = p-2;
    while (n < p){       
        aux = aux -> proximo;
        
        n++;
     }

no* novo = CriaNo (valor, aux -> proximo);
aux -> proximo = novo;
monte -> tam ++;
}

return;

}

void exibir (lista *monte){

    no *inicio = monte -> top;
    while (inicio != NULL){
         printf("%8d", inicio -> valor);
        inicio = inicio -> proximo;

     }

}

lista* aleatoria (int max){

    

}


void menu(lista* monte) {
    int valor;
    int p;
    int selecionador;
    int continuar;
    printf ("\n o que deseja fazer?\n");
    do{
    printf (" <1> adicionar ao topo\n <2> adicionar ao final\n <3> remover inicio\n <4> remover final\n <5> encontrar um numero na lista\n <6> tamanho da lista\n <7> substituir na lista\n <8> inserir na lista\n <9> exibir a lista\n <0> sair\n");
    
    
    scanf ("%d", &selecionador);
    
    
    if (selecionador >= 0 && selecionador <= 9 ){
    switch (selecionador){
    
    case 0:
    printf ("saindo...\n");
    exit (0);

    case 1:
    

    do{
    printf ("\nque valor deseja adicionar?\n");
    scanf ("%d", &valor);
    adicionartop (valor, monte);

    printf ("\n");
    printf (" <1> adicionar outro valor\n <0> sair\n");
    scanf ("%d", &continuar);
    }while(continuar != 0);

    break;
    
    case 2:
    do{
    printf ("\nque valor deseja adicionar?\n");
    scanf ("%d", &valor);
    adicionarbot (valor, monte); 
    printf ("\n");
    printf (" <1> adicionar outro valor\n <0> sair\n");
    scanf ("%d", &continuar);
    }while(continuar != 0);

    break;
    
    case 3:
    removertop(monte);
    printf ("\n");
    break;

    case 4:
    removerbot (monte);
    printf ("\n");
    break;

    case 5:

    printf ("qual numero deseja conferir\n");
    scanf ("%d", &valor);
    encontrar (valor, monte);
    printf("\n");
    break;

    case 6:

    tamanho(monte);
    printf("\n");
    break;

    case 7:

    printf ("deseja substituir o número em qual posição?\n");
    scanf("%d", &p);
    printf ("qual o numero");
    scanf ("%d", &valor);
    substituir (p, valor, monte);
    printf ("\n");
    break;

    case 8:
    printf ("deseja inserir o numero em qual posiaoo?\n");
    scanf("%d", &p);
    printf ("qual o numero");
    scanf ("%d", &valor);
    inserir (p, valor, monte);
    printf ("\n");
    break;

    case 9:
    exibir(monte);
    printf ("\n");
    break;

    default:
        printf ("entrada invalida\n");
   }
}
else{
    
    printf ("\ninvalido\n");
    
}


}

   while (selecionador != 0);


}


int main (){
    

    lista* monte = CriaLista();
   
    menu (monte);


    printf ("\n");

    

    



    return 0;
}