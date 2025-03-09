#include<iostream>
#include<vector>
#include<string>

// creation d'un tableau de notes

int main ()
{
    std::vector<double> tableau_notes {} ;
    double somme {0.0} ;

    while (true)
    {
        std::cout << "(note negative pour quitter) Note:" ;
        double note  {0.0} ;

        if ( !( std::cin >> note) ) 
        {
            std::cout << "Erreur entree\n" ;
            std::cin.clear() ;
            std::cin.ignore(255, '\n') ;
            continue ;
        }
       
        if ( note < 0)
        {
            break ;
        }

        tableau_notes.push_back(note) ;
    }

    for ( auto const element : tableau_notes )
    {
        somme += element ;
    }

    std::cout << "\n\nLa moyenne des notes est: " << somme/std::size(tableau_notes) << std::endl ;

    double min { tableau_notes[0] } ;
    double max { tableau_notes[0] } ;


// Trouver le maximum et le minimun dans un tableau


    for ( auto it { std::begin(tableau_notes) }; it != std::end(tableau_notes); it++ )
    {
        if ( *it < min )
        {
            min = *it ;
        }

        if ( *it > max )
        {
            max = *it ;
        }
    }

    std::cout << "\nPlus petite note: " << min << "\n\nPlus grande note :" << max << std::endl ;


// Separer les paires et les impaires


    std::vector<int> tableau { 1, 7, 12, 15, 18, 4, 13, 16 } ;
    std::vector<int> tableau_pairs {} ;
    std::vector<int> tableau_impairs {} ;

    std::cout << "\n\nVoici des chiffres\n" ;

    for ( auto const e_list : tableau )
    {
        std::cout << e_list << std::endl ;
    }


    for ( auto const elm : tableau )
    {
        if (elm % 2  == 0 )
        {
            tableau_pairs.push_back( elm ) ;
        }
        else 
        {
            tableau_impairs.push_back( elm ) ;

        }
    }

    std::cout << "\nChiffres paires:" << std::endl ;

    for ( auto const elm_pairs : tableau_pairs )
    {
        std::cout << elm_pairs << std::endl ;
    }

    std::cout << "\nChiffres impaires:" << std::endl ;

    for ( auto const elm_impairs : tableau_impairs )
    {
        std::cout << elm_impairs << std::endl ;
    }

// compter dans une chaine

    std::string phrase {""} ;
    char lettre {} ;

    std::cout << "tapez une phrase \n" ;

    std::getline(std::cin >> std::ws, phrase);

//    if ( !(std::cin >> phrase) )
//    {
//        std::cin.clear() ;
//        std::cin.ignore(255, '\n') ;
//    }

    std::cout << "tapez une lettre \n" ;

    if ( !(std::cin >> lettre) )
    {
        std::cin.clear() ;
        std::cin.ignore(255, '\n') ;
    }

    int compteur {0} ;

    for ( auto const ltr : phrase )
    {
        if ( ltr == lettre )
            {
                compteur++ ;
            }
    }

    std::cout << "Il y a " << compteur << ' ' << lettre << " dans la phrase\n" ;

    return 0 ;
}
