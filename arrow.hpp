
/*
 * File: arrow.hpp
 * Author: Mia Hajj
 * Description: Defines the Arrow class, representing arrows that the player can collect in the game.
 * The Arrow class inherits from Event and implements the required methods.
 */
#ifndef ARROW_HPP
#define ARROW_HPP

// TODO Arrow interface (define the arrow class and declare its member functions
// below)

#include "event.hpp"
class game; //forward declaration

class arrow : public event {
public:
    /*
     * Function: arrow
     * Description: Constructor for the Arrow class, initializing its symbol and message.
     * Parameters: None
     * Returns: None
     */
    arrow();
    
    /*
     * Function: percept
     * Description: Arrows have no percept, so this function is empty.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Increases the player's arrow count and removes the arrow from the room.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the Arrow object.
     * Parameters: None
     * Returns: event* - Pointer to the new Arrow object
     */
    event* clone() const override;

    /*
     * Function: ~arrow (Destructor)
     * Description: Destructor for the Arrow class.
     * Parameters: None
     * Returns: None
     */
    ~arrow() override;
};

#endif
