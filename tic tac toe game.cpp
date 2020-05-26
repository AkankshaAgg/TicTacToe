#include<bits/stdc++.h>
using namespace std;

#define Computer 1
#define Human 2

#define length 3 //length of the board

//Human will move with 'O' and computer with 'X'
#define Comp_move 'O'
#define Human_move 'X'

//Intital instructions
void initialInstructions(){
    cout<<"Tic Tac Toe Game"<<endl;
    cout<<"Choose a cell from 1 to 9 as shown below:"<<endl;
    cout<<" 1 | 2 | 3 "<<endl;
    cout<<"..........."<<endl;
    cout<<" 4 | 5 | 6 "<<endl;
    cout<<"..........."<<endl;
    cout<<" 7 | 8 | 9 "<<endl;
    cout<<endl;
    return;
}

///Current board status
void showCurrentBoard(char board[][length]){
    cout<<endl;
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"---------"<<endl;
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"---------"<<endl;
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
    cout<<endl;
    return;
}

//Initialise the game
void initialise(char board[][length], int moves[]){

    //random number generation
    srand(time(NULL));

    //In starting, the board is empty
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            board[i][j] = ' ';
        }
    }

    //Number filing
    int total = length*length;
    for(int i=0;i<total;i++){
        moves[i] = i;
    }

    //randomise the moves
    random_shuffle(moves, moves + total);

    return;
}

//To declare the winner
void declareWinner(int turn){
    if(turn == Computer) cout<<"Computer has won."<<endl;
    else cout<<"Human has won."<<endl;
    return;
}

//Checking if any row get crossed with same player's move
bool rowCrossed(char board[][length]){
    for(int i=0;i<length;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return true;
    }
    return false;
}

//Checking if any column get crossed with same player's move
bool columnCrossed(char board[][length]){
    for(int i=0;i<length;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return true;
    }
    return false;
}

//If any of the diagonal get crossed
bool diagonalCrossed(char board[][length]){
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return true;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return true;
    return false;
}

//If true: game over else False
bool gameOver(char board[][length]){
    return(rowCrossed(board) || columnCrossed(board) || diagonalCrossed(board));
}

//Tic-Tac-Toe function
void TicTacToe(int turn){
    
    char board[length][length];
    int total = length*length;
    int moves[total];

    ///initialise
    initialise(board, moves);

    //initial instructions
    initialInstructions();

    int index = 0;
    int x,y;

    //Play until game over or draw
    while(gameOver(board)==false && index!=total){
        if(turn == Computer){
            x = moves[index]/length;
            y = moves[index]%length;
            board[x][y] = Comp_move;
            cout<<"Computer has put "<<Comp_move<<" in a cell "<<moves[index]+1;
            showCurrentBoard(board);
            index++;
            turn = Human;
        }

        else if(turn == Human){
            x = moves[index]/length;
            y = moves[index]%length;
            board[x][y] = Human_move;
            cout<<"Human has put "<<Human_move<<" in a cell "<<moves[index]+1;
            showCurrentBoard(board);
            index++;
            turn = Computer;
        }
    }

    //Game draw
    if(gameOver(board) == false && index == total){
        cout<<"Game draw"<<endl;
    }
    else{
        //declare actual winner
        if(turn==Computer) turn=Human;
        else if(turn==Human) turn=Computer;

        declareWinner(turn);
    }
    return;
}

int main(){
    TicTacToe(Computer);
    return 0;
}
