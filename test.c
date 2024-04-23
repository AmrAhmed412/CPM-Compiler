#include <stdio.h>

// Define an enum named Color with three constants: RED, GREEN, and BLUE
enum Color
{
    RED,
    GREEN,
    BLUE
};

int main()
{
    // Declare a variable of type Color and initialize it with the GREEN constant
    enum Color myColor = RED;
    char *a = "RED";
    // Use a switch statement to print a message based on the value of myColor
    switch (a)
    {
    case "RED":
        printf("The color is red.\n");
        break;
    case GREEN:
        printf("The color is green.\n");
        break;
    case BLUE:
        printf("The color is blue.\n");
        break;
    default:
        printf("Unknown color.\n");
        break;
    }

    return 0;
}
