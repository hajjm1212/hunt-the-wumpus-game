/*
 * File: game.hpp
 * Authors: Instructor and Mia Hajj
 * Description: Partial code provided by instructor and complemented with Mia's code to define the game class.
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "room.hpp"

// game interface
class game {
private:
	// TODO declare a 2D vector of Room objects:
    std::vector<std::vector<Room> > grid;
    
	// Suggested member variables:
	int num_arrows; 	// keep track of number of arrows remaining
	int width;				// width of the game grid
	int height;				// height of the game grid
	bool debug;				// debug mode or not

	// TODO Feel free to add more member variables if you'd like
    // Player's position
    int player_row;
    int player_col;
    //Initial player position
    int init_row;
    int init_col;
    //wumpus position
    int wumpus_row;
    int wumpus_col;

    // Game state variables
    bool has_gold;
    bool wumpus_alive;
    bool game_over;         //lost game
    bool player_confused;   //in bat room
    
    // Bonus 3 - Lucky Ring
    bool lucky_ring_active;    // Indicates if player has Lucky Ring and is active
    int lucky_ring_lifes; // Remaining protections

    // Internal methods
    /*
     * Function: initialize_grid
     * Description: Initializes the grid with empty rooms.
     * Parameters: None
     * Returns: void
     */
    void initialize_grid();
    
    /*
     * Function: place_events
     * Description: Randomly places events. Except rope event.
     * Parameters: None
     * Returns: void
     */
    void place_events();
    
    /*
     * Function: encounter_current_room
     * Description: Triggers the encounter in the current room if there's an event.
     * Parameters: None
     * Returns: void
     */
    void encounter_current_room();
    
    /*
     * Function: percept_nearby
     * Description: Checks adjacent rooms for events and triggers percepts.
     * Parameters: None
     * Returns: void
     */
    void percept_nearby();
    
    /*
     * Function: move_wumpus
     * Description: Moves the Wumpus to a random room.
     * Parameters: None
     * Returns: void
     */
    void move_wumpus();
    
    /*
     * Function: game::place_one_event
     * Description: Places an event in a random empty room in the grid.
     * Parameters:
     *   event: Pointer to the event to place.
     * Returns: None
     */
    void place_one_event(event* new_event, int & row, int & col);
    
    /*
     * Function: game::place_player_rope
     * Description: Places player and rope in a random empty room in the grid.
     * Parameters:
     *   event: Pointer to the event to place.
     * Returns: None
     */
    void place_player_rope(event* new_event);
    
    /*
     * Function: get_different_direction
     * Description: When player confused choose direction other than the current
     * direction.
     * Parameters:
     *   action (char): The current direction.
     * Returns (char): A random valid direction ('w', 'a', 's', or 'd').
     */
    char get_different_direction(char action);
    
    /*
     * Function: move_wumpus_around
     * Description: Bonus work: Moves the Wumpus to a random empty adjacent room.
     * If all adjacent rooms are occupied, the Wumpus stays in the same room.
     * Parameters: None
     * Returns: void
     */
    void move_wumpus_around();
    
    /*
     * Function: place_hidden_passages
     * Description: Places hidden passages events on the grid. Two hidden passages are added,
     * allowing the player to teleport between them. Ensures no events overlap and avoids placing events
     * at the player's starting position.
     * Parameters: None
     * Returns: None
     */
    void place_hidden_passages();
    
