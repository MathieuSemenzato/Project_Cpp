#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "booster.hpp"
#include "fcgoal.hpp"

class Sponsors:public Booster, public FcGoal{
    public:
        Sponsors()=delete;
        Sponsors(const std::string& nom, const int rarete, const int goal);
        ~Sponsors(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        void affichage() const;
        int getAttaque() const{return 0;};
        int getDefense() const{return 0;};
        int getGoal() const{return this->_goal*this->_rarete;};
        int getCharisme() const {return 0;};
};

//check