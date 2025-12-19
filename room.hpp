/*
 * File: room.hpp
 * Author: Mia Hajj
 * Description: Defines the Room class, representing individual rooms in the game grid.
 * The Room class contains a pointer to an Event and provides methods to manage this event.
 */
#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class Room {
private: 
	// TODO private members
    event* e;
    bool has_event; //check if it has event
    int num_events; //count of events
public:
	// TODO public members
    /*
     * Function: Room (Constructor)
     * Description: Initializes the Room object with no event.
     * Parameters: None
     * Returns: None
     */
    Room();
    
    /*
     * Function: Room (Copy Constructor)
     * Description: Performs a deep copy of the Room object.
     * Parameters:
     *   other: The Room object to copy.
     * Returns: None
     */
    Room(const Room& other);
    
    /*
     * Function: operator= (Assignment Operator)
     * Description: Assigns one Room object to another, performing a deep copy.
     * Parameters:
     *   other: The Room object to assign from.
     * Returns: room& - Reference to the assigned Room object.
     */
    Room& operator=(const Room& other);

    /*
     * Function: ~Room (Destructor)
     * Description: Destructor for the Room class. Cleans up the event pointer.
     * Parameters: None
     * Returns: None
     */
    ~Room();

    /*
     * Function: set_event
     * Description: Sets an event in the Room.
     * Parameters:
     *   new_event: Pointer to the event to set.
     * Returns: void
     */
    void set_event(event* new_event);

    /*
     * Function: remove_event
     * Description: Removes the event from the Room and deletes it.
     * Parameters: None
     * Returns: void
     */
    void remove_event();

    /*
     * Function: get_event
     * Description: Gets the event in the Room.
     * Parameters: None
     * Returns: event* - Pointer to the event in the room.
     */
    event* get_event() const;
    
    /*
     * Function: get_has_event
     * Description: Checks whether a room currently contains an event.
     * Parameters: None
     * Returns (bool): True if the room has an event, false otherwise.
     */
    bool get_has_event() const;
    
    /*
     * Function: set_has_event
     * Description: Sets the flag indicating whether a room contains an event.
     * Parameters:
     *   e_flag (bool): True to indicate the room has an event, false otherwise.
     * Returns: None
     */
    void set_has_event(bool e_flag);
    
    /*
     * Function: get_cnt_events
     * Description: Retrieves the count of events in the room.
     * Parameters: None
     * Returns (int): The number of events currently in the room.
     */
    int get_cnt_events() const;
};

#endif
