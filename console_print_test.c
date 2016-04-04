#include <stdio.h>
#include <stdlib.h>
#include "console_print_test.h"

/** Display the grid **/

void print_maze(int HEIGHT,int WIDTH,int **maze){
    int y,x;
    printf(" ");
    for(x = 0; x < (WIDTH * 2); x++) printf("_");
    printf("\n");
    for(y = 0; y < HEIGHT; y++) {
        if((maze[0][y] & W) !=0)
        {
            printf(" ");
        }
        else
            printf("|");
        for(x = 0; x < WIDTH; x++) {
            printf( ((maze[x][y] & S) !=  0)?" ":"_");
            if((maze[x][y] & E) != 0){
                if(x==WIDTH-1)
                    printf(" ");
                else
                printf((( (maze[x][y] | maze[x + 1][y]) & S) != 0) ?" ":"_");
            }
            else {
            printf("|");
            }
        }
    printf("\n");
    }
}



void print_2Darray_content(int HEIGHT,int WIDTH,int **array){
    int x,y;
    for(y = 0; y < HEIGHT; y++) {
        for(x = 0; x < WIDTH; x++) {
            printf("%3d",array[x][y]);
        }
        printf("\n");
    }

}
