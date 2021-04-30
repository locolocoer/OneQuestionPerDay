/*
һ��n*m�����̣�������k���У�ÿ�����泯����Ϊd��0123�ֱ��ʾ�������ң���ÿ����һ��ս����f��ÿ��ʱ��л����泯������һ��
����������̱߽磬��ô�������泯����ת180�ȣ��˻غϴв����߶��������ĳ��ʱ�������������ϵĴ���ͬһλ�ã���ô���ǽ�����ս����ֻ��ս������ߵĴд������Ĵ�ȫ��ԭ�ؿ�ή�������߶����󾭹�tʱ������де�λ�á�
�����ʽ��

��һ��n m k��Ȼ�������k��ÿ���е���Ϣx y d f�����꣬����ս�����������һ������ʱ��t
�����ʽ��

k�У��ֱ��ʾÿ���е�λ��
����������

5 5 5
1 1 3 3
2 2 0 4
2 4 2 5
3 3 1 4
5 3 0 3
3
���������

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
    int direct; //����
    int CE;     //ս����
} Scallion;
void move(int map[100][100], int n, int m, Scallion *s, int &length);
void kill(Scallion *s, int &length, int x, int y);
void showMap(int map[100][100], int n, int m);

int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    int map[100][100]; //��Ϊ�����Ķ�ά���鴫�β����㣬����Ϊ��ʡ��...
    Scallion s[k];     //��Ŵ�
    int length = k;
    //��ʼ������
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            map[i][j] = 0; //map[i][j]��ֵ��ʾ������map[i][j]���м�����
        }
    }
    //����е���Ϣ
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
    { //�ƶ�ÿһ����
        int x, y;
        x = s[i].x;
        y = s[i].y;
        switch (s[i].direct)
        {
        case 0: //��
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
        case 1: //��
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
        case 2: //��
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
        case 3: //��
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
    //����Ƿ�����ͬһ��λ�õĴ�
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
    int max_CE = -1; //��¼��λ�ô�����ǿ��ս����
    int count = 0;   //����Ҫ����������
    //���ҳ���λ�õ����ս����
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
        { //��Ҫ�����Ĵ�
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
