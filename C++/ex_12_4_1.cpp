#include<iostream>



std::all_of(std::begin(tableau), std::end(tableau), 
    [](auto n) -> bool
{
        return n>0 ;
}) ;


std::sort(std::begin(tableau), std::end(tableau), 
    [](auto a, auto b) -> int
{
    return std::abs(a) < std::abs::(b) ;
}


