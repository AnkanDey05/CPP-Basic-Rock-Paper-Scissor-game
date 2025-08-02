#include <iostream>
#include <string>
#include <cstdlib>
#include <optional>
#include <iomanip>
using namespace std;
#define BBLACK "\033[1;30m"
#define BRED "\033[1;31m"
#define BGREEN "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE "\033[1;34m"
#define BMAGENTA "\033[1;35m"
#define BCYAN "\033[1;36m"
#define BWHITE "\033[1;37m"
#define RESET "\033[0m"
int random(int max = 100, int min = 0)
{
    int random_number{};
    srand(time(NULL));
    random_number = (min + rand() % (max - min + 1));
    return random_number;
}
enum class Moves
{
    Rock,
    Paper,
    Scissor,
    None,
};
int valided_cin(int input, int range){
    cin >> input;
    while (cin.fail()|| input>=range)
    {
        cin.clear();
        std::cin.ignore(1000, '\n');  
        cerr<<"Invalid Input\n";
        cerr<<"Try again: ";
        cin>>input;
    }
    return input;
}
Moves get_computer_move()
{
    int value = random(3, 1);
    switch (value)
    {
    case 1:
        return Moves::Paper;
        break;
    case 2:
        return Moves::Rock;
        break;
    case 3:
        return Moves::Scissor;
        break;
    default:
        return Moves::None;
        break;
    }
}
string enum_to_string(Moves move){
    switch (move)
    {
    case Moves::Rock:
        return "Rock";
        break;
    case Moves::Paper:
        return "Paper";
        break;
    case Moves::Scissor:
        return "Scissor";
        break;
    default:
        return "None";
        break;
    }
}
Moves get_player_move()
{
    int move{};
    while (true)
    {   
        cout << "Chose Your Move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissor\n";
        move=valided_cin(move,4);
        system("cls");
        switch (move)
        {
        case 1:
            return Moves::Rock;
            break;
        case 2:
            return Moves::Paper;
            break;
        case 3:
            return Moves::Scissor;
            break;
        default:
            return Moves::None;
            break;
        }
    }
}
char get_winner(Moves player_move)
{
    Moves computer_move = get_computer_move();
    if (player_move == computer_move)
    {   
        cout<<BBLUE<<"You Chose: "<<RESET<<enum_to_string(player_move)<<setw(20)<<BBLUE<<"Computer Chose:"<<RESET<<enum_to_string(computer_move)<<endl;
        cout<<BMAGENTA<<setw(10)<<"Result: Draw\n"<<RESET;
        return 'D';
    }
    else if (player_move == Moves::Paper && computer_move == Moves::Scissor ||
             player_move == Moves::Rock && computer_move == Moves::Paper ||
             player_move == Moves::Scissor && computer_move == Moves::Rock)
    {
        cout<<BBLUE<<"You Chose: "<<RESET<<enum_to_string(player_move)<<setw(20)<<BBLUE<<"Computer Chose:"<<RESET<<enum_to_string(computer_move)<<endl;
        cout<<BRED<<setw(10)<<"Result: Computer Wins\n"<<RESET;
        return 'C';
    }
    else
    {
        cout<<BBLUE<<"You Chose: "<<RESET<<enum_to_string(player_move)<<setw(20)<<BBLUE<<"Computer Chose:"<<RESET<<enum_to_string(computer_move)<<endl;
        cout<<BYELLOW<<setw(10)<<"Result: Player Wins\n"<<RESET;
        return 'P';
    }
}
void calculate_score(int &ref_player_score, int &ref_computer_score, char &winner)
{
    switch (winner)
    {
    case 'C':
        ++ref_computer_score;
        break;
    case 'P':
        ++ref_player_score;
        break;
    default:
        break;
    }
}
int menu(bool &ingame)
{
    int input;
    if (!ingame)
    {
        cout << "1. Play Vs Computer\n";
        cout << "2. Exit\n";
    }
    else{
        cout<<"1. Replay\n";
        cout<<"2. Exit\n";
    }
    input=valided_cin(input,3);
    system("cls");
    if (input==1)
    {
        ingame=true;
    }
    
    return input;
}
