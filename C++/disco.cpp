#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<limits>
#include<tuple>
#include<cmath>



struct morceau
{
    std::string nom ;
    std::string nom_album ;
    std::string nom_artiste ;
};


using Disco = std::vector<morceau> ;


Disco discographie {} ;


std::ostream& operator<<(std::ostream& flux, morceau const& m )
{
    flux << m.nom << " | " << m.nom_album << " | " << m.nom_artiste ;
    return flux ;
}


std::istream& operator>>(std::istream& flux, morceau const& m)
{
    std::string mot {} ;
    std::ostreamstring entree {} ;

    while ( (flux >> mot) && (flux != '|') )
    {
        
    }
}
