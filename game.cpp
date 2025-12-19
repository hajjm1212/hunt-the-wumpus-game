/*
 * File: game.cpp
 * Authors: Instructor and Mia Hajj
 * Description: Partial code provided by instructor and complemented with Mia's code to implements the game class.
 */

#include <iostream>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"
#include "hidden_passage.hpp"   //Bonus
#include "lucky_ring.hpp"       //Bonus

// game implementation

/*
 * Function: game (Constructor)
 * Description: Constructs game object with a grid matching the given width and height.
 * Parameters:
 *   width (int): Width of the grid
 *   height (int): Height of the grid
 *   debug (bool): Whether or not debug mode should be enabled
 */

int init_row;
int init_col;
//wumpus position
int wumpus_row;
int wumpus_col;

/*
 * Function: Constructor
 * Description: Constructs game object with a grid matching the given
 *         width and height and all the private parameters.
 * Parameters:
 *         width (int): Width of the grid
 *         height (int): Height of the grid
 *         debug (bool): Whether or not debug mode should be enabled
 */
game::game(int width, int height, bool debug) :
		width(width),
		height(height),
		debug(debug), num_arrows(0), has_gold(false), wumpus_alive(true), game_over(false), player_row(-1), player_col(-1), wumpus_row(-1), wumpus_col(-1), player_confused(false), init_row(-1), init_col(-1){
	// TODO Create the game board: 2D vector of room objects
            
    // Initialize grid
    initialize_grid();

	// TODO Randomly insert events (2 bat_swarms, 2 bottomless_pits,
	// 1 wumpus, 1 gold, 2 arrows, 1 escape rope) into the board

    // Place events on the grid
    place_events();
    // Place player and rope at random position
    place_player_rope(new escape_rope());
    
    //Bonus Two rooms with hidden passages
    place_hidden_passages();
            
    //Bonus
    // Place the Lucky Ring with two lifes
    int row = -1, col = -1;
    place_one_event(new lucky_ring(), row, col);
}

/*
 * Function: display_game
 * Description: Displays the game grid in the terminal.
 * Parameters: None
 * Returns: void
 */
void game::display_game() const{
	std::cout << std::endl << std::endl;
	std::cout << "Arrows remaining: " << this->num_arrows << std::endl;

	std::string row_border = "--";
	for (int i = 0; i < this->width; ++i) {
		row_border += "-----";
	}

	std::cout << row_border << std::endl;
	for (int i = 0; i < this->height; ++i) {
		std::cout << "||";
		for (int j = 0; j < this->width; ++j) {
			// The first char indicates whether there is a player in the room
			// at row index i, column index j. TODO If the room contains the
			// player, print an asterisk ("*")

			// TODO else, print a space (" ")

			// The next char indicates the event in the room.
			
			// TODO If debug mode is disabled OR the room at location <i, j>
			// does not have an event, print a space (" ")
			// For example:
			// if (!this->debug || <i, j> ROOM DOES NOT HAVE EVENT) {
			// 	std::cout << " ";
			// }
			//
			// TODO else, print the room's debug symbol. There are a few ways to
			// do this. You can use polymorphism, or an event could have a
			// char debug_symbol member variable and some sort of
			// get_debug_symbol() member function that you could call here
			// to get the character and print it.
            if (player_row == i && player_col == j) {
                std::cout << '*';
            } else {
                std::cout << " "; // Empty space
            };
            char event_char = ' ';
            if (debug && grid[i][j].get_has_event()){
                event_char = grid[i][j].get_event()->get_event_symbol();
            }
            std::cout << event_char;
			std::cout << " ||";
		}
		std::cout << std::endl;
		std::cout << row_border << std::endl;
	}

	//example output (when finished): 
	// ----------------------
	// || P || G || P ||   ||
	// ----------------------
	// ||   || W ||   || S ||
	// ----------------------   
	// ||   ||   ||   || S ||
	// ----------------------   
	// ||*  ||   ||   ||   ||
	// ----------------------
}

