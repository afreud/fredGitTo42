#include<iostream>
#include<string>


int main ()
{
    std::string mot {} ;
    std::string mot_inverse {} ;

    std::cout << "Ecrivez un mot.\n" ;

    if (!(std::cin >> mot))
    {
        std::cin.clear() ;
        std::cin.ignore(255, '\n') ;
    }

    mot_inverse = mot ;

    std::reverse( std::begin(mot_inverse), std::end(mot_inverse) ) ;

    if ( mot == mot_inverse )
    {
        std::cout << "Ce mot est un palindrome" << std::endl ;
    }
    else
    {
        std::cout << "Ce mot n'est pas un palindrome" << std::endl ;
    }

    return 0;
}
