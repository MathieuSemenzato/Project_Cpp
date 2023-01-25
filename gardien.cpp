#include "gardien.hpp"

Gardien::Gardien(const std::string& nom, const std::string& nationalite, const int goal){
    this->_nom=nom;
    this->_typeCarte=gardien;
    this->_nationalite=nationalite;
    this->_goal=goal;
}

bool Gardien::operator== (const Carte& carte) const{
    if(_nom==carte.getNom()) return true;
    return false;
}

void Gardien::affichage() const{
    std::cout<<"Type : GARDIEN\t Nom : "<<this->_nom<<" ("<<this->_nationalite<<")\t Goal : "<<std::to_string(this->_goal)<<std::endl;
}

//check