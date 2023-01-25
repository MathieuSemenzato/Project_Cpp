#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream> 

typedef enum CategorieType{pays, supporters, coach, sponsors, gardien, attaquant, defenseur, defaut} Type;
//le type de carte va ainsi permettre de différencier chaque type de carte et de l'afficher adéquatement

class Carte{
    //La classe n'est pas déclarée virtuelle pure car nous devons créer un tableau de carte dans le MAIN
    public:
        virtual ~Carte(){};
        bool operator==(Carte* carte) const;//permettra de vérifier que 2 cartes ne sont pas identiques
        std::string getNom() const {return this->_nom;};
        virtual void affichage() const;
        Type getType() const{return _typeCarte;};
        //on n'aura pas besoin de créer un objet de classe Carte (les classes héritées de carte seront créer), donc les getter vont être redéfini pour chaque type de carte mais ne servent pas ici
        //d'ou le return 0 puisque l'on définira des points d'att, de def, de goal ou de charisme pour les classes hérités (Pays, Attaquant, Defenseur, Goal)
        //le fait de les définir ici permet de les redéfinir pour chaque classe héritées
        virtual int getAttaque() const {return 0;};
        virtual int getDefense() const {return 0;};
        virtual int getGoal() const {return 0;};
        virtual int getCharisme() const {return 0;};
    protected:
        std::string _nom;
        Type _typeCarte;
};

//check