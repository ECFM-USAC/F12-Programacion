#include<iostream>

main()
{
    
    int(count) = 0;
    std::string linea;
    std::getline(std::cin, linea);
    for(int i=0; i<linea.size(); i++)
    {
        char c = linea[i]; 

        // Convertir el caracter a minúscula 
        if(tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
        {
            count++;
        }
    }
    std::cout<<count<< std::endl;
return 0;
}   