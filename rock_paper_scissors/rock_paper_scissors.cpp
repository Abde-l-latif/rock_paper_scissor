#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum egame { rock = 1 , paper , scissor };
int get_random_number(int from , int to)
{
    int random = rand() % (to - from + 1) + from;
    return random;
}
short int get_rounds()
{
    short int round = 0;
    do {
        cout << "How many rounds do you wanna play from 1 to 10 ... : ";
        cin >> round;
    } while (round > 10 || round <= 0);
    return round;
}
egame player_choice()
{
    short int num = 0;
    egame choice;
    do {
       cout << "your choice : press [1] rock , [2] paper , [3] scissor : ";
       cin >> num; 
    } while (num <= 0 || num > 3);
    choice = (egame)num;
    return choice;
}
egame computer_choice()
{
    egame computer_choice = (egame)get_random_number(1, 3);
    return computer_choice;
}
string check_choice(egame choice)
{
    switch (choice)
    {
    case egame::paper :
        return "paper";
    case egame::rock:
        return "rock";
    case egame::scissor:
        return "scissor";
    default:
        return "inknown";
    }
}
string check_winner(egame player, egame computer , short int& player_win, short int& computer_win , short int& draw)
{
    if (player == egame::paper && computer == egame::rock ||
        player == egame::scissor && computer == egame::paper ||
        player == egame::rock && computer == egame::scissor)
    {
        system("color 27");
        player_win++;
        return "[player]";
    }
    else if (computer == egame::paper && player == egame::rock ||
        computer == egame::scissor && player == egame::paper ||
        computer == egame::rock && player == egame::scissor)
    {
        cout << '\a';
        system("color 47");
        computer_win++;
        return "[computer]";
    }
    else {
        system("color 60");
        draw++;
        return "[no winner]";
    }
}
void round_info(egame player , egame computer , short int round, short int& player_win, short int& computer_win , short int& draw)
{
    cout << "\n" << endl;
    cout << "_____________________ ROUND " << round << " _____________________" << endl;
    cout << "\n" << endl;
    cout << "player choice : " << check_choice(player) << endl;
    cout << "computer choice : " << check_choice(computer) << endl;
    cout << "the winner is : " << check_winner(player , computer , player_win , computer_win , draw) << endl;
    cout << "\n" << endl;
    cout << "____________________________________________________" << endl;
    cout << "\n" << endl;
}
void game_start(short int& player_win , short int& computer_win , short int& draw , short int round)
{
    for (short int i = 1; i <= round; i++)
    {
        cout << "Round [" << i << "] begins : " << endl;
        egame player = player_choice();
        egame computer = computer_choice();
        round_info(player, computer , i , player_win , computer_win , draw);
    }
}
void game_over(short int player_win, short int computer_win, short int draw , short int round , string& final_winner)
{
    if (computer_win > player_win) {
        system("color 47");
        final_winner = "Computer";
    }
    else if (computer_win < player_win) {
        system("color 27");
        final_winner = "Player";
    }
    else {
        system("color 60");
        final_winner = "No winner";
    }
    cout << "\t\t  _______________________________________________________________________  \t\t\n\n";
    cout << "\t\t                           +++ GAME OVER +++                          \t\t" << endl;
    cout << "\t\t  _______________________________________________________________________  \t\t\n\n";
    cout << "\t\t  _________________________ [ GAME RESULTS ] ________________________  \t\t\n\n";
    cout << "\t\t  Game rounds              : " << round << endl ;
    cout << "\t\t  Player won times         : " << player_win << endl;
    cout << "\t\t  Computer won times       : " << computer_win << endl;
    cout << "\t\t  Draw times               : " << draw << endl;
    cout << "\t\t  Final winner             : " << final_winner << endl;
    cout << "\t\t  _______________________________________________________________________  \t\t\n\n";
}
void play()
{
    char repeat = 'n';
    do {
        short int round = get_rounds(), draw = 0, computer_win = 0, player_win = 0;
        string final_winner = "";
        game_start(player_win, computer_win, draw, round);
        game_over(player_win, computer_win, draw, round, final_winner);
        cout << "Do you want to play again y/n : ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    play();
    return 0;
}
