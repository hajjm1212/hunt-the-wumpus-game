/*
 * File: wumpus.hpp
 * Author: Mia Hajj
 * Description: Defines the Wumpus class, representing the Wumpus creature.
 * The Wumpus class inherits from Event and implements the required methods.
 */

#ifndef WUMPUS_HPP
#define WUMPUS_HPP

// TODO Wumpus interface (define the wumpus class and declare its member
// functions below)


#include "event.hpp"

class wumpus : public event {
private:

public:
    /*
     * Function: wumpus
     * Description: Constructor for the Wumpus class, initializing its symbol and percept message.
     * Parameters: None
     * Returns: None
     */
    wumpus();
    
    /*
     * Function: percept
     * Description: Prints "You smell a terrible stench." to indicate the Wumpus is nearby.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Ends the game if the Wumpus is encountered.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the Wumpus object.
     * Parameters: None
     * Returns: event* - Pointer to the new Wumpus object
     */
    event* clone() const override;

    /*
     * Function: ~wumpus (Destructor)
     * Description: Destructor for the Wumpus class.
     * Parameters: None
     * Returns: None
     */
    ~wumpus() override;
};

#endif
