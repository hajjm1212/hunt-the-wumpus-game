/*
 * File: event.cpp
 * Author: Mia Hajj
 * Description: Implements the Event class. Since Event is an abstract class, only the destructor is defined here.
 */
#include "event.hpp"

// Event implementation (define non-pure-virtual event member functions below,
// if relevant)
event::~event() {
    // Empty destructor for proper cleanup of derived classes
    
}

/*
 * Function: get_event_symbol
 * Description: Retrieves the event symbol associated with the event.
 * Parameters: None
 * Returns (char): The symbol representing the event.
 */
char event::get_event_symbol() const{
    return event_symbol;
}
