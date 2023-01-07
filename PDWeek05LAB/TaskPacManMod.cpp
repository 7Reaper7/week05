#include<iostream>
#include<windows.h>
using namespace std;

void scorekeeper();
void gotoxy(int,int);
void printMaze();
void printPacMan(int,int);
void erase(int, int);
bool direct(int, char);
char getCharAtxy(short int, short int);

int score;

main()
{
    system("Cls");
    int x=5, y=5;
    int score;
    int directionFlag;
    char nextSpot;
    bool run = true, move;
    printMaze();
    printPacMan(x,y);

    while(run)
    {
        move = true;
        if(GetAsyncKeyState(VK_RIGHT))
        {
            directionFlag = 1;
            nextSpot = getCharAtxy(x+1,y);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                while(move)
                {
                    erase(x,y);
                    x = x + 1;
                    printPacMan(x,y);
                    nextSpot = getCharAtxy(x+1,y);
                    if(nextSpot == '.')
                    {
                        scorekeeper();
                    }
                    move = direct(directionFlag,nextSpot);
                    Sleep(150);
                }   
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            directionFlag = 2;
            nextSpot = getCharAtxy(x-1,y);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                while(move)
                {
                    erase(x,y);
                    x = x - 1;
                    printPacMan(x,y);
                    nextSpot = getCharAtxy(x-1,y);
                    if(nextSpot == '.')
                    {
                        scorekeeper();
                    }
                    move = direct(directionFlag,nextSpot);
                    Sleep(150);
                }   
            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            directionFlag = 3;
            nextSpot = getCharAtxy(x,y-1);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                while(move)
                {
                    erase(x,y);
                    y = y - 1;
                    printPacMan(x,y);
                    nextSpot = getCharAtxy(x,y-1);
                    if(nextSpot == '.')
                    {
                        scorekeeper();
                    }
                    move = direct(directionFlag,nextSpot);
                    Sleep(250);
                }   
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            directionFlag = 4;
            nextSpot = getCharAtxy(x,y+1);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                while(move)
                {
                    erase(x,y);
                    y = y + 1;
                    printPacMan(x,y);
                    nextSpot = getCharAtxy(x,y+1);
                    if(nextSpot == '.')
                    {
                        scorekeeper();
                    }
                    move = direct(directionFlag,nextSpot);
                    Sleep(250);
                }   
            }
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            run = false;
        }
        
        Sleep(100);
    }
    
    
}

void scorekeeper()
{
    gotoxy(0,18);
    score = score + 10;
    cout << "Score=> " << score;
}

void gotoxy(int x,int y)
{

	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}

void printMaze()
{	

    cout << "################################################               " << endl;
	cout << "#                         ...                  #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#              ...                             #" << endl;
    cout << "#                                  #           #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                %                             #" << endl;
	cout << "#  ...                      ...                #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                ...                           #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                  %#          #" << endl;
	cout << "#          ...                                 #" << endl;
	cout << "#                                              #" << endl;
	cout << "################################################               " << endl;

}

void printPacMan(int x,int y)
{
    gotoxy(x,y);
    cout << "P";
}

void erase(int x,int y)
{
    gotoxy(x,y);
    cout << " ";
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

bool direct(int directionFlag, char nextSpot)
{
    if(GetAsyncKeyState(VK_RIGHT) && directionFlag != 1)
    {
        return false;
    }
    if(GetAsyncKeyState(VK_LEFT) && directionFlag != 2)
    {
        return false;
    }
    if(GetAsyncKeyState(VK_UP) && directionFlag != 3)
    {
        return false;
    }
    if(GetAsyncKeyState(VK_DOWN) && directionFlag != 4)
    {
        return false;
    }
    if(nextSpot == '#' || nextSpot == '|' || nextSpot == '%')
    {
        return false;
    }
    return true;
}