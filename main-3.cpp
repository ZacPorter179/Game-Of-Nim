#include <ctime>
#include <iostream>
using namespace std;
int computerChoice(int remainingToothpicks) {
  if (remainingToothpicks == 1) {
    return 1;
  } else if (remainingToothpicks >= 2 && remainingToothpicks <= 4) {
    return remainingToothpicks - 1;
  } else if (remainingToothpicks >= 6 && remainingToothpicks <= 8) {
    return remainingToothpicks - 5;
  } else {
    int x = (rand() % 3) + 1;
    return (4 * x) % 3 + 1;
  }
}
int main() {

  srand(time(0));

  int toothPicks = 23;
  string playerName;
  int playerPick;
  int computerPick;

  cout << "Welcome to the 23 Toothpick Game!\n";
  cout << "Please enter your name:\n";
  cin >> playerName;

  while (toothPicks > 0) {
    cout << "There are " << toothPicks << " toothpicks left.\n";
    cout << "How many toothpicks will you take out? (1, 2, or 3)\n";
    cin >> playerPick;

    if (playerPick < 1 || playerPick > 3 || playerPick > toothPicks) {
      cout << "Invalid input. Please try again.\n";
      continue;
    }
    toothPicks -= playerPick;

    if (toothPicks == 0) {
      cout << "Sorry, " << playerName
           << " you lost to a dang computer! Better luck next time!\n";
      break;
    }
    computerPick = computerChoice(toothPicks);
    cout << "The computer took out " << computerPick << " toothpicks.\n";

    toothPicks -= computerPick;

    if (toothPicks == 0) {
      cout << "Congradulations, " << playerName
           << " ! You beat the computer!\n";
      break;
    }
  }
  cout << "Game Over. Thanks for playing!\n";
  return 0;
}
