#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>//!!
using namespace std;
enum Color {
    Black, Blue, Green, Cyan, Red,
    Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan,
    LightRed, LightMagenta, Yellow, White
};

enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27, Space = 32 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//�������� ���������� ��������� ����
void SetCursor(int x, int y)
{
    COORD myCoords = { x,y };
    SetConsoleCursorPosition(hStdOut, myCoords);
}
void SetColor(Color text, Color background)
{
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void showMenu(char mas[][20], int row, int point)
{
    for (size_t i = 0; i < row; i++)
    {
        SetCursor(30, 11 + i);
        if (i == point)
        {
            SetColor(Red, Black);
        }
        else
            SetColor(White, Black);
        cout << mas[i];
    }
    SetColor(White, Black);
}

int ActivePoint(char mas[][20], int row)
{
    int number = 0, key;
    do
    {
        showMenu(mas, row, number);
        key = _getch();
        switch (key)
        {
        case Up:
            if (number >= 1)
                number--;
            break;
        case Down:
            if (number < 3)
                number++;
            break;
        case Enter:
            return number;
            break;

        }
    } while (key != esc);
    return -1;
}
void ShowHeader()//���������� ������� ������
{
    int time = 0;
    const int stringrow = 15, stringcol = 60;
    //������ ��� ����� ����������
    char str0[stringrow][stringcol] = { "                                ##    ##   #######",
                                        "                                 ##  ##    ##   ##",
                                        "########   ##   ##    #######     ####     ##   ##",
                                        "   ##      ##   ##    ##           ##      ##   ##",
                                        "   ##      #######    ####        ####     ##   ##",
                                        "   ##      ##   ##    ##         ##  ##    ##   ##",
                                        "   ##      ##   ##    #######   ##    ##   #######", };
    for (size_t i = 0; i < stringrow; i++)
    {
        SetCursor(10, 1 + i);
        for (size_t j = 0; j < stringcol; j++)
        {
            if (str0[i][j] == '#' && i == 0)
            {
                SetColor(LightBlue, LightBlue);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 1)
            {
                SetColor(Magenta, Magenta);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 2)
            {
                SetColor(LightMagenta, LightMagenta);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 3)
            {
                SetColor(Red, Red);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 4)
            {
                SetColor(LightRed, LightRed);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 5)
            {
                SetColor(Yellow, Yellow);
                //Sleep(time);
            }
            else if (str0[i][j] == '#' && i == 6)
            {
                SetColor(White, White);
                //Sleep(time);
            }
            else
            {
                SetColor(White, Black);
                //Sleep(time);
            }
            cout << str0[i][j];
            //Sleep(time);
        }
        cout << "\n";
        Sleep(time);
    }
    SetColor(White, Black);
}
int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int allExit = 0, exit = 0;//����� �� ����
    //����
    do
    {
        char menu[2][20] = { "����� ����","�����" };
        const int length = 10;
        int mas[length];
        int point = 0, pointLvl = 0, pointChoise = 0, gameModePoint = 0, PvP = 0, key;//����
        char user, user2, comp;//���������
        do
        {
            ShowHeader();
            point = ActivePoint(menu, 2);
            if (point == 0)
            {
                system("cls");
                ShowHeader();
                char gameMode[2][20] = { "������ ����������","������ ������" };
                gameModePoint = ActivePoint(gameMode, 2);
                if (gameModePoint == 0)
                {
                    system("cls");
                    ShowHeader();
                    char pointMenu[4][20] = { "�����", "������","������", "�����" };
                    pointLvl = ActivePoint(pointMenu, 4);

                    if (pointLvl == 0)
                    {
                        system("cls");
                        ShowHeader();
                        SetCursor(26, 9);
                        cout << "���� �� ��������?";
                        char pointMenu2[2][20] = { "��������", "������", };
                        pointChoise = ActivePoint(pointMenu2, 2);
                        if (pointChoise == 0)
                        {
                            user = 'x';
                            comp = 'o';
                            point = -1;
                        }
                        else if (pointChoise == 1)
                        {
                            user = 'o';
                            comp = 'x';
                            point = -1;
                        }
                    }
                    else if (pointLvl == 1)
                    {
                        system("cls");
                        ShowHeader();
                        SetCursor(26, 9);
                        cout << "���� �� ��������?";
                        char pointMenu2[2][20] = { "��������", "������", };
                        pointChoise = ActivePoint(pointMenu2, 2);
                        if (pointChoise == 0)
                        {
                            user = 'x';
                            comp = 'o';
                            point = -1;
                        }
                        else if (pointChoise == 1)
                        {
                            user = 'o';
                            comp = 'x';
                            point = -1;
                        }
                    }
                    else if (pointLvl == 2)
                    {
                        system("cls");
                        ShowHeader();
                        SetCursor(26, 9);
                        cout << "���� �� ��������?";
                        char pointMenu2[2][20] = { "��������", "������", };
                        pointChoise = ActivePoint(pointMenu2, 2);
                        if (pointChoise == 0)
                        {
                            user = 'x';
                            comp = 'o';
                            point = -1;
                        }
                        else if (pointChoise == 1)
                        {
                            user = 'o';
                            comp = 'x';
                            point = -1;
                        }

                    }
                    else if (pointLvl == 3)
                        system("cls");
                }
                else if (gameModePoint == 1)
                {
                    system("cls");
                    ShowHeader();
                    SetCursor(26, 9);
                    cout << "���� �� ��������?";
                    char pointMenu2[2][20] = { "��������", "������", };
                    pointChoise = ActivePoint(pointMenu2, 2);
                    if (pointChoise == 0)
                    {
                        user = 'x';
                        user2 = 'o';
                        PvP = 1;
                        point = -1;
                    }
                    else if (pointChoise == 1)
                    {
                        user = 'o';
                        user2 = 'x';
                        PvP = 1;
                        point = -1;
                    }
                }
            }
            else if (point == 1)
            {
                system("cls");
                allExit = 1;
                point = -1;
            }
        } while (point != -1);
        system("cls");

        //������ �� ����� ������� ����
        int firstMove = rand() % 2;//���� 0 - ����� ����� 1, ���� 1 - ����� �����2 
        Sleep(200);
        if (PvP == 1)
        {
            if (firstMove == 0)
            {
                SetCursor(26, 9);
                cout << "������ ����� �����1";
            }
            else if (firstMove == 1)
            {
                SetCursor(26, 9);
                cout << "������ ����� �����2";
            }
        }
        SetCursor(0, 0);
        // ����� ����� ������� ������
        if (PvP == 0)
        {

            if (pointLvl == 0)//������ �������
            {
                do
                {
                    char field[3][3] = { {'.','.','.'},{'.','.','.'},{'.','.','.'} }; //������� ����
                    bool userWin = false, compWin = false, notWin = false;
                    int x = 0, y = 0; //����� �������
                    int movCount = 0;//���������� �����
                    if (firstMove == 1)
                    {
                        do
                        {
                            x = rand() % 3;//������ ��� ����������
                            y = rand() % 3;
                        } while (field[x][y] != '.');
                        field[x][y] = comp; //��� ����������
                        movCount++;
                    }
                    do
                    {
                        for (size_t i = 0; i < 3; i++)
                        {
                            for (size_t j = 0; j < 3; j++)
                            {
                                /*if (field[j][i] == '.')
                                    SetColor(Black, Black);
                                else
                                    SetColor(White, Black);*/
                                cout << field[j][i];
                            }
                            cout << "\n";
                        }
                        int key, pointPause;
                        do
                        {
                            SetCursor(x, y);
                            key = _getch();
                            switch (key)
                            {
                            case Up:
                                if (y > 0) y -= 1;
                                break;
                            case Left:
                                if (x > 0) x -= 1;
                                break;
                            case Right:
                                if (x < 2) x += 1;
                                break;
                            case Down:
                                if (y < 2) y += 1;
                                break;
                            case esc: //�������� ����� � ���� �����
                                key = esc;
                                break;

                            case Space:
                                if (field[x][y] == user || field[x][y] == comp)
                                    key = -1;
                                else
                                    field[x][y] = user;//����� ������
                                break;
                            default:
                                break;
                            }
                        } while (key != Space);
                        movCount++;

                        //��� ����������
                        if (movCount != 9)
                        {
                            do
                            {
                                x = rand() % 3;
                                y = rand() % 3;
                            } while (field[x][y] != '.');
                            field[x][y] = comp;
                            movCount++;
                        }

                        //������� ������
                        if (field[0][0] == user && field[0][1] == user && field[0][2] == user ||//������
                            field[1][0] == user && field[1][1] == user && field[1][2] == user ||
                            field[2][0] == user && field[2][1] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][0] == user && field[2][0] == user ||//�������
                            field[0][1] == user && field[1][1] == user && field[2][1] == user ||
                            field[0][2] == user && field[1][2] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][1] == user && field[2][2] == user ||//���������
                            field[0][2] == user && field[1][1] == user && field[2][0] == user)
                        {
                            userWin = true;
                        }
                        else if (field[0][0] == comp && field[0][1] == comp && field[0][2] == comp ||//������
                            field[1][0] == comp && field[1][1] == comp && field[1][2] == comp ||
                            field[2][0] == comp && field[2][1] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][0] == comp && field[2][0] == comp ||//�������
                            field[0][1] == comp && field[1][1] == comp && field[2][1] == comp ||
                            field[0][2] == comp && field[1][2] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][1] == comp && field[2][2] == comp ||//���������
                            field[0][2] == comp && field[1][1] == comp && field[2][0] == comp)

                        {
                            compWin = true;
                        }
                        else if (userWin == false && compWin == false && movCount == 9)
                        {
                            notWin = true;
                        }
                        system("cls");
                    } while (userWin == false && compWin == false && notWin == false);
                    //�������� �� ����������
                    ShowHeader();
                    SetCursor(26, 9);
                    if (userWin == true) cout << "����� �������" << endl;
                    else if (user2 == true)cout << "��������� �������" << endl;
                    else if (notWin == true)cout << "����������� ���" << endl;
                    char exitMenu[3][20] = { "��� ���","� ����", "�����" };
                    int exitPoint = ActivePoint(exitMenu, 3);
                    if (exitPoint == 0)
                    {
                        system("cls");
                        exit = 0;
                    }
                    else if (exitPoint == 1)
                    {
                        system("cls");
                        exit = 1;
                    }
                    else if (exitPoint == 2)
                    {
                        system("cls");
                        exit = 1;
                        allExit = 1;
                    }
                } while (exit != 1);
            }

            else if (pointLvl == 2)//������� �������
            {
                do
                {
                    char field[3][3] = { {'.','.','.'},{'.','.','.'},{'.','.','.'} }; //������� ����
                    bool userWin = false, compWin = false, notWin = false;
                    int x = 0, y = 0; //����� �������
                    int movCount = 0;//���������� �����
                    if (firstMove == 1)
                    {
                        do
                        {
                            x = rand() % 3;//������ ��� ����������
                            y = rand() % 3;
                        } while (field[x][y] != '.');
                        field[x][y] = comp; //��� ����������
                        movCount++;
                    }
                    do
                    {
                        for (size_t i = 0; i < 3; i++)
                        {
                            for (size_t j = 0; j < 3; j++)
                            {
                                cout << field[j][i];
                            }
                            cout << "\n";
                        }
                        int key;
                        do
                        {
                            SetCursor(x, y);
                            key = _getch();
                            switch (key)
                            {
                            case Up:
                                if (y > 0) y -= 1;
                                break;
                            case Left:
                                if (x > 0) x -= 1;
                                break;
                            case Right:
                                if (x < 2) x += 1;
                                break;
                            case Down:
                                if (y < 2) y += 1;
                                break;
                            case esc:
                                break;
                            case Space:
                                if (field[x][y] == user || field[x][y] == comp)
                                    key = -1;
                                else
                                    field[x][y] = user;//����� ������
                                break;
                            default:
                                break;
                            }
                        } while (key != Space);
                        movCount++;
                        //��� ����������
                        if (movCount != 9)
                        {
                            //��������������� ������
                            if (field[0][0] == user && field[1][0] == user && field[1][1] == user && field[2][0] == comp && field[0][1] == comp && field[1][2] == comp && field[2][2] == '.')field[2][2] = comp;
                            else if (field[0][0] == user && field[0][1] == user && field[1][1] == user && field[1][0] == comp && field[2][1] == comp && field[2][2] == comp && field[0][2] == '.')field[0][2] = comp;
                            else if (field[1][0] == user && field[2][1] == user && field[2][2] == user && field[0][0] == comp && field[0][1] == comp && field[1][1] == comp && field[0][2] == '.')field[0][2] = comp;
                            else if (field[0][0] == user && field[1][0] == user && field[2][0] == '.') field[2][0] = comp;//������
                            else if (field[0][1] == user && field[1][1] == user && field[2][1] == '.') field[2][1] = comp;
                            else if (field[0][2] == user && field[1][2] == user && field[2][2] == '.') field[2][2] = comp;
                            else if (field[0][0] == user && field[2][0] == user && field[0][1] == '.') field[0][1] = comp;
                            else if (field[0][1] == user && field[2][1] == user && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][2] == user && field[2][2] == user && field[2][1] == '.') field[2][1] = comp;
                            else if (field[0][0] == user && field[0][1] == user && field[0][2] == '.') field[0][2] = comp;//�������
                            else if (field[1][0] == user && field[1][1] == user && field[1][2] == '.') field[1][2] = comp;
                            else if (field[2][0] == user && field[2][1] == user && field[2][2] == '.') field[2][2] = comp;
                            else if (field[0][0] == user && field[0][2] == user && field[0][1] == '.') field[0][1] = comp;
                            else if (field[0][1] == user && field[2][1] == user && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][2] == user && field[2][2] == user && field[1][2] == '.') field[1][2] = comp;
                            else if (field[0][0] == user && field[1][1] == user && field[2][2] == '.') field[2][2] = comp;//���������
                            else if (field[0][2] == user && field[1][1] == user && field[2][0] == '.') field[2][0] = comp;
                            else if (field[2][0] == user && field[1][1] == user && field[0][2] == '.') field[0][2] = comp;
                            //������                
                            else if (field[0][0] == comp && field[1][0] == comp && field[2][0] == '.') field[2][0] = comp;
                            else if (field[0][1] == comp && field[1][1] == comp && field[2][1] == '.')field[2][1] = comp;
                            else if (field[0][2] == comp && field[1][2] == comp && field[2][2] == '.') field[2][2] = comp;
                            else if (field[0][0] == user && field[1][0] == '.') field[1][0] = comp;
                            else if (field[1][0] == user && field[2][0] == '.') field[2][0] = comp;
                            else if (field[0][0] == comp && field[1][0] == '.') field[1][0] = comp;
                            else if (field[1][0] == comp && field[2][0] == '.') field[2][0] = comp;
                            else if (field[0][1] == comp && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][2] == comp && field[1][2] == '.') field[1][2] = comp;
                            //�������                
                            else if (field[0][0] == comp && field[0][1] == comp && field[0][2] == '.') field[0][2] = comp;
                            else if (field[1][0] == comp && field[1][1] == comp && field[1][2] == '.')field[1][2] = comp;
                            else if (field[2][0] == comp && field[2][1] == comp && field[2][2] == '.')field[2][2] = comp;
                            else if (field[0][0] == user && field[0][1] == '.') field[0][1] = comp;
                            else if (field[1][0] == user && field[1][1] == '.') field[1][1] = comp;
                            else if (field[2][0] == user && field[2][1] == '.') field[2][1] = comp;
                            else if (field[0][0] == comp && field[0][1] == '.') field[0][1] = comp;
                            else if (field[1][0] == comp && field[1][1] == '.') field[1][1] = comp;
                            else if (field[2][0] == comp && field[2][1] == '.') field[2][1] = comp;
                            //���������              
                            else if (field[0][0] == comp && field[1][1] == comp && field[2][2] == '.')field[2][2] == comp;
                            else if (field[0][2] == comp && field[1][1] == comp && field[2][0] == '.')field[2][0] == comp;
                            else if (field[0][0] == user && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][2] == user && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][0] == comp && field[1][1] == '.') field[1][1] = comp;
                            else if (field[0][2] == comp && field[1][1] == '.') field[1][1] = comp;
                            else
                            {
                                do
                                {
                                    x = rand() % 3;
                                    y = rand() % 3;
                                } while (field[x][y] != '.');
                                field[x][y] = comp;
                            }
                            movCount++;
                        }

                        //������� ������
                        if (field[0][0] == user && field[0][1] == user && field[0][2] == user ||//������
                            field[1][0] == user && field[1][1] == user && field[1][2] == user ||
                            field[2][0] == user && field[2][1] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][0] == user && field[2][0] == user ||//�������
                            field[0][1] == user && field[1][1] == user && field[2][1] == user ||
                            field[0][2] == user && field[1][2] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][1] == user && field[2][2] == user ||//���������
                            field[0][2] == user && field[1][1] == user && field[2][0] == user)
                        {
                            userWin = true;
                        }
                        else if (field[0][0] == comp && field[0][1] == comp && field[0][2] == comp ||//������
                            field[1][0] == comp && field[1][1] == comp && field[1][2] == comp ||
                            field[2][0] == comp && field[2][1] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][0] == comp && field[2][0] == comp ||//�������
                            field[0][1] == comp && field[1][1] == comp && field[2][1] == comp ||
                            field[0][2] == comp && field[1][2] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][1] == comp && field[2][2] == comp ||//���������
                            field[0][2] == comp && field[1][1] == comp && field[2][0] == comp)

                        {
                            compWin = true;
                        }
                        else if (userWin == false && compWin == false && movCount == 9)
                        {
                            notWin = true;
                        }
                        system("cls");
                    } while (userWin == false && compWin == false && notWin == false);
                    //�������� �� ����������
                    ShowHeader();
                    SetCursor(26, 9);
                    if (userWin == true) cout << "����� �������" << endl;
                    else if (compWin == true)cout << "��������� �������" << endl;
                    else if (notWin == true)cout << "����������� ���" << endl;
                    char exitMenu[3][20] = { "��� ���","� ����", "�����" };
                    int exitPoint = ActivePoint(exitMenu, 3);
                    if (exitPoint == 0)
                    {
                        system("cls");
                        exit = 0;
                    }
                    else if (exitPoint == 1)
                    {
                        system("cls");
                        exit = 1;
                    }
                    else if (exitPoint == 2)
                    {
                        system("cls");
                        exit = 1;
                        allExit = 1;
                    }
                } while (exit != 1);
            }
            else if (pointLvl == 1)//������� �������
            {
                do
                {
                    char field[3][3] = { {'.','.','.'},{'.','.','.'},{'.','.','.'} }; //������� ����
                    bool userWin = false, compWin = false, notWin = false;
                    int x = 0, y = 0; //����� �������
                    int movCount = 0;//���������� �����
                    if (firstMove == 1)
                    {
                        do
                        {
                            x = rand() % 3;//������ ��� ����������
                            y = rand() % 3;
                        } while (field[x][y] != '.');
                        field[x][y] = comp; //��� ����������
                        movCount++;
                    }
                    do
                    {
                        for (size_t i = 0; i < 3; i++)
                        {
                            for (size_t j = 0; j < 3; j++)
                            {
                                cout << field[j][i];
                            }
                            cout << "\n";
                        }
                        int key;
                        do
                        {
                            SetCursor(x, y);
                            key = _getch();
                            switch (key)
                            {
                            case Up:
                                if (y > 0) y -= 1;
                                break;
                            case Left:
                                if (x > 0) x -= 1;
                                break;
                            case Right:
                                if (x < 2) x += 1;
                                break;
                            case Down:
                                if (y < 2) y += 1;
                                break;
                            case esc:
                                break;
                            case Space:
                                if (field[x][y] == user || field[x][y] == comp)
                                    key = -1;
                                else
                                    field[x][y] = user;//����� ������
                                break;
                            default:
                                break;
                            }
                        } while (key != Space);
                        movCount++;
                        //��� ����������
                        if (movCount != 9)
                        {
                            if (field[0][0] == user && field[0][1] == user && field[0][2] == '.') field[0][2] = comp;//������
                            else if (field[1][0] == user && field[1][1] == user && field[1][2] == '.') field[1][2] = comp;
                            else if (field[2][0] == user && field[2][1] == user && field[2][2] == '.') field[2][2] = comp;

                            else if (field[0][0] == user && field[1][0] == user && field[2][0] == '.') field[2][0] = comp;//�������
                            else if (field[0][1] == user && field[1][1] == user && field[2][1] == '.') field[2][1] = comp;
                            else if (field[0][2] == user && field[1][2] == user && field[2][2] == '.') field[2][2] = comp;

                            else if (field[0][0] == user && field[1][1] == user && field[2][2] == '.') field[2][2] = comp;//���������
                            else if (field[0][2] == user && field[1][1] == user && field[2][0] == '.') field[2][0] = comp;
                            else
                            {
                                do
                                {
                                    x = rand() % 3;
                                    y = rand() % 3;
                                } while (field[x][y] != '.');
                                field[x][y] = comp;
                            }
                            movCount++;
                        }
                        //������� ������
                        if (field[0][0] == user && field[0][1] == user && field[0][2] == user ||//������
                            field[1][0] == user && field[1][1] == user && field[1][2] == user ||
                            field[2][0] == user && field[2][1] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][0] == user && field[2][0] == user ||//�������
                            field[0][1] == user && field[1][1] == user && field[2][1] == user ||
                            field[0][2] == user && field[1][2] == user && field[2][2] == user ||

                            field[0][0] == user && field[1][1] == user && field[2][2] == user ||//���������
                            field[0][2] == user && field[1][1] == user && field[2][0] == user)
                        {
                            userWin = true;
                        }
                        else if (field[0][0] == comp && field[0][1] == comp && field[0][2] == comp ||//������
                            field[1][0] == comp && field[1][1] == comp && field[1][2] == comp ||
                            field[2][0] == comp && field[2][1] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][0] == comp && field[2][0] == comp ||//�������
                            field[0][1] == comp && field[1][1] == comp && field[2][1] == comp ||
                            field[0][2] == comp && field[1][2] == comp && field[2][2] == comp ||

                            field[0][0] == comp && field[1][1] == comp && field[2][2] == comp ||//���������
                            field[0][2] == comp && field[1][1] == comp && field[2][0] == comp)
                        {
                            compWin = true;
                        }
                        else if (userWin == false && compWin == false && movCount == 9)
                        {
                            notWin = true;
                        }
                        system("cls");
                    } while (userWin == false && compWin == false && notWin == false);
                    //�������� �� ����������
                    ShowHeader();
                    SetCursor(26, 9);
                    if (userWin == true) cout << "����� �������" << endl;
                    else if (compWin == true)cout << "��������� �������" << endl;
                    else if (notWin == true)cout << "����������� ���" << endl;
                    char exitMenu[3][20] = { "��� ���","� ����", "�����" };
                    int exitPoint = ActivePoint(exitMenu, 3);
                    if (exitPoint == 0)
                    {
                        system("cls");
                        exit = 0;
                    }
                    else if (exitPoint == 1)
                    {
                        system("cls");
                        exit = 1;
                    }
                    else if (exitPoint == 2)
                    {
                        system("cls");
                        exit = 1;
                        allExit = 1;
                    }
                } while (exit != 1);
            }
        }
        else if (PvP == 1)
        {
            do
            {
                char field[3][3] = { {'.','.','.'},{'.','.','.'},{'.','.','.'} }; //������� ����
                bool userWin = false, user2Win = false, notWin = false;
                int x = 0, y = 0; //����� �������
                int movCount = 0;//���������� �����
                do
                {
                    for (size_t i = 0; i < 3; i++)
                    {
                        for (size_t j = 0; j < 3; j++)
                        {
                            cout << field[j][i];
                        }
                        cout << "\n";
                    }
                    int key, pointPause;
                    do
                    {
                        SetCursor(x, y);
                        key = _getch();
                        switch (key)
                        {
                        case Up:
                            if (y > 0) y -= 1;
                            break;
                        case Left:
                            if (x > 0) x -= 1;
                            break;
                        case Right:
                            if (x < 2) x += 1;
                            break;
                        case Down:
                            if (y < 2) y += 1;
                            break;
                        case esc:
                            key = esc;
                            break;
                        case Space:
                            if (firstMove == 0)
                            {
                                if (field[x][y] == user || field[x][y] == user2)
                                    key = -1;
                                else
                                    field[x][y] = user;//����� ������ 1
                                firstMove = 1;
                                break;
                            }
                            else if (firstMove == 1)
                            {
                                if (field[x][y] == user || field[x][y] == user2)
                                    key = -1;
                                else
                                    field[x][y] = user2;//����� ������ 2
                                firstMove = 0;
                                break;
                            }
                        default:
                            break;
                        }
                    } while (key != Space);
                    movCount++;

                    //������� ������
                    if (field[0][0] == user && field[0][1] == user && field[0][2] == user ||//������
                        field[1][0] == user && field[1][1] == user && field[1][2] == user ||
                        field[2][0] == user && field[2][1] == user && field[2][2] == user ||

                        field[0][0] == user && field[1][0] == user && field[2][0] == user ||//�������
                        field[0][1] == user && field[1][1] == user && field[2][1] == user ||
                        field[0][2] == user && field[1][2] == user && field[2][2] == user ||

                        field[0][0] == user && field[1][1] == user && field[2][2] == user ||//���������
                        field[0][2] == user && field[1][1] == user && field[2][0] == user)
                    {
                        userWin = true;
                    }
                    else if (field[0][0] == user2 && field[0][1] == user2 && field[0][2] == user2 ||//������
                        field[1][0] == user2 && field[1][1] == user2 && field[1][2] == user2 ||
                        field[2][0] == user2 && field[2][1] == user2 && field[2][2] == user2 ||

                        field[0][0] == user2 && field[1][0] == user2 && field[2][0] == user2 ||//�������
                        field[0][1] == user2 && field[1][1] == user2 && field[2][1] == user2 ||
                        field[0][2] == user2 && field[1][2] == user2 && field[2][2] == user2 ||

                        field[0][0] == user2 && field[1][1] == user2 && field[2][2] == user2 ||//���������
                        field[0][2] == user2 && field[1][1] == user2 && field[2][0] == user2)

                    {
                        user2Win = true;
                    }
                    else if (userWin == false && user2Win == false && movCount == 9)
                    {
                        notWin = true;
                    }
                    system("cls");
                } while (userWin == false && user2Win == false && notWin == false);
                //�������� �� ����������
                ShowHeader();
                SetCursor(26, 9);
                if (userWin == true) cout << "�����1 �������" << endl;
                else if (user2 == true)cout << "�����2 �������" << endl;
                else if (notWin == true)cout << "����������� ���" << endl;
                char exitMenu[3][20] = { "��� ���","� ����", "�����" };
                int exitPoint = ActivePoint(exitMenu, 3);
                if (exitPoint == 0)
                {
                    system("cls");
                    exit = 0;
                }
                else if (exitPoint == 1)
                {
                    system("cls");
                    exit = 1;
                }
                else if (exitPoint == 2)
                {
                    system("cls");
                    exit = 1;
                    allExit = 1;
                }
            } while (exit != 1);
        }
    } while (allExit != 1);


    SetColor(White, Black);
    cout << endl << endl;
    return 0;
}