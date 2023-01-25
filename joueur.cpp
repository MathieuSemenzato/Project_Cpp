#include "joueur.hpp"

struct Tri{
    inline bool operator() (const Carte* carte1, const Carte* carte2) const {
        return carte1->getType()<carte2->getType();
    }
};

Joueur::Joueur(const std::string& nom, std::vector<Carte*> cartes){
    this->_nom = nom;
    this->_lCartes=cartes;
    std::sort(this->_lCartes.begin(), this->_lCartes.end(), Tri());
}

void Joueur::setDeck(Deck* deck1, Deck* deck2){
    this->_lDeck.clear();
    this->_lDeck.push_back(deck1);
    this->_lDeck.push_back(deck2);
}

Deck* Joueur::getDeck(const int indice){
    Deck* temp;
    if(indice==1){
        temp = _lDeck.front();
    }
    else if(indice==2){
        temp = _lDeck.back();
    }
    else{
        return NULL;
    }
    return temp;
}

//fonction pour ajouter une Carte au vecteur de Carte qui permet de faire ses decks. Si la carte n'est pas déjà présente dans _lCartes, alors elle est rajoutée
void Joueur::newCarte(Carte* carte){
    if(std::find(std::begin(this->_lCartes), std::end(this->_lCartes), carte)!=std::end(this->_lCartes)){
        std::cout<<"Vous possédez déjà la carte '"<<carte->getNom()<<"', DOMMAGE !\n"<<std::endl;
    }
    else{
        std::cout<<"Nouvelle Carte débloquée !\n"<<std::endl;
        this->_lCartes.push_back(carte);
        std::sort(this->_lCartes.begin(), this->_lCartes.end(), Tri());
        std::cout<<"/----------------------------------------------\\"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|\t"<<carte->getNom()<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"/----------------------------------------------\\\n"<<std::endl;
    }
}

//Le vecteur de carte contient les cartes triées dans l'ordre, ce qui permet de faire plus facilement le choix des Cartes que l'on veut dans son deck
Deck Joueur::newDeck(){
    long unsigned int choice;
    bool ok = true;
    std::list<Carte*> List_deck;
    while(ok){
        std::cout << "Choix du Pays : indices = "; std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==pays)){
            List_deck.push_back((this->_lCartes[choice-1]));
            ok = false;}}
    while(!ok){
        std::cout << "Choix du Booster : indices = ";std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==supporters || this->_lCartes[choice-1]->getType()==coach || this->_lCartes[choice-1]->getType()==sponsors)){
            List_deck.push_back((this->_lCartes[choice-1]));
            ok = true;}}
    while(ok){
        std::cout << "Choix du Gardien : indices = ";std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==gardien)){
            List_deck.push_back((this->_lCartes[choice-1]));
            ok = false;}}
    for(int i = 0; i<4; i++){
        ok = true;
        while(ok){
            std::cout << "Choix des 4 Joueurs restants : indices = "; std::cin >> choice;
            if( (std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0  && (this->_lCartes[choice-1]->getType()==attaquant || this->_lCartes[choice-1]->getType()==defenseur)){
                List_deck.push_back((this->_lCartes[choice-1]));
                ok = false;}}}
    std::string nom;std::cout << "Nom du Deck : " << std::flush;std::cin >> nom;if(nom.length()<8){nom+="        ";};
    Deck newDeck(nom, List_deck);
    return newDeck;
}

//surcharge d'opérateur qui va permettre de vérifier, lors de la création du deuxième deck, que les cartes séléctionnées ne spnt pas les mêmes que pour le premier deck
Deck Joueur::newDeck(Deck* other){
    std::list<Carte*> compar = other->getMain();
    long unsigned int choice;
    bool ok = true;
    std::list<Carte*> List_deck;
    while(ok){
        std::cout << "Choix du Pays : indices = "; std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==pays)){
            if((std::find(std::begin(compar), std::end(compar), this->_lCartes[choice-1]) == std::end(compar))){
                List_deck.push_back((this->_lCartes[choice-1]));
                ok = false;}}}
    while(!ok){
        std::cout << "Choix du Booster : indices = ";std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==supporters || this->_lCartes[choice-1]->getType()==coach || this->_lCartes[choice-1]->getType()==sponsors)){
            if((std::find(std::begin(compar), std::end(compar), this->_lCartes[choice-1]) == std::end(compar))){
                List_deck.push_back((this->_lCartes[choice-1]));
                ok = true;}}}
    while(ok){
        std::cout << "Choix du Gardien : indices = ";std::cin >> choice;
        if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0 && (this->_lCartes[choice-1]->getType()==gardien)){
            if((std::find(std::begin(compar), std::end(compar), this->_lCartes[choice-1]) == std::end(compar))){
                List_deck.push_back((this->_lCartes[choice-1]));
                ok = false;}}}
    for(int i = 0; i<4; i++){
        ok = true;
        while(ok){
            std::cout << "Choix des 4 Joueurs restants : indices = "; std::cin >> choice;
            if((std::find(std::begin(List_deck), std::end(List_deck), this->_lCartes[choice-1]) == std::end(List_deck)) && choice<=this->_lCartes.size() && choice>0  && (this->_lCartes[choice-1]->getType()==attaquant || this->_lCartes[choice-1]->getType()==defenseur)){
                if((std::find(std::begin(compar), std::end(compar), this->_lCartes[choice-1]) == std::end(compar))){
                    List_deck.push_back((this->_lCartes[choice-1]));
                    ok = false;}}}}
    std::string nom;std::cout << "Nom du Deck : " << std::flush;std::cin >> nom;if(nom.length()<8){nom+="        ";};
    Deck newDeck(nom, List_deck);
    return newDeck;
}

void Joueur::affichage() const{
    std::cout<<"Joueur : "<<_nom<<"\n"<<std::endl;
    int i = 1;
    for(const auto& ptCarte : _lCartes){
        std::cout<<std::to_string(i)<<") "<<std::flush;
        ptCarte->affichage();
        i++;
    }
}

//check