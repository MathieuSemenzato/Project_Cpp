#pragma once
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include "deck.hpp"
//la classe est crée avec pour attribut un vecteur de Carte _lCartes constituant la base pour constituer les 2 decks du joueur qui seront stockés dans la liste de deck _lDecks 
class Joueur{
	public:
		Joueur(const std::string& nom, std::vector<Carte*> cartes);
		~Joueur(){};
      	void affichage() const;
      	void setDeck(Deck* deck1, Deck* deck2);
      	Deck* getDeck(const int indice);
      	void newCarte(Carte* carte);
      	Deck newDeck();
      	Deck newDeck(Deck* other);
	private :
		std::string _nom;
		std::vector<Carte*> _lCartes;
		std::list<Deck*> _lDeck;
};

//check