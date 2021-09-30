#ifdef _WIN32
#include <conio.h>
#else
#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")
#endif

#include <stdbool.h>

#define BOARD_SIZE 9
#define ROWS 3
#define COLUMNS 3

void draw_board();
bool select_square(int position, int player);
bool square_already_selected(int position);
bool is_valid_position(int position);
bool square_available();
bool player_won(char player);

char board_state[BOARD_SIZE] = {'1','2','3','4','5','6','7','8','9'};
char players[2] = {'X', 'O'};

int main() {
  int player = 0;
  bool square_selected = false;
  int square;
  bool game_over = false;

  draw_board();
  do {
    // wait for state to change
    bool square_selected = false;
    while(!square_selected) {
      printf("Player %d (%c)> ", player + 1, players[player]);
      scanf("%d", &square);
      square_selected = select_square(square, player);
    }

    // update UI with changed state
    draw_board();

    // determine end state
    if(player_won(players[player])) {
      printf("Player %d won!\n", player + 1);
      game_over = true;
    } else if(!square_available()) {
      printf("No more moves avaiable\n");
      game_over = true;
    }

    player = (player + 1) % 2;
  } while(!game_over);
}

/**
 * @brief Draw the Tic-Tac-Toe board in the screen
 */
void draw_board() {
  clrscr();
  int current_index = 0;
  for(int row = 0; row < ROWS; row++){
    for(int column = 0; column < COLUMNS; column++) {
      printf("%c ", board_state[current_index]);
      current_index += 1;
    }
    printf("\n");
  }
}

/**
 * @brief There are only BOARD_SIZE squares available; the user cannot choose any number higher than that.
 * 
 * @param position the number on the board
 * @return true   position is between 1 and BOARD_SIZE
 * @return false  position is either negative or larger than BOARD_SIZE
 */
bool is_valid_position(int position) {
  return ((position > 0) && (position <= BOARD_SIZE));
}

/**
 * @brief if a square already has an X or O, it can't be replaced
 * 
 * @param position the desired position to place the game piece
 * @return true    the square already contains an X or O
 * @return false   the square is available
 */
bool square_already_selected(int position) {
  char entry = board_state[position - 1];
  return (entry == 'X') || (entry == 'O');
}

/**
 * @brief Mark a square with an X or O
 * 
 * @param position The square to mark
 * @param player   X or O
 * @return true    The square has been marked with an X or O
 * @return false   The square has been marked previously
 */
bool select_square(int position, int player) {
  bool succesfully_selected_square = false;
  if(is_valid_position(position)) {
    if(square_already_selected(position)) {
      printf("Square %d has already been selected\n", position);
    } else {
      char game_piece = players[player];
      board_state[position - 1] = game_piece;
      succesfully_selected_square = true;
    }
  } else {
    printf("Can only choose from 1-9\n");
  }

  return succesfully_selected_square;
}

/**
 * @brief Did the player have all their game pieces in a row
 * 
 * @param player  X or O
 * @return true   The player won
 * @return false  The game continues
 */
bool player_won(char player) {
  static int winning_positions[8][3] = {
    // horizontal
    {0,1,2},
    {3,4,5},
    {6,7,8},
    // vertical
    {0,3,6},
    {1,4,7},
    {2,5,8},
    // diagonals
    {0,4,8},
    {2,4,6}
  };

  bool found_winning_position = false;
  for(int row = 0; (row < 8) && !found_winning_position; row++) {
    char first_position = board_state[winning_positions[row][0]];
    char second_position = board_state[winning_positions[row][1]];
    char third_position = board_state[winning_positions[row][2]];

    found_winning_position = (first_position == player) && (second_position == player) && (third_position == player);
  }

  return found_winning_position;
}

/**
 * @brief Determine tie
 * 
 * @return true   squares can still be marked
 * @return false  game over
 */
bool square_available() {
  static int num_squares = 0;
  return ++num_squares < BOARD_SIZE;
}
