/*
 * File: wumpus.cpp
 * Author: Mia Hajj
 * Description: Implements the Wumpus class methods.
 */
#include "wumpus.hpp"

// TODO Wumpus implementation (define wumpus member functions below)

#include "game.hpp"
#include <iostream>

/*
 * Function: wumpus
 * Description: Constructor for the Wumpus class, initializing its symbol and percept message.
 * Parameters: None
 * Returns: None
 */
wumpus::wumpus() {
    event_symbol = 'W';       // Display symbol for the Wumpus
    message = "You smell a terrible stench."; // Percept message
}

/*
 * Function: percept
 * Description: Prints "You smell a terrible stench." to indicate the Wumpus is nearby.
 * Parameters: None
 * Returns: void
 */
void wumpus::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Ends the game if the Wumpus is encountered.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void wumpus::encounter(game& g) {
    if (g.is_wumpus_alive()) {
        if (g.use_ring_lifes()) {
            std::cout << "The Lucky Ring saved you from the Wumpus!" << std::endl;
        } else {
            std::cout << "The Wumpus got you! Game over." << std::endl;
            g.set_game_over(true);
        }
    } else {
        std::cout << "You see the dead body of the Wumpus." << std::endl;
    }
}

/*
 * Function: clone
 * Description: Creates a copy of the Wumpus object.
 * Parameters: None
 * Returns: event* - Pointer to the new Wumpus object
 */
event* wumpus::clone() const {
    return new wumpus(*this);
}

/*
 * Function: ~wumpus (Destructor)
 * Description: Destructor for the Wumpus class.
 * Parameters: None
 * Returns: None
 */
wumpus::~wumpus() {
    // No dynamic memory to clean up
}
