/*
 * File: arrow.cpp
 * Author: Mia Hajj
 * Description: Implements the Arrow class methods.
 */
#include "arrow.hpp"

// TODO Arrow implementation (define arrow member functions below)

#include "game.hpp"
#include <iostream>

/*
 * Function: arrow
 * Description: Constructor for the Arrow class, initializing its symbol and message.
 * Parameters: None
 * Returns: None
 */
arrow::arrow() {
    event_symbol = 'A';       // Display symbol for Arrow
    message = ""; // No message for arrow
}

/*
 * Function: percept
 * Description: Arrows have no percept, so this function is empty.
 * Parameters: None
 * Returns: void
 */
void arrow::percept() const {
    // No percept message for arrows
}

/*
 * Function: encounter
 * Description: Increases the player's arrow count and removes the arrow from the room.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void arrow::encounter(game& g) {
    // Increase the player's arrow count
    g.increase_arrow_count();

    // Remove the arrow from the current room
    g.remove_event_from_current_room();

    // Notify the player
    std::cout << "You found an arrow! You now have " << g.get_arrows() << " arrow";
    if (g.get_arrows() > 1)
        std::cout <<"s";
    std::cout << ". Arrow is removed from this room." << std::endl;
}

/*
 * Function: clone
 * Description: Creates a copy of the Arrow object.
 * Parameters: None
 * Returns: event* - Pointer to the new Arrow object
 */
event* arrow::clone() const {
    return new arrow(*this);
}

/*
 * Function: ~arrow (Destructor)
 * Description: Destructor for the Arrow class.
 * Parameters: None
 * Returns: None
 */
arrow::~arrow() {
    // No dynamic memory to clean up
}
