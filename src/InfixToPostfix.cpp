/*
 * InfixToPostfix.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: yunus
 */

#include "InfixToPostfix.h"
#include "StackOverflow.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

InfixToPostfix::InfixToPostfix() {
  // TODO Auto-generated constructor stub

}

InfixToPostfix::~InfixToPostfix() {
  // TODO Auto-generated destructor stub
}

bool InfixToPostfix::precedence(char op1, char op2) {
  int prec1, prec2;
  if (op1 == '*' || op1 =='/')
    prec1 = 2;
  else if (op1 == '+' || op1 == '-')
    prec1 = 1;
  else if ((op1 ='('))
    prec1 = 0;
  if (op2 == '*' || op2 == '/')
    prec2 = 2;
  else if (op2 =='+' || op2 == '-')
    prec2 = 1;
  return (prec1 >= prec2);
}

void InfixToPostfix::getInfix(string data) {
  infix = data;
}

string InfixToPostfix::showInfix(){
  return infix;
}

string InfixToPostfix::showPostfix() {
  return postfix;
}

bool is_operand(char thing) {
  if (thing >= '0' && thing <= '9')
    return true;
  else if (thing >= 'A' && thing <= 'Z')
    return true;
  else if (thing >= 'a' && thing <= 'Z')
    return true;
  return false;
}

bool is_operator(char thing) {
  bool plus = (thing == '+'), minus = (thing == '-'), times = (thing == '*'), divided_by = (thing == '/');
  if (plus || minus || times || divided_by)
    return true;
  return false;
}

bool isOpenPars(char thing) {
  if (thing == '(')
    return true;
  return false;
}

bool isClosePars(char thing) {
  if (thing == ')')
    return true;
  return false;
}

string InfixToPostfix::convertToPostfix() {
  StackOverflow s;
  for (int i = 0; i < infix.length(); i++) {
    if(infix[i] == ' ' || infix[i] == ',')
      continue;
    if (is_operand(infix[i]))
      postfix = postfix + infix[i];
    else if (is_operator(infix[i])) {
      while (!s.is_empty() && precedence(s.show_top(), infix[i]) && !isOpenPars(infix[i])) {
        postfix = postfix + s.show_top();
        s.pop();
      }
      s.push(infix[i]);
    }
    else if (isOpenPars(infix[i]))
      s.push(infix[i]);
    else if (isClosePars(infix[i])) {
      while (!s.is_empty() && !isOpenPars(s.show_top())) {
        postfix = postfix + s.show_top();
        s.pop();
      }
      s.pop();
    }
  }
  // pop and append whatever operands are left
  while(!s.is_empty()) {
    postfix = postfix + s.show_top();
    s.pop();
  }
  return postfix;
}

string InfixToPostfix::convertToPostfix_STL() {
  stack <char> s;
  for (int i = 0; i < infix.length(); i++) {
    if(infix[i] == ' ' || infix[i] == ',')
      continue;
    if (is_operand(infix[i]))
      postfix = postfix + infix[i];
    else if (is_operator(infix[i])) {
      while (!s.empty() && precedence(s.top(), infix[i]) && !isOpenPars(infix[i])) {
        postfix = postfix + s.top();
        s.pop();
      }
      s.push(infix[i]);
    }
    else if (isOpenPars(infix[i]))
      s.push(infix[i]);
    else if (isClosePars(infix[i])) {
      while (!s.empty() && !isOpenPars(s.top())) {
        postfix = postfix + s.top();
        s.pop();
      }
      s.pop();
    }
  }
  // pop and append whatever operands are left
  while(!s.empty()) {
    postfix = postfix + s.top();
    s.pop();
  }
  return postfix;
}






