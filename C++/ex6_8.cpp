#include<iostream>

// verifie si un nombre est premier


int main ()
{
    int nombre {0} ;

    std::cout << "Donnez un nombre \n " ;

    if ( !(std::cin >> nombre) )
    {
        std::cin.clear() ;
        std::cin.ignore( 255, '\n' ) ;
    }


    for ( int i {2} ; i < nombre ; i++)
    {
        if ( (nombre % i) == 0 )
        {
            std::cout << "Ce n'est pas un nombre premier\n" ;
            break ;
        }
        
        else if ( i == (nombre - 1) )
        {
            std::cout << "C' est un nombre premier\n" ;
        }
    }
    
    return 0 ;
}
