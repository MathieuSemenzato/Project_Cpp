#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "booster.hpp"
#include "fcatt.hpp"

class Supporters:public Booster, public FcAtt{
    public:
        Supporters()=delete;
        Supporters(const std::string& nom, const int rarete, const int attaque);
        ~Supporters(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        void affichage() const;
        int getAttaque() const{return this->_attaque*this->_rarete;};
        int getDefense() const{return 0;};
        int getGoal() const{return 0;};
        int getCharisme() const {return 0;};
};

//check