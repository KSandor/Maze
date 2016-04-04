enum {N=1,E=4,S=2,W=8};
int DX[9];
int DY[9];
int OPPOSITE[9];

int main_maze_generator(int WIDTH, int HEIGHT);
int shuffle_array_recursif(int *array,int size,int i);
int carve_passage(int cx, int cy,int HEIGHT, int WIDTH, int **grid);
int carve_passage_2(int cx, int cy, int dx, int dy, int nx, int ny, int HEIGHT, int WIDTH, int **grid, int *directions, int i);
int maze_entrance_exit(int HEIGHT, int WIDTH, int **grid);
int** table2D(int lenght, int width, int i, int** table_0);
