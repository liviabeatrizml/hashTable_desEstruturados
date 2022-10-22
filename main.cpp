#include "Hash.cpp"
#include "lerArquivos.cpp"

void inserirTodos();

int main(){
    inserirTodos();

    return 0;
}

void inserirTodos(){
    cidade *allCity = getCidades((char*)"bancoDeDadosTemp/legenda.txt");
    gps *allLocal = getGps((char*)"bancoDeDadosTemp/coordenadas.csv");

    dataItem* d = getItens(allCity, allLocal);

    hash H;
    init(H);

    int colisao = 0;

    for(int i = 0; i < MAX; i++){
        colisao += -1 * inserir(H, d+i, divisao);
    }

    // printf("Colisoes: %d", colisao);

    remover(H, buscar(H, 110001, divisao), divisao);

    buscar(H, 430781, divisao);
}