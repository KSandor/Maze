#include <stdio.h>
#include <time.h>
#include "labyrinth_generation.h"



int main_maze_generator(int WIDTH, int HEIGHT) {


    int x,y;
    OPPOSITE[N] = S;
    OPPOSITE[E] = W;
    OPPOSITE[S] = N;
    OPPOSITE[W] = E;

    DX[N] = 0;
    DX[E] = 1;
    DX[S] = 0;
    DX[W] = -1;

    DY[N] = -1;
    DY[E] = 0;
    DY[S] = 1;
    DY[W] = 0;

    int grid[WIDTH][HEIGHT];

    srand((unsigned int)time((time_t *)NULL));

    memset(&grid[0], 0, sizeof(grid));

    carve_passage(0, 0,HEIGHT,WIDTH, grid);

    maze_entrance_exit(HEIGHT,WIDTH,grid);




    /** Display the grid **/
    printf(" ");
    for(x = 0; x < (WIDTH * 2); x++) printf("_");
    printf("\n");
    for(y = 0; y < HEIGHT; y++) {
        printf("|");
        for(x = 0; x < WIDTH; x++) {
            printf( ((grid[x][y] & S) !=  0)?" ":"_");
            if((grid[x][y] & E) != 0){
                printf((( (grid[x][y] | grid[x + 1][y]) & S) != 0) ?" ":"_");
            }
            else {
            printf("|");
            }
        }
    printf("\n");
    }



  return grid;
}


int shuffle_array_recursif(int *array,int size,int i) {
    if(i<(size-1)) {
        int r=i+(rand()%(size-i));
        int temp=array[i];
        array[i]=array[r];
        array[r]=temp;
        return(array,size,i+1);
    }
}


int carve_passage(int cx, int cy,int HEIGHT, int WIDTH, int *grid[WIDTH][HEIGHT]) {
    int dx, dy, nx, ny;
    int *directions = NULL;
    directions = (int*)malloc(4*sizeof(int));
    directions[0]=N;
    directions[1]=E;
    directions[2]=S;
    directions[3]=W;
    shuffle_array_recursif(directions, 4,0);
    carve_passage_2(cx,cy,dx,dy,nx,ny,HEIGHT,WIDTH,grid,directions,0);
}




int carve_passage_2(int cx, int cy, int dx, int dy, int nx, int ny, int HEIGHT, int WIDTH, int *grid[WIDTH][HEIGHT], int *directions, int i) {
    if(i<4){
        dx = DX[directions[i]];
        dy = DY[directions[i]];
        nx = cx + dx;
        ny = cy + dy;
        if ( ((nx < WIDTH) & (nx >= 0)) & ((ny < HEIGHT) & (ny >= 0)) ) {
            if (grid[nx][ny] == 0) {
                grid[cx][cy] = (int)((int)grid[cx][cy] | (int)directions[i]);
                grid[nx][ny] = (int)((int)grid[nx][ny] | (int)OPPOSITE[directions[i]]);
                carve_passage(nx, ny,HEIGHT,WIDTH,grid);
            }
        }
        return carve_passage_2(cx,cy,dx,dy,nx,ny,HEIGHT,WIDTH,grid,directions,i+1);
    }
}





int maze_entrance_exit(int HEIGHT, int WIDTH, int *grid[WIDTH][HEIGHT]) {
    int x=rand()%HEIGHT;
    int y=rand()%HEIGHT;
    grid[0][x]=grid[0][0]+W;
    grid[HEIGHT-1][HEIGHT-1]=grid[HEIGHT-1][HEIGHT-1]+E;
}








/** Dynamic allocation of a 2 dimension array **/

int** table2D(int lenght, int width, int i, int** table_0)
{
    if(i==0)
        table_0 = (int**)malloc(lenght*sizeof(int));
    if(i < lenght) {
        table_0[i] = (int*)malloc(width*sizeof(int));
        table2D(lenght,width,i+1,table_0);
    }
    else
        return table_0;
}


