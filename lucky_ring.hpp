/*
 * File: lucky_ring.hpp
 * Author: Mia Hajj
 * Description: Defines the lucky_ring class, representing the Lucky Ring event
 * that protects the player from two fatal encounters. Inherits from the event class.
 */

#ifndef LUCKY_RING_HPP
#define LUCKY_RING_HPP

#include "event.hpp"
#include "game.hpp"

class lucky_ring : public event {

public:
    /*
     * Function: lucky_ring
     * Description: Constructs a lucky_ring object with 2 protections.
     * Parameters: None
     * Returns: None
     */
    lucky_ring();

    /*
     * Function: percept
     * Description: Displays the percept message for the Lucky Ring when the player is nearby.
     * Parameters: None
     * Returns: None
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Triggers the encounter where the player picks up the Lucky Ring.
     * Activates the Lucky Ring's protection in the game.
     * Parameters:
     *   g (game&): Reference to the game object to update the player's state.
     * Returns: None
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a polymorphic copy of the lucky_ring object.
     * Parameters: None
     * Returns (event*): A dynamically allocated copy of the lucky_ring object.
     */
    event* clone() const override;
};

#endif
