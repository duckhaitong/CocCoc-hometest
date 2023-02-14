//
//  Game.cpp
//  RobotMovement
//
//  Created by Tong Duc Khai on 2/13/23.
//

#include "Game.hpp"
namespace CocCoc
{
Game::Game(string input_file) : input_file_(input_file) {
    robot = std::make_unique<Robot>(0, 0);
    console_grid = std::make_unique<ConsoleGrid>();
    this->Run();
}

vector<string> Game::parseFileToCommands(string input_file) {
    ifstream input;
    input.open(input_file.c_str());
    
    if (!input.good()) {
        cerr << "Error: " << input_file << ": " << strerror(errno) << endl;
        exit(EXIT_FAILURE);
    }
    
    ofstream output;
    vector<string> commands;
    
    while (!input.eof()) {
        string command;
        getline(input, command);
        
        if (command.size() > 0) {
            commands.push_back(command);
        }
    }
    
    input.close();
    return commands;
}

vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> elems;
    
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    
    return elems;
}

void Game::Run() {
    vector<string> commands = this->parseFileToCommands(this->input_file_);
    vector<string> elems = split(commands[0], ' ');
    const int size = stoi(elems.back());
    this->console_grid->initiateGrid(size);
    
    commands.erase(commands.begin());
    
    for (auto &command : commands) {
        string cmd = split(command, ' ')[0];
        string pos = split(command, ' ')[1];
        int x = stoi(split(pos, ',')[0]);
        int y = stoi(split(pos, ',')[1]);
        if (cmd == "MOVE_TO") {
            this->robot->moveTo(x, y, this->console_grid);
        }
        if (cmd == "LINE_TO") {
            this->robot->lineTo(x, y, this->console_grid);
        }
    }
    
    this->console_grid->output();
}
}
