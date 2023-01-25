#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <unordered_map>
#include "deck.hpp"

class Match{
	public:
		Match(Deck* deck1, Deck* deck2);
		Match(){};
		~Match(){};
		void result();
		Deck* getDeck(int indice);
		Deck* getWinnerMatch();
	private :
		std::list<Deck*> _lDeck;
		std::unordered_map<Deck*, int> _resultat;
};

//check