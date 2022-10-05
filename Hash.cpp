#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

typedef dataItem *hash[SIZE];

void init(hash &H) {
    for (int i = 0; i < SIZE; i++) {
        H[i] = 0;
    }
}
int inserir(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    int key = funcHash(d);
    if (H[key] == 0) {
        H[key] = d;
        return 0;
    }
    return -1;
}


int divisao(dataItem *d) {
    return d->key % SIZE;
}

typedef unsigned long long int bigNumber;

int multiplicacao(dataItem *d) {
    bigNumber key = (bigNumber)d->key;
    key *= key;
    int digits = ceil(log10((bigNumber)540000 * 540000) / log10(2));
    int signif = ceil(log10(SIZE - 1) / log10(2));
    int remover = digits - signif;
    int digitMask = (int)ceil(float(remover) / 2);
    bigNumber mask = (1023 << digitMask);
    key = key & mask;
    key = (key >> digitMask);
    return key;
}

int hashCodeDobra(dataItem *d) {
    return d->key % SIZE;
}

int main() {
    dataItem *d = (dataItem *)malloc(sizeof(dataItem));

    d->city.cidade = (char *)"Pau dos Ferros";
    d->city.id = 340940;
    d->city.estado = (char *)"RN";
    d->key = 340940;
    d->GPS.id = 340940;
    d->GPS.la = -6.11;
    d->GPS.lo = -38.2;

    int res = multiplicacao(d);
    hash H;
    init(H);

    inserir(H, d, divisao);
    
    //Não faz sentido mudar a função Hash, mas coloquei aqui para mostrar que é possível
    
    inserir(H, d, multiplicacao);
}