/*
 * Function: check_win
 * Description: Determines whether the player has won the game.
 * Parameters: None
 * Returns: bool - True if the player has won, false otherwise
 */
bool game::check_win() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has won the game. Return false otherwise.
    return ((has_gold && player_row == init_row && player_col == init_col) || !wumpus_alive);
}

/*
 * Function: check_lose
 * Description: Determines whether the player has lost the game.
 * Parameters: None
 * Returns: bool - True if the player has lost, false otherwise
 */
bool game::check_lose() const{
	// TODO Delete the below placeholder code. Return true if the player
	// has lost the game. Return false otherwise.
    return game_over;
}

/*
 * Function: is_direction
 * Description: Returns true if the given character is a valid direction character (w/a/s/d) and false otherwise.
 * Parameters:
 *   c (char): The character to check
 * Returns: bool - Indicates whether the character is a valid direction character
 */
bool game::is_direction(char c) {
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

/*
 * Function: to_lower
 * Description: Converts a given character to lowercase. Used to standardize a user's character input.
 * Parameters:
 *   direction (char): Character to convert to lowercase
 * Returns: char - Character converted to lowercase
 */
char game::to_lower(char direction) {
	if (direction >= 'A' && direction <= 'Z') {
		return direction + ('a' - 'A');
	}
	return direction;
}

/*
 * Function: can_move_in_direction
 * Description: Determines whether the player can move in the given direction, based on their current location and the size of the grid.
 * Parameters:
 *   direction (char): Direction the player wishes to move in
 * Returns: bool - True if the player can move in the given direction without moving off the grid
 */
bool game::can_move_in_direction(char direction) {
	// TODO Delete the below placeholder code. Return true if the player can
	// move in the given direction ('w' for up, 'a' for left, 's' for down,
	// 'd' for right). Return false otherwise. The player can move in the
	// given direction so long as it wouldn't cause them to move off the
	// grid.

    direction = to_lower(direction);
    if (direction == 'w') return player_row > 0;
    if (direction == 'a') return player_col > 0;
    if (direction == 's') return player_row < height - 1;
    if (direction == 'd') return player_col < width - 1;
    return false;
}

/*
 * Function: is_valid_action
 * Description: Determines whether the given action is valid.
 * Parameters:
 *   action (char): Action the player wishes to perform
 * Returns: bool - True if the requested action is valid, false otherwise
 */
bool game::is_valid_action(char action) {
	if (this->is_direction(action)) {
		char direction = action;
		return this->can_move_in_direction(direction);
	} else if (action == 'f') {
		return this->num_arrows > 0;
	}
	return false;
}

/*
 * Function: print_action_error
 * Description: Prints a clear error message associated with the user's provided invalid action.
 * Parameters:
 *   action (char): Invalid action that the user requested
 * Returns: void
 */
void game::print_action_error(char action) {
	if (this->is_direction(action)) {
		std::cout << "You can't move in that direction!" << std::endl <<
			std::endl;
	} else if (action == 'f') {
		std::cout << "You're out of arrows!" << std::endl << std::endl;
	} else {
		std::cout << std::endl << "That's an invalid input!" << std::endl
			<< std::endl;
	}
}

/*
 * Function: get_player_action
 * Description: Prompts the player for their action for the turn and returns it as a char (w, a, s, d, or f). If the player enters an invalid action, this function reprompts until a valid one is provided.
 * Parameters: None
 * Returns: char - The valid action provided by the player
 */
char game::get_player_action() {
	char action = ' ';
	bool first = true;
	do {
		if (!first) {
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << std::endl << std::endl << "What would you like to do?" <<
			std::endl << std::endl;
		std::cout << "w: move up" << std::endl;
		std::cout << "a: move left" << std::endl;
		std::cout << "s: move down" << std::endl;
		std::cout << "d: move right" << std::endl;
		std::cout << "f: fire an arrow" << std::endl;

		std::cin >> action;
		action = this->to_lower(action);
	} while (!this->is_valid_action(action));
    
    if(player_confused){
        set_confused_flag(false);
        action = get_different_direction(action);
    }

	return action;
}

/*
 * Function: get_arrow_fire_direction
 * Description: Prompts the player for the direction they want to fire an arrow (w, a, s, or d) and returns it as a char. If the player enters an invalid direction, this function reprompts until a valid one is provided.
 * Parameters: None
 * Returns: char - The valid direction provided by the player
 */
char game::get_arrow_fire_direction() {
	char direction;
	bool first = true;
	do {
		if (!first) {
			std::cout << std::endl << "That's an invalid input!" <<
				std::endl << std::endl;
		}
		first = false;

		std::cout << std::endl << std::endl <<
			"What direction would you like to fire the arrow?" << std::endl <<
			std::endl;
		std::cout << "w: up" << std::endl;
		std::cout << "a: left" << std::endl;
		std::cout << "s: down" << std::endl;
		std::cout << "d: right" << std::endl;

		std::cin >> direction;
		direction = this->to_lower(direction);
	} while (!this->is_direction(direction));

	return direction;
}

/*
 * Function: move_up
 * Description: Moves the player up one grid space.
 * Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
 * Post-condition: Player is moved accordingly
 * Parameters: None
 * Returns: void
 */
void game::move_up() {
	// TODO Delete the below placeholder code. Move the player up one
	// space in the grid, however you choose to do that.
    if (player_row > 0) {
        player_row--;
    } else {
        std::cout << "You can't move up. There's a wall." << std::endl;
    }
}

/*
 * Function: move_down
 * Description: Moves the player down one grid space.
 * Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
 * Post-condition: Player is moved accordingly
 * Parameters: None
 * Returns: void
 */
void game::move_down() {
	// TODO Delete the below placeholder code. Move the player down one
	// space in the grid, however you choose to do that.
    if (player_row < height - 1) {
        player_row++;
    } else {
        std::cout << "You can't move down. There's a wall." << std::endl;
    }
}

/*
 * Function: move_left
 * Description: Moves the player left one grid space.
 * Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
 * Post-condition: Player is moved accordingly
 * Parameters: None
 * Returns: void
 */
void game::move_left() {
	// TODO Delete the below placeholder code. Move the player left one
	// space in the grid, however you choose to do that.
    if (player_col > 0) {
        player_col--;
    } else {
        std::cout << "You can't move left. There's a wall." << std::endl;
    }
}

/*
 * Function: move_right
 * Description: Moves the player right one grid space.
 * Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
 * Post-condition: Player is moved accordingly
 * Parameters: None
 * Returns: void
 */
void game::move_right() {
	// TODO Delete the below placeholder code. Move the player right one
	// space in the grid, however you choose to do that.
    if (player_col < width - 1) {
        player_col++;
    } else {
        std::cout << "You can't move right. There's a wall." << std::endl;
    }
}

/*
 * Function: move
 * Description: Moves the player in the direction specified by the given character.
 * Parameters:
 *   direction (char): Direction in which to move the player (a for west, s for south, d for east, w for north)
 * Pre-condition: Player is capable of moving in this direction (without hitting the edge of the board)
 * Post-condition: Player is moved accordingly
 * Returns: void
 */
void game::move(char direction) {
	if (direction == 'w') {
		this->move_up();
	} else if (direction == 'a') {
		this->move_left();
	} else if (direction == 'd') {
		this->move_right();
	} else {
		this->move_down();
	}
}

/*
 * Function: fire_arrow_up
 * Description: Fires an arrow upward.
 * Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves if missed.
 * Parameters: None
 * Returns: void
 */
void game::fire_arrow_up() {
	// TODO Delete the below placeholder code. Fire the arrow upward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
    
    //num_arrows--;
    // Check each room upwards
    int counter = 0;
    for (int row = player_row - 1; row >= 0 && counter < 3; --row) {
        counter++;
        event* e = grid[row][player_col].get_event();
        if (grid[row][player_col].get_has_event() && e->get_event_symbol() == 'W') {
            std::cout << "You hear a scream. You killed the Wumpus!" << std::endl;
            wumpus_alive = false;
            grid[row][player_col].remove_event();
            return;
        }
    }
    std::cout << "You missed. The Wumpus might have moved." << std::endl;
    // Wumpus moves
    move_wumpus();
}

/*
 * Function: fire_arrow_down
 * Description: Fires an arrow downward.
 * Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves if missed.
 * Parameters: None
 * Returns: void
 */
void game::fire_arrow_down() {
	// TODO Delete the below placeholder code. Fire the arrow downward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses

    int counter = 0;
    for (int row = player_row + 1; row < height && counter < 3; ++row) {
        counter++;
        event* e = grid[row][player_col].get_event();
        if (grid[row][player_col].get_has_event() && e->get_event_symbol() == 'W') {
            std::cout << "You hear a scream. You killed the Wumpus!" << std::endl;
            wumpus_alive = false;
            grid[row][player_col].remove_event();
            return;
        }
    }
    std::cout << "You missed. The Wumpus might have moved." << std::endl;
    // Wumpus moves
    move_wumpus();
}

/*
 * Function: fire_arrow_left
 * Description: Fires an arrow leftward.
 * Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves if missed.
 * Parameters: None
 * Returns: void
 */
void game::fire_arrow_left() {
	// TODO Delete the below placeholder code. Fire the arrow leftward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses

    int counter = 0;
    for (int col = player_col - 1; col >= 0 && counter < 3; --col) {
        counter ++;
        event* e = grid[player_row][col].get_event();
        if (grid[player_row][col].get_has_event() && e->get_event_symbol() == 'W') {
            std::cout << "You hear a scream. You killed the Wumpus!" << std::endl;
            wumpus_alive = false;
            grid[player_row][col].remove_event();
            return;
        }
    }
    std::cout << "You missed. The Wumpus might have moved." << std::endl;
    // Wumpus moves
    move_wumpus();
}

/*
 * Function: fire_arrow_right
 * Description: Fires an arrow rightward.
 * Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves if missed.
 * Parameters: None
 * Returns: void
 */
void game::fire_arrow_right() {
	// TODO Delete the below placeholder code. Fire the arrow rightward, killing
	// the wumpus if it hits it or making the wumpus "wake up" and move
	// randomly if it misses
    
    int counter = 0;
    for (int col = player_col + 1; col < width && counter < 3; ++col) {
        counter++;
        event* e = grid[player_row][col].get_event();
        if (grid[player_row][col].get_has_event() && e->get_event_symbol() == 'W') {
            std::cout << "You hear a scream. You killed the Wumpus!" << std::endl;
            wumpus_alive = false;
            grid[player_row][col].remove_event();
            return;
        }
    }
    std::cout << "You missed. The Wumpus might have moved." << std::endl;
    // Wumpus moves
    move_wumpus();
}

/*
 * Function: fire_arrow
 * Description: Fires an arrow in the direction specified by the given character.
 * Parameters:
 *   direction (char): Direction in which to fire arrow (a for west, s for south, d for east, w for north)
 * Post-condition: Arrow is fired. Wumpus is killed if hit and moves if missed.
 * Returns: void
 */
void game::fire_arrow(char direction) {
	if (direction == 'w') {
		this->fire_arrow_up();
	} else if (direction == 'a') {
		this->fire_arrow_left();
	} else if (direction == 'd') {
		this->fire_arrow_right();
	} else {
		this->fire_arrow_down();
	}

	this->num_arrows--;
}

/*
 * Function: play_game
 * Description: Runs one full iteration of the game.
 * Parameters: None
 * Returns: void
 */
void game::play_game(){
	while (!this->check_win() && !this->check_lose()) {
		// Print game board
		this->display_game();

		// TODO Display precepts around player's location
        percept_nearby();

		// Ask player for their action
		char action = this->get_player_action();
        

		// Process action
		if (this->is_direction(action)) {
			// W/A/S/D = move player
			char direction = action;
			this->move(direction);
		} else {
			// F = prompt for arrow fire direction and fire arrow
			char direction = this->get_arrow_fire_direction();
			this->fire_arrow(direction);
		}

		// TODO If the user is on a space with an event, trigger its encounter
        encounter_current_room();
        
        if (check_win()) {
            std::cout << "Congratulations! You've won the game!" << std::endl;
            //game_over = true;
        } else if (check_lose()) {
            std::cout << "Game over. You've lost the game." << std::endl;
            //game_over = true;
        }
        move_wumpus_around();  // Wumpus moves at the end of each turn
        
	}
}

/*******************************************************************/
/*******************************************************************/
//Added functions
/*******************************************************************/
/*******************************************************************/

/*
 * Function: initialize_grid
 * Description: Initializes the grid with empty rooms.
 * Parameters: None
 * Returns: void
 */
void game::initialize_grid() {
    grid.resize(height, std::vector<Room>(width));
}


/*
 * Function: game::place_one_event
 * Description: Places an event in a random empty room in the grid.
 * Parameters:
 *   event: Pointer to the event to place.
 * Returns: None
 */
void game::place_one_event(event* new_event, int & e_row, int & e_col) {
    int row, col;
    while (true) {
        row = rand() % height; // Random row
        col = rand() % width;  // Random column
        if (!grid[row][col].get_has_event() && row!= player_row && col != player_col) {
            grid[row][col].set_event(new_event); // Place event
            break;
        }
    }
    e_row = row;
    e_col = col;
}

/*
 * Function: game::place_player_rope
 * Description: Places player and rope in a random empty room in the grid.
 * Parameters:
 *   event: Pointer to the event to place.
 * Returns: None
 */
void game::place_player_rope(event* new_event) {
    int row, col;
    place_one_event(new_event, row, col);
    player_row = row;
    player_col = col;
    init_row = player_row;
    init_col = player_col;
}


/*
 * Function: place_events
 * Description: Randomly places events. Except rope event.
 * Parameters: None
 * Returns: void
 */
void game::place_events() {
    int row, col;
    // Place Wumpus
    place_one_event(new wumpus(), wumpus_row, wumpus_col );
    // Place Gold
    place_one_event(new gold(), row, col);
    // Place Pits
    for (int i = 0; i < 2; ++i)
        place_one_event(new bottomless_pit(), row, col);

    // Place Bats
    for (int i = 0; i < 2; ++i)
        place_one_event(new bat_swarm(), row, col);
    
    // Place Arrows
    for (int i = 0; i < 2; ++i)
        place_one_event(new arrow(), row, col);
}

/*
 * Function: move_wumpus
 * Description: Moves the Wumpus to a random room.
 * Parameters: None
 * Returns: void
 */

void game::move_wumpus() {
    if (!wumpus_alive) {
        // If the Wumpus is dead, it doesn't move
        return;
    }
    int prev_wumpus_row = wumpus_row;
    int prev_wumpus_col = wumpus_col;
    place_one_event(new wumpus(), wumpus_row, wumpus_col);
    grid[prev_wumpus_row][prev_wumpus_col].remove_event();
}

/*
 * Function: encounter_current_room
 * Description: Triggers the encounter in the current room if there's an event.
 * Parameters: None
 * Returns: void
 */
void game::encounter_current_room() {
    event* e = grid[player_row][player_col].get_event();
    if (e) {
        e->encounter(*this);
    }
}

/*
 * Function: percept_nearby
 * Description: Checks adjacent rooms for events and triggers percepts.
 * Parameters: None
 * Returns: void
 */
void game::percept_nearby() {
    // Directions to check: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Check each direction
    for (int i = 0; i < 4; ++i) {
        int new_row = player_row + directions[i][0];
        int new_col = player_col + directions[i][1];

        // Check if the new position is within the grid boundaries
        if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width) {
            // If there's an event in the adjacent room, trigger its percept
            event* adjacent_event = grid[new_row][new_col].get_event();
            if (adjacent_event) {
                adjacent_event->percept();
            }
        }
    }
}

/*
 * Function: set_has_gold
 * Description: Updates the flag indicating whether the player has collected the gold.
 * Parameters:
 *   g_flag (bool): True if the player has collected the gold, false otherwise.
 * Returns: None
 */
void game::set_has_gold(bool g_flag){
    has_gold = g_flag;
}

/*
 * Function: increase_arrow_count
 * Description: Increases the player's arrow count by one.
 * Parameters: None
 * Returns: None
 */
void game::increase_arrow_count(){
    num_arrows++;
}


/*
 * Function: remove_event_from_current_room
 * Description: Removes the event from the player's current room.
 * Parameters: None
 * Returns: void
 */
void game::remove_event_from_current_room() {
    // Access the player's current room on the grid
    Room& current_room = grid[player_row][player_col];

    // Remove the event from the current room
    current_room.remove_event();
}

/*
 * Function: get_arrows
 * Description: Retrieves the current count of arrows the player has.
 * Parameters: None
 * Returns (int): The number of arrows the player currently possesses.
 */
int game::get_arrows() const{
    return num_arrows;
}

/*
 * Function: set_game_over
 * Description: Sets the game over flag to indicate whether the game has ended.
 * Parameters:
 *   game_flag (bool): True to mark player lost and the game as over, false otherwise.
 * Returns: None
 */
void game::set_game_over(bool game_flag){
    game_over = game_flag;
}

/*
 * Function: set_confused_flag
 * Description: Sets the player's confused state flag.
 * Parameters:
 *   c_flag (bool): True if the player is confused, false otherwise.
 * Returns: None
 */
void game::set_confused_flag(bool c_flag){
    player_confused = c_flag;
}

/*
 * Function: has_player_collected_gold
 * Description: Checks whether the player has collected the gold.
 * Parameters: None
 * Returns (bool): True if the player has collected the gold, false otherwise.
 */
bool game::has_player_collected_gold() const{
    return has_gold;
    
}

/*
 * Function: is_wumpus_alive
 * Description: Checks whether the Wumpus is still alive.
 * Parameters: None
 * Returns (bool): True if the Wumpus is alive, false otherwise.
 */
bool game::is_wumpus_alive() const{
    return wumpus_alive;
}

/*
 * Function: get_different_direction
 * Description: When player confused choose direction other than the current
 * direction.
 * Parameters:
 *   action (char): The current direction.
 * Returns (char): A different valid direction ('w', 'a', 's', or 'd').
 */
char game::get_different_direction(char action){
    int i=0, j=0;
    char arr[4]={'w', 'a', 's', 'd'};
    for (j = 0; j < 4; j++)
        if(arr[j] == action)
            break;
    do {
        i = rand()%4;
    } while (i == j  && !this->is_valid_action(arr[i]));
    return arr[i];
}

/*
 * Function: game::~game
 * Description: Destructs the Game object, ensuring all events are properly deleted.
 * Parameters: None
 * Returns: None
 */
game::~game() {
    // Iterate over the grid to delete all events
    // Loop through each row of the grid
    for (int i = 0; i < width; ++i) {
        // Loop through each room in the row
        for (int j = 0; j < height; ++j) {
            if(grid[i][j].get_has_event())
                grid[i][j].remove_event(); // Remove and delete any events in the room
        }
    }
}

/*
 * Function: move_wumpus_around
 * Description: Bonus Work. Moves the Wumpus to a random empty adjacent room.
 * If all adjacent rooms are occupied, the Wumpus stays in the same room.
 * Parameters: None
 * Returns: void
 */
void game::move_wumpus_around() {
    if (!wumpus_alive) {
        // If the Wumpus is dead, it doesn't move
        return;
    }

    // Directions for adjacent movement: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int empty_rooms[4][2];  // Array to store empty adjacent rooms
    int empty_count = 0;    // Counter for empty adjacent rooms

    // Check each adjacent room
    for (int i = 0; i < 4; ++i) {
        int new_row = wumpus_row + directions[i][0];
        int new_col = wumpus_col + directions[i][1];

        // Check if the room is within bounds and empty
        if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width &&
            !grid[new_row][new_col].get_has_event() && !(new_row == player_row && new_col == player_col)) {
            empty_rooms[empty_count][0] = new_row;
            empty_rooms[empty_count][1] = new_col;
            empty_count++;
        }
    }

    if (empty_count > 0) {
        // Randomly select one of the empty adjacent rooms
        int random_index = rand() % empty_count;
        int new_row = empty_rooms[random_index][0];
        int new_col = empty_rooms[random_index][1];

        // Move the Wumpus to the new location
        grid[new_row][new_col].set_event(new wumpus());
        grid[wumpus_row][wumpus_col].remove_event(); // Remove Wumpus from old location

        // Update Wumpus position
        wumpus_row = new_row;
        wumpus_col = new_col;
    }
}

