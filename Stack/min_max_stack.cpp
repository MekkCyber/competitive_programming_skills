/* 
    Write a MinMaxStack class for a Min Max Stack. The class should
    support:
    Pushing and popping values on and off the stack.
    Peeking at the value at the top of the stack.  
    Getting both the minimum and the maximum values in the stack at any given
    point in time.
    All class methods, when considered independently, should run in constant time
    and with constant space.
*/

/*
    The idea is to keep two datastructures, a vector that behaves like a stack and an unordered map that keeps track of the min and max
    when an element is inserted
*/

#include <stack>
using namespace std;

class MinMaxStack {
 public:
  vector<int> s;
  vector<unordered_map<string,int>> minMax;
  int peek() {
    return s[s.size()-1];   
  }

  int pop() {
    minMax.pop_back();
    int top = s[s.size()-1];
    s.pop_back();
    return top;
  }

  void push(int number) {
    if (minMax.empty()) {
        minMax.push_back({{"min", number}, {"max", number}
    });
    } else minMax.push_back({{"min",min(number,minMax[minMax.size()-1]["min"])},{"max",max(number,minMax[minMax.size()-1]["max"])}});
    s.push_back(number);
  }

  int getMin() {
    return minMax[minMax.size()-1]["min"];
  }

  int getMax() {
    return minMax[minMax.size()-1]["max"];
  }
};
