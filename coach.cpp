#include "coach.hpp"

Coach::Coach(const std::string& nom, const int rarete, const int defense){
    this->_nom=nom;
    this->_typeCarte=supporters;
    this->_rarete=rarete;
    this->_defense=defense;
}

bool Coach::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Coach::affichage() const{
    std::cout<<"Type : COACH\t Nom : "<<this->_nom<<"\t Défense : "<<std::to_string(this->_defense)<<"\t Rareté : "<<std::to_string(this->_rarete)<<std::endl;
}

//check