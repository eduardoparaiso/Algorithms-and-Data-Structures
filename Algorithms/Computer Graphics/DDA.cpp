#include <iostream>
#include <math.h>

typedef struct{
    double x;
    double y;
}ponto;

void imprime_pontos(ponto p, bool cabecalho){
    if(cabecalho == true){
        std::cout << 'X' << '\t' << 'Y' << '\t' << "(X,Y)" << std::endl;
    }
    std::cout << p.x << '\t' << p.y << "\t(" << round(p.x) << ',' << round(p.y) << ')' << std::endl;
}

void DDA(ponto A, ponto B){
    int delta_x, delta_y;
    int passos, k; 
    double x_incremento, y_incremento;

    delta_x = B.x - A.x;
    delta_y = B.y - A.y;

    if(abs(delta_x) > abs(delta_y)){
        passos = abs(delta_x);
    }else{
        passos = abs(delta_y);
    }

    x_incremento = (double)delta_x/passos;
    y_incremento = (double)delta_y/passos;

    ponto novo_ponto;
    novo_ponto.x = A.x;
    novo_ponto.y = A.y;
    //set_pixel(round(x), round(y));
    imprime_pontos(novo_ponto, true);
   
    for(k = 1; k <= passos; k++){
        novo_ponto.x += x_incremento;
        novo_ponto.y += y_incremento;
        //set_pixel(round(x), round(y));
       imprime_pontos(novo_ponto, false); 
    }
}

int main(int argc, char const *argv[]){
    std::cout.precision(2);

    ponto A;
    std::cin >> A.x;
    std::cin >> A.y;

    ponto B;
    std::cin >> B.x;
    std::cin >> B.y;

    DDA(A,B);

    return 0;
}
