#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "attaquant.hpp"
#include "defenseur.hpp"
#include "gardien.hpp"
#include "pays.hpp"
#include "coach.hpp"
#include "supporters.hpp"
#include "sponsors.hpp"

class Deck{
	public:
		Deck(const std::string& nom, std::list<Carte*> main);
		Deck(const Deck& copie);
		~Deck(){};
        bool operator==(Deck* deck) const;
		std::string getNom()const{return this->_nom;};
		void setNom();
		int getAttaque()const{return this->_total_attaque;};
		int getDefense()const{return this->_total_defense;};
		int getGoal()const{return this->_total_goal;};
		float getCharisme()const{return this->_total_charisme;};
		std::list<Carte*> getMain()const{return this->_main;};
      	void affichage() const;
	private :
		std::string _nom;
		std::list<Carte*> _main;
		int _total_attaque;
		int _total_defense;
		int _total_goal;
		int _total_charisme;
};

//check