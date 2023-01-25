#include "attaquant.hpp"

Attaquant::Attaquant(const std::string& nom, const std::string& nationalite, const int attaque){
    this->_nom=nom;
    this->_typeCarte=attaquant;
    this->_nationalite=nationalite;
    this->_attaque=attaque;
}

bool Attaquant::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Attaquant::affichage() const{
    std::cout<<"Type : ATTAQUANT\t Nom : "<<this->_nom<<" ("<<this->_nationalite<<")\t Attaque : "<<std::to_string(this->_attaque)<<std::endl;
}

//check