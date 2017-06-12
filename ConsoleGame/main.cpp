#include <iostream>
#include <windows.h>
#define GAME_SPEED 40
using namespace std;
int x = 1, y = 1;
bool gameisrunning = true;
char Map[11][11] = {
    "##########",
    "#@       #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "##########"
};

void clearScreen()
{
    HANDLE hOut;
    COORD Position;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void showMap()
{

    for (int y = 0; y < 10; y++) {
        cout << Map[y] << endl;
    }
}

int main()
{
    system("cls");
    while (gameisrunning) {

        for (int y = 0; y < 10; y++) {

            for (int x = 0; x < 10; x++) {
                clearScreen();
                showMap();
                switch (Map[y][x]) {
                case '#': {
                    Map[y][x] = 219;
                }
                case '@': {
                    if (GetAsyncKeyState(VK_DOWN)) {
                        switch (Map[y + 1][x]) {
                        case ' ': {
                            y += 1;
                            Map[y][x] = '@';
                            Map[y - 1][x] = ' ';
                        }
                        }
                    }

                    else if (GetAsyncKeyState(VK_UP)) {
                        switch (Map[y - 1][x]) {
                        case ' ': {
                            y -= 1;
                            Map[y][x] = '@';
                            Map[y + 1][x] = ' ';
                        }
                        }
                    }
                    else if (GetAsyncKeyState(VK_RIGHT)) {
                        switch (Map[y][x + 1]) {
                        case ' ': {
                            x += 1;
                            Map[y][x] = '@';
                            Map[y][x - 1] = ' ';
                        }
                        }
                    }
                    else if (GetAsyncKeyState(VK_LEFT)) {
                        switch (Map[y][x - 1]) {
                        case ' ': {
                            x -= 1;
                            Map[y][x] = '@';
                            Map[y][x + 1] = ' ';
                        }
                        }
                    }
                    Sleep(GAME_SPEED);
                }
                }
            }
        }
    }
}
