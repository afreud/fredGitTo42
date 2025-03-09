#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<cctype>


int main()
{
    std::string adresse {""} ;

    std::cout << "Chemin du fichier:\n" ;

    if( !(std::cin >> adresse) )
    {
        std::cin.clear() ;
        std::cin.ignore(255, '\n') ;
    }

    std::ifstream fichier { adresse } ;

    int compteur_lignes {0} ;
    int compteur_mots {0} ;
    int compteur_lettres {0} ;
    std::string string_tampon {""} ;

    while ( std::getline(fichier >> std::ws, string_tampon) )
    {
        auto it_debut { std::begin(string_tampon) } ;
        auto it_fin { std::find(it_debut, std::end(string_tampon), ' ') } ;

        while ( it_fin != std::end(string_tampon) ) 
        {
            compteur_mots ++ ;
            it_debut = it_fin ;
            it_debut++ ;
            it_fin = std::find(it_debut, std::end(string_tampon), ' ')  ;
        }
        
        compteur_mots ++ ;

        for ( auto elements : string_tampon )
        {
            if ( !(isspace(elements)) )
            {
                compteur_lettres++ ;
            }
        }

        compteur_lignes++ ;
    }

    std::cout << "Nombre de lignes: " << compteur_lignes << std::endl ;
    std::cout << "Nombre de mots: " << compteur_mots << std::endl ;
    std::cout << "Nombre de lettres: " << compteur_lettres << std::endl ;

    return 0;
}
