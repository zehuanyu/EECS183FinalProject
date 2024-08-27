/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project. 
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
    test_position();
    test_ship();
    test_player();
    test_game();
    
    return;
}

void test_position() {
    Position start_pos;
    Position end_pos;
    
    cout << "Test of default constructor" << endl;
    Position p1;
    cout << "Expected: 00" << endl;
    cout << "Actual  : ";
    cout << p1.get_row() << p1.get_col() << endl;
    
    cout << "test of the other construct" << endl;
    Position p2(2, 10);
    cout << "Expected: 27" << endl;
    cout << "Actual  : ";
    cout << p2.get_row() << p2.get_col() << endl;
    
    Position p3('1','a');
    cout << "Expected: 00" << endl;
    cout << "Actual  : ";
    cout << p3.get_row() << p3.get_col() << endl;
    
    Position p4('8','k');
    cout << "Expected: 77" << endl;
    cout << "Actual  : ";
    cout << p4.get_row() << p4.get_col() << endl;
    
    cout << "Test of member function: set_row(int row_in)" << endl;
    p1.set_row(6);
    p1.set_col(6);
    cout << "Expected:(6,6)" << endl;
    cout << "Actual  :";
    cout << "(" << p1.get_row()
         << "," << p1.get_col()
    << ")" << endl;
    
    cout << "Testing position read" << endl;
    Position p9;
    ifstream ins;
    ins.open("grid2.txt");
    if (ins.good()) {
        ins >> start_pos >> end_pos;
        cout << endl;
        cout << "Expected: (3,F)(3,G)" << endl;
        cout << "Actual output: " << start_pos << end_pos << endl;
    }
    else {
        cout << endl;
        cout << "Error opening grid2.txt" << endl;
    }
    return;
}

void test_ship() {
    cout << "Test of default constructor" << endl;
    Ship s0;
    cout << "Expected: 00" << endl;
    cout << "Actual output: " << s0.get_start().get_row() << s0.get_start().get_col() << endl;
    cout << "Expected: 00" << endl;
    cout << "Actual output: " << s0.get_end().get_row() << s0.get_end().get_col() << endl;
    cout << "Expected ship size: 0; Actual ship size: " << s0.get_size() << endl;
    
    cout << "Test of nondefault constructor" << endl;
    Position sp1;
    sp1.set_row(1);
    sp1.set_col(2);
    Position sp2;
    sp2.set_row(1);
    sp2.set_col(5);
    Ship s1(sp1, sp2);
    cout << "Test of get_started" << endl;
    cout << "Expected ship start position: 12" << endl;
    cout << "Actual output: " << s1.get_start().get_row() << s1.get_start().get_col() << endl;
    cout << "test of get_ended\n";
    cout << "Expected ship end position: 15" << endl;
    cout << "Actual output: " << s1.get_end().get_row() << s1.get_end().get_col() << endl;
    
    cout << "Test of is_horizontal()" << endl;
    cout << "Expected: 1 (true); Actual output: " << s1.is_horizontal() << endl;
    Position sp3;
    sp3.set_row(1);
    sp3.set_col(2);
    Position sp4;
    sp4.set_row(5);
    sp4.set_col(2);
    Ship s2(sp3, sp4);
    cout << "Expected: 0 (false); Actual output: " << s2.is_horizontal() << endl;
    
    cout << "Test of has_position" << endl;
    Position pos1(1,3);
    cout << "Expected: 1 (true); Actual output: " << s1.has_position(pos1) << endl;
    Position pos2(2,3);
    cout << "Expected: 0 (false); Actual output: " << s1.has_position(pos2) << endl;
    Position pos3(3,2);
    cout << "Expected: 1 (true); Actual output: " << s2.has_position(pos3) << endl;
    Position pos4(3,3);
    cout << "Expected: 0 (false); Actual output: " << s2.has_position(pos4) << endl;
        
    cout << "Test of hit and has_sunk" << endl;
    cout << "s1 has size of 4 means will sunk after 4 hits." << endl;
    cout << "(0 hit) Expected: 0 (false); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
    cout << "(1 hit) Expected: 0 (false); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
    cout << "(2 hit) Expected: 0 (false); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
    cout << "(3 hit) Expected: 0 (false); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
    cout << "(4 hit) Expected: 1 (true); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
    cout << "(4 hit) Expected: 1 (true); Actual output: " << s1.has_sunk() << endl;
    s1.hit();
}

