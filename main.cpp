#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[200], tailY[200];
int nTail;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
}
void Draw()
{
    system("cls"); // systme("clear");
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)                       // {if,else if,else,if(!print): only
                cout << "O";                            // one condition run from these conditions i think  
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }

                if (!print) //this condition works if for loop didn't perform 
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)

        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;
}
void Input()
{
    if (_kbhit())
     {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX; //prevX = x;
        tailY[i] = prevY; //prevY = y;
        prevX = prev2X;
        prevY = prev2Y;
        
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    if (x > width || x < 0 || y < 0 || y > height)
        gameOver = true;
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200); // sleep(10)
    }


// int prevX = tailX[0];
    
//     int prev2X;
//     tailX[0] = x; // x = 0
    
//     for (int i = 1; i < nTail; i++)
//     {
//         prev2X = tailX[i];
        
//         tailX[i] = prevX; //tailX[1] = 0
        
//         prevX = prev2X;
        
//     }

//  for (int k = 0; k < nTail; k++)
//                 {
//                     if (tailX[k] == j && tailY[k] == i) // if (tailX[1] == 0 && tailY[1] == 0)
//                     {
//                         cout << "o";
//                         print = true;
//                     }
//                 }


    return 0;
}
