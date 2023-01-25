#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "sportif.hpp"
#include "fcatt.hpp"

class Attaquant:public Sportif, public FcAtt{
    public:
        Attaquant()=delete;
        Attaquant(const std::string& nom, const std::string& nationalite, const int attaque);
        ~Attaquant(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        int getAttaque() const{return this->_attaque;};
        int getDefense() const{return 0;};
        int getGoal() const{return 0;};
        int getCharisme() const {return 0;};
        void affichage() const;
};

//check