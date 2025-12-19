/*
 * File: gold.cpp
 * Author: Mia Hajj
 * Description: Implements the Gold class methods.
 */
#include "gold.hpp"

// TODO Gold implementation (define gold member functions below)

#include "game.hpp"
#include <iostream>

/*
 * Function: gold
 * Description: Constructor for the Gold class, initializing its symbol and percept message.
 * Parameters: None
 * Returns: None
 */
gold::gold() {
    event_symbol = 'G';       // Display symbol for Gold
    message = "You see something shimmer nearby."; // Percept message
}

/*
 * Function: percept
 * Description: Prints "You see something shimmer nearby." to indicate gold is nearby.
 * Parameters: None
 * Returns: void
 */
void gold::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Adds gold to the player's inventory and removes gold from the game.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void gold::encounter(game& g) {
    std::cout << "You found the gold! It will be automatically picked up and removed from room." << std::endl;
    g.set_has_gold(true);
    g.remove_event_from_current_room();
}

/*
 * Function: clone
 * Description: Creates a copy of the Gold object.
 * Parameters: None
 * Returns: event* - Pointer to the new Gold object
 */
event* gold::clone() const {
    return new gold(*this);
}

/*
 * Function: ~gold (Destructor)
 * Description: Destructor for the Gold class.
 * Parameters: None
 * Returns: None
 */
gold::~gold() {
    // No dynamic memory to clean up
}
