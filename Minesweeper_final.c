#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
 
 
#define BOARD_SIZE 10
#define TRUE 1
#define FALSE 0
 
 
typedef struct playerInfo{
    char name[15];
    int age;
    int time;
} Player;
 
char board[BOARD_SIZE][BOARD_SIZE];

//Game Board
char uboard[BOARD_SIZE][BOARD_SIZE]; 
 
 
void setupMines();
void buildUserBoard();
void printBoard();
void printUserBoard();
void getInfo();
int findMines(int row, int column);
int mineSweep(int row, int column);
void setupGame();
int winCheck();
void win();
void loss();
 
 
int main()
{
    setupGame();
    return 0;
}
 
 
void getInfo()
{  
    Player p1;
    printf("Enter player name: ");
    scanf("%s", p1.name);
    printf("Please enter your age: ");
    scanf("%d", &p1.age);
    printf("\nHi %s, Let Minesweeper Begin!\n\n",p1.name);
}

 
void printBoard()
{
    int column, row;
 
 
    // Print the top row of numbers.
    for(column = 0; column < BOARD_SIZE ; column++)
        printf(" %d ", column);
    printf("\n");
 
 
    for(row = 0; row < BOARD_SIZE; row++)
    {
        for(column = 0; column < BOARD_SIZE; column++)
            printf(" %c ", board[row][column]);
        if(row >= 0 &&  row <= BOARD_SIZE -1)
            printf("%d", row);
        printf("\n");
    }
}
 
 
 
 
void buildUserBoard(){
    int column, row;
 
 
    // Set all elements in the board to '-'
    for(column = 0; column < BOARD_SIZE; column++)
        for(row = 0; row < BOARD_SIZE; row++)
            uboard[column][row] = '-';
}
void printUserBoard(){
    int column, row;
 
 
    system("cls");
    // Print the top row of numbers.
    for(column = 0; column < BOARD_SIZE ; column++)
        printf(" %d ", column);
    printf("\n\n");
 
 
    // Print the actual board with column numbers.
    for(column = 0; column < BOARD_SIZE ; column++)
    {
        for(row = 0; row < BOARD_SIZE; row++)
        {
            printf(" %c ", uboard[column][row]);
        }
        if(column >= 0 &&  column <= BOARD_SIZE  )
            printf("   %d", column);
        printf("\n");
    }
 
 
}
 
 
 
 
// Setting up mines within the board-M
void setupMines(){
 
 
    int col, row;
 
 
    for(col = 0; col < BOARD_SIZE ; col++){
        for (row = 0; row < BOARD_SIZE ; row++)
            board[col][row] = '-';
    }
 
 
    srand(time(0));
    for(row = 0; row < BOARD_SIZE ; row++){
        int random = rand() % (BOARD_SIZE );
        board[random][row] = 'M';
    }
}
//Finds mines in adjacent locations to user selection
int findMines(int row, int column){
 
 
     int mines = 0;
 
 
    // Checking up, down, left, right.
    if(board[row - 1][ column] == 'M')
        mines++;
    if(board[row + 1][ column] == 'M')
        mines++;
    if(board[row][ column - 1] == 'M')
        mines++;
    if(board[row][ column + 1] == 'M')
        mines++;
 
 
 
 
    // Checking the diagonal relationships
    if(board[row - 1][ column + 1] == 'M')
        mines++;
    if(board[row - 1][ column - 1] == 'M')
        mines++;
    if(board[row + 1][ column + 1] == 'M')
        mines++;
    if(board[row + 1][ column - 1] == 'M')
        mines++;
 
 
    return mines;
}
 
 
//Sets up board and prints intial board for user input.
void setupGame()
{
    int xpos, ypos;
 
    getInfo();
    system("pause");
    setupMines();
    buildUserBoard();
    printUserBoard();
 
 
    for(;;){
    do{ printf("\nEnter the row: ");
        scanf("%d",&xpos);
        printf("Enter the column: ");
        scanf("%d",&ypos);
        printf("\n");
        } while(xpos < 0 || xpos > BOARD_SIZE -1 || ypos < 0 || ypos > BOARD_SIZE -1 );
 
 
        if (board[xpos][ypos] == 'M'){
            printf("You have hit a mine!\n\n");
            printBoard();
            loss();
        }
        else
            mineSweep(xpos, ypos);
 
 
    printUserBoard();
    }
}
//Checking ig player has lost
void loss()
{
    char choice;
 
    scanf("%c", &choice);
    printf("You have lost!\n\nWould you like to play again? Press Y or N : ");
    scanf("%c", &choice);
    if (toupper(choice) == 'Y')
	{
        system("cls");
        setupGame();
    }
 
 
    else
        printf("\nThanks for playing, bye! \n\n ");
        exit(0);
}
 
 
//Has the player won?
int winCheck(){
 
 
    int col, row;
 
 
    for(col = 1; col < BOARD_SIZE - 1; col++)
        for(row = 1; row < BOARD_SIZE - 1; row++) {
            if(uboard[col][row] == '-' && board[col][row] != 'M')
                return FALSE;
        }
 
 
    return TRUE;
}
 
 
void win(){
 
 
    char choice;
 
 
    printf("Congratulations, you have won! \nWould you like to start another game? (Y/N)--> ");
    scanf("%c", &choice);
 
 
    if (toupper(choice) == 'y'){
        system("cls");
    }
    else
        exit(99);
}
 
 
int mineSweep(int column, int row){
 
 
    int nearbymines = 0;
 
 
    if( row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE || uboard[column][row] != '-'){
        return 0;
    }
 
 
 
 
    nearbymines = findMines(column, row);
    uboard[column][row] = (char)(((int)'0') + nearbymines);
    //Want to check each mine see if 0, if 0 check each space around it
    if (nearbymines < 1){
        mineSweep(column, row -1);
        mineSweep(column+1, row-1);
        mineSweep(column+1, row);
        mineSweep(column+1, row+1);
        mineSweep(column, row+1);
        mineSweep(column-1, row+1);
        mineSweep(column-1, row);
        mineSweep(column-1, row-1);
    }
 
 
 
 
    return 1;
 
 
}