#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 5

void generate_pattern(char pattern[][7], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern[i][j] = (rand() % 2) ? '*' : '!';
        }
    }
}

void print_pattern(char pattern[][7], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }
}

int game_level(char pattern1[][7], char pattern2[][7], int rows, int cols, int differences_to_find) {
    int attempts = MAX_ATTEMPTS, differences = 0;
    int row, col;

    printf("\n**Spot the Difference - Level Start!**\n");
    printf("Find %d differences between the two patterns!\n", differences_to_find);

    printf("Pattern 1:\n");
    print_pattern(pattern1, rows, cols);
    printf("Pattern 2:\n");
    print_pattern(pattern2, rows, cols);

    while (attempts > 0 && differences < differences_to_find) {
        printf("You have %d attempts left.\n", attempts);
        printf("Enter your guess (row column): ");
        scanf("%d %d", &row, &col);

        if (row >= 1 && row <= rows && col >= 1 && col <= cols) {
            row--; col--;
            if (pattern1[row][col] != pattern2[row][col]) {
                printf("Correct! You found a difference at (%d, %d).\n", row + 1, col + 1);
                differences++;
            } else {
                printf("Incorrect! Try again.\n");
            }
        } else {
            printf("Invalid input. Row and column should be between 1 and %d.\n", rows);
            continue;
        }

        attempts--;
        
        if (differences == differences_to_find) {
            printf("Congratulations! You found all %d differences!\n", differences_to_find);
            break;
        }

        if (attempts == 0) {
            printf("Game over! You've run out of attempts.\n");
            break;
        }
    }
    
    return differences;
}

int main() {
    srand(time(0));

    char pattern1[5][5], pattern2[5][5];
    char pattern3[7][7], pattern4[7][7];
    char pattern5[9][9], pattern6[9][9];
    int total_score = 0;

    generate_pattern(pattern1, 5, 5);
    generate_pattern(pattern2, 5, 5);
    generate_pattern(pattern3, 7, 7);
    generate_pattern(pattern4, 7, 7);
    generate_pattern(pattern5, 9, 9);
    generate_pattern(pattern6, 9, 9);

    printf("**Welcome to the Spot the Difference Game!**\n");

    int differences_level_1 = game_level(pattern1, pattern2, 5, 5, 5);
    total_score += differences_level_1;
    printf("\nYour score after Level 1: %d\n", total_score);

    char choice;
    printf("\nDo you want to move to Level 2? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int differences_level_2 = game_level(pattern3, pattern4, 7, 7, 6);
        total_score += differences_level_2;
        printf("\nYour score after Level 2: %d\n", total_score);

        printf("\nDo you want to move to Level 3? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            int differences_level_3 = game_level(pattern5, pattern6, 9, 9, 7);
            total_score += differences_level_3;
            printf("\nYour score after Level 3: %d\n", total_score);

            printf("\n**Game Over!**\n");
        } else {
            printf("Thanks for playing! Your final score is: %d\n", total_score);
        }
    } else {
        printf("Thanks for playing! Your final score is: %d\n", total_score);
    }

    return 0;
}
