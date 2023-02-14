//
//  Game.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>

namespace CocCoc
{
Game::Game(std::string input_file) : input_file_(input_file) {
    robot = std::make_unique<Robot>(0, 0);
    console_grid = std::make_unique<ConsoleGrid>();
    Run();
}

std::vector<std::string> Game::parseFileToCommands(std::string input_file) {
    std::ifstream input;
    input.open(input_file.c_str());
    
    if (!input.good()) {
        std::cerr << "Error: " << input_file << ": " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::ofstream output;
    std::vector<std::string> commands;
    
    while (!input.eof()) {
        std::string command;
        getline(input, command);
        
        if (command.size() > 0) {
            commands.push_back(command);
        }
    }
    
    input.close();
    return commands;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> elems;
    
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    
    return elems;
}

void Game::Run() {
    std::vector<std::string> commands = parseFileToCommands(input_file_);
    std::vector<std::string> elems = split(commands[0], ' ');
    const int size = stoi(elems.back());
    console_grid->initiateGrid(size);
    
    commands.erase(commands.begin()); // remove DIMENSION command
    
    for (auto &command : commands) {
        std::string cmd = split(command, ' ')[0];
        std::string pos = split(command, ' ')[1];
        try {
            int x = stoi(split(pos, ',')[0]);
            int y = stoi(split(pos, ',')[1]);
            if (x < 0 || y < 0 || x >= size || y >= size) {
                throw std::invalid_argument("Invalid position.");
            }
            if (cmd == "MOVE_TO") {
                robot->moveTo(x, y, console_grid);
            }
            if (cmd == "LINE_TO") {
                robot->lineTo(x, y, console_grid);
            }
        } catch (std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    
    console_grid->output();
}
}
