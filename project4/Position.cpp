/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Zehuan yu, Raymond Tao
 * zehuanyu, taosa
 *
 * Project 4: Battleship
 *
 * This file is focusing on the position. Which will include if the coordinates is valid in the grid or not, if the
 * input index is valid, and read the file for the position for further uses in ship and game.
 */

#include "Position.h"
#include "utility.h"

// Default for the position, row and col to 0.
Position::Position() {
    row = 0;
    col = 0;
    return;
}

// Non-default for postion.
Position::Position(int row_in, int col_in) {
    row = Position::check_range(row_in);
    col = Position::check_range(col_in);
    
}

// Non-default for position
Position::Position(char row_in, char col_in) {
    row = Position::check_range((int)row_in - (int)'1');
    col_in = toupper(col_in);
    col = Position::check_range((int)col_in - (int)'A');
}

// Get the row
int Position::get_row() {
    return row;
}

// Set the row
void Position::set_row(int row_in) {
    row = Position::check_range(row_in);
}

// Get the col
int Position::get_col() {
    return col;
}

// Set the col
void Position::set_col(int col_in) {
    col = Position::check_range(col_in);

}

// Reading the position from the file.
void Position::read(istream &is) {
    int rowin = 0;
    char colin;
    is >> rowin >> colin;
    if (is.fail()) {
        is.clear();
        char junk;
        is >> junk >> rowin >> junk >> colin >> junk;
    }
    row = Position::check_range(rowin - 1);
    colin = toupper(colin);
    col = Position::check_range((int)colin - (int)'A');
}

// Output for the correct format of the position
void Position::write(ostream &os) {
    os << "(" << row + 1 << "," << (char)(col + (int)'A') << ")";
}

// Check if the position is in the grid size or not.
int Position::check_range(int val) {
    if ((val >= 0) && (val < MAX_GRID_SIZE)) {
        val = val;
    }
    else {
        if (abs(val - 0) < abs(val - (MAX_GRID_SIZE - 1))) {
            val = 0;
        }
        else {
            val = MAX_GRID_SIZE - 1;
        }
    }
    return val;
}


// Your code goes above this line.
// Don't change the implementations below!

istream &operator>>(istream &is,  Position &pos) {
    pos.read(is);
    return is;
}

ostream &operator<<(ostream &os, Position pos) {
    pos.write(os);
    return os;
}

