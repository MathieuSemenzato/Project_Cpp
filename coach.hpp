#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "booster.hpp"
#include "fcdef.hpp"

class Coach:public Booster, public FcDef{
    public:
        Coach()=delete;
        Coach(const std::string& nom, const int rarete, const int defense);
        ~Coach(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        int getAttaque() const{return 0;};
        int getDefense() const{return this->_defense*this->_rarete;};
        int getGoal() const{return 0;};
        int getCharisme() const {return 0;};
        void affichage() const;
};

//check