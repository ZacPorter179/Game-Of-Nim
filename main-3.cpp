#include <ctime> // Include library for time-based functions
#include <iostream> // Include library for input and output operations
using namespace std; // Use the standard namespace

// Function to determine the computer's choice of toothpicks
int computerChoice(int remainingToothpicks) {
  if (remainingToothpicks == 1) { // If only one toothpick remains
    return 1; // Take the last toothpick
  } else if (remainingToothpicks >= 2 && remainingToothpicks <= 4) { // If 2 to 4 toothpicks remain
    return remainingToothpicks - 1; // Take enough to leave 1 for the opponent
  } else if (remainingToothpicks >= 6 && remainingToothpicks <= 8) { // If 6 to 8 toothpicks remain
    return remainingToothpicks - 5; // Take enough to leave 5 toothpicks
  } else {
    int x = (rand() % 3) + 1; // Generate a random number between 1 and 3
    return (4 * x) % 3 + 1; // Compute the number of toothpicks to take
  }
}

// Main function
int main() {
  srand(time(0)); // Seed the random number generator with current time

  int toothPicks = 23; // Initialize the total number of toothpicks
  string playerName; // Variable to store the player's name
  int playerPick; // Variable to store the player's choice of toothpicks
  int computerPick; // Variable to store the computer's choice of toothpicks

  cout << "Welcome to the 23 Toothpick Game!\n"; // Display game introduction
  cout << "Please enter your name:\n"; // Prompt the player for their name
  cin >> playerName; // Read the player's name from input

  while (toothPicks > 0) { // Loop until all toothpicks are taken
    cout << "There are " << toothPicks << " toothpicks left.\n"; // Display remaining toothpicks
    cout << "How many toothpicks will you take out? (1, 2, or 3)\n"; // Ask for player's move
    cin >> playerPick; // Read the player's choice

    if (playerPick < 1 || playerPick > 3 || playerPick > toothPicks) { // Validate input
      cout << "Invalid input. Please try again.\n"; // Display error message
      continue; // Restart the loop
    }
    toothPicks -= playerPick; // Subtract player's pick from total toothpicks

    if (toothPicks == 0) { // If no toothpicks remain
      cout << "Sorry, " << playerName
           << " you lost to a dang computer! Better luck next time!\n"; // Display loss message
      break; // Exit the loop
    }
    computerPick = computerChoice(toothPicks); // Get computer's move
    cout << "The computer took out " << computerPick << " toothpicks.\n"; // Display computer's move

    toothPicks -= computerPick; // Subtract computer's pick from total toothpicks

    if (toothPicks == 0) { // If no toothpicks remain
      cout << "Congratulations, " << playerName
           << " ! You beat the computer!\n"; // Display win message
      break; // Exit the loop
    }
  }
  cout << "Game Over. Thanks for playing!\n"; // Display game over message
  return 0; // Return successful execution status
}
