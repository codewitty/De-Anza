/* Calculator.h - Our node class template. */
#pragma once

#include<iostream>
#include<string>
#include "Stack.h"


using namespace std;

// Function to check for digit
bool	isOperator(string c);
// Function to check precedence
int		precedence(char c);
// Function to convert infix to postfix
string	infixToPostfix(string infix);
// Function to convert infix into prefix
string	infixToPrefix(string infix);
// Helper function for converting infix into prefix
string	convertToPrefix(string infix);
// Function to validate user input
bool	inputValidationOp(string input);
// Function to help validate braces
bool	checkPair(char opening, char closing);
// Function to check well formed expression
bool	balancedParentheses(string exp);
// Function to evaluate Postfix expression and return output
int		EvaluatePostfix(string expression);
// Function to evaluate Postfix expression and return output
int		EvaluatePrefix(string expression);
// Function to perform an operation and return output. 
int		PerformOperation(char operation, int operand1, int operand2);
// Function to verify whether a character is operator symbol or not. 
bool	IsOperator(char C);
