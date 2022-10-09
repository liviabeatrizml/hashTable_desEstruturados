#include "Hash.cpp"
#include "lerArquivos.cpp"

void teste01() {
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

    // Não faz sentido mudar a função Hash, mas coloquei aqui para mostrar que é possível
    inserir(H, d, multiplicacao);
    remover(H, d, multiplicacao);
    inserir(H, d, multiplicacao);
    dataItem *dt = buscar(H, 340940, multiplicacao);
}

void inserirTodos(){
    cidade *todasCidades = getCidades((char*)"bancoDeDados/legenda.txt");
    gps *todoLocal = getGps((char*)"bancoDeDados/coordenadas.csv");
    dataItem* d = getItens(todasCidades, todoLocal);
    hash H;
    init(H);
    int colisao = 0;
    for(int i=0; i<MAX; i++){
        colisao += -1*inserir(H, d+i, multiplicacao);
    }
}

int main() {
    //teste01();
    inserirTodos(); //Tentativa de inserção
}