public:
	// Suggested functions (there are no required functions here):
	
	/*
	 * Function: Constructor
	 * Description: Constructs game object with a grid matching the given
	 * 		width and height and all the private parameters.
	 * Parameters:
	 * 		width (int): Width of the grid
	 * 		height (int): Height of the grid
	 * 		debug (bool): Whether or not debug mode should be enabled
	 */
	game(int width, int height, bool debug);

	/*
	 * Function: display_game
	 * Description: Displays the game grid in the terminal
	 */
	void display_game() const;

	/*
	 * Function: check_win
	 * Description: Determines whether the player has won the game
	 * Returns (bool): True if the player has won, false otherwise
	 */
	bool check_win() const;

	/*
	 * Function: check_lose
	 * Description: Determines whether the player has lost the game
	 * Returns (bool): True if the player has lost, false otherwise
	 */
	bool check_lose() const;

	/*
	 * Function: is_direction
	 * Description: Returns true if the given character is a valid direction
	 * 		character (w/a/s/d) and false otherwise
	 * Parameters:
	 * 		c (char): The character to check
	 * Returns (bool): Boolean indicating whether the character is a valid
	 * 		direction character (w/a/s/d)
	 */
	bool is_direction(char c);

	/*
	 * Function: to_lower
	 * Description: Converts a given character to lowercase. Used to standardize
	 * 		a user's character input.
	 * Parameters:
	 * 		direction (char): Character to convert to lowercase
	 * Returns (char): Character converted to lowercase
	 */
	char to_lower(char direction);

	/*
	 * Function: can_move_in_direction
	 * Description: Determines whether the player can move in the given
	 * 		direction, based on their current location and the size of the
	 * 		grid.
	 * Parameters:
	 * 		direction (char): Direction the player wishes to move in
	 * Returns (bool): True if the player can move in the given direction
	 * 		without moving off the grid. False otherwise.
	 */
	bool can_move_in_direction(char direction);

	/*
	 * Function: is_valid_action
	 * Description: Determines whether the given action is valid.
	 * Parameters:
	 * 		action (char): Action the player wishes to perform.
	 * Returns (bool): True if the requested action is valid. False otherwise.
	 */
	bool is_valid_action(char action);

	/*
	 * Function: print_action_error
	 * Description: Prints a clear error message associated with the user's
	 * 		provided invalid action
	 * Parameters:
	 * 		action (char): Invalid action that the user requested
	 */
	void print_action_error(char action);

	/*
	 * Function: get_player_action
	 * Description: Prompts the player for their action for the turn and
	 * 		returns it as a char (w, a, s, d, or f). If the player enters
	 * 		an invalid action, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid action provided by the player.
	 */
	char get_player_action();

	/*
	 * Function: get_arrow_fire_direction
	 * Description: Prompts the player for the direction they want to fire an
	 * 		arrow (w, a, s, or d) and returns it as a char. If the player enters
	 * 		an invalid direction, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid direction provided by the player.
	 */
	char get_arrow_fire_direction();

	/*
	 * Function: move_up
	 * Description: Moves the player up one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_up();

	/*
	 * Function: move_down
	 * Description: Moves the player down one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_down();

	/*
	 * Function: move_left
	 * Description: Moves the player left one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_left();

	/*
	 * Function: move_right
	 * Description: Moves the player right one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_right();

	/*
	 * Function: move
	 * Description: Moves the player in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to move the player (a for
	 * 			west, s for south, d for east, w for north).
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move(char direction);

	/*
	 * Function: fire_arrow_up
	 * Description: Fires an arrow upward
	 * Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_up();

	/*
	 * Function: fire_arrow_down
	 * Description: Fires an arrow downward
	 * Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_down();

	/*
	 * Function: fire_arrow_left
	 * Description: Fires an arrow leftward
	 * Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_left();

	/*
	 * Function: fire_arrow_right
	 * Description: Fires an arrow rightward
	 * Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_right();

	/*
	 * Function: fire_arrow
	 * Description: Fires an arrow in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to fire arrow (a for
	 * 			west, s for south, d for east, w for north).
	 * Post-condition: Arrow is fired. Wumpus is killed if hit and moves if
	 * 		missed.
	 */
	void fire_arrow(char direction);

	/*
	 * Function: play_game
	 * Description: Runs one full iteration of the game
	 */
	void play_game();

	// TODO Add more member functions here
    //Accessor and mutators
    /*
     * Function: get_arrows
     * Description: Retrieves the current count of arrows the player has.
     * Parameters: None
     * Returns (int): The number of arrows the player currently possesses.
     */
    int get_arrows() const;
    
    /*
     * Function: has_player_collected_gold
     * Description: Checks whether the player has collected the gold.
     * Parameters: None
     * Returns (bool): True if the player has collected the gold, false otherwise.
     */
    bool has_player_collected_gold() const;
    
    /*
     * Function: is_wumpus_alive
     * Description: Checks whether the Wumpus is still alive.
     * Parameters: None
     * Returns (bool): True if the Wumpus is alive, false otherwise.
     */
    bool is_wumpus_alive() const;
    
    /*
     * Function: set_has_gold
     * Description: Updates the flag indicating whether the player has collected the gold.
     * Parameters:
     *   g_flag (bool): True if the player has collected the gold, false otherwise.
     * Returns: None
     */
    void set_has_gold(bool g_flag);
    
    /*
     * Function: increase_arrow_count
     * Description: Increases the player's arrow count by one.
     * Parameters: None
     * Returns: None
     */
    void increase_arrow_count();
    
    /*
     * Function: remove_event_from_current_room
     * Description: Removes the event from the player's current room.
     * Parameters: None
     * Returns: void
     */
    void remove_event_from_current_room();
    
    /*
     * Function: set_game_over
     * Description: Sets the game over flag to indicate whether the game has ended.
     * Parameters:
     *   game_flag (bool): True to mark player lost and the game as over, false otherwise.
     * Returns: None
     */
    void set_game_over(bool game_flag);
    
    /*
     * Function: set_confused_flag
     * Description: Sets the player's confused state flag.
     * Parameters:
     *   c_flag (bool): True if the player is confused, false otherwise.
     * Returns: None
     */
    void set_confused_flag(bool c_flag);
    
    /*
     * Function: game::~game
     * Description: Destructs the Game object, ensuring all events are properly deleted.
     * Parameters: None
     * Returns: None
     */
    ~game();
    
    /*
     * Function: move_player
     * Description: Updates the player's position on the game grid. This is for Bonus part.
     * Updates the player's coordinates and ensures that the new position is valid.
     * Parameters:
     *   row (int): The new row index for the player.
     *   col (int): The new column index for the player.
     * Returns: None
     */
    void move_player(int row, int col);
    

    /*
     * Function: set_has_lucky_ring
     * Description: Activates or deactivates the Lucky Ring and sets protections.
     * Parameters:
     *   active (bool): True to activate the Lucky Ring, false to deactivate it.
     * Returns: None
     */
    void set_has_lucky_ring(bool active);

    /*
     * Function: use_ring_lifes
     * Description: Uses one protection from the Lucky Ring, if available.
     * Parameters: None
     * Returns (bool): True if the Lucky Ring was used, false otherwise.
     */
    bool use_ring_lifes();

};
#endif
