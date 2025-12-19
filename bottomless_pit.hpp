/*
 * File: bottomless_pit.hpp
 * Author: Mia Hajj
 * Description: Defines the BottomlessPit class, representing rooms with a bottomless pit.
 * The BottomlessPit class inherits from Event and implements the required methods.
 */
#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

// TODO Bottomless Pit interface (define the bottomless_pit class and declare
// its member functions below)

#include "event.hpp"

class bottomless_pit : public event {
public:
    /*
     * Function: bottomless_pit
     * Description: Constructor for the Bottomless Pit class, initializing its symbol and percept message.
     * Parameters: None
     * Returns: None
     */
    bottomless_pit();
    
    /*
     * Function: percept
     * Description: Prints "You feel a breeze." to indicate the presence of a pit nearby.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Triggers game-over logic when the player enters the pit room.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the BottomlessPit object.
     * Parameters: None
     * Returns: event* - Pointer to the new BottomlessPit object
     */
    event* clone() const override;

    /*
     * Function: ~bottomless_pit (Destructor)
     * Description: Destructor for the BottomlessPit class.
     * Parameters: None
     * Returns: None
     */
    ~bottomless_pit() override;
};


#endif
