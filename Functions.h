enum class Moves{
    Rock,
    Paper,
    Scissor,
    None,
};
int random(int max=100, int min=0);
Moves get_player_move();
char get_winner(Moves player_move);
void calculate_score(int& ref_player_score, int& ref_computer_score, char& winner);
int menu(bool& ingame);