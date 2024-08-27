/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Game.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Zehuan yu, Raymond Tao
 * zehuanyu, taosa
 *
 * Project 4: Battleship
 *
 * This Game.cpp relates the functions we've written in different classes before. Judge the winner in each round of the game and the specific game flow. It also decides whether to end the game and determine the winner
 */

#include <fstream>

#include "Game.h"

// This is the default Game function for setting both p1 and p2 default-constructed player.
Game::Game() {
    p1 = Player();
    p2 = Player();
    
}

//This is the non-default constructor. Sets p1 to player1 and p2 to player2.
Game::Game(Player player1, string grid1, Player player2, string grid2) {
    p1 = player1;
    p2 = player2;
    if (grid1 != "") {
        p1.load_grid_file(grid1);
    }
    else if ((grid1 == "") || (!p1.load_grid_file(grid1))) {
        generate_random_grid(p1);
        cout << "Generating random grid for " << p1.get_name() << endl;
    }
    if (grid2 != "") {
        p2.load_grid_file(grid2);
    }
    else if ((grid2 == "") || (!p2.load_grid_file(grid2))){
        generate_random_grid(p2);
        cout << "Generating random grid for " << p2.get_name() << endl;
    }
}

//This function returns p1.
Player Game::get_p1() {
    return p1;
}

//This function returns p2.
Player Game::get_p2() {
    return p2;
}

//This function prompts the user for the user's name and returns the name.
string Game::get_move(string player_name) {
    cout << player_name << " enter your move:" << endl;
    string input;
    cin >> input;
    return input;
}


//This function check whether the move entered by player is valid or not.
bool Game::check_valid_move(string move) {
    bool valid = true;
    int row_num = (int)move[0];
    int col_num = (int)toupper(move[1]);
    if (move.size() != 2) {
        valid = false;
        cout << p1.get_name() << " you entered an invalid input" << endl;
    }
    else if ((row_num < '1') || (row_num > '8') ||
             (col_num < (int)'A') || (col_num > (int)'H')) {
        valid = false;
        cout << p1.get_name() << " you entered an invalid position" << endl;
    }
    else {
        valid = true;
    }
    return valid;
}

//This function starts the game with the difficulty choosing by the player. It prints the grid for both players and concludes who is the winner of the game within the maximum number of rounds.
void Game::start(char difficulty, int max_num_rounds) {
    int round = 1;
    while (!p1.destroyed() && !p2.destroyed() && (round <= max_num_rounds)) {
        string move = get_move(p1.get_name());
        while (!check_valid_move(move)) {
            move = get_move(p1.get_name());
        }
        Position attackPosition(move[0], move[1]);
        p1.attack(p2, attackPosition);
        if (p2.destroyed()) {
            cout << endl;
            cout << "Your grid" << endl << endl;
            p1.print_grid();
            cout << p2.get_name() << "'s grid" << endl << endl;
            p1.print_guess_grid();
            cout << endl;
            cout << "Game over, winner is " << p1.get_name() << " in " <<
            round << " rounds" << endl;
            return;
        }
        opponent_make_move(difficulty);
        cout << endl;
        cout << "Your grid" << endl;
        cout << endl;
        p1.print_grid();
        cout << p2.get_name() << "'s grid" << endl;
        cout << endl;
        p1.print_guess_grid();
        if (p1.destroyed()) {
            cout << endl;
            cout << "Game over, winner is " << p2.get_name() << " in " <<
            round << " rounds" << endl;
            return;
        }
        round += 1;
    }
    cout << endl;
    cout << "Game over, winner is no one in " << max_num_rounds << " rounds";
    return;
}
// Your code goes above this line.
// Don't change the implementations below!

void Game::generate_random_grid(Player &p) {
    // grid to check which position has been taken
    bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = {{false}};

    for (int k = 0; k < 10 && p.get_num_ships() < 5; k++) {
        // i is the length of the ship to be made
        // decrementing i to create 2 ships of size 3
        int i = p.get_num_ships() + 1;
        if (i > 2) {
            i--;
        }

        // generate random position 1
        int row = get_random_number() % MAX_GRID_SIZE;
        int col = get_random_number() % MAX_GRID_SIZE;
        Position pos1(row, col);

        if (!grid[row][col]) {
            Position pos2;
            // Check if creating position two is not off the grid relative to
            // position 1 inthe order of bottom, right, left, top
            if (row + i < MAX_GRID_SIZE) {
                pos2 = Position(row + i, col);
            } else if (col + i < MAX_GRID_SIZE) {
                pos2 = Position(row, col + i);
            } else if (col - i >= 0) {
                pos2 = Position(row, col - i);
            } else if (row - i >= 0) {
                pos2 = Position(row - i, col);
            } else {
                continue;
            }

            Ship s(pos1, pos2);

            bool pos2_taken = false;
            if (s.is_horizontal()) {
                // start and end depends on if pos1 is to the left of pos2
                int start = pos1.get_col() < pos2.get_col() ?
                            pos1.get_col() : pos2.get_col();
                int end = pos1.get_col() < pos2.get_col() ?
                          pos2.get_col() : pos1.get_col();
                // Loop through start and end to check if any of the positions
                // has been taken
                for (int j = start; j <= end; j++) {
                    // break out of the loop if any of the position is taken
                    if (grid[pos1.get_row()][j]) {
                        pos2_taken = true;
                        break;
                    }
                }

                // If none of the positions were taken, set them as taken
                for (int j = start; j <= end; j++) {
                    grid[pos1.get_row()][j] = true;
                }
            } else {
                // start and end depends on if pos1 is to the left of pos2
                int start = pos1.get_row() < pos2.get_row() ?
                            pos1.get_row() : pos2.get_row();
                int end = pos1.get_row() < pos2.get_row() ?
                          pos2.get_row() : pos1.get_row();
                // Loop through start and end to check if any of the positions
                // has been taken
                for (int j = start; j <= end; j++) {
                    // break out of the loop if any of the position is taken
                    if (grid[j][pos1.get_col()]) {
                        pos2_taken = true;
                        break;
                    }
                }

                // If none of the positions were taken, set them as taken
                for (int j = start; j <= end; j++) {
                    grid[j][pos1.get_col()] = true;
                }
            }

            // Restart from beginning
            if (pos2_taken) {
                continue;
            }

            // Add the ship to p2's ships
            p.add_ship(s);
        }
    }
}

void Game::opponent_make_move(char difficulty) {
    if (difficulty == EMULATE) {
        Position next;
        cout << "Enter CPU emulation move: ";
        cin >> next;
        cout << endl;
        p2.attack(p1, next);
        cout << "You received an attack at " << next << endl << endl;
    } else if (difficulty == EASY) {
#ifndef NOCPU
        int randRow = get_random_number() % MAX_GRID_SIZE;
        int randCol = get_random_number() % MAX_GRID_SIZE;
        Position randCoord(randRow, randCol);
        p2.attack(p1, randCoord);
        cout << "You received an attack at " << randCoord << endl << endl;
#else
        Position next;
        cin >> next;
        if (cin.fail()) {
            cin.clear();
            next = Position(7, 4);
        }
        p2.attack(p1, next);
        cout << "You received an attack at " << next << endl << endl;
#endif
    } else if (difficulty == MEDIUM) {
        // Simple AI that checks right, bottom, left, top of hit position
        // TODO: implement for S'more version
    }
}

