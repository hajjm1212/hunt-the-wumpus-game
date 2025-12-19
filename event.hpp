/*
 * File: event.hpp
 * Author: Mia Hajj
 * Description: Defines the abstract base class Event, which serves as a blueprint for all event types in the game.
 * The Event class declares pure virtual methods for percept, encounter, and clone.
 */

#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>

class game; //forward declaration

// Event interface
class event {
private:
	// TODO private members, if relevant
protected:
	// TODO protected members, if relevant
    char event_symbol;      //display symbol for event
    std::string message;    // Percept message for event
public:
	// TODO public members
    /*
     * Function: percept
     * Description: Pure virtual function that triggers the percept message for an event.
     * Parameters: None
     * Returns: void
     */
    virtual void percept() const = 0;

    /*
     * Function: encounter
     * Description: Pure virtual function that defines the encounter behavior when a player enters a room with this event.
     * Parameters:
     *   g: Reference to the game object
     * Returns: void
     */
    virtual void encounter(game& g) = 0;

    /*
     * Function: clone
     * Description: Pure virtual function to create a copy of the event object.
     * Parameters: None
     * Returns: event* - Pointer to the new event object
     */
    virtual event* clone() const = 0;

    // Virtual destructor for proper cleanup of derived classes
    virtual ~event();
    
    /*
     * Function: get_event_symbol
     * Description: Retrieves the event symbol associated with the event.
     * Parameters: None
     * Returns (char): The symbol representing the event.
     */
    char get_event_symbol() const;
};

#endif
