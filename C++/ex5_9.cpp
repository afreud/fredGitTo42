#include <iostream>


int main ()
{
    int heure {} ;
    
    std::cout << "Donnez une heure entre 1 et 24" << std::endl ;
    std::cin >> heure ;

    if ( (heure > 0) && (heure < 6) )
    {
        std::cout << "Nous sommes la nuit." << std::endl ;
    }

    else if ( (heure >= 6) && (heure < 12) )
    {
        std::cout << "Nous sommes le matin." << std::endl ;
    }

    else if ( (heure > 12) && (heure < 18) )
    {
        std::cout << "Nous sommes l'apres-midi." << std::endl ;
    }
    else if ( (heure >= 18) && (heure < 24) )
    {
        std::cout << "Nous sommes le soir." << std::endl ;
    }

    else if ( (heure == 0) || (heure == 24) )
    {
        std::cout << "Il est minuit !!!" << std::endl ;
    }

    else if (heure == 12)
    {
        std::cout << "Il est midi." << std::endl ;
    }

    else
    {
        std::cout << "Il n'y a que 24 heures dans une journee.." << std::endl ;
    }

    return (0);
}
