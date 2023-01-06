#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int,int);
void printMaze();
void printPacMan(int,int);
void erase(int, int);
char getCharAtxy(short int, short int);

main()
{
    system("Cls");
    int x=5, y=5;
    char nextSpot;
    bool run = true;
    printMaze();
    printPacMan(x,y);

    while(run)
    {
        if(GetAsyncKeyState(VK_RIGHT))
        {
            nextSpot = getCharAtxy(x+1,y);
            if(nextSpot == ' ')
            {
                erase(x,y);
                x = x + 1;
                printPacMan(x,y);
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            nextSpot = getCharAtxy(x-1,y);
            if(nextSpot == ' ')
            {
                erase(x,y);
                x = x - 1;
                printPacMan(x,y);
            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            nextSpot = getCharAtxy(x,y-1);
            if(nextSpot == ' ')
            {
                erase(x,y);
                y = y - 1;
                printPacMan(x,y);
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            nextSpot = getCharAtxy(x,y+1);
            if(nextSpot == ' ')
            {
                erase(x,y);
                y = y + 1;
                printPacMan(x,y);
            }
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            run = false;
        }

        Sleep(200);
    }
    
    
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
	cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
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