/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Player.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Zehuan yu, Raymond Tao
 * zehuanyu, taosa
 *
 * Project 4: Battleship
 *
 * This player cpp. mostly with all the information that a plaer need for the game. Including adding the ship,
 * attack the opponent, and announcement.
 */

#include <fstream>

#include "Player.h"


// This is the default Player function for setting everything to 0.
Player::Player() {
    name = "";
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}


// This is the function for non-default, setting the name to name_val.
Player::Player(string name_val) {
    name = name_val;
    num_ships = 0;
    remaining_ships = 0;
    init_grid();
}


// This function will set every element in grid and guess grid with empty
// letter.
void Player::init_grid() {
    for (int i = 0; i < MAX_GRID_SIZE; i++) {
        for (int j = 0; j < MAX_GRID_SIZE; j++) {
            grid[i][j] = EMPTY_LETTER;
            guess_grid[i][j] = EMPTY_LETTER;
        }
    }
    return;
}


// This function return the name of the player.
string Player::get_name() {
   
    return name;
}



// This function return the number of ships of the player.
int Player::get_num_ships() {
    return num_ships;
}



// This function return the number of remaining ships of the player.
int Player::get_remaining_ships() {
    return remaining_ships;
}


// This function return the element with the input index of the grid.
char Player::get_grid_at(int row, int col) {
    return grid[row][col];
}


// This function return the element with the input index of the guess grid.
char Player::get_guess_grid_at(int row, int col) {
    return guess_grid[row][col];
}


//This function will add the ships until it reach the maximum number of ships.
void Player::add_ship(Ship ship) {
    if (num_ships == MAX_NUM_SHIPS) {
        return;
    }
    else if (num_ships < MAX_NUM_SHIPS) {
        ships[num_ships] = ship;
        num_ships += 1;
        remaining_ships +=1;
        if (ship.is_horizontal()){
            if (ship.get_start().get_col() < ship.get_end().get_col()) {
                int i = ship.get_start().get_col();
                while (i <= ship.get_end().get_col()) {
                    grid[ship.get_start().get_row()][i] = SHIP_LETTER;
                    i += 1;
                }
            }
            else {
                int i = ship.get_end().get_col();
                while (i <= ship.get_start().get_col()) {
                    grid[ship.get_end().get_row()][i] = SHIP_LETTER;
                    i += 1;
                }
            }
        }
        else {
            if (ship.get_start().get_row() < ship.get_end().get_row()) {
                int i = ship.get_start().get_row();
                while (i <= ship.get_end().get_row()) {
                    grid[i][ship.get_start().get_col()] = SHIP_LETTER;
                    i += 1;
                }
            }
            else {
                int i = ship.get_end().get_row();
                while (i <= ship.get_start().get_row()) {
                    grid[i][ship.get_start().get_col()] = SHIP_LETTER;
                    i += 1;
                }
            }
        }
        
    }
}


// This function will get a position of attack, and then attack the opponent's
// grid. Mark hit letter if hit, and miss letter if the position has already
// hitted or missed.
void Player::attack(Player &opponent, Position pos) {
    bool record = false;
    const int status = -1;
    int n = status;
    for (int i = 0; i < opponent.get_num_ships(); i++) {
        if (opponent.ships[i].has_position(pos)) {
            n = i;
            if (guess_grid[pos.get_row()][pos.get_col()] != EMPTY_LETTER) {
                record = false;
            }
            else {
                record = true;
                opponent.grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
                guess_grid[pos.get_row()][pos.get_col()] = HIT_LETTER;
                opponent.ships[n].hit();
            }
        }
    }
    if (record) {
        cout << get_name() << " (" << pos.get_row() + 1 << "," <<
        (char)(pos.get_col() + (int)'A') << ") hit" << endl;
        if (opponent.ships[n].has_sunk()) {
            opponent.remaining_ships -= 1;
            announce_ship_sunk(opponent.ships[n].get_size());
        }
    }
    else {
        opponent.grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        guess_grid[pos.get_row()][pos.get_col()] = MISS_LETTER;
        cout << get_name() << " (" << pos.get_row() + 1 << "," <<
        (char)(pos.get_col() + (int)'A') << ") miss" << endl;
    }
}



// This function will annouce which type of ship has sunk depending on its size
void Player::announce_ship_sunk(int size) {
    if (size == 2) {
        cout << "Congratulations "  << name << "! You sunk a Destroyer" <<
        endl;
    }
    else if (size == 3) {
        cout << "Congratulations "  << name << "! You sunk a Submarine" <<
        endl;
    }
    else if (size == 4) {
        cout << "Congratulations "  << name << "! You sunk a Battleship" <<
        endl;
    }
    else if (size == 5) {
        cout << "Congratulations "  << name << "! You sunk a Carrier" <<
        endl;
    }
}



// This function will read the start and end position for the ships.
bool Player::load_grid_file(string filename) {
    ifstream ins;
    Position start_pos;
    Position end_pos;
    ins.open(filename);
    if (ins.is_open()) {
        ins >> start_pos >> end_pos;
        while (!ins.fail()) {
            Ship Ship(start_pos, end_pos);
            add_ship(Ship);
            ins >> start_pos >> end_pos;
        }
        return true;
    }
    else {
        return false;
    }
}

// This function will check if the remaining ship is 0 or not.
bool Player::destroyed() {
    if (remaining_ships == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

void Player::print_grid() {
    ::print_grid(grid);
}

void Player::print_guess_grid() {
    ::print_grid(guess_grid);
}
