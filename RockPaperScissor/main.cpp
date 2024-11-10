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

struct Player
{
    int choice;
    int score = 0;
};

// If else statement solution
void choiceCheck(Player& _player, Player& _cpu)
{
    if (_player.choice == _cpu.choice)
    {
        std::cout << "It's a draw!\n";
    }
    else if(_player.choice == 1 && _cpu.choice == 3)
    {
        std::cout << "It's a win for the Player!\n" << std::endl;
        _player.score++;
    }
    else if(_player.choice == 1 && _cpu.choice == 2)
    {
        std::cout << "It's a win for the CPU!\n" << std::endl;
        _cpu.score++;
    }
    else if(_player.choice == 2 && _cpu.choice == 1)
    {
        std::cout << "It's a win for the Player\n" << std::endl;
        _player.score++;
    }
    else if(_player.choice == 2 && _cpu.choice == 3)
    {
        std::cout << "It's a win for the CPU!\n" << std::endl;
        _cpu.score++;
    }
    else if(_player.choice == 3 && _cpu.choice == 2)
    {
        std::cout << "It's a win for the Player\n" << std::endl;
        _player.score++;
    }
    else if(_player.choice == 3 && _cpu.choice == 1)
    {
        std::cout << "It's a win for the CPU!\n" << std::endl;
        _cpu.score++;
    }
    else
    {
    }
    
};

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
        std::cout << " Player wins!";
    }
    else if (player.score < CPU.score)
    {
        std::cout << " CPU wins!";
    }
    else
    {
        std::cout << " It's a draw";
    }
    
    return 0;
}

