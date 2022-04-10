/*
int nTail; //default value of this variable is: {nTail == 0}

void draw{
    for{
        if (i == y && j == x)
        cout << "O";
    }

    for (int k = 0; k < nTail; k++) //(int k = 0; k < 1; k++)
                {
                    if (tailX[k] == j && tailY[k] == i) //(tailX[0] == j && tailY[0] == i)
                    {                                   //(8 == j && taily[0] == i)
                        cout << "o";
                        print = true;
                    }
                }
}
void input{
    changes x value from x to x--
}
void logic{
    int prevX = tailX[0];
    int prevY = tailY[0];
    tailX[0] = x; //x-- {x = 9 -> x-- = 8} //tailX[0] = 8;
    tailY[0] = y; 
    int prev2X, prev2Y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX; //prevX = x;
        tailY[i] = prevY; //prevY = y;
        prevX = prev2X;
        prevY = prev2Y;
        
    }

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
int main(){
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(200); // sleep(10)
    }
*/