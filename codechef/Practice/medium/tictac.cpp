#include <bits/stdc++.h>
using namespace std;
enum Symbol
{
    Cross,
    Zero,
    Blank
};

enum GameResult {
    None,
    Draw,
    CrossWins,
    ZeroWins
};

enum Turn {
    Player1,
    Player2
};

/*******************************************************************
FUNCTION TO DETERMINE IF THE MATCH IS WON,DRAW OR STILL TO BE PLAYED
 ********************************************************************/

GameResult checkResult(Symbol ptr[4][4]) 
{
    // check horizontal rows
    for(int i=0;i<4;i++) 
    {
        /*
            Logic:
                It will store first symbol in prev and then cmp
                it with all other symbol and if all matched then 
                that symbol player wins
        */
        bool flag = true;
        Symbol prev = ptr[i][0];
        if(prev == Blank) 
        {
            continue;
        }
        for(int j=1;j<4;j++) 
        {
            if(prev != ptr[i][j]) 
            {
                flag = false;
            }
        }
        if(flag == true) 
        {
            if(prev == Cross) 
            {
                return CrossWins;
            } 
            else if(prev = Zero) 
            {
                return ZeroWins;
            }
        }
    }
    
    // now check for vertical row
    for(int j=0;j<4;j++) 
    {
        bool flag = true;
        Symbol prev = ptr[0][j];
        if(prev == Blank) 
        {
            continue;
        }
        // now since first elem is not blank 
        // check for other elem
        for(int i=1;i<4;i++) 
        {
            if(ptr[i][j] != prev) 
            {
                flag = false;
            }
        }
        if(flag == true) 
        {
            if(prev == Cross) 
            {
                return CrossWins;
            } 
            else if(prev = Zero) 
            {
                return ZeroWins;
            }
        }
    }
    
    // diagonal
    Symbol prev = ptr[0][0];
    if(prev != Blank) 
    {
        bool flag = true;
        for(int i=1;i<4;i++) 
        {
            if(ptr[i][i] != prev) 
            {
                flag = false;
            }
        }
        if(flag == true) 
        {
            if(prev == Cross) 
            {
                return CrossWins;
            } 
            else if(prev = Zero) 
            {
                return ZeroWins;
            }
        }
    }
    
    prev = ptr[0][3];
    if(prev != Blank) 
    {
        bool flag = true;
        for(int i = 1;i<4;i++) 
        {
            if(prev != ptr[i][3-i]) 
            {
                flag = false;
            }
        }
        if(flag == true) 
        {
            if(prev == Cross) 
            {
                return CrossWins;
            } 
            else if(prev = Zero) 
            {
                return ZeroWins;
            }
        }
    }
    
    for(int i=0;i<4;i++) 
    {
        for(int j=0;j<4;j++) 
        {
            if(ptr[i][j] == Blank) 
            {
                return None;
            } 
        }
    }
    
    return Draw;

}

/*
    It will print the TicTacToe Matrix
    
    Input: 4x4 matrix
    Output: Print visual of matrix using symbols in StdOut
*/

/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/

void printMatrix(Symbol ptr[4][4]) {
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            switch(ptr[i][j]) {
                case Cross:
                cout << "X";
                break;
                case Zero:
                cout << "0";
                break;
                case Blank:
                cout << "-";
                break;
            }
            cout << " ";
        }
        cout << endl;
    }
}

/*******************************************************************
FUNCTION TO FLIP TURNS AMONG PLAYER 1 AND PLAYER 2
 ********************************************************************/

void flipTurn(Turn &tmp) {
    if(tmp == Player1) {
        tmp = Player2;
    } else {
        tmp = Player1;
    }
}

/*******************************************************************
MAIN FUNCTION TO HANDLE THE PROGRAM
 ********************************************************************/


int main() 
{
    Symbol mat[4][4];
    // First set all the box to Blank
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            mat[i][j] = Blank;
        }
    }
    
    
    // For playing
    cout << "For Player 1 = X  and for Player 2 = O" << endl;
    Turn state = Player1;
    GameResult  res = None;
    do 
    {
        // notify which player you are
        if(state == Player1) 
        {
            cout << "You are playing as player 1" << endl;
        } 
        else 
        {
            cout << "You are playing as player2" << endl;
        }
        // now print current tictac toe matrix
        printMatrix(mat);
        cout << "now enter your move x, y :";
        int x,y;
        cin >> x >> y;
        // validate the move
        if((x > 0 && x < 5) && (y > 0 && y<5) && (mat[x-1][y-1] == Blank)) 
        {
            if(state == Player1) 
            {
                mat[x-1][y-1] = Cross;
            } 
            else 
            {
                mat[x-1][y-1] = Zero;
            }
            res = checkResult(mat);
            flipTurn(state);
        } 
        else 
        {
            cout << "Invalid Input" << endl;
        }
    } while(res == None);
    
    cout << "Game Ended : ";
    switch(res) 
    {
        case Draw:
        cout << "Game Draw";
        break;
        case CrossWins:
        cout << "Player1 Wins";
        break;
        case ZeroWins:
        cout << "Player2 Wins";
        break;
    }
    cout << endl;
}
