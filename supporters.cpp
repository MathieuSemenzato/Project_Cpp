#include "supporters.hpp"

Supporters::Supporters(const std::string& nom, const int rarete, const int attaque){
    this->_nom=nom;
    this->_typeCarte=supporters;
    this->_rarete=rarete;
    this->_attaque=attaque;
}

bool Supporters::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Supporters::affichage() const{
    std::cout<<"Type : SUPPORTERS\t Nom : "<<this->_nom<<"\t Attaque : "<<std::to_string(this->_attaque)<<"\t Rareté : "<<std::to_string(this->_rarete)<<std::endl;
}

//check