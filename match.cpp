#include "match.hpp"

Match::Match(Deck* deck1, Deck* deck2){
    this->_lDeck.clear();
    this->_lDeck.push_back(deck1);
    this->_lDeck.push_back(deck2);
}

void Match::result(){
    int scoreA = (((_lDeck.front())->getAttaque()) - ((_lDeck.back())->getDefense())) / ((_lDeck.back())->getGoal());
    int scoreB = (((_lDeck.back())->getAttaque()) - ((_lDeck.front())->getDefense())) / ((_lDeck.front())->getGoal());
    if(scoreA==scoreB){//Si égalité on départage en fonction du charisme
        if(((_lDeck.front())->getCharisme())>((_lDeck.back())->getCharisme())){
            scoreA++;}
        else if(((_lDeck.front())->getCharisme())<((_lDeck.back())->getCharisme())){
            scoreB++;}
        else{//si égalité on départage en fonction du gardien
            if(((_lDeck.front())->getGoal())>((_lDeck.back())->getGoal())){
                scoreA++;}
            else if(((_lDeck.front())->getGoal())<((_lDeck.back())->getGoal())){
                scoreB++;}
            else{//si égalité on départage en fonction de l'attaque
                if(((_lDeck.front())->getAttaque())>((_lDeck.back())->getAttaque())){
                    scoreA++;}
                else{
                    scoreB++;}}}}
    this->_resultat.clear();
    this->_resultat.insert({ {_lDeck.front(), scoreA}, {_lDeck.back(), scoreB} });
}

Deck* Match::getWinnerMatch(){
    std::cout<<this->_lDeck.front()->getNom()<<" "<<std::to_string(this->_resultat.at(this->_lDeck.front()))<<" - "<<std::to_string(this->_resultat.at(this->_lDeck.back()))<<" "<<this->_lDeck.back()->getNom()<<std::endl;
    if(this->_resultat.at(this->_lDeck.front()) > this->_resultat.at(this->_lDeck.back())){
        return this->_lDeck.front();
    }
    else{
        return this->_lDeck.back();
    }
}

Deck* Match::getDeck(int indice){
    if(indice){
        return this->_lDeck.back();
    }
    else{
        return this->_lDeck.front();
    }
}

//check