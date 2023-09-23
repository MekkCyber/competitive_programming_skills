/*
  Write a function that takes in an n x m two-dimensional array (that can be
  square-shaped when n == m) and returns a one-dimensional array of all the
  array's elements in zigzag order.
  Zigzag order starts at the top left corner of the two-dimensional array, goes
  down by one element, and proceeds in a zigzag pattern all the way to the
  bottom right corner.
  Ex : array = [
    [1,  3,  4, 10],
    [2,  5,  9, 11],
    [6,  8, 12, 15],
    [7, 13, 14, 16],
  ]
  output : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
*/

/*
    My idea for the solution is to look at the indices of the elements when traversing the matrix,
    we can notice that we have the following seq : (0,0)->(1,0)->(0,1)->(0,2)->(1,1)->(2,0)->(3,0)->(2,1)->(1,2)->(0,3)...
    we can see that we are traversing the diagonals one by one, the diagonales have an intersting property which is that
    the sum index_col+index_line is constant, and in order to determine from where to start, the top or the bottom we need
    to check if the constant given is odd or even, if even we start from the top : (0,2)->(1,1)->(2,0) (constant = 2), and
    if odd we start from the bottom : (3,0)->(2,1)->(1,2)->(0,3)
*/

// My approach
#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array)
{
  int m = array.size();
  int n = array[0].size();
  vector<int> result;
  for (int i = 0; i <= m + n - 2; i++)
  {
    if (i % 2 == 0)
    {
      for (int j = 0; j <= i; j++)
      {
        if (j < m && i - j < n)
        {
          result.push_back(array[j][i - j]);
        }
      }
    }
    else
    {
      for (int j = i; j >= 0; j--)
      {
        if (j < m && i - j < n)
        {
          result.push_back(array[j][i - j]);
        }
      }
    }
  }
  return result;
}