/*
 * Function: place_hidden_passages
 * Description: Places hidden passages events on the grid. Two hidden passages are added,
 * allowing the player to teleport between them. Ensures no events overlap and avoids placing events
 * at the player's starting position.
 * Parameters: None
 * Returns: None
 */
void game::place_hidden_passages() {
    int row1, col1, row2, col2;

    // Place hidden passages
    do {
        row1 = rand() % height;
        col1 = rand() % width;
    } while (grid[row1][col1].get_has_event() || (row1 == player_row && col1 == player_col));

    do {
        row2 = rand() % height;
        col2 = rand() % width;
    } while ((row1 == row2 && col1 == col2) || grid[row2][col2].get_has_event() || (row2 == player_row && col2 == player_col));

    grid[row1][col1].set_event(new hidden_passage(row2, col2));
    grid[row2][col2].set_event(new hidden_passage(row1, col1));
}

/*
 * Function: move_player
 * Description: Updates the player's position on the game grid.
 * Updates the player's coordinates and ensures that the new position is valid.
 * Parameters:
 *   row (int): The new row index for the player.
 *   col (int): The new column index for the player.
 * Returns: None
 */
void game::move_player(int row, int col) {
    // Update player's position
    player_row = row;
    player_col = col;

    // Log the change in player position for debugging
    //std::cout << "Player moved to position (" << row << ", " << col << ")." << std::endl;
}

/*
 * Function: set_has_lucky_ring
 * Description: Activates or deactivates the Lucky Ring and sets protections.
 * Parameters:
 *   active (bool): True to activate the Lucky Ring, false to deactivate it.
 * Returns: None
 */
void game::set_has_lucky_ring(bool active) {
    lucky_ring_active = active;
    if (active) {
        lucky_ring_lifes = 2; // Set initial protections
    }
}

/*
 * Function: use_ring_lifes
 * Description: Uses one protection from the Lucky Ring, if available.
 * Parameters: None
 * Returns (bool): True if the Lucky Ring was used, false otherwise.
 */
bool game::use_ring_lifes() {
    if (lucky_ring_lifes > 0) {
        --lucky_ring_lifes;
        if (lucky_ring_lifes == 0) {
            std::cout << "The Lucky Ring crumbles apart after saving you." << std::endl;
            lucky_ring_active = false;
        }
        return true;
    }
    return false;
}
