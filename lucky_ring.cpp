
/*
 * File: lucky_ring.cpp
 * Author: Mia Hajj
 * Description: Implements the lucky_ring class methods, including the percept,
 * encounter, and clone methods, which provide protection functionality to the player.
 */

#include "lucky_ring.hpp"
#include <iostream>

/*
 * Function: lucky_ring
 * Description: Constructs a lucky_ring object with 2 protections.
 * Parameters: None
 * Returns: None
 */
lucky_ring::lucky_ring() {
    event_symbol = 'L';       // Display symbol for Lucky Ring
    message = "You feel like luck is on your side, today."; // Percept message
}

/*
 * Function: percept
 * Description: Displays the percept message for the Lucky Ring when the player is nearby.
 * Parameters: None
 * Returns: None
 */
void lucky_ring::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Triggers the encounter where the player picks up the Lucky Ring.
 * Activates the Lucky Ring's protection in the game.
 * Parameters:
 *   g (game&): Reference to the game object to update the player's state.
 * Returns: None
 */
void lucky_ring::encounter(game& g) {
    std::cout << "You found the Lucky Ring! It will protect you from two fatal encounters. It will be removed from room." << std::endl;
    g.set_has_lucky_ring(true); // Activate the Lucky Ring
    g.remove_event_from_current_room();
}

/*
 * Function: clone
 * Description: Creates a polymorphic copy of the lucky_ring object.
 * Parameters: None
 * Returns (event*): A dynamically allocated copy of the lucky_ring object.
 */
event* lucky_ring::clone() const {
    return new lucky_ring(*this);
}
