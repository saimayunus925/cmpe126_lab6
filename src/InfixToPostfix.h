/*
 * InfixToPostfix.h
 *
 *  Created on: Nov 20, 2019
 *      Author: yunus
 */

#ifndef INFIXTOPOSTFIX_H_
#define INFIXTOPOSTFIX_H_

#include "StackOverflow.h"
#include <iostream>
#include <string>
#include <stack>

class InfixToPostfix {
  friend bool is_operand(char), is_operator(char), isOpeningPars(char), isClosingPars(char);
public:
  InfixToPostfix();
  virtual ~InfixToPostfix();
  bool precedence(char op1, char op2);
  void getInfix(std::string data);
  std::string showPostfix(), showInfix();
  std::string convertToPostfix();
  std::string convertToPostfix_STL();
private:
  std::string infix, postfix;
};

#endif /* INFIXTOPOSTFIX_H_ */
