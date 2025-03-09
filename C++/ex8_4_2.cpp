#include<iostream>
#include<string>
#include<algorithm>
#include<functional>




int main ()
{
    std::string phrase {"    une phrase avec des espaces    "} ;


        auto it_debut { std::begin (phrase) } ;

        while ( isspace(*it_debut) )
        {
            it_debut++;
        }


        auto it_fin = (std::end(phrase)) ;


        while ( isspace(*(it_fin-1)) )
        {
            it_fin-- ;
        }



    std::cout << "Avant:\n" << phrase << std::endl ;

    std::string phrase_cut { it_debut, it_fin } ;

    std::cout << "Apres:\n" << phrase_cut << std::endl ;

    return 0;
}
