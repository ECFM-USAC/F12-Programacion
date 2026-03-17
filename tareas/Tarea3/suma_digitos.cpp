#include<iostream>
#include <algorithm>
int n;
int main() {
    
    std::cin >> n;
    int suma=0;

    while(n>0 && n<=1000000000){
        suma += n%10; //para encontrar el último dígito de n
        n = n/10; //para eliminar el último dígito de n
    }
    std::cout << suma << std::endl;
    return 0;
}