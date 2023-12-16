/*
    You're given a list of string tokens representing a mathematical
    expression using Reverse Polish Notation. Reverse Polish Notation is a
    notation where operators come after operands, instead of between them. For
    example 2 4 + would evaluate to 6.
    You're given a list of string tokens representing a mathematical
    expression using Reverse Polish Notation. Reverse Polish Notation is a
    notation where operators come after operands, instead of between them. For
    example 2 4 + would evaluate to 6.
    Write a function that takes this list of tokens and returns
    the result. Your function should support four operators: +, -, *, and / for addition,
    subtraction, multiplication, and division respectively.
    Ex : tokens = ["50", "3", "17", "+", "2", "-", "/"]
    output : 2 // (50 / ((3 + 17) - 2)))
*/

/*
    The idea is simple, we just use a stack to store the numbers, and every time we encounter an operation
    we pop the first two elements in the stack, perform the operation, and then push the result
*/


#include <stack>
using namespace std;

int calculate(int a, int b, string op);

int reversePolishNotation(vector<string> tokens) {
  int result = 0;
  stack<int> s;
  int i = 0;
  while (i<tokens.size()){
    if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
      int first_operand = s.top();
      s.pop();
      int second_operand = s.top();
      s.pop();
      s.push(calculate(int(second_operand),int(first_operand),tokens[i]));
    } else {
      s.push(stoi(tokens[i]));
    }
    i++;
  }
  return s.top();
}

int calculate(int a, int b, string op){
  if (op=="+"){
    return a+b;
  } else if (op=="-"){
    return a-b;
  } else if (op=="*"){
    return a*b;
  } else {
    if (b!=0) return (int)a/b;
    else return 0;
  }
}
