/*
 * File: gold.hpp
 * Author: Mia Hajj
 * Description: Defines the Gold class, representing gold for collection.
 * The Gold class inherits from Event and implements the required methods.
 */
#ifndef GOLD_HPP
#define GOLD_HPP

// TODO Gold interface (define the gold class and declare its member functions
// below)

#include "event.hpp"

class gold : public event {
public:
    /*
     * Function: gold
     * Description: Constructor for the Gold class, initializing its symbol and percept message.
     * Parameters: None
     * Returns: None
     */
    gold();
    
    /*
     * Function: percept
     * Description: Prints "You see something shimmer nearby." to indicate gold is nearby.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Adds gold to the player's inventory and removes gold from the game.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the Gold object.
     * Parameters: None
     * Returns: event* - Pointer to the new Gold object
     */
    event* clone() const override;

    /*
     * Function: ~gold (Destructor)
     * Description: Destructor for the Gold class.
     * Parameters: None
     * Returns: None
     */
    ~gold() override;
};

#endif
