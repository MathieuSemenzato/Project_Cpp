#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "carte.hpp"

//la classe Booster hérite de la classe Carte. Cependant, comme nous allons utiliser différents types de booster, cette classe est abstraite. En efffet, on aura jamais besoin d'appeler cette classe directement, on appellera à la place la classe du Booster (Coach, Sponsor ou Supporter)
class Booster:public Carte{
    public:
        virtual ~Booster(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        int getRarete() const {return this->_rarete;};
        virtual void affichage() const =0;//la classe est abstraite
        //de la même manière que pour la classe Carte, la classe booster ne sera jamais appelé elle-même mais les clases héritées (Coach, Sponsor, Supporter) qui donneront des points d'att, de def ou de goal d'ou le return 0
        virtual int getAttaque() const{return 0;};
        virtual int getDefense() const{return 0;};
        virtual int getGoal() const{return 0;};
        virtual int getCharisme() const {return 0;};
    protected:
        int _rarete;
};

//check