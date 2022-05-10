#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct FVector2D
{
    int X;
    int Y;
};

void SetLocation(FVector2D NewLocation);


int main()
{

    bool bRunning = true;
    FVector2D PlayerPosition;
    PlayerPosition.X = 0;
    PlayerPosition.Y = 0;

    while (bRunning)
    {
        int KeyCode = _getch();

        switch (KeyCode)
        {
        case 'w':
        case 'W':
            PlayerPosition.Y--;
            break;
        case 's':
        case 'S':
            PlayerPosition.Y++;
            break;
        case 'a':
        case 'A':
            PlayerPosition.X--;
            break;
        case 'd':
        case 'D':
            PlayerPosition.X++;
            break;
        case 27:
            bRunning = false;
            break;

        }

        PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
        PlayerPosition.X = PlayerPosition.X > 17 ? 17 : PlayerPosition.X;
        PlayerPosition.Y = PlayerPosition.Y > 9 ? 9 : PlayerPosition.Y;

        system("cls");

        int Map[10][10] = {
{1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1},
        };
        for (int MapY = 0; MapY < 10; ++MapY)
        {
            for (int MapX = 0; MapX < 10; ++MapX)
            {
                if (Map[MapY][MapX] == 1)
                {
                    cout << "=" << ' ';
                }
                else if (Map[MapY][MapX] == 0)
                {
                    cout << " " << ' ';
                }
                else if (Map[MapY][MapX] == 2)
                {
                    cout << "P" << ' ';
                }
            }
            cout << '\n';
        }

        SetLocation(PlayerPosition);

        cout << "P";
    }


    return 0;
}


void SetLocation(FVector2D NewLocation)
{
    COORD Cur;
    Cur.X = NewLocation.X;
    Cur.Y = NewLocation.Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}