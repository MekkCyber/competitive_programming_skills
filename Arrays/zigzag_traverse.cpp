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

/*
    The idea of the solution is either we go down or up. When we are going down and we are on the 0 column, we go down vertically only once
    and inverse the direction to up. When we are going down and we are on the last row, we go right once and inverse the direction to up.
    If we are in neither cases we just keep going down diagonally. The same thing in the up case. When going up and we find ourselves in the 
    first row we move right and inverse the direction, if we are in the last column we move down and inverse the position. 
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

// Solution Approach : less clean

vector<int> zigzagTraverse(vector<vector<int>> array)
{
  // Write your code here.
  bool goingDown = true;
  int rows = array.size();
  int cols = array[0].size();
  int r = 0;
  int c = 0;
  vector<int> result;
  while (r < rows && c < cols)
  {
    result.push_back(array[r][c]);
    if (goingDown)
    {
      if (c == 0 && r != rows - 1)
      {
        r++;
        goingDown = false;
      }
      else if (r == rows - 1)
      {
        c++;
        goingDown = false;
      }
      else
      {
        r++;
        c--;
      }
    }
    else
    {
      if (r == 0 && c != cols - 1)
      {
        c++;
        goingDown = true;
      }
      else if (c == cols - 1)
      {
        r++;
        goingDown = true;
      }
      else
      {
        r--;
        c++;
      }
    }
  }
  return result;
}
