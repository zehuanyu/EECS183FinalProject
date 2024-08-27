/**
 * focaccia.cpp
 *
 * Zehuan Yu
 * zehuanyu
 *
 * EECS 183: Project 1
 * Winter 2023
 * 
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
    
    //calculate the number of loaves with the number of people we get from above.
    int loaves;
    loaves = ceil(people / 4.0);

    cout << "You need to make: " << loaves << " " <<  pluralize("loaf", "loaves", loaves) << " of focaccia" << endl;
    cout << endl;
    cout << "Shopping List for Focaccia Bread" << endl;
    cout << "--------------------------------" << endl;
    
    //calculate the number of bags of flour.
    int flourBags;
    const double FLOUR_CUPS_PER_LOAF = 5.0;
    const double FLOUR_CUPS_PER_BAG = 20.0;
    flourBags = ceil(loaves * FLOUR_CUPS_PER_LOAF / FLOUR_CUPS_PER_BAG);
    cout << flourBags << " " <<  pluralize("bag", "bags", flourBags) << " of flour" << endl ;
    
    //calculate the number of packages of yeast.
    int yeastPackages;
    const double YEAST_TEASPOONS_PER_LOAF = 1.75;
    const double YEAST_TEASPOONS_PER_PACKAGE = 2.25;
    yeastPackages = ceil(loaves * YEAST_TEASPOONS_PER_LOAF / YEAST_TEASPOONS_PER_PACKAGE);
    cout << yeastPackages << " " <<  pluralize("package", "packages", yeastPackages) << " of yeast" << endl;
    
    //calculate the number of canisters of salt.
    int saltCanisters;
    const double SALT_TEASPOONS_PER_LOAF = 1.875;
    const double SALT_GRAMS_PER_TEASPOONS = 5.0;
    const double SALT_GRAMS_PER_CANISTER = 30.0;
    
    saltCanisters = ceil(loaves * SALT_TEASPOONS_PER_LOAF * SALT_GRAMS_PER_TEASPOONS / SALT_GRAMS_PER_CANISTER);
    cout << saltCanisters << " " <<  pluralize("canister", "canisters", saltCanisters) << " of salt" << endl;
    
    //calculate the number of bottles of oil.
    int oilBottles;
    const double OIL_TABLESPOONS_PER_LOAF = 2.0;
    const double OIL_MILLILITRES_PER_TABLESPOONS = 14.8;
    const double OIL_MILLILITRES_PER_BOTTLE = 500.0;
    
    oilBottles = ceil(loaves * OIL_TABLESPOONS_PER_LOAF * OIL_MILLILITRES_PER_TABLESPOONS / OIL_MILLILITRES_PER_BOTTLE);
    cout << oilBottles << " " <<  pluralize("bottle", "bottles", oilBottles) << " of olive oil" << endl;
    cout << endl;
    
    //calculate the total cost of ingredients.
    double totalcost;
    const double FLOUR_BAG_PRICE = 2.69;
    const double YEAST_PACKAGE_PRICE = 0.40;
    const double SALT_CANISTER_PRICE = 0.49;
    const double OIL_BOTTLE_PRICE = 6.39;
    totalcost = flourBags * FLOUR_BAG_PRICE + yeastPackages * YEAST_PACKAGE_PRICE + saltCanisters * SALT_CANISTER_PRICE + oilBottles * OIL_BOTTLE_PRICE;
    cout << "Total expected cost of ingredients: $" << totalcost << endl;
    cout << endl;
    cout << "Have a great party!" << endl;
    

    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
