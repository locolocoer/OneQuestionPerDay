/*
一个n*m的棋盘，上面有k根葱，每根葱面朝方向为d（0123分别表示上下左右），每根葱一个战斗力f。每隔时间葱会向面朝方向走一格，
如果遇到棋盘边界，那么他将把面朝方向转180度（此回合葱不会走动），如果某个时刻有两个或以上的葱在同一位置，那么他们将发生战争，只有战斗力最高的葱存活，其他的葱全部原地枯萎，不在走动，求经过t时间后所有葱的位置。
输入格式：

第一行n m k，然后接下来k行每根葱的信息x y d f（坐标，方向，战斗力），最后一行输入时间t
输出格式：

k行，分别表示每个葱的位置
输入样例：

5 5 5
1 1 3 3
2 2 0 4
2 4 2 5
3 3 1 4
5 3 0 3
3
输出样例：

[5,0]
[2,0]
[0,4]
*/ 
#include <iostream>
#include <cstring>
using namespace std;
typedef struct Scallion
{
    int x;
    int y;
    int direct; //方向
    int CE;     //战斗力
} Scallion;
void move(int map[100][100], int n, int m, Scallion *s, int &length);
void kill(Scallion *s, int &length, int x, int y);
void showMap(int map[100][100], int n, int m);

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    int map[100][100]; //因为变量的二维数组传参不方便，这里为了省事...
    Scallion s[k];     //存放葱
    int length = k;
    //初始化棋盘
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = 0; //map[i][j]的值表示棋盘上map[i][j]处有几根葱
        }
    }
    //读入葱的信息
    int x, y, d, CE;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y >> d >> CE;
        map[x][y] = 1;
        s[i].x = x;
        s[i].y = y;
        s[i].direct = d;
        s[i].CE = CE;
    }
    int time;
    cin >> time;
    while (time > 0)
    {
        showMap(map, n, m);
        move(map, n, m, s, length);
        time--;
    }

    //showMap(map,n,m);
    cout << "length=" << length << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "[" << s[i].x << "," << s[i].y << "] d=" << s[i].direct << " CE=" << s[i].CE << endl;
    }
    return 0;
}

void move(int map[100][100], int n, int m, Scallion *s, int &length)
{
    for (int i = 0; i < length; i++)
    { //移动每一个葱
        int x, y;
        x = s[i].x;
        y = s[i].y;
        switch (s[i].direct)
        {
        case 0: //上
            if (y > 0)
            {
                map[x][y] -= 1;
                map[x][y - 1] += 1;
                s[i].y -= 1;
            }
            else
            {
                s[i].direct = 1;
            }
            break;
        case 1: //下
            if (y < n - 1)
            {
                map[x][y] -= 1;
                map[x][y + 1] += 1;
                s[i].y += 1;
            }
            else
            {
                s[i].direct = 0;
            }
            break;
        case 2: //左
            if (x > 0)
            {
                map[x][y] -= 1;
                map[x - 1][y] += 1;
                s[i].x -= 1;
            }
            else
            {
                s[i].direct = 3;
            }
            break;
        case 3: //右
            if (x < m - 1)
            {
                map[x][y] -= 1;
                map[x + 1][y] += 1;
                s[i].x += 1;
            }
            else
            {
                s[i].direct = 2;
            }
            break;
        }
    }
    //检查是否有在同一个位置的葱
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] > 1)
            {
                kill(s, length, i, j);
                map[i][j] = 1;
            }
        }
    }
}

void kill(Scallion *s, int &length, int x, int y)
{
    int max_CE = -1; //记录该位置葱中最强的战斗力
    int count = 0;   //计数要消除几根葱
    //先找出该位置的最大战斗力
    for (int i = 0; i < length; i++)
    {
        if (s[i].x == x && s[i].y == y && s[i].CE > max_CE)
        {
            max_CE = s[i].CE;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (s[i].x == x && s[i].y == y && s[i].CE < max_CE)
        { //需要消除的葱
            //Scallion temp = s[i];
            //s[i] = s[length-1-count];
            //s[length-1-count] = temp;
            swap(s[i], s[length - 1 - count]);
            count++;
        }
    }
    length -= count;
}

void showMap(int map[100][100], int n, int m)
{
    cout << "***********************" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[j][i];
        }
        cout << endl;
    }
    cout << "***********************" << endl;
}
