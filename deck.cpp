#include "deck.hpp"

bool Deck::operator== (Deck* deck) const{
    if(this==deck) return true;
    return false;
}

Deck::Deck(const std::string& nom, std::list<Carte*> main){
    this->_nom = nom;
    this->_main = main;
    this->_total_attaque = 0;
    this->_total_defense = 0;
    this->_total_goal = 0;
    this->_total_charisme = 0;
    //std::list<Carte*>::iterator it;
    for(auto iter = std::cbegin(this->_main); iter != std::cend(this->_main); iter=std::next(iter)){ //c pour empecher l'écriture
        this->_total_attaque += (*iter)->getAttaque();
        this->_total_defense += (*iter)->getDefense();
        this->_total_goal += (*iter)->getGoal();
        this->_total_charisme += (*iter)->getCharisme();
    }
}

Deck::Deck(const Deck& copie){
    //std::cout<<"ON EST ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    this->_nom=copie._nom;
    this->_main=copie._main;
    this->_total_attaque=copie._total_attaque;
    this->_total_defense=copie._total_defense;
    this->_total_goal=copie._total_goal;
}

void Deck::setNom(){
    std::cout << "Nom du Deck : " << std::flush;
    std::cin >> this->_nom;
}

void Deck::affichage() const{
    std::cout<<"\nDeck : "<<this->_nom<<"\nAttaque : "<<std::to_string(this->_total_attaque)<<"\nDefense : "<<std::to_string(this->_total_defense)<<"\nGoal : "<<std::to_string(this->_total_goal)<<"\nCharisme : "<<std::to_string(this->_total_charisme)<<std::endl;
    for(const auto& ptCarte : _main){
        ptCarte->affichage();
    }
}

//check