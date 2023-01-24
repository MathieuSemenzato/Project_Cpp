//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "tableau.hpp"
#include <charconv>
#include <bits/stdc++.h>

/*TEST_CASE("Test des Cartes"){
	printf("============Test des Cartes============\n");
	Attaquant att("Nom", "FRA", 2);
	Defenseur def("Nom", "FRA", 2);
	Gardien gar("Nom", "FRA", 2);
	Sponsors spo("Nom", 1, 2);
	Coach coa("Nom", 1, 2);
	Supporters sup("Nom", 1, 2);
	Pays pay("France", 1, 2, 3, 4);
	CHECK(att ==att);
	CHECK(att.getNom() == "Nom");
	CHECK(att.getAttaque() == 2);
	CHECK(def.getNom() == "Nom");
	CHECK(def.getDefense() == 2);
	CHECK(gar.getNom() == "Nom");
	CHECK(gar.getGoal() == 2);
	CHECK(sup.getNom() == "Nom");
	CHECK(sup.getAttaque() == 2);
	CHECK(sup.getRarete() == 1);
	CHECK(coa.getNom() == "Nom");
	CHECK(coa.getDefense() == 2);
	CHECK(coa.getRarete() == 1);
	CHECK(spo.getNom() == "Nom");
	CHECK(spo.getGoal() == 2);
	CHECK(spo.getRarete() == 1);
	CHECK(pay.getNom() == "France");
	CHECK(pay.getAttaque() == 1);
	CHECK(pay.getDefense() == 2);
	CHECK(pay.getGoal() == 3);
	CHECK(pay.getCharisme() == 4);
}

TEST_CASE("Test des Deck et Joueur"){
	printf("============Test des Deck et Joueur============\n");
	Attaquant att("Nom1", "FRA", 2);
	Defenseur def("Nom2", "FRA", 2);
	Gardien gar("Nom3", "FRA", 2);
	Sponsors spo("Nom4", 1, 2);
	Coach coa("Nom5", 1, 2);
	Supporters sup("Nom6", 1, 2);
	Pays pay("France", 1, 2, 3, 4);
	Attaquant att2("Nom7", "FRA", 2);
	Defenseur def2("Nom8", "FRA", 2);
	Gardien gar2("Nom9", "FRA", 2);
	Sponsors spo2("Nom10", 1, 2);
	Coach coa2("Nom11", 1, 2);
	Supporters sup2("Nom12", 1, 2);
	Pays pay2("FranceBIS", 1, 2, 3, 4);
	std::list<Carte*> liste;
	liste.push_back(&att);
	liste.push_back(&def);
	liste.push_back(&gar);
	liste.push_back(&spo);
	liste.push_back(&coa);
	liste.push_back(&sup);
	liste.push_back(&pay);
	Deck deck1("Nom1", liste);
	Deck deck2("Nom2", liste);
	std::vector<Carte*> vector;
	vector.push_back(&att);
	vector.push_back(&def);
	vector.push_back(&gar);
	vector.push_back(&spo);
	vector.push_back(&coa);
	vector.push_back(&sup);
	vector.push_back(&pay);
	vector.push_back(&att2);
	vector.push_back(&def2);
	vector.push_back(&gar2);
	vector.push_back(&spo2);
	vector.push_back(&coa2);
	vector.push_back(&sup2);
	vector.push_back(&pay2);
	Joueur jou("Nom3", vector);
	CHECK(deck1.getNom() == "Nom1");
	CHECK(deck1.getAttaque() == 5);
	CHECK(deck1.getDefense() == 6);
	CHECK(deck1.getGoal() == 7);
	CHECK(deck1.getCharisme() == 4.0f);
}

TEST_CASE("Test des Match"){
	printf("============Test des Match============\n");
	Attaquant att("Nom1", "FRA", 2);
	Defenseur def("Nom2", "FRA", 2);
	Gardien gar("Nom3", "FRA", 2);
	Sponsors spo("Nom4", 1, 2);
	Coach coa("Nom5", 1, 2);
	Supporters sup("Nom6", 1, 2);
	Pays pay("France", 1, 2, 3, 4);
	Attaquant att2("Nom7", "FRA", 2);
	Defenseur def2("Nom8", "FRA", 2);
	Gardien gar2("Nom9", "FRA", 2);
	Sponsors spo2("Nom10", 1, 2);
	Coach coa2("Nom11", 1, 2);
	Supporters sup2("Nom12", 1, 2);
	Pays pay2("FranceBIS", 1, 2, 3, 4);
	std::list<Carte*> liste;
	liste.push_back(&att);
	liste.push_back(&def);
	liste.push_back(&gar);
	liste.push_back(&spo);
	liste.push_back(&coa);
	liste.push_back(&sup);
	liste.push_back(&pay);
	Deck deck1("Nom1", liste);
	Deck deck2("Nom2", liste);
	Match ma(&deck1, &deck2);
	CHECK(ma.getDeck(0) == &deck1);
	CHECK(ma.getDeck(1) == &deck2);
}*/


