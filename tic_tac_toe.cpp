#include<bits/stdc++.h>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"      
#define GREEN   "\033[32m"      
#define CYAN    "\033[36m"      
void printarray(char a[3][3])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cout << CYAN << (a[i][j] == '\0' ? ' ' : a[i][j]) << " | " << RESET;
        }
        cout << endl;
    }
}
char anyWinner(char a[3][3])
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2])
        return a[i][0];
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        if(a[0][i] == a[1][i] && a[1][i] == a[2][i])
        return a[0][i];
    }
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2])
    {
        return a[0][0];
    }    
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0])
    {
        return a[1][1];
    }    
    return 'F';
}
void gameStarts()
{
    char arr[3][3] = {} ;
    int row,col;
    int i = 0;
    for(i = 0 ; i < 9 ; i++)
    {
        if(i % 2 == 0)
        {
            cout << "Player O Enter:";
        }
        else
        {
            cout << "Player X Enter:"; 
        }
        cin >> row;
        cin >> col;  
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || arr[row][col] != '\0') {
            cout << "Invalid position or position already taken. Try again." << endl;
            i--;
            continue;
        }
        if(i % 2 == 0)
        {
            arr[row][col] = 'O';
        }
        else
        {
            arr[row][col] = 'X';
        }
        printarray(arr);
        char flag = anyWinner(arr);
        if(flag == 'O' || flag == 'X')
        {
            cout<< GREEN << "Player" << flag << " WINS" << RESET << endl;
            break;
        }
    }
    if(i==9)
    {
        cout << "IT'S DRAW" << endl;
    }
}
int main()
{
    char Want;
    cout << "Want To Play the Game(y/n)";
    cin >> Want ;
    while(Want == 'y')
    {
        gameStarts();
        cout << "Want To Play Again(y/n)";
        cin >> Want;
    }    
    cout << GREEN << "Thank you for playing" << RESET;
}