void test_player() {
    cout << "Test for default constructor" << endl;
    Player player0;
    cout << "Expected: ; Actual output: " << player0.get_name() << endl;
    cout << "Expected: 0; Actual output: " << player0.get_num_ships() << endl;
    cout << "Expected: 0; Actual output: " << player0.get_remaining_ships() << endl;
    cout << "Expected: the initial grid; Actual output: " << endl;
    player0.print_grid();
    
    cout << "Test for non-default constructor" << endl;
    Player player1("Alice");
    cout << "Expected: Alice; Actual output: " << player1.get_name() << endl;
    cout << "Expected: 0; Actual output: " << player1.get_num_ships() << endl;
    cout << "Expected: 0; Actual output: " << player1.get_remaining_ships() << endl;
    cout << "Expected: the initial grid; Actual output: " << endl;
    player1.print_grid();
    
    cout << "Test for add_ship" << endl;
    Player player2("Bob");
    Position shippositon1;
    Position shippositon2;
    shippositon1.set_row(0);
    shippositon1.set_col(5);
    shippositon2.set_row(0);
    shippositon2.set_col(7);
    Ship ship1(shippositon1, shippositon2);
    player2.add_ship(ship1);
    cout << "Expected: First ship add from (1,F) to (3,H); Actual output: " << endl;
    player2.print_grid();
    cout << "Expected: No ship will be add in the opponent's grid; Actual output: " << endl;
    player2.print_guess_grid();
    
    Position shippositon3;
    Position shippositon4;
    shippositon3.set_row(2);
    shippositon3.set_col(0);
    shippositon4.set_row(6);
    shippositon4.set_col(0);
    Ship ship2(shippositon3, shippositon4);
    player2.add_ship(ship2);
    cout << "Expected: Second ship add from (3,A) to (7,A); Actual output: " << endl;
    player2.print_grid();
    cout << "Expected: No ship will be add in the opponent's grid; Actual output: " << endl;
    player2.print_guess_grid();
    
    Position shippositon5;
    Position shippositon6;
    shippositon5.set_row(2);
    shippositon5.set_col(4);
    shippositon6.set_row(4);
    shippositon6.set_col(7);
    Ship ship3(shippositon5, shippositon6);
    player2.add_ship(ship3);
    cout << "Expected: Third ship add from (3,B) to (5,E); Actual output: " << endl;
    player2.print_grid();
    cout << "Expected: No ship will be add in the opponent's grid; Actual output: " << endl;
    player2.print_guess_grid();
    
    Position shippositon7;
    Position shippositon8;
    shippositon7.set_row(7);
    shippositon7.set_col(1);
    shippositon8.set_row(7);
    shippositon8.set_col(2);
    Ship ship4(shippositon7, shippositon8);
    player2.add_ship(ship4);
    
    Position shippositon9;
    Position shippositon10;
    shippositon9.set_row(5);
    shippositon9.set_col(7);
    shippositon10.set_row(7);
    shippositon10.set_col(7);
    Ship ship5(shippositon9, shippositon10);
    player2.add_ship(ship5);
    
    cout << "Expected: Forth ship add from (8,B) to (8,C) and fifth ship add from (6,H) to (8,H)";
    cout << "Actual output: " << endl;
    player2.print_grid();
    cout << "Expected: No ship will be add in the opponent's grid; Actual output: " << endl;
    player2.print_guess_grid();
    
    Position shippositon11;
    Position shippositon12;
    shippositon11.set_row(1);
    shippositon11.set_col(2);
    shippositon12.set_row(1);
    shippositon12.set_col(4);
    Ship ship6(shippositon9, shippositon10);
    player2.add_ship(ship6);
    cout << "Expected: The sixth ship will never be add in the grid, and the grid shoud keep the same as above.";
    cout << "Actual output: " << endl;
    player2.print_grid();
    
    cout << "test for load_grid_file\n";
    Player player3;
    player3.load_grid_file("grid1.txt");
    cout << "Expected ship number: 5; Actural: " << player3.get_num_ships() << endl;
    cout << "Expected remaining ship number: 5; Actural: " << player3.get_remaining_ships() << endl;
    cout << "Expected: 5 ships with positions in grid1; Actural: " << endl;
    player3.print_grid();
    
    Player player4;
    player4.load_grid_file("grid2.txt");
    cout << "Expected ship number: 5; Actural: " << player4.get_num_ships() << endl;
    cout << "Expected remaining ship number: 5; Actural: " << player4.get_remaining_ships() << endl;
    cout << "Expected: 5 ships with positions in grid2; Actural: " << endl;
    player4.print_grid();
    
    Player player5;
    player4.load_grid_file("grid3.txt");
    cout << "Expected ship number: 0; Actural: " << player5.load_grid_file("grid.txt") << endl;
    cout << "Expected remaining ship number: 0; Actural: " <<  player5.get_num_ships() << endl;
    cout << "Expected: No file named grid3 so no ship should be added in the initial grid; Actural: " << endl;
    player5.print_grid();
    
    cout << "Test for attack" << endl;
    Player opponent("CPU");
    Position start1(1,3);
    Position end1(2,3);
    Ship CPUship1(start1, end1);
    opponent.add_ship(CPUship1);
    
    Position attack1(1,3);
    Player playerCPU;
    cout << "Expected: (2,D) hit; Actural: " << endl;
    playerCPU.attack(opponent, attack1);
    cout << "Expected ship number: 1; Actural: " << opponent.get_num_ships() << endl;
    cout << "Expected remaining ship number: 1; Actural: " << opponent.get_remaining_ships() << endl;
    cout << "Expected: Mark O on (2,D); Actural: " << endl;
    playerCPU.print_guess_grid();
    
    cout << "Expected: (4,D) miss; Actural: " << endl;
    Position attack2(3,3);
    playerCPU.attack(opponent, attack2);
    cout << "Expected ship number: 1; Actural: " << opponent.get_num_ships() << endl;
    cout << "Expected remaining ship number: 1; Actural: " << opponent.get_remaining_ships() << endl;
    cout << "Expected: Mark X on (4,D); Actural: " << endl;
    playerCPU.print_guess_grid();
    
    Position attack3(1,3);
    cout << "Expected: (2,D) miss; Actural: " << endl;
    playerCPU.attack(opponent, attack1);
    cout << "Expected ship number: 1; Actural: " << opponent.get_num_ships() << endl;
    cout << "Expected remaining ship number: 1; Actural: " << opponent.get_remaining_ships() << endl;
    cout << "Expected: Mark O on (2,D); Actural: " << endl;
    playerCPU.print_guess_grid();
    
    cout << "Expected: (3,D) hit Congratulations ! You sunk a Destroyer; Actural: " << endl;
    Position attack4(2,3);
    playerCPU.attack(opponent, attack4);
    cout << "Expected ship number: 1; Actural: " << opponent.get_num_ships() << endl;
    cout << "Expected remaining ship number: 0; Actural: " << opponent.get_remaining_ships() << endl;
    cout << "Expected: Mark O on (3,D); Actural: " << endl;
    playerCPU.print_guess_grid();
}

void test_game() {
    cout << "Test for default constructor" << endl;
    Game game0;
    cout << "Expected: the initial grid; Actual output: " << endl;
    game0.get_p1().print_grid();
    cout << "Expected: the initial grid; Actual output: " << endl;
    game0.get_p2().print_grid();
    
    cout << "Test for non-default constructor" << endl;
    Player p1("Alice");
    Player p2("CPU");
    Game game1(p1, "grid1.txt", p2, "grid2.txt");
    cout << "Expected: the grid in grid1; Actual output: " << endl;
    game1.get_p1().print_grid();
    cout << "Expected: the grid in grid2; Actual output: " << endl;
    game1.get_p2().print_grid();
    
    cout << "Test for check_valid_move" << endl;
    cout << "Expected: 1 (true); Actual output: " << game1.check_valid_move("1A") << endl;
    cout << "Expected: 1 (true); Actual output: " << game1.check_valid_move("1a") << endl;
    cout << "Expected: 0 (false); Actual output: " << game1.check_valid_move("12") << endl;
    cout << "Expected: 0 (false); Actual output: " << game1.check_valid_move("1AB") << endl;
    cout << "Expected: 0 (false); Actual output: " << game1.check_valid_move("A1") << endl;
}
