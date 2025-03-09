#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<limits>


struct info_perso
{
    std::string prenom ;
    std::string nom;
    std::string  sexe ;
    int age ;
};


//template <typename T>
//void entree_securisee( T & info )
//{
//    while ( !(std::cin >> info) )
//    {
//        std::cout << "Erreur entree" << std::endl ;
//        std::cin.clear() ;
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
//    }
    
template <typename T1, typename T2>
void entree_securisee( T1 & info, T2 lambda )
{
    while ( !(std::cin >> info) || !(lambda(info)) )
    {
        std::cout << "Erreur entree!!!" << std::endl ;
        std::cin.clear() ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n') ;
    }
}


void demander_info ( info_perso & structure )
{

    
    auto test_alpha = [](std::string reponse) -> bool {return std::all_of(std::begin(reponse), std::end(reponse), isalpha);} ;
    auto test_age = [](int age) -> bool {return (age>0);};

    std::cout << "Prenom? " ;
    entree_securisee(structure.prenom, test_alpha) ;
    std::cout << "Nom? " ;
    entree_securisee(structure.nom, test_alpha) ;
    std::cout << "Sexe? " ;
    entree_securisee(structure.sexe, test_alpha) ;
    std::cout << "Age? " ;
    entree_securisee(structure.age, test_age) ;
}

void enregistrer_info ( info_perso const structure)
{
    std::string nom_fichier { structure.prenom + '.' + structure.nom + ".csv" } ;
    std::ofstream fichier {nom_fichier} ;
    fichier << structure.nom << ',' << structure.prenom << ',' << structure.sexe << ','  << structure.age << std::endl ;

}

int main()
{
    info_perso structure_tempo {} ;

    demander_info(structure_tempo) ;
    enregistrer_info(structure_tempo) ;

    return 0 ;
}
