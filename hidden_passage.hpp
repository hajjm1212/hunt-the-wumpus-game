/*
 * File: hidden_passage.hpp
 * Author: Mia Hajj
 * Description: Defines the hidden_passage class, representing hidden passages that teleport players
 * to a connected room. The hidden_passage class inherits from event and implements the required methods.
 */

#ifndef HIDDEN_PASSAGE_HPP
#define HIDDEN_PASSAGE_HPP

#include "event.hpp"
#include "game.hpp"

class hidden_passage : public event {
private:
    int connected_room_row; // Row coordinate of the connected room
    int connected_room_col; // Column coordinate of the connected room

public:
    /*
     * Function: hidden_passage
     * Description: Constructs a hidden_passage object with the connected room's coordinates.
     * Parameters:
     *   row (int): Row index of the connected room.
     *   col (int): Column index of the connected room.
     * Returns: None
     */
    hidden_passage(int row, int col);

    /*
     * Function: percept
     * Description: Displays the percept message for the hidden passage when the player is nearby.
     * Parameters: None
     * Returns: None
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Teleports the player to the connected room when the hidden passage is encountered.
     * Parameters:
     *   g (game&): Reference to the game object to update the player's position.
     * Returns: None
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the hidden_passage object to ensure deep copying.
     * Parameters: None
     * Returns (event*): A dynamically allocated copy of the hidden_passage object.
     */
    event* clone() const override;
};

#endif
