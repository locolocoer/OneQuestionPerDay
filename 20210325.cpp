/*
是不是素数？
输入一个整数，如果这个数字大于0，则输出1，等于0，则输出0，小于0，则输出-1。
输入格式：

每次输入1个整数
输出格式：

输出1或0或-1
输入样例：

34
输出样例：

1
*/
#include <iostream>

using namespace std;
int function(int num);
int main(void) {
  int num;
  cout << "请输入一个整数:" << endl;
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
