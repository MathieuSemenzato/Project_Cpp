#include "tableau.hpp"

Tableau::Tableau(Joueur* joueur1, Joueur* joueur2){
    this->_match1 = Match(joueur1->getDeck(1), joueur2->getDeck(2));
    this->_match2 = Match(joueur1->getDeck(2), joueur2->getDeck(1));
    //this->_matchFIN = Match(this->_match1.getWinnerMatch(), this->_match2.getWinnerMatch());
    this->_lJoueur.clear();
    this->_lJoueur.push_back(joueur1);
    this->_lJoueur.push_back(joueur2);
}

Joueur* Tableau::getWinnerCup(){
    Deck* winner = this->_matchFIN.getWinnerMatch();
    for(auto iter = std::cbegin(this->_lJoueur); iter != std::cend(this->_lJoueur); iter=std::next(iter)){
        if(winner==(*iter)->getDeck(1)){
            return (*iter);
        }
        if(winner==(*iter)->getDeck(2)){
            return (*iter);
        }
    }
    return NULL;
}

void Tableau::affichage(int phase){
    if(phase==1){
        std::cout<<"[1]\t"<<(this->_match1.getDeck(0))->getNom()<<"\t----\n"<<"\t\t\t   |   \n"<<"\t\t\t   ----\t?????\t----\n"<<"\t\t\t   |   \t     \t   |"<<"\n[2]\t"<<(this->_match1.getDeck(1))->getNom()<<"\t----   \t     \t   |"<<"\n\t\t\t\t\t   |"<<"\n\t\t\t\t\t   ----\t?????"<<"\n\t\t\t\t\t   |"<<"\n[3]\t"<<(this->_match2.getDeck(0))->getNom()<<"\t----   \t     \t   |"<<"\n\t\t\t   |   \t     \t   |"<<"\n\t\t\t   ----\t?????\t----"<<"\n\t\t\t   |   "<<"\n[4]\t"<<(this->_match2.getDeck(1))->getNom()<<"\t----\n"<<std::endl;
    }
    else if(phase==2){
        std::cout<<"[1]\t"<<(this->_match1.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n[2]\t"<<(this->_match1.getDeck(1))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t\t\t\t   |"<<"\n\t\t\t\t\t\t   ----\t????"<<"\n\t\t\t\t\t\t   |"<<"\n[3]\t"<<(this->_match2.getDeck(0))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(1))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n[4]\t"<<(this->_match2.getDeck(1))->getNom()<<"\t----\n"<<std::endl;
    }
    else if(phase==3){
        std::string Nom = this->_matchFIN.getWinnerMatch()->getNom();
        std::cout<<"[1]\t"<<(this->_match1.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n[2]\t"<<(this->_match1.getDeck(1))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t\t\t\t   |"<<"\n\t\t\t\t\t\t   ----\t"<<Nom<<"\n\t\t\t\t\t\t   |"<<"\n[3]\t"<<(this->_match2.getDeck(0))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(1))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n[4]\t"<<(this->_match2.getDeck(1))->getNom()<<"\t----\n"<<std::endl;
    }
}

void Tableau::affichage(std::string Nom){
    std::cout<<"[1]\t"<<(this->_match1.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(0))->getNom()<<"\t----"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n[2]\t"<<(this->_match1.getDeck(1))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t\t\t\t   |"<<"\n\t\t\t\t\t\t   ----\t"<<Nom<<"\n\t\t\t\t\t\t   |"<<"\n[3]\t"<<(this->_match2.getDeck(0))->getNom()<<"\t----   \t     \t\t   |"<<"\n\t\t\t   |   \t     \t\t   |"<<"\n\t\t\t   ----\t"<<(this->_matchFIN.getDeck(1))->getNom()<<"\t----"<<"\n\t\t\t   |   "<<"\n[4]\t"<<(this->_match2.getDeck(1))->getNom()<<"\t----\n"<<std::endl;
}

//check