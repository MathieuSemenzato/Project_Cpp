#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "sportif.hpp"
#include "fcdef.hpp"

class Defenseur:public Sportif, public FcDef{
    public:
        Defenseur()=delete;
        Defenseur(const std::string& nom, const std::string& nationalite, const int defense);
        ~Defenseur(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        void affichage() const;
        int getAttaque() const{return 0;};
        int getDefense() const{return this->_defense;};
        int getGoal() const{return 0;};
        int getCharisme() const {return 0;};
};

//check