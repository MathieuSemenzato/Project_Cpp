#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <unordered_map>
#include "match.hpp"
#include "joueur.hpp"

class Tableau{
	public:
		Tableau(Joueur* joueur1, Joueur* joueur2);
		~Tableau(){};
		Joueur* getWinnerCup();
		Match* getMatch1() {return &(this->_match1);};
		Match* getMatch2() {return &(this->_match2);};
		Match* getMatchFIN() {return &(this->_matchFIN);};
		void setMatchFIN(Deck* deck1, Deck* deck2){this->_matchFIN = Match(deck1, deck2);};
		void affichage(int phase);
		void affichage(std::string Nom);
	private :
		std::list<Joueur*> _lJoueur;
		Match _match1;
		Match _match2;
		Match _matchFIN;
};

//check