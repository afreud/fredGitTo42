#include<iostream>
#include<string>


int main ()
{
    std::string phrase {""} ;

    std::cout << "Tapez une phrase\n" ;
    std::getline( std::cin >> std::ws, phrase) ;

    auto it_début_mot { std::begin(phrase) } ;
    auto it_fin_mot { std::find( std::begin(phrase), std::end(phrase), ' ' ) } ;

    for ( int i {1}; it_fin_mot != std::end(phrase); i++ )
    {
        std::cout << "Il y a " << std::count(it_début_mot, it_fin_mot, 'e')  << " e dans le mot n° " << i << std::endl ;

        it_fin_mot++
        it_début_mot = it_fin_mot ;
        it_fin_mot = std::find( it_début_mot, std::end(phrase), ' ' ) ;
    }

    return 0;
}
