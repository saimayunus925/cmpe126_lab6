/*
 * StackOverflow.h
 *
 *  Created on: Nov 20, 2019
 *      Author: yunus
 */

// this is my stack class
// I named it "StackOverflow" as a joke, and so I could distinguish b/w it and the STL stack

#ifndef STACKOVERFLOW_H_
#define STACKOVERFLOW_H_
#define SIZE 10000

#include <iostream>

class StackOverflow {
public:
  StackOverflow();
  virtual ~StackOverflow();
  int top;
  char *A;
  bool is_empty();
  void destroy(), initialize_stack();
  void push(char value);
  void pop();
  char show_top();
  void display_stack();
};

#endif /* STACKOVERFLOW_H_ */
