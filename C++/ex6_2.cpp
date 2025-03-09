#include <iostream>


int main ()
{
    int poid_linge {0} ;
    int nbr_m5kg {0} ;
    int nbr_m10kg {0} ;

    std::cout << "Nombre de kilos de linge? \n" ;
    std::cin >> poid_linge ;

    if ( poid_linge <= 5 )
    {
        nbr_m5kg ++ ;
    }

    else if ( poid_linge > 5 && poid_linge <= 10 )
    {
        nbr_m10kg++ ;
    }

    else 
    {
        nbr_m10kg = poid_linge / 10 ;

        int reste { poid_linge % 10 } ;


        if ( (reste <= 5) && (reste !=0) )
        {
            nbr_m5kg++ ;
        }
        
        else if ( (reste > 5) && (reste !=0) )
        {
            nbr_m10kg++ ;
        }
    }

    std::cout << nbr_m5kg << "  machines de 5kg. \n" << nbr_m10kg << "  machines de 10kg \n" ;

    return 0;
}
