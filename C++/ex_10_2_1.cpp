#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<cctype>





void affiche_rectangle( int h, int l )
{
    while ( h > 0 )
    {
        while (l > 0)
        {
            std::cout << '*' ;
            l-- ;
        }

        std::cout << std::endl ;
        h-- ;
    }
}


std::vector<int> distributeur( int somme, std::vector<int> coupures )
{
    std::vector<int> nbr_billets {} ;
    auto it_nbr_billets {std::begin(nbr_billets) } ;
    
    auto it_coupures { std::begin(coupures) } ;

    while ( it_coupures != std::end(coupures) )
    {
        *it_nbr_billets = somme / *it_coupures ;
        somme = somme % *it_coupures ;
        it_coupures++ ;
        it_nbr_billets++ ;
    }

    return nbr_billets ;
}

void afficher_nbr_billets( int somme, std::vector<int> coupures )
{
    std::vector<int> nbr_billets { distributeur(somme, coupures) ;

    auto it_nbr_billets {std::begin(nbr_billets) } ;
    auto it_coupures { std::begin(coupures) } ;

    while ( it_coupures != std::end(coupures) )
    {
        if (*it_nbr_billets != 0)
        {
            std::cout << *it_nbr_billets << " x " << *it_coupures << " euros." << std::endl ;
            it_nbr_billets++ ;
            it_coupures++ ;
        }
    }
}


bool parentheses( std::string phrase )
{
    int p_ouvrantes {0} ;
    int p_fermantes {0} ;

    auto it { std::begin(phrase) } ;

    while (it != std::end(phrase))
    {
        auto lettre { *it } ;

        if (lettre == '(')
        {
          p_ouvrantes++ ;
        }
        else if (lettre == ')') ;
        {
            p_fermantes++ ;
        }
        else
        {
            return false ;
        }

        if ( p_fermantes > p_ouvrantes )
        {
            return false ;
        }

        it++ ;
    }

    if (p_ouvrantes != p_fermantes)
    {
        return false ;
    }
    else
    {
        return true ;
    }
}


void read_string(int valeur )
{
    while ( !(std::cin >> valeur) )
    {
        std::cout << "Erreur entree, recommencez " << std::endl ;
        std::cin.clear() ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),"\n") ;
    }
}
