#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include <math.h>



int main()
{
    int WIDTH,HEIGHT;
    printf("Enter the Width then the Height of the maze you want:\n");
    scanf("%d",&WIDTH);
    scanf("%d",&HEIGHT);


    int **maze=NULL;
    maze=table2D(WIDTH,HEIGHT,0,maze);

    maze=main_maze_generator(WIDTH,HEIGHT);



    print_maze(HEIGHT,WIDTH,maze);

    print_2Darray_content(HEIGHT,WIDTH,maze);


  return 0;

}
