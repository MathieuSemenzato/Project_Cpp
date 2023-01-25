#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 
#include "carte.hpp"
//classe abstraite puisque la classe Sportif ne sera jamais directement créer, on créera plutot les classe héritées de cette classe (Attaquant, Defenseur, Gardien)
//On gardera tout de même l'attribut de nationalité pour les 3 classes héritées.
class Sportif:public Carte{
    public:
        virtual ~Sportif(){};
        bool operator==(const Carte& carte) const;
        std::string getNom() const {return this->_nom;};
        virtual void affichage() const =0;
        virtual int getAttaque() const{return 0;};
        virtual int getDefense() const{return 0;};
        virtual int getGoal() const{return 0;};
        virtual int getCharisme() const {return 0;};
    protected:
        std::string _nationalite;
};

//check