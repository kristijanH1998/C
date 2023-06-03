#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess (int num, int rndnum, int low, int high){
    int attempt = 1;
    while (num != rndnum){
        if (num < rndnum){
            low = num + 1;
            printf("The number you entered is lower than computer's choice, the"
                   " correct number is in the range from %d to %d\n", low, high);
        } else if (num > rndnum){
            high = num - 1;
            printf("The number you entered is higher than computer's choice, the"
                   " correct number is in the range from %d to %d\n", low, high);

        }
        printf("Make another guess: ");
        scanf("%d", &num);
        attempt++;
    }
    printf("That's right! You guessed right in %d attempts!\n", attempt);

}




int main()
{
    int num = 0;
    int rndnum = 0;
    int low = 0;
    int high = 100;
    printf("The computer chose a random number from 0 to 100. Can you guess "
           "which number it is? Enter your guess: ");
    scanf("%d", &num);
    printf("\n");

    srand(time(0));
    rndnum = (rand() % 100 + 1);
    printf("%d\n", rndnum);

    guess(num, rndnum, low, high);

    return 0;
}
