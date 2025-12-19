/*
 * File: bat_swarm.cpp
 * Author: Mia Hajj
 * Description: Implements the BatSwarm class methods.
 */
#include "bat_swarm.hpp"

// TODO Bat Swarm implementation (define bat_swarm member functions below)

#include "game.hpp"
#include <iostream>

/*
 * Function: bat_swarm
 * Description: Constructor for the Bat Swarm class, initializing its symbol and percept message.
 * Parameters: None
 * Returns: None
 */
bat_swarm::bat_swarm() {
    event_symbol = 'S';       // Display symbol for Bat Swarm
    message = "You hear screeching."; // Percept message
}

/*
 * Function: percept
 * Description: Prints "You hear screeching." to indicate the presence of bats nearby.
 * Parameters: None
 * Returns: void
 */
void bat_swarm::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Randomizes the player's position to a random room.
 * Parameters:
 *   g: Reference to the game object
 * Returns: void
 */
void bat_swarm::encounter(game& g) {
    std::cout << "A swarm of bats is all over you. Try to get out!" << std::endl;
    g.set_confused_flag(true);
}

/*
 * Function: clone
 * Description: Creates a copy of the BatSwarm object.
 * Parameters: None
 * Returns: event* - Pointer to the new BatSwarm object
 */
event* bat_swarm::clone() const {
    return new bat_swarm(*this);
}

/*
 * Function: ~bat_swarm (Destructor)
 * Description: Destructor for the BatSwarm class.
 * Parameters: None
 * Returns: None
 */
bat_swarm::~bat_swarm() {
    // No dynamic memory to clean up
}
