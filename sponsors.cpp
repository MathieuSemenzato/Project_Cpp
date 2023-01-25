#include "sponsors.hpp"

Sponsors::Sponsors(const std::string& nom, const int rarete, const int goal){
    this->_nom=nom;
    this->_typeCarte=supporters;
    this->_rarete=rarete;
    this->_goal=goal;
}

bool Sponsors::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Sponsors::affichage() const{
    std::cout<<"Type : SPONSORS\t Nom : "<<this->_nom<<"\t Goal : "<<std::to_string(this->_goal)<<"\t Rareté : "<<std::to_string(this->_rarete)<<std::endl;
}

//check