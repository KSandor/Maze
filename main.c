#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "labyrinth_generation.h"

int main()
{
    int WIDTH,HEIGHT;
    printf("Enter the Width then the Height of the maze you want:\n");
    scanf("%d",&WIDTH);
    scanf("%d",&HEIGHT);
    main_maze_generator(WIDTH,HEIGHT);
}
