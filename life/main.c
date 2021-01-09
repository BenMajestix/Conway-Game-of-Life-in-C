//
//  main.c
//  life
//
//  Created by Ben Bartel on 2021-01-08.
//

#include <stdio.h>
#include "stdlib.h"
#include <unistd.h>
#include <string.h>
void printBoard(void);
void createBoard(void);

int lookUp(int x, int y);
int lookDown(int x, int y);
int lookRight(int x, int y);
int lookLeft(int x, int y);
int lookUpRight(int x, int y);
int lookUpLeft(int x, int y);
int lookDownRight(int x, int y);
int lookDownLeft(int x, int y);

void birth(int x, int y);
void death(int x, int y);

void evalPos(void);
void evalBirth(int x, int y);
void evalDeath(int x, int y);

void runGame(int generations, unsigned int delay);

static int * * board;

int main(int argc, const char * argv[]) {
    FILE * filePointer;
    filePointer = fopen("model.txt", "r") ;
    char input[1181];
    
    if ( filePointer == NULL )
        {
            printf( "File failed to open." ) ;
        }
    fscanf(filePointer, "%[^\n]", input);
    fclose(filePointer);
    
    for (int i=0; i <= 1181; i++) {
        printf("%c\n", input[i]);
    }
    
    
    createBoard();
    
    
    int gen = 0;
    unsigned int delay = 0;
    printf("\nHow many Generations should it show?");
    printf("\nHow much should the Delay be? If none, put 0.");
    printf("\nWrite those in the next line, first Generations and then Delay.");
    scanf("%d %d", &gen, &delay);
    printf("%d %d", gen, delay);
    runGame(gen, delay);
    return 0;
}

void runGame(int generations, unsigned int delay){
    int generationCount = 0;
    printBoard();
    if(delay == 0){
        for(generationCount = 0; generationCount <= generations; generationCount ++){
            printf("Generation: %d", generationCount);
            evalPos();
            printBoard();
            }
    }
    else{
        for(generationCount = 0; generationCount <= generations; generationCount ++){
            printf("Generation: %d", generationCount);
            evalPos();
            printBoard();
            sleep(delay);
            }
        
    }
    

    
    exit(0);
}




void birth(int x, int y){
    board[x][y] = 1;
}
void death(int x, int y){
    board[x][y] = 0;
}

void evalPos(){
    int i, j;
    int x, y = 0;
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            x = j;
            y = i;
            
            if(board[x][y] == 0){
                evalBirth(x, y);
            }
            else if(board[x][y] == 1){
                evalDeath(x, y);
            }
        }
    }
}
void evalBirth(int x, int y){
    //Number of Objects around
    int s = 0;
    
    s += lookUp(x, y);
    s += lookDown(x, y);
    s += lookRight(x, y);
    s += lookLeft(x, y);
    s += lookUpRight(x, y);
    s += lookUpLeft(x, y);
    s += lookDownRight(x, y);
    s += lookDownLeft(x, y);
    
    if(s == 3){birth(x, y);}
}
void evalDeath(int x, int y){
    //Number of Objects around
    int s = 0;
    
    s += lookUp(x, y);
    s += lookDown(x, y);
    s += lookRight(x, y);
    s += lookLeft(x, y);
    s += lookUpRight(x, y);
    s += lookUpLeft(x, y);
    s += lookDownRight(x, y);
    s += lookDownLeft(x, y);
    
    if(s < 2 || s > 3){
        death(x, y);
    }
}


















void printBoard(){
    int x;
    int y;
    
    int row = 0;
    int column = 0;
    
    for (int i = 0; i<= 30; i++) {
        printf("\n");
    }
    
    
    
    for (x = 0; x < 20; x++) {
        column = 0;
        if(row == 0){
            printf(" ----------------------------------------- \n");
        }
        
        for(y = 0; y < 20; y++){
            
            if(column == 0){
                printf("| ");
            }
            
            int o = board[x][y];
            if(o == 0){printf("  ");}
            else if(o == 1){printf("0 ");}
            
            column ++;
            if(column == 20){
                printf("| ");
            }
            
        }
        printf("\n");
        
        row ++;
        
        if(row == 20){
            printf(" ----------------------------------------- \n");
        }
    }
}


void createBoard(){
    
    
    int i, j;
    int array[20][20] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    board = (int**)malloc(sizeof(int*)*20);

    for(i = 0; i < 20; i++){
        board[i] = (int*)malloc(sizeof(int)*20);

        for(j = 0; j < 20; j++){
            board[i][j] = array[i][j];
        }
    }
    
}







//UP
int lookUp(int x, int y){
    int u = 0;
    if(x == 0){
        u = 0;
    }
    else{
        if(board[x-1][y] == 1){
            u = 1;
        }
    }
    return u;
}
//DOWN
int lookDown(int x, int y){
    int d = 0;
    if(x == 19){
        d = 0;
    }
    else{
        if(board[x+1][y] == 1){
            d = 1;
        }
    }
    return d;
}
//RIGHT
int lookRight(int x, int y){
    int r = 0;
    if(y == 19){
        r = 0;
    }
    else{
        if(board[x][y+1] == 1){
            r = 1;
        }
    }
    return r;
}
//LEFT
int lookLeft(int x, int y){
    int l = 0;
    if(y == 0){
        l = 0;
    }
    else{
        if(board[x][y-1] == 1){
            l = 1;
        }
    }
    return l;
}



int lookUpRight(int x, int y){
    int l = 0;
    if(x == 0 || y == 19){
        l = 0;
    }
    else{
        if(board[x-1][y+1] == 1){
            l = 1;
        }
    }
    return l;
}
int lookUpLeft(int x, int y){
    int l = 0;
    if(y == 0 || x == 0){
        l = 0;
    }
    else{
        if(board[x-1][y-1] == 1){
            l = 1;
        }
    }
    return l;
}
int lookDownRight(int x, int y){
    int l = 0;
    if(y == 19 || x == 19){
        l = 0;
    }
    else{
        if(board[x+1][y+1] == 1){
            l = 1;
        }
    }
    return l;
}
int lookDownLeft(int x, int y){
    int l = 0;
    if(y == 0 || x == 19){
        l = 0;
    }
    else{
        if(board[x+1][y-1] == 1){
            l = 1;
        }
    }
    return l;
}

