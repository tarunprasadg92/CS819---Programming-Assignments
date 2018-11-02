#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
#include<sstream>
#include<cctype>
#include<queue>
#include<string.h>
#include<stdlib.h>

using namespace std;

// Function to evaluate individual arithmetic operations
int evaluate(int operand_1, int operand_2, char *token);

// Function to convert the infix expression to postfix expression
string infix_to_postfix(string expr);

// Function to compute the postfix expression and print the result
void postfix_evaluator(string postfix);
