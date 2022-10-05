#include "cidade.cpp"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

typedef dataItem *hash[SIZE];

int divisao(dataItem *d) {
    return d->key % SIZE;
}

typedef unsigned long long int bigNumber;

int multiplicacao(dataItem *d) {
    bigNumber key = (bigNumber)d->key;
    key *= key;
    int digits = ceil(log10((bigNumber)540000*540000)/log10(2));
    int signif = ceil(log10(SIZE-1)/log10(2));
    int remover = digits - signif;
    int digitMask = (int)ceil(float(remover)/2);
    bigNumber mask = (1023 << digitMask);
    key = key & mask;
    key = (key >> digitMask);
    return key;
}

int dobra(dataItem *d){
    bigNumber key = (bigNumber)d->key;

}
int hashCodeDobra(dataItem *d) {
    return d->key % SIZE;
}

int main() {
    dataItem *d = (dataItem *)malloc(sizeof(dataItem));
    d->city.cidade = (char *)"Pau dos Ferros";
    d->GPS.la = -6.11;
    d->GPS.lo = -38.2;
    d->key = 340940;
    int res = multiplicacao(d);
}