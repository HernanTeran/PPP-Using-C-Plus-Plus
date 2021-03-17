// Rock, Paper, Scissors
// Author: Hernan Teran
// Created on: 2021/03/17

#include <iostream>
#include <random>

using namespace std;

enum class RPS { Rock = 0, Paper, Scissors };

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rand(1, 3);

    int player{ 0 }, computer{ 0 }, player_pts{ 0 }, computer_pts{ 0 };
    const int MAX_PTS{ 3 };
    bool GAME_OVER{ false };

    while (!GAME_OVER)
    {
        RPS computer_draw{}, player_draw{};
        computer = rand(gen);
        cout << "Rock! Paper! Scissors!\n"
             << "Your turn (1=Rock, 2=Paper, 3=Scissors): ";
        cin >> player;
        cout << "Shoot!\n\n";

        switch (computer)
        {
        case 1:
            computer_draw = RPS::Rock;
            player_draw = RPS::Rock;
            break;
        case 2:
            computer_draw = RPS::Paper;
            player_draw = RPS::Paper;
            break;
        case 3:
            computer_draw = RPS::Scissors;
            player_draw = RPS::Scissors;
            break;
        default:
            break;
        }

        switch (player)
        {
        case 1:
            player_draw = RPS::Rock;
            break;
        case 2:
            player_draw = RPS::Paper;
            break;
        case 3:
            player_draw = RPS::Scissors;
            break;
        default:
            break;
        }

        switch (player_draw)
        {
        case RPS::Rock:
            if (computer_draw == RPS::Paper) { ++computer_pts; }
            if (computer_draw == RPS::Scissors) { ++player_pts; }
            break;
        case RPS::Paper:
            if (computer_draw == RPS::Rock) { ++player_pts; }
            if (computer_draw == RPS::Scissors) { ++computer_pts; }
            break;
        case RPS::Scissors:
            if (computer_draw == RPS::Rock) { ++computer_pts; }
            if (computer_draw == RPS::Paper) { ++player_pts; }
            break;
        default:
            break;
        }

        if (player_pts == MAX_PTS && computer_pts < MAX_PTS) { GAME_OVER = true; }
        if (computer_pts == MAX_PTS && player_pts < MAX_PTS) { GAME_OVER = true; }
    }

    if (player_pts > computer_pts)
    { 
        cout << "You won! The score is " << player_pts << '-' << computer_pts << '.' << endl;
    }
    else
    {
        cout << "The computer won! The score is " << computer_pts << '-' << player_pts << '.' << endl;
    }

	return 0;
}
