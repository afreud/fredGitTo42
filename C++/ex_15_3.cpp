#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<limits>
#include<tuple>
#include<cmath>


struct duree
{
    int secondes ;
};



duree create_duree(int heures, int minutes, int secondes)
{
    return { (heures * 3600) + (minutes * 60) + (secondes) } ;
}

duree create_duree(int minutes, int secondes)
{
    return { (minutes * 60) + (secondes) } ;
}

duree create_duree(int secondes)
{
    return { secondes } ;
}

int know_duree_secondes(duree & a)
{
    return (a.secondes );
}

std::tuple<int, int, int> know_duree_hms(duree & a)
{

    int heures {a.secondes / 3600} ;
    int reste {a.secondes % 3600} ;
    int minutes {reste / 60} ;
    int secondes { reste % 60} ;
    minutes = abs(minutes) ;
    secondes = abs(secondes) ;

    return {heures, minutes, secondes} ;
}


std::tuple<int,int> know_duree_ms(duree & a)
{

    int minutes {a.secondes / 60} ;
    int secondes { a.secondes % 60} ;

    return {minutes, abs(secondes)} ;
}

duree operator+(duree const & a, duree const & b)
{
    return {a.secondes + b.secondes} ;
}

duree operator-(duree const & a, duree const & b)
{
    return {a.secondes - b.secondes} ;
}

duree operator-(duree const & a)
{
    return {-a.secondes} ;
}

bool operator==(duree const & a, duree const & b)
{
    return (a.secondes == b.secondes) ;
}

bool operator<=(duree const & a, duree const & b)
{
    return (a.secondes <= b.secondes) ;
}

bool operator>=(duree const & a, duree const & b)
{
    return (a.secondes >= b.secondes) ;
}

bool operator!=(duree const & a, duree const & b)
{
    return (a.secondes != b.secondes) ;
}

std::ostream & operator<<(std::ostream & flux, duree & a)
{
    auto [heures, minutes, secondes] = know_duree_hms(a)  ;

    return flux << heures << R"(:)" << minutes << R"(')" << secondes << R"&(")&" ; 
}


int main()
{
    duree un { create_duree(1, 1, 6) } ;
    int un_en_secondes {know_duree_secondes(un)} ;

    std::cout << un <<" vaut " << un_en_secondes << " secondes." << std::endl ;

    return 0 ;
}
