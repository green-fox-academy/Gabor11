#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int main()
{
	int lives, range; // I renamed 'x' to 'lives' and 'y' to 'range'..
	int round; // I renamed 'count' to 'round'..
	int guess = 0;
	unsigned int rand_max;
	unsigned int rand_min;
	printf("please add the minimum number!\n");
	scanf("%d", &rand_min);
	printf("please add the maximum number!\n");
	scanf("%d", &rand_max);	srand(time(NULL));
	int rand_num = rand() % (rand_max + 1 - rand_min) + rand_min;
	range = rand_max - rand_min;
	lives = log10(range) / log10(2) - 3; // I put the substracted 3 to here because it is more obvious where it oomes from

	printf("I have a number between %d and %d. You have %d lives\n", rand_min, rand_max, lives);

	for (round = 1; round <= lives; round++) {
		printf("\n>");
		scanf("%d", &guess);

		// I took this 'while loop' out of here, because of no need.
        if (guess == rand_num) {
            printf("Yeeeeey, you did well! It took you %d tries!", round);
            break;
        }

        if (guess > rand_num)
            printf("Too big, You have %d, lives left\n", lives - round);
        else
            printf("Too low, You have %d, lives left\n", lives - round);

	}
    // I removed an "if" statement because it was useless here.
    printf("You have used all your lives!\nGAME OVER!");

	return 0;
}
