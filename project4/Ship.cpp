/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Zehuan yu, Raymond Tao
 * zehuanyu, taosa
 *
 * Project 4: Battleship
 *
 *  This file is addressing with the ship. Get the ship position, the number of ship get hits, and what is the
 *  suize of the ship. All of those elements will be addressed and get from this file.
 */

#include <cmath>

#include "Ship.h"


// Default, setting everything to 0.
Ship::Ship() {
    start.set_row(0);
    start.set_col(0);
    end.set_row(0);
    end.set_col(0);
    num_hits = 0;
    size = 0;
}

// Non0-default, set the start and end position with the input.
Ship::Ship(Position start_in, Position end_in) {
    start = start_in;
    end = end_in;
    num_hits = 0;
    if (is_horizontal()) {
        size = abs(start.get_col() - end.get_col()) + 1;
    }
    else {
        size = abs(start.get_row() - end.get_row()) + 1;
    }
}

// This function will return the start position
Position Ship::get_start() {
    return start;
}

// This function will return the end position.
Position Ship::get_end() {
    return end;
}

// This function will return the size of the ship.
int Ship::get_size() {
    return size;
}

// This function will check if the ship is on the same row.
bool Ship::is_horizontal() {
    if (start.get_row() == end.get_row()) {
        return true;
    }
    else {
        return false;
    }
}


// This function will check if the input positin is valid.
bool Ship::has_position(Position pos) {
    if (is_horizontal()) {
        if (start.get_col() <= end.get_col()) {
            if ((pos.get_row() == start.get_row()) &&
                (pos.get_col() >= start.get_col()) &&
                (pos.get_col() <= end.get_col())) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if ((pos.get_row() == start.get_row()) &&
                (pos.get_col() >= end.get_col()) &&
                (pos.get_col() <= start.get_col())) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else {
        if (start.get_row() <= end.get_row()) {
            if ((pos.get_col() == start.get_col()) &&
                (pos.get_row() >= start.get_row()) &&
                (pos.get_row() <= end.get_row())) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if ((pos.get_col() == start.get_col()) &&
                (pos.get_row() >= end.get_row()) &&
                (pos.get_row() <= start.get_row())) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

// This function check the number of hits that a ship get.
void Ship::hit() {
    if (num_hits < size) {
        num_hits += 1;
    }
}

// If the number of hits is equal to the size of ship, this ship is sunk.
bool Ship::has_sunk() {
    if (num_hits == size) {
        return true;
    }
    else {
        return false;
    }
}
