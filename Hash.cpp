#ifndef HASH_CPP
#define HASH_CPP

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
    dataItem *copy = (dataItem*)malloc(sizeof(dataItem));
    *copy = *d;
    if (H[key] == 0) {
        H[key] = copy;
        return 0;
    }
    return -1;
}

int remover(hash H, dataItem *d, int (*funcHash)(dataItem *)) {
    int key = funcHash(d);
    if (H[key] != 0) {
        dataItem *purge = H[key];
        delete purge; //linux
        // free(purge); //windows
        H[key] = 0;
        return 0;
    }
    return -1;
}

dataItem *buscar(hash H, int key, int (*funcHash)(dataItem *)){
    dataItem *res = (dataItem*)malloc(sizeof(dataItem));
    res->key = key;
    int pos = funcHash(res);
    res = H[pos];
    return res;
}

int divisao(dataItem *d) {
    return d->key % SIZE;
}

typedef unsigned long long int bigNumber;

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
#endif