#ifndef HASH_CPP
#define HASH_CPP

#include "lerArquivos.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 40
#define divs 2

typedef dataItem *hash[SIZE];
typedef unsigned long long int bigNumber;

dataItem *createDummy(){
    dataItem *dummy = (dataItem *)malloc(sizeof(dataItem *));
    
    dummy->key = -1;
}

void init(hash &H) {
    for (int i = 0; i < SIZE; i++) {
        H[i] = NULL;
    }
}

int contagem(int num){
    int cont;
    cont = 0;

    while (num != 0){
        num = num / 10;
        
        cont++;
    }
    
    return cont;
}

int inverte(int num){
    int invt;
    invt = 0;

    while (num > 0) {
        invt = 10 * invt + num % 10;
        num /= 10;
    }

    return invt;
}

int somaR(int num1, int num2){    
    return ((num1 / 10) + (num2 / 10) * 10) + (num1 % 10) + (num2 % 10);
}

int divisao(dataItem *d) {
    return d->key % SIZE;
}

int multiplicacao(dataItem *d) {
    bigNumber key = (bigNumber)d->key;

    key *= key;

    int digits = ceil(log2((bigNumber)540000 * 540000));
    int signif = ceil(log2(SIZE - 1));
    int remover = digits - signif;
    int digitMask = (int)ceil(float(remover) / 2);

    bigNumber mask = ((SIZE-1) << digitMask);

    key = key & mask;
    key = (key >> digitMask);

    return key;
}

int dobra(dataItem *d) {
    int key, totalAlgarismos, process;
    
    key = d->key;
    totalAlgarismos = contagem(key);

    while (totalAlgarismos % divs != 0){
        key *= 10;
    } 
    
    process = totalAlgarismos / divs;

    int num1, num2, aux, cont = 1;

    aux = key / pow(10, totalAlgarismos - divs);
    num1 = inverte(aux);

    while (process != 1){
        key -= (aux * pow(10, totalAlgarismos - (cont*divs)));
        
        cont++;
        process -= 1;

        num2 = key / pow(10, totalAlgarismos - (cont*divs)); 
         
        num1 = somaR(num1, num2);
        aux = num2;
    }

    return num1;    
}

int inserir(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    unsigned int key;
    
    key = funcHash(d);

    dataItem *copy = (dataItem*)malloc(sizeof(dataItem));
    *copy = *d;

    key = key > SIZE ? key % SIZE : key;

    if (H[key] == NULL) {
        H[key] = copy;
        return 0;
    }

    // Endereçamento ABERTO

            ///* TRATAMENTO SEQUENCIAL ou LINEAR

    while (H[key] != NULL){
        key++;

        if (H[key] == NULL || H[key]->key == -1) {
            H[key] = copy;
            return 0;
        }  
    }

    //*/

        /* TRATAMENTO DUPLO-HASH

        int i = 2;

        while (H[key] != NULL){
            key = (multiplicacao(d) + divisao(d)) * (i - 1);

            if (H[key] == NULL) {
                H[key] = copy;
                return 0;
            } 

            i++;
        }
        
    */

        /* TRATAMENTO QUADRÁTICO

        int i = 2, c1 = 2, c2 = 5;

        while (H[key] != NULL){
            key = key + c1*(i - 1) + c2 * pow((i - 1), 2);

            if (H[key] == NULL) {
                H[key] = copy;
                return 0;
            }

            i++;  
        }

    */

    return -1;
}

int remover(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    int key = funcHash(d);

    while (H[key] != NULL){
        if(H[key]->key == d->key){
            dataItem *purge = H[key];

            free(purge);     //windows
            // delete purge; //linux
            
            inserir(H, createDummy(), funcHash);

            return 0;
        }

        key++; 
    }

    return -1;
}

dataItem *buscar(hash H, int key, int (*funcHash)(dataItem *)){
    dataItem *res = (dataItem*)malloc(sizeof(dataItem));
    res->key = key;

    int pos = funcHash(res);

    while (H[pos] != NULL){
        if (H[pos]->key == key) {
            res = H[pos];
            return res;
        }

        pos++;  
    }
}

void inserirTodos(hash H){
    cidade *allCity = getCidades((char*)"bancoDeDadosTemp/legenda.txt");
    gps *allLocal = getGps((char*)"bancoDeDadosTemp/coordenadas.csv");

    dataItem* d = getItens(allCity, allLocal);

    int colisao = 0;

    for(int i = 0; i < MAX; i++){
        colisao += -1 * inserir(H, d+i, divisao);
    }

    // printf("Colisoes: %d", colisao);
}

#endif

/*

int main() {
    int i = 0;

    // char *cid = (char *)"TesteTemp/legenda.txt";
    // cidade *todasCidades = getCidades(cid);

    // char *loc = (char *)"TesteTemp/coordenadas.csv";
    // gps *locais = getGps(loc);

    // dataItem *d = getItens(todasCidades, locais);

    hash H;
    init(H);

    // while (i < MAX){
    //     inserir(H, dt, divisao);
    // }
    
    d->city.cidade = (char *)"Pau dos Ferros";
    d->city.id = 340940;
    d->city.estado = (char *)"RN";
    d->key = 340940;
    d->GPS.id = 340940;
    d->GPS.la = -6.11;
    d->GPS.lo = -38.2;

    int res = multiplicacao(d);

    // hash H;
    // init(H);

    inserir(H, d, divisao);

    inserir(H, d, multiplicacao);
    remover(H, d, multiplicacao);
    inserir(H, d, multiplicacao);

    dataItem* dt = buscar(H, 340940, multiplicacao);
}

*/