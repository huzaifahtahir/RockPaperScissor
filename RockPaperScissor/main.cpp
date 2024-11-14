//
//  main.cpp
//  RockPaperScissor
//
//  Created by Huzaifah Tahir on 11/10/24.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <unordered_map>

struct Player
{
    int choice;
    int score = 0;
};

void choiceCheck(Player& _player, Player& _cpu)
{
    std::unordered_map<int, int> winConditions = {
        {1,3}, // Rock beat scissors
        {2,1}, // Paper beats rock
        {3,2} // Scissor beats paper
    };
    
    if (_player.choice == _cpu.choice)
    {
        std::cout << "It's a draw!\n";
    }
    else if (winConditions[_player.choice] == _cpu.choice)
    {
        std::cout << "It's a win for the Player!\n" << std::endl;
        _player.score++;
    } else {
        std::cout << "It's a win for the CPU!\n" << std::endl;
        _cpu.score++;
    }
}




int main(int argc, const char * argv[]) {
    // insert code here...
    int numOfRounds = 0;
    std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;
    std::cout << "How many rounds would you like to play: ";
    std::cin >> numOfRounds;
    std::cout << "Perfect. " << numOfRounds << " it is!\n";
    
    Player player;
    Player CPU;
    //Create random device
    std::random_device rd;
    // Use random_device for generating seed
    std::mt19937 gen(rd());
    // Define a int range
    std::uniform_int_distribution<int> dist(1,3);
    
    
    for (int i  = 0; i < numOfRounds; i++) {
        std::cout << "(1) for Rock, (2) for Paper, (3) for scissors.\nWhat is your choice: ";
        std::cin >> player.choice;
        CPU.choice = dist(gen);
        choiceCheck(player, CPU);
    }
    
    std::cout << "You had a score of " << player.score << " & CPU had a score of " << CPU.score << ".";
    if (player.score > CPU.score)
    {
        std::cout << " Player wins!\n";
    }
    else if (player.score < CPU.score)
    {
        std::cout << " CPU wins!\n";
    }
    else
    {
        std::cout << " It's a draw\n";
    }
    
    return 0;
}

