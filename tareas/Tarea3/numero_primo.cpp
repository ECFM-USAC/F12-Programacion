#include <iostream>
#include <cmath>

int main() {
    int n;
    int d;
    
    std::cin >> n;
    
    while (n>=2 && n<=1000000){
        d=2; //el primer divisor a probar es el 2
        while (d<=sqrt(n) && n%d!=0){ //mientras el divisor sea menor o igual a la raiz de n y n no sea divisible por d
            d++; //probar el siguiente divisor
        }

        if (d>sqrt(n)){ //si el divisor es mayor que la raiz de n, entonces n es primo        
            std::cout << "primo" << std::endl;
        } else {
            std::cout << "no primo" << std::endl;
        }
        break;
    }
    return 0;
}