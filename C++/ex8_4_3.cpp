#include<iostream>
#include<string>
#include<vector>


int main ()
{
    std::string phrase {"Une phrase de test"} ;
    std::vector<std::string> tab_mots {} ;

    auto it_debut { std::begin(phrase) } ;
    auto it_fin { std::find(std::begin(phrase), std::end(phrase), ' ') } ;

    do
    {
        std::string mot { it_debut, it_fin } ;

        tab_mots.push_back(mot) ;

        it_debut = ( it_fin + 1 ) ;
        it_fin = std::find(it_debut, std::end(phrase), ' ') ;

    } while ( it_debut != (std::end(phrase) +1) ) ;

    for ( std::string const element : tab_mots )
    {
        std::cout <<  element << std::endl ;
    }

    return 0;
}
