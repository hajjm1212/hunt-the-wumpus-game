/*
 * File: room.cpp
 * Author: Mia Hajj
 * Description: Implements the Room class methods.
 */

#include "room.hpp"

// TODO Room implementation (define room member functions below)


/*
 * Function: Room (Constructor)
 * Description: Initializes the Room object with no event.
 * Parameters: None
 * Returns: None
 */
Room::Room() : e(nullptr), has_event(false), num_events(0) {
    // Room initialized with no event
    
}

/*
 * Function: Room (Copy Constructor)
 * Description: Performs a deep copy of the Room object.
 * Parameters:
 *   other: The Room object to copy.
 * Returns: None
 */
Room::Room(const Room& other) {
    if (other.e) {
        e = other.e->clone();
        set_has_event(other.get_has_event());
        num_events = other.get_cnt_events();
    } else {
        e = nullptr;
        set_has_event(false);
        num_events = 0;
    }
}

/*
 * Function: operator= (Assignment Operator)
 * Description: Assigns one Room object to another, performing a deep copy.
 * Parameters:
 *   other: The Room object to assign from.
 * Returns: room& - Reference to the assigned Room object.
 */
Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete e;
        if (other.e) {
            e = other.e->clone();
            set_has_event(other.get_has_event());
            num_events = other.get_cnt_events();
        } else {
            e = nullptr;
            set_has_event(false);
            num_events = 0;
        }
    }
    return *this;
}

/*
 * Function: ~Room (Destructor)
 * Description: Destructor for the Room class. Cleans up the event pointer.
 * Parameters: None
 * Returns: None
 */
Room::~Room() {
    remove_event();
    set_has_event(false);
    num_events=0;
}

/*
 * Function: set_event
 * Description: Sets an event in the room.
 * Parameters:
 *   new_event: Pointer to the event to set.
 * Returns: void
 */
void Room::set_event(event* new_event) {
    remove_event();            // Delete existing event to prevent memory leaks
    e = new_event;    // Assign the new event
    set_has_event(true);
    num_events++;
}

/*
 * Function: remove_event
 * Description: Removes the event from the room and deletes it.
 * Parameters: None
 * Returns: void
 */
void Room::remove_event() {
    if (e) {
        delete e;     // Delete the event to free memory
        e = nullptr;  // Set pointer to nullptr
        set_has_event(false);
        num_events--;
    }
}

/*
 * Function: get_event
 * Description: Gets the event in the room.
 * Parameters: None
 * Returns: event* - Pointer to the event in the room.
 */
event* Room::get_event() const {
    return e;
}

/*
 * Function: get_has_event
 * Description: Checks whether a room currently contains an event.
 * Parameters: None
 * Returns (bool): True if the room has an event, false otherwise.
 */
bool Room::get_has_event() const{
    return has_event;
}

/*
 * Function: set_has_event
 * Description: Sets the flag indicating whether a room contains an event.
 * Parameters:
 *   e_flag (bool): True to indicate the room has an event, false otherwise.
 * Returns: None
 */
void Room::set_has_event(bool e_flag){
    has_event = e_flag;
}

/*
 * Function: get_cnt_events
 * Description: Retrieves the count of events in the room.
 * Parameters: None
 * Returns (int): The number of events currently in the room.
 */
int Room::get_cnt_events() const{
    return num_events;
    }
