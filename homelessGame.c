#include <stdio.h>
#include <stdlib.h>
// define player and city structs
struct Player {
  int hunger;
  int thirst;
  int health;
  int money;
    int x;
  int y;
};

struct City {
  int x;
  int y;
};

// define global variables
struct Player player;
struct City city;

// define function prototypes
void setup();
void loop();
void printPlayerStats();
void printLocation();
void handleInput();
void printOptions();
void checkGameOver();

void gatherFood();
void gatherMoney();
void move(int, int);

int main() {
  setup();
  loop();
  return 0;
}


void setup() {
  player.hunger = 100;
  player.thirst = 100;
  player.health = 100;
  player.money = 0;

  city.x = 10;
  city.y = 10;
}

// main game loop
void loop() {
  // print player stats and current location
  while (1){
  printPlayerStats();
  printLocation();

  // present options to player
  printOptions();

  // check if player has won or lost
  checkGameOver();
  }
}

// print player stats (hunger, thirst, health, money)
void printPlayerStats() {
  printf("Hunger: %d\n", player.hunger);
  printf("Thirst: %d\n", player.thirst);
  printf("Health: %d\n", player.health);
  printf("Money: $%d\n", player.money);
}

// print player's current location in the city
void printLocation() {
  printf("Location: (%d, %d)\n", player.x, player.y);
}

// present options to player (move, gather, craft, etc.)
void printOptions() {
  printf("What do you want to do?\n");
  printf("1. Move\n");
  printf("2. Gather\n");
  // etc.

  // get player input and handle action
  int input = 0;
  printf("Enter option number: ");
  scanf("%d", &input);

  switch (input) {
    case 1:
      // move player in a specific direction
      int dx = 0;
      int dy = 0;
      printf("Enter direction to move (N, S, E, W): ");
      char direction = getchar();
      if (direction == 'N') {
        dy = 1;
      } else if (direction == 'S') {
        dy = -1;
      }
else if (direction == 'E') {
        dx = 1;
      } else if (direction == 'W') {
        dx = -1;
      }
      move(dx, dy);
      break;
    case 2:
      // gather food or money
      int choice = 0;
      printf("1. Find food\n");
      printf("2. Make money\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      if (choice == 1) {
        gatherFood();
      } else if (choice == 2) {
        gatherMoney();
      }
      break;
    // etc.
  }
}

// move player in a specific direction
void move(int dx, int dy) {
  player.x += dx;
  player.y += dy;

  // reduce player's health for moving
  player.health -= 5;
}

// gather food from the city
void gatherFood() {
  // find food and increase hunger level
  player.hunger += 10;
}

// make money in the city
void gatherMoney() {
  // make money and increase thirst level
  player.money += 10;
  player.thirst += 5;
}

// check if player has won or lost
void checkGameOver() {
  // player wins if they reach the end of the city
  if (player.x == city.x && player.y == city.y) {
    printf("Congratulations! You reached the end of the city and won the game!\n");
    exit(0);
  }

  // player loses if their health, hunger, or thirst reaches 0
  if
(player.health <= 0 || player.hunger <= 0 || player.thirst <= 0) {
    printf("Game over! You ran out of health, hunger, or thirst and lost the game.\n");
    exit(0);
  }
}
