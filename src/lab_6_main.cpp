//============================================================================
// Name        : lab_6_main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>
#include "StackOverflow.h"
#include "InfixToPostfix.h"
using namespace std;

int main() {
  InfixToPostfix converter[5];

  string expressions[5] = {
      "A + B - C",
      "(A + B) * C",
      "(A + B) * (C - D)",
      "A + ((B + C) * (E - F) - G) / (H - I)",
      "A + B * (C + D ) - E / F * G + H"
  }, results[5];

  for (int i = 0; i < 5; i++) {

    converter[i].getInfix(expressions[i]);

    results[i] = converter[i].convertToPostfix();

    cout << "Infix Expression: " << expressions[i] << ';' << endl;
    cout << "Postfix Expression: " << results[i] << endl;
  }



}
