#include "pays.hpp"

Pays::Pays(const std::string& nom, const int attaque, const int defense, const int goal, const int charisme){
    this->_nom=nom;
    this->_typeCarte=pays;
    this->_attaque=attaque;
    this->_defense=defense;
    this->_goal=goal;
    this->_charisme=charisme;
}

bool Pays::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Pays::affichage() const{
    std::cout<<"Type : PAYS\t Nom : "<<this->_nom<<"\t Charisme : "<<std::to_string(this->_charisme)<<"\t Attaque : "<<std::to_string(this->_attaque)<<"\t Défense : "<<std::to_string(this->_defense)<<"\t Goal : "<<std::to_string(this->_goal)<<std::endl;
}

//check