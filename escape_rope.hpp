/*
 * File: escape_rope.hpp
 * Author: Mia Hajj
 * Description: Defines the EscapeRope class, representing the escape rope location.
 * The EscapeRope class inherits from Event and implements the required methods.
 */
#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

// TODO Escape rope interface (define the escape_rope class and declare its
// member functions below)


#include "event.hpp"

class escape_rope : public event {
public:
    /*
     * Function: escape_rope
     * Description: Constructor for the Escape Rope class, initializing its symbol and percept message.
     * Parameters: None
     * Returns: None
     */
    escape_rope();
    
    /*
     * Function: percept
     * Description: Escape rope has no percept, so this function is empty.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Triggers win condition if the player has collected the gold.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the EscapeRope object.
     * Parameters: None
     * Returns: event* - Pointer to the new EscapeRope object
     */
    event* clone() const override;

    /*
     * Function: ~escape_rope (Destructor)
     * Description: Destructor for the EscapeRope class.
     * Parameters: None
     * Returns: None
     */
    ~escape_rope() override;
};


#endif
