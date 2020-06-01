/*
 * StackOverflow.cpp
 *
 *  Created on: Nov 20, 2019
 *      Author: yunus
 */

#include "StackOverflow.h"
#include <iostream>
using namespace std;

StackOverflow::StackOverflow() {
  // TODO Auto-generated constructor stub
}

StackOverflow::~StackOverflow() {
  // TODO Auto-generated destructor stub
  delete [] A;
}

void StackOverflow::destroy() {
  top = -1;
  A = new char [SIZE];
}

void StackOverflow::initialize_stack() {
  destroy();
}

bool StackOverflow::is_empty() {
  if (top == -1)
    return true;
  else
    return false;
}

void StackOverflow::push(char value) {
  if (top == SIZE-1)
    cout << "Full Stack" << endl;
  else {
    top++;
    A[top] = value;
  }
}

void StackOverflow::pop() {
  if (is_empty())
    cout << "Empty Stack" << endl;
  else
    top--;
}

char StackOverflow::show_top() {
  if (is_empty()) {
    return '\0';
  }
  else
    return A[top];
}

void StackOverflow::display_stack() {
  if (is_empty())
    cout << "Empty Stack" << endl;
  else {
    for (int j = 0; j <= top; j++)
      cout << A[j] << endl;
  }
}
