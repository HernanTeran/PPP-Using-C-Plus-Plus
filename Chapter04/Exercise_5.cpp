// Author: Hernan Teran
// Date:   2021/04/18
// Chapter 4 Exercise 5

#include <iostream>

using namespace std;

int main()
{
  double v1{0.0}, v2{0.0}, res{0.0};
  char oper{'0'};

  for (;;)
  {
    cout << "enter: n m operator" << endl;
    cin >> v1 >> v2 >> oper;
    switch (oper)
    {
      case '+':
      res = v1 + v2;
      break;
      case '-':
      res = v1 - v2;
      break;
      case '*':
      res = v1 * v2;
      break;
      case '/':
      if (v2 == 0)
      {
        std::cerr << "division by zero is not possible" << std::endl;
        v1 = v2 = 0.0;
        res = -1;
        break;
      }
      res = v1 / v2;
      break;
      default:
      std::cerr << "invalid operator" << std::endl;
      break;
      }
      if (res != -1)
      {
        std::cout << "ans = " << res << std::endl;
      }
    }

  return 0;
}
