/*
 * File: bottomless_pit.cpp
 * Author: Mia Hajj
 * Description: Implements the BottomlessPit class methods.
 */
#include "bottomless_pit.hpp"

// TODO Bottomless Pit implementation (define bottomless_pit member functions
// below)

#include "game.hpp"
#include <iostream>


/*
 * Function: bottomless_pit
 * Description: Constructor for the Bottomless Pit class, initializing its symbol and percept message.
 * Parameters: None
 * Returns: None
 */
bottomless_pit::bottomless_pit() {
    event_symbol = 'P';       // Display symbol for Bottomless Pit
    message = "You feel a breeze."; // Percept message
}

/*
 * Function: percept
 * Description: Prints "You feel a breeze." to indicate the presence of a pit nearby.
 * Parameters: None
 * Returns: void
 */
void bottomless_pit::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Triggers game-over logic when the player enters the pit room.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void bottomless_pit::encounter(game& g) {
    //50% chance of falling in pit
    if (rand()%100 < 50){
        if (g.use_ring_lifes()) {
            std::cout << "The Lucky Ring saved you from falling into the bottomless pit!" << std::endl;
        } else {
            std::cout << "You fell into a bottomless pit! Game over." << std::endl;
            g.set_game_over(true);
        }
    }
}

/*
 * Function: clone
 * Description: Creates a copy of the BottomlessPit object.
 * Parameters: None
 * Returns: event* - Pointer to the new BottomlessPit object
 */
event* bottomless_pit::clone() const {
    return new bottomless_pit(*this);
}

/*
 * Function: ~bottomless_pit (Destructor)
 * Description: Destructor for the BottomlessPit class.
 * Parameters: None
 * Returns: None
 */
bottomless_pit::~bottomless_pit() {
    // No dynamic memory to clean up
}
