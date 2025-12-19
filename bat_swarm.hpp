/*
 * File: bat_swarm.hpp
 * Author: Mia Hajj
 * Description: Defines the BatSwarm class, representing bat swarms that randomize the player's movement.
 * The BatSwarm class inherits from Event and implements the required methods.
 */
#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

// TODO Bat Swarm interface (define the bat_swarm class and declare its member
// functions below)


#include "event.hpp"

class bat_swarm : public event {
public:
    /*
     * Function: bat_swarm
     * Description: Constructor for the Bat Swarm class, initializing its symbol and percept message.
     * Parameters: None
     * Returns: None
     */
    bat_swarm();
    
    /*
     * Function: percept
     * Description: Prints "You hear screeching." to indicate the presence of bats nearby.
     * Parameters: None
     * Returns: void
     */
    void percept() const override;

    /*
     * Function: encounter
     * Description: Randomizes the player's position to a random room.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    void encounter(game& g) override;

    /*
     * Function: clone
     * Description: Creates a copy of the BatSwarm object.
     * Parameters: None
     * Returns: event* - Pointer to the new BatSwarm object
     */
    event* clone() const override;

    /*
     * Function: ~bat_swarm (Destructor)
     * Description: Destructor for the BatSwarm class.
     * Parameters: None
     * Returns: None
     */
    ~bat_swarm() override;
};

#endif

