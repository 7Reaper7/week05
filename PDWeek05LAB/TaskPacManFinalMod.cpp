#include<iostream>
#include<windows.h>
using namespace std;

void scorekeeper();
void gotoxy(int,int);
void printMaze();
void printMazeEmpty();
void printPacMan(int,int);
void printghost(int,int);
void erase(int, int);
void death(int, int);
bool direct(int, char);
char getCharAtxy(short int, short int);

int d_flag;
int d1_flag;
int score=0;
bool loop;

main()
{
    system("Cls");
    int x=5, y=5, gx=2, gy=9, gx1=24, gy1=2;
    int directionFlag;
    char nextSpot;
    bool run = true, move;
    printMaze();
    printPacMan(x,y);
     
    while(run)
    {
        if(gx==2)
        {
            d_flag = 1;
        }
        if(gx==44)
        {
            d_flag = 2;
        }
        if(gy1==14)
        {
            d1_flag = 1;
        }
        if(gy1==2)
        {
            d1_flag = 2;
        }

        if(d_flag == 1)
        {
            erase(gx,gy);
            gx = gx + 1;
            printghost(gx,gy);
            Sleep(30);
        }
        if(d_flag == 2)
        {
            erase(gx,gy);
            gx = gx - 1;
            printghost(gx,gy);
            Sleep(30);
        }
        if(d1_flag == 1)
        {
            erase(gx1,gy1);
            gy1 = gy1 - 1;
            printghost(gx1,gy1);
            Sleep(100);
        }
        if(d1_flag == 2)
        {
            erase(gx1,gy1);
            gy1 = gy1 + 1;
            printghost(gx1,gy1);
            Sleep(100);
        }
    
        if(GetAsyncKeyState(VK_RIGHT))
        {
            nextSpot = getCharAtxy(x+1,y);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                erase(x,y);
                x = x + 1;
                printPacMan(x,y);
                nextSpot = getCharAtxy(x+1,y);
                if(nextSpot == '.')
                {
                    scorekeeper();
                }
                if(nextSpot == 'G')
                {
                    run = false;
                }
                Sleep(30);
            }
        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            nextSpot = getCharAtxy(x-1,y);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                erase(x,y);
                x = x - 1;
                printPacMan(x,y);
                nextSpot = getCharAtxy(x-1,y);
                if(nextSpot == '.')
                {
                    scorekeeper();
                }  
                if(nextSpot == 'G')
                {
                    run = false;
                }
                Sleep(30);
            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            
            nextSpot = getCharAtxy(x,y-1);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                erase(x,y);
                y = y - 1;
                printPacMan(x,y);
                nextSpot = getCharAtxy(x,y-1);
                if(nextSpot == '.')
                {
                    scorekeeper();
                }
                if(nextSpot == 'G')
                {
                    run = false;
                }
                Sleep(100);
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            
            nextSpot = getCharAtxy(x,y+1);
            if(nextSpot == ' ' || nextSpot == '.')
            {
                erase(x,y);
                y = y + 1;
                printPacMan(x,y);
                nextSpot = getCharAtxy(x,y+1);
                if(nextSpot == '.')
                {
                    scorekeeper();
                }
                if(nextSpot == 'G')
                {
                    run = false;
                }
                Sleep(100);
            }
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            run = false;
        }
        Sleep(100);
    }
    death(x,y);
    
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

void printMazeEmpty()
{	
    gotoxy(0,0);
    cout << "################################################               " << endl;
	cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                              #" << endl;
    cout << "#                                  #           #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                %                             #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                  %#          #" << endl;
	cout << "#                                              #" << endl;
	cout << "#                                              #" << endl;
	cout << "################################################               " << endl;

}

void printPacMan(int x,int y)
{
    gotoxy(x,y);
    cout << "P";
}

void printghost(int x,int y)
{
    gotoxy(x,y);
    cout << "G";
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

void death(int x, int y)
{
    printMazeEmpty();
    gotoxy(x,y);
    cout << "I";
    gotoxy(x,y);
    Sleep(120);
    cout << "!";
    gotoxy(x,y);
    Sleep(120);
    cout << "\\";
    gotoxy(x,y);
    Sleep(120);
    cout << "__";
    gotoxy(x,y);
    Sleep(120);
    cout << "_ ";
    gotoxy(x,y);
    Sleep(120);
    cout << ". ";
    gotoxy(x,y);
    Sleep(120);
    cout << "  ";
    gotoxy(20,8);
    Sleep(120);
    cout << "YOU DIED";
}