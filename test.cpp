#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver = false;
int frameWidth = 20;
int frameHeight = 20;
int score = 0;
int x = frameWidth / 2;
int y = frameHeight / 2;
int fruitX = rand() % frameWidth;
int fruitY = rand() % frameHeight;
int tailx[20];
int taily[20];
int ntail = 0;

enum direction
{
    stop = 0,
    L,
    R,
    U,
    D
};
direction dir;

void draw()
{

    system("cls");
    for (int i = 0; i < frameWidth + 2; i++)
        cout << "#";
    cout << endl;
    for (int i = 0; i < frameHeight; i++)
    {

        for (int j = 0; j < frameWidth; j++)
        {
            if (j == 0)
                cout << "#";

            if (i == y && j == x)
                cout << 'O';
            else if (i == fruitY && j == fruitX)
                cout << 'F';
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                    if (tailx[k] == j &&  taily[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == frameWidth - 1)
                cout << "#";
        }

        cout << endl;
    }

    for (int i = 0; i < frameWidth + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score;
}
void input()
{

    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = L;
            break;
        case 'd':
            dir = R;
            break;
        case 'w':
            dir = U;
            break;
        case 's':
            dir = D;
            break;

        }
    }
}

void logic()
{

    int prevx = tailx[0];
    int prevy = taily[0];
    tailx[0] = x;
    taily[0] = y;
    int prevx2, prevy2;
    for (int i = 1; i < ntail; i++)
    {
        prevx2 = tailx[i];
        prevy2 = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prevx2;
        prevy = prevy2;
    }

    switch (dir)
    {
    case L:
        x--;
        break;
    case R:
        x++;
        break;
    case U:
        y--;
        break;
    case D:
        y++;
        break;
    }

    if (x > frameWidth || x < 0 || y < 0 || y > frameHeight)
        gameOver = true;

            for (int i = 0; i < ntail; i++)
        if (tailx[i] == x && taily[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 5;
        fruitX = rand() % frameWidth;
        fruitY = rand() % frameHeight;
        ntail++;
    }
}

int main()
{

    dir = stop;
    while (!gameOver)
    {
        draw();
        input();
        logic();
        Sleep(200);
    }
    return 0;
}