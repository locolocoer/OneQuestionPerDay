/*
�ǲ���������
����һ�����������������ִ���0�������1������0�������0��С��0�������-1��
�����ʽ��

ÿ������1������
�����ʽ��

���1��0��-1
����������

34
���������

1
*/
#include <iostream>

using namespace std;
int function(int num);
int main(void) {
  int num;
  cout << "������һ������:" << endl;
  cin >> num;
  cout << function(num) << endl;
  ;
  return 0;
}
int function(int num) {
  if (num > 0) {
    return 1;
  } else if (num == 0) {
    return 0;
  } else {
    return -1;
  }
}
