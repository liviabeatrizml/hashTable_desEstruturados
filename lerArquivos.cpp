#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cidade.cpp"
#define MAX 5570

dataItem *getItens(cidade *, gps *);
void printDataItens(dataItem *);
void saveDataItens(dataItem *);

cidade *getCidades(char *arquivo);
gps *getGps(char *);
char* remover(char* text);

int main() {
    char *arquivo1 = (char *)"bancoDeDados/legenda.txt";
    cidade *todasCidades = getCidades(arquivo1);

    char *arquivo2 = (char *)"bancoDeDados/coordenadas.csv";
    gps *locais = getGps(arquivo2);
    
    dataItem *d = getItens(todasCidades, locais);
    printDataItens(d);
    saveDataItens(d);
}

cidade *getCidades(char *arquivo) {
    FILE *f = fopen(arquivo, "r");
    cidade *cidades = (cidade *)malloc(MAX * sizeof(cidade));
    if (!f) {
        perror("Arquivo não existe");
        return NULL;
    }
    fscanf(f, "CODIGO MUNICIPIO;UF;NOME MUNICIPIO");
    unsigned int cod;
    char *uf;
    char *cid;
    int i = 0;
    while (!feof(f)) {
        uf = (char *)malloc(2 * sizeof(char));
        cid = (char *)malloc(40 * sizeof(char));
        fscanf(f, "%d %s ", &cod, uf);
        fgets(cid, 40 * sizeof(char), f);
        printf("%d %s %s", cod, uf, cid);
        cidades[i].id = cod;
        cidades[i].estado = uf;
        cidades[i].cidade = cid;
        i = i + 1;
    }
    return cidades;
}

gps *getGps(char *localizacoes) {
    FILE *f = fopen(localizacoes, "r");
    gps *local = (gps *)malloc(MAX * sizeof(gps));
    if (!f) {
        perror("Arquivo não existe");
        return NULL;
    }
    fscanf(f, "CODIGO MUNICIPIO;LATITUDE;LONGITUDE");
    unsigned int cod;
    latitude la;
    longitude lo;
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%u;%f;%f", &cod, &la, &lo);
        printf("%u;%.2f;%.2f\n", cod, la, lo);
        local[i].id = cod;
        local[i].la = la;
        local[i].lo = lo;
        i = i + 1;
    }
    return local;
}


void printDataItens(dataItem *dados) {
    for (int i = 0; i < MAX; i++) {
        printf("%d %d %s %.2f %.2f %s", i, dados[i].key, dados[i].city.estado, dados[i].GPS.la, dados[i].GPS.lo, dados[i].city.cidade);
    }
}

void saveDataItens(dataItem *dados){
    FILE *f = fopen("dados.dat", "w");
    for (int i = 0; i < MAX; i++) {
        fprintf(f, "%d %d %s %.2f %.2f %s", i, dados[i].key, dados[i].city.estado, dados[i].GPS.la, dados[i].GPS.lo, dados[i].city.cidade);
    }
}

dataItem *getItens(cidade *cities, gps *local) {
    dataItem *dados = (dataItem *)malloc(MAX * sizeof(dataItem));
    int k = 0;
    for (size_t i = 0; i < MAX; i++) {
        dados[k].key = cities[i].id;
        for (size_t j = 0; j < MAX; j++) {
            if (cities[i].id == local[j].id) {
                dados[k].city = cities[i];
                dados[k].GPS = local[j];
                k++;
            }
        }
    }
    return dados;
}