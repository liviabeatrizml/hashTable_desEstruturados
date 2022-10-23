#include "Hash.cpp"

int main(){
    hash H;
    init(H);

    inserirTodos(H);

    remover(H, buscar(H, 110001, divisao), divisao);
    buscar(H, 120001, divisao);

    // dataItem *d = (dataItem *)malloc(sizeof(dataItem));
    // d->city.cidade = (char *)"Alta Floresta d`Oeste";
    // d->city.id = 110001;
    // d->city.estado = (char *)"RO";
    // d->key = 110001;
    // d->GPS.id = 110001;
    // d->GPS.la = -11.92;
    // d->GPS.lo = -61.99;

    // inserir(H, d, divisao);

    return 0;
}
