#include "Player.h"

Player::Player(const Player& p){
    name = p.name;
    num_of_cards = p.num_of_cards;
    for(int i = 0; i < p.cardsVec.size(); i++)
    {
        cardsVec.push_back(p.cardsVec.at(i));
    }
}

Player& Player::operator= (const Player& player){
    num_of_cards = player.num_of_cards;
    name = player.name;
    cardsVec.clear();
    for(int i = 0; i < player.cardsVec.size(); i++)
    {
        cardsVec.push_back(player.cardsVec.at(i));
    }
    return *this;
}

void Player::generateCards(const int& num_of_cards){
    for (int i = 0; i < num_of_cards; i++) {
        this->cardsVec.push_back(Card::generate_card());
    }
}

bool Player::play(Card& card){ 
    cout << "current: " << card << endl;

    auto x = 0;
    cout << name << " your turn - ";
    
    cout << "\nYour cards: ";
    for(int i = 0; i < num_of_cards; i++)
    {
        cout << "(" + to_string((long long)(i+1)) + ")" << this->cardsVec.at(i) << " ";
    }
    cout << endl;
    
    while(true){
        cin >> x;
        if(x == 0){
            num_of_cards++;
            this->cardsVec.push_back(Card::generate_card());
            break;
        }
        else if(x < 0){
            cout << "wrong input, cant accept negative numbers, please enter again" << endl;
        }
        else if(x > 0){
            if(x > num_of_cards){
                cout << "wrong input, no such card exists, please enter again" << endl;
            }
            else if(!card.is_legal(cardsVec.at(x-1))){
                cout << "illegal card, please enter again" << endl;
            }
            else{
                card = cardsVec.at(x-1);
                curr_sign = card.get_sign();
                cardsVec.erase(cardsVec.begin() + x - 1);
                num_of_cards--;
                return false;
            }
        }
    }
   

    return true;
    

}

