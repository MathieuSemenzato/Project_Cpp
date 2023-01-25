#include "sportif.hpp"

bool Sportif::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Sportif::affichage() const{
    std::cout<<"/-----------------------------\\"<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"| Nom : "<<this->_nom<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"| Nationalité : "<<this->_nationalite<<std::endl;
    std::cout<<"|"<<std::endl;
    std::cout<<"\\-----------------------------/\n"<<std::endl;
}

//check