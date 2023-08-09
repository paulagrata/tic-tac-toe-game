#include <iostream>
#include "play.hpp"

std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int position = 0;

void introduction() {

  std::cout << "press [enter] to begin game: ";
  std::cin.ignore();
  std::cout << "\n";
  std::cout << "==========================\n";
  std::cout << "      ticy-tacy-toey\n";
  std::cout << "==========================\n\n";
  
  std::cout << "player 1 is ✖'s\n";
  std::cout << "player 2 is ⊙'s\n\n";

  std::cout << "here's the board:\n\n";

  std::cout << "     |     |      \n";
  std::cout << "  1  |  2  |  3   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  4  |  5  |  6   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  7  |  8  |  9   \n";
  std::cout << "     |     |      \n\n";
}

// checking each to see if all three cells in a row/column/diagonals contain the same non-empty value
bool is_winner() {
  bool winner = false;
  // rows
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
    winner = true;
  } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
    winner = true;
  } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
    winner = true;
  } // columns
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
    winner = true;
  } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
    winner = true;
  } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
    winner = true;
  } // diagonals
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
    winner = true;
  }
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
    winner = true;
  }
  return winner;
}

// checks if board is completely filled up
bool filled_up() {
  bool filled = true;
  for (int i = 0; i < 9; i++) {
    if (board[i] == " ") {
      filled = false;
    }
  }
  return filled;
}

// draws board displaying the current state of the game
void draw() {
  std::cout << "     |     |      \n";
  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  std::cout << "     |     |      \n";
  std::cout << "\n";
}

// checks if number is on board
void check_position(){
   while (!(std::cin >> position) || position < 1 || position > 9) {
    std::cout << "player " << player << ", that number is not on the board silly. [enter #1-9]: ";
    std::cin.clear();
    std::cin.ignore();
  }
}

// check if position is taken
void check_taken(){
  while (board[position-1] != " ") {
    std::cout << "that spot is taken! redo? [enter #1-9]: ";
    check_position();
  }
}


// asks user's input for turn placement and checks if number is on board and if spot on board is taken
void set_position() {
  std::cout << "player " << player << "'s turn [enter #1-9]: ";
  check_position();
  check_taken();
  std::cout << "\n";
}



// updates the game board based on the current player's move
void update_board() {
  if (player % 2 == 1) {
    board[position-1] = "✖";
  } else {
    board[position-1] = "⊙";
  }
}

// switches player
void change_player() {
  if (player == 1) {
    player++;
  } else {
    player--;
  }
}

// checks if there is winner/board is filled, then calls functions 
void take_turn() {
  while (!is_winner() && !filled_up()) {
    set_position();
    update_board();
    draw();
    if (!is_winner() && !filled_up()) {
      change_player();
    }
  }
}

// ends game if there is a winner or tie
void end_game() {
  if (is_winner()) {
    //player = (player == 1) ? 2 : 1;
    std::cout << "winner, winner, chicken dinner!\n\n";
    std::cout << "player " << player << " is the winner!!! ggs.";
  }
  else if (filled_up()) {
    std::cout << "tie??? ew!\n";
  }
}
