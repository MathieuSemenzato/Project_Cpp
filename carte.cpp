#include "carte.hpp"

bool Carte::operator== (Carte* carte) const{
    if(this==carte) return true;
    return false;
}

void Carte::affichage() const{
    std::cout<<"/-----------------------------\\"<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"| Nom : "<<this->_nom<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"\\-----------------------------/\n"<<std::endl;
}

//check