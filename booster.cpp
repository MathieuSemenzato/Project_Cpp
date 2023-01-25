#include "booster.hpp"

bool Booster::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Booster::affichage() const{
    std::cout<<"/-----------------------------\\"<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"| Nom : "<<this->_nom<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"| Rareté : "<<this->_rarete<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"\\-----------------------------/\n"<<std::endl;
}

//check