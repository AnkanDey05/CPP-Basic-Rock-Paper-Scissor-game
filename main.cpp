#include <iostream>
#include <string>
#include <cstdlib>
#include <optional>
#include <iomanip>
#include "Functions.h"
int main() {
    int player_score{};
    int com_score{};
    bool in_game{false};
    int command=menu(in_game);
       while (command==1)
        {
        Moves player=get_player_move();
       char winner= get_winner(player);
        calculate_score(player_score,com_score,winner);
        std::cout<<"\nYour Score: "<<player_score;
        std::cout<<std::setw(15)<<" | ";
        std::cout<<std::setw(15)<<"Computer Score: "<<com_score<<"\n"<<std::endl;
        command=menu(in_game);
        }
    return 0;

}