
/*
 * File: escape_rope.cpp
 * Author: Mia Hajj
 * Description: Implements the EscapeRope class methods.
 */
#include "escape_rope.hpp"

// TODO Escape rope implementation (define escape_rope member functions below)

#include "game.hpp"
#include <iostream>

/*
 * Function: escape_rope
 * Description: Constructor for the Escape Rope class, initializing its symbol and percept message.
 * Parameters: None
 * Returns: None
 */
escape_rope::escape_rope() {
    event_symbol = 'R';       // Display symbol for escape rope
    message = "";              // Percept message
}

/*
 * Function: percept
 * Description: Escape rope has no percept, so this function is empty.
 * Parameters: None
 * Returns: void
 */
void escape_rope::percept() const {
    // No percept message for escape rope
}

/*
 * Function: encounter
 * Description: Triggers win condition if the player has collected the gold.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void escape_rope::encounter(game& g) {
    if (g.has_player_collected_gold()) {
        std::cout << "You escaped with the gold! You win!" << std::endl;
        //g.set_game_over(true);
    } else {
        std::cout << "You found the escape rope but you don't have the gold." << std::endl;
    }
}

/*
 * Function: clone
 * Description: Creates a copy of the EscapeRope object.
 * Parameters: None
 * Returns: event* - Pointer to the new EscapeRope object
 */
event* escape_rope::clone() const {
    return new escape_rope(*this);
}

/*
 * Function: ~escape_rope (Destructor)
 * Description: Destructor for the EscapeRope class.
 * Parameters: None
 * Returns: None
 */
escape_rope::~escape_rope() {
    // No dynamic memory to clean up
}
