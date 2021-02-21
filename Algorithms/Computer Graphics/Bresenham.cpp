#include <iostream>
#include <math.h>

typedef struct{
    int x;
    int y;
}ponto;

void imprime_pontos(ponto p, bool cabecalho){
    if(cabecalho == true){
        //colocar dados base;
        std::cout << 'X' << '\t' << 'Y' << '\t' << "(X,Y)" << std::endl;
    }
    std::cout << p.x << '\t' << p.y << "\t(" << round(p.x) << ',' << round(p.y) << ')' << std::endl;
}


void bresenham(ponto A, ponto B){
    int delta_x, delta_y;
    int x,y;
    int const1, const2;
    int p;

    delta_x = B.x - A.x;
    delta_y = B.y - A.y;

    int x_incremento, y_incremento;
    if(delta_x >= 0){
        x_incremento = 1;
    }else{
        x_incremento = -1;
        delta_x = -delta_x;
    }

    if(delta_y >= 0){
        y_incremento = 1;
    }else{
        y_incremento = -1;
        delta_y = -delta_y;
    }

    ponto novo_ponto;
    novo_ponto.x = A.x;
    novo_ponto.y = A.y;

    imprime_pontos(novo_ponto, true);

    if(delta_y < delta_x){
        p = (delta_y * 2) - delta_x;
        const1 = delta_y * 2;
        const2 = (delta_y - delta_x) * 2;

        for(int i = 0; i < delta_x; i++){
            novo_ponto.x += x_incremento;
            if(p < 0){
                p += const1;
            }else{
                novo_ponto.y += y_incremento;
                p += const2;
            }
            imprime_pontos(novo_ponto, false);
        }
    }else{
        p = (delta_x * 2) - delta_y;
        const1 = delta_x * 2;
        const2 = (delta_x - delta_y) * 2;
        for (int i = 0; i < delta_y; i++){
            novo_ponto.y += y_incremento;
            if(p < 0){
               p += const1;
            }else{
               novo_ponto.x += x_incremento;
               p += const2;
            }
            imprime_pontos(novo_ponto, false);
        }
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

    bresenham(A,B);

    return 0;
}