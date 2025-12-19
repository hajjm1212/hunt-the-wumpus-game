
/*
 * File: hidden_passage.cpp
 * Author: Mia Hajj
 * Description: Implements the hidden_passage class methods, including percept, encounter,
 * and clone, to enable the teleportation behavior of hidden passages in the game.
 */

#include "hidden_passage.hpp"
#include "game.hpp"
#include <iostream>

/*
 * Function: hidden_passage
 * Description: Constructs a hidden_passage object with the connected room's coordinates.
 * Parameters:
 *   row (int): Row index of the connected room.
 *   col (int): Column index of the connected room.
 * Returns: None
 */
hidden_passage::hidden_passage(int row, int col) : connected_room_row(row), connected_room_col(col) {
    
    event_symbol = 'H';       // Display symbol for the Wumpus
    message = "You hear water dripping."; // Percept message
}

/*
 * Function: percept
 * Description: Displays the percept message for the hidden passage when the player is nearby.
 * Parameters: None
 * Returns: None
 */
void hidden_passage::percept() const {
    std::cout << message << std::endl;
}

/*
 * Function: encounter
 * Description: Teleports the player to the connected room when the hidden passage is encountered.
 * Parameters:
 *   g (game&): Reference to the game object to update the player's position.
 * Returns: None
 */
void hidden_passage::encounter(game& g) {
    //std::cout << "You discovered a hidden passage!" << std::endl;
    g.move_player(connected_room_row, connected_room_col);
}

/*
 * Function: clone
 * Description: Creates a copy of the hidden_passage object to ensure deep copying.
 * Parameters: None
 * Returns (event*): A dynamically allocated copy of the hidden_passage object.
 */
event* hidden_passage::clone() const {
    return new hidden_passage(*this);
}
