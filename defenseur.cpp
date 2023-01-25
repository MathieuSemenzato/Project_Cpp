#include "defenseur.hpp"

Defenseur::Defenseur(const std::string& nom, const std::string& nationalite, const int defense){
    this->_nom=nom;
    this->_typeCarte=defenseur;
    this->_nationalite=nationalite;
    this->_defense=defense;
}

bool Defenseur::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Defenseur::affichage() const{
    std::cout<<"Type : DEFENSEUR\t Nom : "<<this->_nom<<" ("<<this->_nationalite<<")\t Défense : "<<std::to_string(this->_defense)<<std::endl;
}

//check