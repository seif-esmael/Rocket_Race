#include <iostream>
#include <vector>
using namespace std;
class Board
{
private:
    int n; //number of board size (n * n)
    vector<vector<char>> board;
public:
    void prepare_board(int num)
    {
        n = num;
        board.resize(n);
        for (int i = 0; i < n; i++)
        {
            board[i].resize(n); 
        }
        for(int i=0; i<n; i++)
        {
            for(int k=0; k<n; k++)
            {
                board[i][k] = '-';
            }
        }
        board[0][0] = 'X';
        board[0][n - 1] = 'X';
        board[n - 1][0] = 'X';
        board[n - 1][n - 1] = 'X';
        for (int i = 1; i < n - 1; i++)
        {
            board[0][i] = 'U';
        }
        for (int i = 1; i < n - 1; i++)
        {
            board[i][0] = '>';
        }
    }
    //----------------------------------------
    void display_board()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    //----------------------------------------
    bool check_move(int move , int player)
    {
        if (player == 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if ((board[move][i] == '>' && board[move][i + 1] == '-') || (board[move][i] == '>' && board[move][i + 1] == 'U' && board[move][i + 2] == '-'))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                if ((board[i][move] == 'U' && board[i + 1][move] == '-') || (board[i][move] == 'U' && board[i + 1][move] == '>' && board[i + 2][move] == '-'))
                {
                    return true;
                }
            }
            return false;
        }
    }
    //--------------------------------------------
    bool is_winner(int player)
    {
        if (player == 1)
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (board[i][n - 1] == '-')
                {
                    return false;
                }
            }
            return true;
        }
        else   // player 2
        {
            for (int i = 1; i < n - 1; i++)
            {
                if (board[n - 1][i] == '-')
                {
                    return false;
                }
            }
            return true;
        }
        
    }
    //-------------------------------------------------
    bool check_if_the_player_has_correct_move(int player)    // we use this function when the player enter a invalid move but he/she has another correct move
    {
        if(player == 1)
    {
        for(int k=1; k<n-1; k++)
        {
            for(int i=0; i<n-1; i++)
            {
                if((board[k][i] == '>' && board[k][i+1] == '-') || (board[k][i] == '>' && board[k][i+1] == 'U' && board[k][i+2] == '-')) return true;
            }
        }
        return false;
    }
    else
    {
        for(int k=1; k<n-1; k++)
        {
            for(int i=0; i<n-1; i++)
            {
                if((board[i][k] == 'U' && board[i+1][k] == '-') || (board[i][k] == 'U' && board[i+1][k] == '>' && board[i+2][k] == '-')) return true;
            }
        }
        return false;
    }
    }
    //-------------------------------------------------
    void update_board(int move , int player)
    {
        if(player == 1)
    {
        for(int i=0; i<n; i++)
        {
            if(board[move][i] == '>' && board[move][i+1] == '-')
            {
                board[move][i] = '-';
                board[move][i+1] = '>';
                break;
            }
            else if (board[move][i] == '>' && board[move][i + 1] == 'U' && board[move][i + 2] == '-')
            {
                board[move][i] = '-';
                board[move][i + 2] = '>';
                break;
            }
        }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(board[i][move] == 'U' && board[i+1][move] == '-')
            {
                board[i][move] = '-';
                board[i+1][move] = 'U';
                break;
            }
            else if(board[i][move] == 'U' && board[i+1][move] == '>' && board[i + 2][move] == '-')
            {
                board[i][move] = '-';
                board[i+2][move] = 'U';
                break;
            }
        }
    }
    }
    
};
//_________________________________________________________________________________________________
class Manager_of_multi_playing
{
public:
    void run()
    {
        int number_of_dimensions;
        string name1 , name2;
        cout << "\t\t\t\t\tWelcome TO Rocket Race-Game (Player VS Player) :)" << endl;
        cout << "\t\t\t\t\t----------------------------------------" << endl;
        cout << "First player's name: "; 
        cin >> name1;
        cout << "Second player's name: ";
        cin >> name2;
        cout << "Enter the number of dimensions of the board (n * n): ";
        cin >> number_of_dimensions;
        Board b;
        b.prepare_board(number_of_dimensions);
        cout << "This is your starting board: " << endl;
        cout << "-----------------------------" << endl;
        int move;
        while (true)
        {
            b.display_board();
            cout << endl;
            if (b.check_if_the_player_has_correct_move(1))
            {
                cout << name1 << " please enter the number of the rocket you want to move: ";
                cin >> move;
                while (!b.check_move(move , 1))
                {
                    cout << "Invalid input , you cannot move as there is 2 rockets of the enemy infront of your rocket. please try again: ";
                    cin >> move;
                }
                b.update_board(move , 1);
                if (b.is_winner(1))
                {
                    cout << "CONGRATULATIONS " << name1 << " you won the game :)" << endl;
                    cout << "---------------------------------------------------" << endl;
                    cout << endl;
                    break;
                }
            }
            else
            {
                cout << "Sorry " << name1 << " but you can't move any rocket:(" << endl;
            }
            b.display_board();
            cout << endl;
            if (b.check_if_the_player_has_correct_move(2))
            {
                cout << name2 << " please enter the number of the rocket you want to move: ";
                cin >> move;
                while (!b.check_move(move , 2))
                {
                    cout << "Invalid input , you cannot move as there is 2 rockets of the enemy infront of your rocket. please try again:  ";
                    cin >> move;
                }
                b.update_board(move , 2);
                if (b.is_winner(2))
                {
                    cout << endl << endl << "This is the final board :)" << endl;
                    cout << "--------------------------" << endl;
                    cout << "CONGRATULATIONS:) : ) " << name2 << " you won the game" << endl;
                    break;
                }
            }
            else
            {
                cout << "Sorry " << name2 << " but you can't move any rocket:(" << endl;
            }
        }
        cout << "Thanks for playing , The GAME ENDED :)" << endl;
    }
};
//_____________________________________________________________________________
int main()
{
    cout << "\t\t\t\t\t\tWelcome to >> *---Rocket Race---*" << endl;
    cout << "\t\t\t\t\t\t---------------------------------" << endl;
    cout << "1- Every player has a number of rockets equal to (n - 2) as n is the number of board's dimensions." << endl;
    cout << "2- The rocket you will choose will move to the next: " << endl;
    cout << "- if the rocket has a valid move to the next cell it will go directly to it." << endl;
    cout << "- if the rocket has another rocket in the front but the cell next to it is empty so the rocket eill move to it." << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;
    int choice;
    cout << "-Type 1 if Player VS Player." << endl;
    cout << "-Type 2 if you want to exit" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        Manager_of_multi_playing gg;
        gg.run();
    }
    else if (choice == 2)
    {
        cout << "Thanks for visiting us:)" << endl;
        exit(-1);
    }
    else
    {
        cout << "Wrong input :(" << endl;
    }
}