int main(){
	std::string nom, attaque, defense, goal, charisme, nationalite, rarete;
	int entrer=1;
	std::list<Carte*> liCollection;

	//Création des cartes Pays :
	std::list<Pays> liPays;
	std::ifstream file1("pays.txt");
	while( file1 >> nom){
		file1>>attaque;
		file1>>defense;
		file1>>goal;
		file1>>charisme;
		int att, def, goa, cha;
		std::from_chars(attaque.c_str(), attaque.c_str()+ attaque.length(), att);
		std::from_chars(defense.c_str(), defense.c_str()+ defense.length(), def);
		std::from_chars(goal.c_str(), goal.c_str()+ goal.length(), goa);
		std::from_chars(charisme.c_str(), charisme.c_str()+ charisme.length(), cha);
	    liPays.push_back(Pays(nom, att, def, goa, cha));
	}
	for (auto iter = std::begin(liPays); iter!= std::end(liPays); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Attaquant :
	std::list<Attaquant> liAttaquant;
	std::ifstream file2("attaquant.txt");
	while( file2 >> nom){
		file2>>nationalite;
		file2>>attaque;
		int att;
		std::from_chars(attaque.c_str(), attaque.c_str()+ attaque.length(), att);
	    liAttaquant.push_back(Attaquant(nom, nationalite, att));
	}
	for (auto iter = std::begin(liAttaquant); iter!= std::end(liAttaquant); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Défenseur :
	std::list<Defenseur> liDefenseur;
	std::ifstream file3("defenseur.txt");
	while( file3 >> nom){
		file3>>nationalite;
		file3>>defense;
		int def;
		std::from_chars(defense.c_str(), defense.c_str()+ defense.length(), def);
	    liDefenseur.push_back(Defenseur(nom, nationalite, def));
	}
	for (auto iter = std::begin(liDefenseur); iter!= std::end(liDefenseur); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Gardien :
	std::list<Gardien> liGardien;
	std::ifstream file4("gardien.txt");
	while( file4 >> nom){
		file4>>nationalite;
		file4>>goal;
		int goa;
		std::from_chars(goal.c_str(), goal.c_str()+ goal.length(), goa);
	    liGardien.push_back(Gardien(nom, nationalite, goa));
	}
	for (auto iter = std::begin(liGardien); iter!= std::end(liGardien); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Supporters :
	std::list<Supporters> liSupporters;
	std::ifstream file5("supporters.txt");
	while( file5 >> nom){
		file5>>attaque;
		file5>>rarete;
		int att, rar;
		std::from_chars(attaque.c_str(), attaque.c_str()+ attaque.length(), att);
		std::from_chars(rarete.c_str(), rarete.c_str()+ rarete.length(), rar);
	    liSupporters.push_back(Supporters(nom, rar, att));
	}
	for (auto iter = std::begin(liSupporters); iter!= std::end(liSupporters); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Coach :
	std::list<Coach> liCoach;
	std::ifstream file6("coach.txt");
	while( file6 >> nom){
		file6>>defense;
		file6>>rarete;
		int def, rar;
		std::from_chars(defense.c_str(), defense.c_str()+ defense.length(), def);
		std::from_chars(rarete.c_str(), rarete.c_str()+ rarete.length(), rar);
	    liCoach.push_back(Coach(nom, rar, def));
	}
	for (auto iter = std::begin(liCoach); iter!= std::end(liCoach); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//Création des cartes Sponsors :
	std::list<Sponsors> liSponsors;
	std::ifstream file7("sponsors.txt");
	while( file7 >> nom){
		file7>>goal;
		file7>>rarete;
		int goa, rar;
		std::from_chars(goal.c_str(), goal.c_str()+ goal.length(), goa);
		std::from_chars(rarete.c_str(), rarete.c_str()+ rarete.length(), rar);
	    liSponsors.push_back(Sponsors(nom, rar, goa));
	}
	for (auto iter = std::begin(liSponsors); iter!= std::end(liSponsors); iter++)
	{
		liCollection.push_back(&(*iter));
	}

	//implémentation du jeu
	//etape 3 et 4 : à partir des listes de cartes crées précédemment, on chosit de manière aléatoire
	//des cartes dans chaque liste pour les mettre dans une seule liste
	std::vector<Carte*> Vector1, Vector2;
	int choice1, choice2;

	//choix des pays
	for (int i=0; i<3; i++){
		//std::list<Pays>::iterator it = liPays.begin();
		choice1 = rand()%liPays.size();
		choice2 = rand()%liPays.size();
		auto it = std::begin(liPays);
		std::advance(it,choice1);
		Vector1.push_back(&(*it));
		it = std::begin(liPays);
		std::advance(it,choice2);
		Vector2.push_back(&(*it));
	}

	//choix des attaquants
	for (int i=0; i<5; i++){
		choice1 = rand()%liAttaquant.size();
		choice2 = rand()%liAttaquant.size();
		auto it = std::begin(liAttaquant);
		std::advance(it,choice1);
		Vector1.push_back(&(*it));
		it = std::begin(liAttaquant);
		std::advance(it,choice2);
		Vector2.push_back(&(*it));
	}

	//choix des défenseurs
	for (int i=0; i<5; i++){
		choice1 = rand()%liDefenseur.size();
		choice2 = rand()%liDefenseur.size();
		auto it = std::begin(liDefenseur);
		std::advance(it,choice1);
		Vector1.push_back(&(*it));
		it = std::begin(liDefenseur);
		std::advance(it,choice2);
		Vector2.push_back(&(*it));
	}

	//choix des goals
	for (int i=0; i<3; i++){
		choice1 = rand()%liGardien.size();
		choice2 = rand()%liGardien.size();
		auto it = std::begin(liGardien);
		std::advance(it,choice1);
		Vector1.push_back(&(*it));
		it = std::begin(liGardien);
		std::advance(it,choice2);
		Vector2.push_back(&(*it));
	}

	//choix des 3 cartes boosters
	choice1 = rand()%(liSponsors.size()/2);
	auto it1 = std::begin(liSponsors);
	std::advance(it1,choice1);
	Vector1.push_back(&(*it1));
	std::advance(it1,choice1);
	Vector2.push_back(&(*it1));
	
	choice1 = rand()%(liSupporters.size()/2);
	auto it2 = std::begin(liSupporters);
	std::advance(it2,choice1);
	Vector1.push_back(&(*it2));
	std::advance(it2,choice1);
	Vector2.push_back(&(*it2));
	
	choice1 = rand()%(liCoach.size()/2);
	auto it3 = std::begin(liCoach);
	std::advance(it3,choice1);
	Vector1.push_back(&(*it3));
	std::advance(it3,choice1);
	Vector2.push_back(&(*it3));

	system("clear"); //Permet de nettoyer

	//Affichage des règles : 
	std::cout<<"Voici les règles de notre jeu :\n\nIl s'agit d'un jeu de collection. Une liste de cartes est donnée pour chaque joueur (le joueur 1 puis le joueur 2).\nLa liste est créée aléatoirement à partir d’une base de données de cartes de chaque type (Pays, Booster, Sportif).\nPar souci de réalisme, chaque carte a des caractéristiques proches de la réalité, ainsi certaines nations sont plus fortes que d’autres, les gardiens n’ont par exemple aucune influence sur les points d’attaque de votre équipe mais seront décisifs pour empêcher l’équipe adverse de marquer.\nA partir de cette liste, le joueur doit constituer 2 decks contenant chacun 1 carte pays parmi celles présentes dans la liste, 1 carte booster, 1 carte gardien ainsi que 4 cartes joueurs, qu’ils soient attaquant ou défenseur.\n\nUne fois que les 2 joueurs ont fait leurs 2 decks respectifs, des paris sont proposés. Au total, nous allons avoir 3 matchs."<<std::endl;

	std::cout<<"\nAppuyez sur 0 puis ENTER lorsque vous avez bien compris les règles"<<std::endl;
	while(entrer)std::cin>>entrer;
	entrer=1;
	system("clear");

	char nom1[50], nom2[50];
	std::cout<<"C'est l'heure de me donner vos petits noms\n\nJoueur 1, comment t'appelles tu ?"<<std::endl;
	std::cin>>nom1;
	std::cout<<"Et toi joueur 2, c'est quoi ton blaze ?"<<std::endl;
	std::cin>>nom2;
	std::cout<<nom2<<" ??? Sérieusement !!! J'ai mieux, tu t'appelleras 'Gontrand', ça claque plus nan ?"<<std::endl;

	std::cout<<"Vos noms ont bien été attribués : "<<nom1<<" et Gontrand"<<"\n\nAppuyez sur 0 puis ENTER"<<std::endl;
	while(entrer)std::cin>>entrer;
	entrer=1;
	system("clear");

	char jouer = 'O';
	Joueur J1(nom1, Vector1);
	Joueur J2("Gontrand", Vector2);

	while(jouer=='O' || jouer=='o'){
		jouer='N';
		//etape 5 : construction du deck
		//a partir des cartes, on affiche maintenant la liste et on de mande au joueur de faire son deck
		std::cout<<"Le joueur 1 va maintenant devoir faire ses decks. Joueur 2, quitte la pièce" << std::endl;
		std::cout<<"\nAppuyez sur 0 puis ENTER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");
		std::cout<<"Je sais que t'es encore là Joueur 2, QUITTE la pièce"<<std::endl;
		for(int i=0; i<200000000; i++);
		std::cout<<"DEGAGEEEEEEEEEEEEE"<<std::endl;
		std::cout<<"\nAppuyez sur 0 puis ENTER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");
		std::cout<<nom1<<", tu vas maintenant choisir tes cartes.\nTa liste de carte va t'être presentée, choisi parmi ces cartes 1 carte pays, 1 carte booster et 5 cartes joueurs\n" << std::endl;
		std::cout << "Pour se faire, rentre les indices des cartes désirées\n" << std::endl;
		J1.affichage();
		std::cout<<"\nChoix des cartes du premier deck :"<<std::endl;
		Deck deck1_j1 = J1.newDeck();
		std::cout<<"\nChoix des cartes du deuxième deck :"<<std::endl;
		Deck deck2_j1 = J1.newDeck(&deck1_j1);
		J1.setDeck(&deck1_j1, &deck2_j1);
		system("clear");
		std::cout<<"Voici les deux decks choisis :"<<std::endl;
		deck1_j1.affichage();
		deck2_j1.affichage();

		std::cout<<"\nLe choix des Decks du joueur 1 terminé, appuie sur 0 puis ENTER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");


		std::cout<<"C'est maintenant au joueur 2 de choisir ses decks. Joueur 1, quitte la pièce"<<std::endl;
		std::cout<<"\nAppuyez sur 0 puis ENTER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");
		std::cout<<"GONTRAND, tu vas maintenant choisir tes cartes.\nTa liste de carte va t'être presentée, choisi parmi ces cartes 1 carte pays, 1 carte booster et 5 cartes joueurs\n" << std::endl;
		std::cout << "Pour se faire, rentre les indices des cartes désirées\n" << std::endl;
		J2.affichage();
		std::cout<<"\nChoix des cartes du premier deck :"<<std::endl;
		Deck deck1_j2 = J2.newDeck();
		std::cout<<"\nChoix des cartes du deuxième deck :"<<std::endl;
		Deck deck2_j2 = J2.newDeck(&deck1_j2);
		J2.setDeck(&deck1_j2, &deck2_j2);
		system("clear");
		std::cout<<"Voici les deux decks choisis :"<<std::endl;
		deck1_j2.affichage();
		deck2_j2.affichage();

		std::cout<<"\nLe choix des Decks du joueur 2 terminé, appuie sur 0 puis ENTRER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");

		Tableau Tab_competition(&J1, &J2);
		Tab_competition.affichage(1);

		int score_j1=0, score_j2=0;
		//paris
		Deck* tab_paris[2][3];
		int pari, ok=1;
		std::cout << "Nous allons maintenant passer aux paris.\nPour chacun des 2 matchs de Demi-Finales, vous allez devoir parier sur votre équipe (ou sur l'équipe adverse si vous avez si peu confiance en vous).\n" << std::endl;
		for(int i=0; i<2; i++){
			for (int j=0; j<2; j++){
				ok = 1;
				std::cout << "Pour le match " << std::to_string(j+1) << ", joueur " << std::to_string(i+1) <<", pour quelle équipe pariez vous ?" << std::endl;
				std::cin >> pari;
				while (ok){
					if ( ( (j==0) && (pari == 1 || pari == 2) ) || ( (j==1) && (pari == 3 || pari == 4) ) ){
						ok = 0;
						switch(pari){
							case 1:
								tab_paris[i][j] = &deck1_j1;
								break;
							case 2:
								tab_paris[i][j] = &deck2_j2;
								break;
							case 3:
								tab_paris[i][j] = &deck2_j1;
								break;
							case 4:
								tab_paris[i][j] = &deck1_j2;
								break;
						}
					}
					else{
						if(j==0){
							std::cout <<  "Tu n'as pas parié sur le bon deck. Pari sur un deck approprié, ici 1 ou 2, c'est pourtant pas compliqué !\n" << std::flush;
							std::cin >> pari;
						}
						else{
							std::cout <<  "Tu n'as pas parié sur le bon deck. Pari sur un deck approprié, ici 3 ou 4, tu sais lire au moins ?\n" << std::flush;
							std::cin >> pari;
						}
					}
				}
			}
		}

		std::cout<<"\nPhase de pari pour les Demi-Finales terminée, appuyez sur 0 puis ENTRER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");

		std::cout<<"\t\tRESULTATS DEMI-FINALES\n"<<std::endl;

		Tab_competition.getMatch1()->result();
		Deck* winner1 = Tab_competition.getMatch1()->getWinnerMatch();
		Tab_competition.getMatch2()->result();
		Deck* winner2 = Tab_competition.getMatch2()->getWinnerMatch();

		std::cout<<std::endl;
		Tab_competition.setMatchFIN(winner1, winner2);
		Tab_competition.affichage(2);

		//on indique quel joueur a gagné le 1er match
		if (winner1 == &deck1_j1)
			score_j1 ++;
		else
			score_j2 ++;

		//on indique quel joueur a gagné le 1er pari
		if (winner1 == tab_paris[0][0]){
			std::cout << "Joueur 1 a gagné le permier pari !!!" << std::endl;
			score_j1 ++;
		}
		if (winner1 == tab_paris[1][0]){
			std::cout << "Joueur 2 a gagné le permier pari !!!" << std::endl;
			score_j2 ++;	
		}

		//on indique quel joueur a gagné le 2eme match
		if (winner2 == &deck2_j1)
			score_j1 ++;
		else
			score_j2 ++;

		//on indique quel joueur a gagné le 1er pari
		if (winner2 == tab_paris[0][1]){
			std::cout << "Joueur 1 a gagné le deuxieme pari !!!" << std::endl;
			score_j1 ++;
		}
		if (winner2 == tab_paris[1][1]){
			std::cout << "Joueur 2 a gagné le deuxieme pari !!!" << std::endl;
			score_j2 ++;	
		}

		std::cout<<"\nLes Demi-Finales sont terminées, appuyez sur 0 puis ENTRER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");
		
		std::cout<<"Nous arrivons en Finale, un grand BRAVO à nos deux équipes\n"<<std::endl;
		Tab_competition.affichage(2);

		//dernier pari
		std::cout << "C'est le dernier match, l'ULTIME et dernier pari. Sur quelle équipe pariez vous pour l'après-pénultième?" << std::endl;
		std::cout <<"Appuyer sur : \t1 pour parier pour " << winner1->getNom() << "\n\t\t2 pour parier pour " << winner2->getNom() << std::endl;
		for (int i=0; i<2; i++){
			std::cout << "Joueur " << std::to_string(i+1) <<", pour quelle équipe pariez vous ?" << std::endl;
			std::cin >> pari;
			ok=1;
			while (ok){
				if ( pari == 1 || pari == 2 ){
					ok = 0;
					switch(pari){
						case 1:
							tab_paris[i][2] = winner1;
							break;
						case 2:
							tab_paris[i][2] = winner2;
					}
				}
				else{
					std::cout <<  "Tu n'as pas parié sur le bon deck.Parie sur un deck approprié, ici 1 ou 2.\nT'a soter le CéPé où Koi ?" << std::endl;
					std::cin >> pari;
				}
			}
		}

		system("clear");

		Tab_competition.getMatchFIN()->result();
		Deck* winnerFin = Tab_competition.getMatchFIN()->getWinnerMatch();
		std::cout<<std::endl;

		Tab_competition.affichage(winnerFin->getNom());
		std::cout<<"Le grand vainqueur est : "<<winnerFin->getNom()<<"\n"<<std::endl;

		//on indique quel joueur a gagné le dernier match
		if(J1.getDeck(1)==winnerFin || J1.getDeck(2)==winnerFin)
			score_j1++;
		else
			score_j2++;

		//on indique quel joueur a gagné le dernier pari
		if (winnerFin == tab_paris[0][2]){
			std::cout << "Joueur 1 a gagné le dernier pari !!!" << std::endl;
			score_j1 ++;
		}
		if(winnerFin == tab_paris[1][2]){
			std::cout << "Joueur 2 a gagné le dernier pari !!!" << std::endl;
			score_j2 ++;
		}

		if (score_j1 < score_j2) std::cout << "\nAvec un score de " << std::to_string(score_j2) << " contre "<< std::to_string(score_j1) <<", le joueur 2 remporte la partie" << std::endl;
		else std::cout << "Avec un score de " << std::to_string(score_j1) << " contre "<< std::to_string(score_j2) << ", le joueur 1 remporte la partie" << std::endl;

		std::cout<<"\nLe jeu est terminé, êtes-vous prêt a voir les cartes que vous avez gagner ?\nappuyez sur 0 puis ENTRER"<<std::endl;
		while(entrer)std::cin>>entrer;
		entrer=1;
		system("clear");

		if(score_j1) std::cout<<"------------------- Voici les gains de "<<nom1<<" -------------------\n"<<std::endl;
		for(int i=0; i<score_j1; i++){
			auto iter = std::begin(liCollection);
			choice1 = rand()%liCollection.size();
			std::advance(iter,choice1);
			J1.newCarte(*iter);
		}
		if(score_j2) std::cout<<"\n------------------- Voici les gains de Gontrand -------------------\n"<<std::endl;
		for(int i=0; i<score_j2; i++){
			auto iter = std::begin(liCollection);
			choice2 = rand()%liCollection.size();
			std::advance(iter,choice2);
			J2.newCarte(*iter);
		}
		std::cout<<"Voulez vous faire une nouvelle partie ? O/N"<<std::endl;
		std::cin>>jouer;
		system("clear");
	}

	//liCollection.clear();
	return 0;
}