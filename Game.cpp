#include "Game.h"
#include <iostream>

void Game::start(){
        bool winner = false;
        int steps_to_move;
        Player player;

        cout << "How many players?"<<endl;
        cin  >> num_of_players;

        cout << "How many cards?"<<endl;
        cin  >> init_num_of_cards;
        
        for(int i = 0; i < num_of_players; i++)
        {
                string name;
                cout << "player number " << (i+1) << " name?" << endl;
                cin >> name;
                players.emplace_back(name, init_num_of_cards);
                players.at(i).generateCards(init_num_of_cards);
        }

        Card openCard;
        while(true){
                openCard = Card::generate_card();
                if(openCard.get_sign() == sign::CD || openCard.get_sign() == sign::STOP || openCard.get_sign() == sign::PLUS)
                        openCard = Card::generate_card();
                else
                        break;
        }
        
        while(!winner){
                
                steps_to_move = 1;
                // Start current player's turn
	        players.at(turn).play(openCard);

                 if(players.at(turn).getNumOfCards()==0){
                         cout<<players.at(turn).getname()<<" wins!"<<endl;
                         winner=true;
                 }

                // If current player used a CD card, Flip the direction of the game then move to the next turn
		if (players.at(turn).getCurr_sign() == sign::CD)
                {
			direction = -direction;
		}

                // If current player used a STOP card, Move two turns forward
		else if (players.at(turn).getCurr_sign() == sign::STOP) 
                {
			steps_to_move = 2;
		}

                // If player used a PLUS card, The turn will not be changed and he will get another turn
		else if (players.at(turn).getCurr_sign() == sign::PLUS)
                {
			steps_to_move = 0;
		}
                
                turn = turn + direction*steps_to_move;

                if (turn >= 0)
                {
                        turn = turn % num_of_players;
                }
                else
                {
                        while(turn < 0)
                        {
                                turn += this->num_of_players;
                        }
	        }

                players.at(turn).reset_curr_sign();
                

        }  
}

