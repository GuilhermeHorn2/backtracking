#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

void n_queens(int n, int col, std::vector<std::vector<int>> &pos, int &k);

int n_queens(int n);
main()
{
 /* ?\n;||(or) e &&(and)*/

 std::cout << n_queens(8);

 return 0;
}

bool is_safe(int a, int b, std::vector<std::vector<int>> &pos)
{
 for (int i = 0; i < pos.size(); i++)
 {
  if (a == pos[i][0])
  {
   return false;
  }
  if (b == pos[i][1])
  {
   return false;
  }
  if (a - b == pos[i][0] - pos[i][1])
  {
   return false;
  }
  if (a + b == pos[i][0] + pos[i][1])
  {
   return false;
  }
 }
 return true;
}

void n_queens(int col, int n, std::vector<std::vector<int>> &pos, int &k)
{
 if (col >= n)
 {
  k++;
  return;
 }
 for (int i = 0; i < n; i++)
 {
  if (is_safe(i, col, pos))
  {
   std::vector<int> tmp = {i, col};
   pos.push_back(tmp);
   n_queens(col + 1, n, pos, k);
   pos.pop_back();
  }
 }
}

int n_queens(int n)
{
 std::vector<std::vector<int>> pos;
 int k = 0;
 n_queens(0, n, pos, k);
 return k;
}
