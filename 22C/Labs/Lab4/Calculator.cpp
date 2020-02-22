#include "Calculator.h"
bool isOperator(string c)
{
	// Convert string to char to check for digit
	char b = c[0];
	return (!isdigit(b));
}

// Set precedence of operators for use in calculations
// on postfix and prefix operations
int precedence(char c)
{
	if (c == '-' || c == '+')
		return 1;
	else if (c == '*' || c == '/' || c == '%')
		return 2;
	return 0;
}

//**********************************************************************//
// This infix to postfix convertor.										// 
// pre:  User provided infix string expression.							//
// return: returns a string formatted in postfix format.				//
//**********************************************************************//
string infixToPostfix(string infixExpr)
{
	infixExpr = '(' + infixExpr + ')';
	int exprSize(infixExpr.size());
	Stack<string> expr_stack;
	string output;

	for (int ndx = 0; ndx < exprSize; ndx++) {
		// -------------------------------------------------------
		// CASE : ' ' delimiter
		// -------------------------------------------------------
		if (isspace(infixExpr[ndx]))
			output += infixExpr[ndx];
		// If the scanned character is an 
		// operand, add it to output. 
		else if (isdigit(infixExpr[ndx]))
			output += infixExpr[ndx];

		// -------------------------------------------------------
		// CASE : '(', Parens handled specially.  In this case 
		//        push it to the stack.                     
		// ------------------------------------------------------- 
		else if (infixExpr[ndx] == '(')
			expr_stack.push("(");

		// -------------------------------------------------------
		// CASE : ')', Parens handled specially.  If ‘)’, pop and 
		//        output until an ‘(‘ is encountered.	
		// -------------------------------------------------------
		// 
		else if (infixExpr[ndx] == ')') {

			while (expr_stack.peek() != "(") {
				output += expr_stack.peek();
				expr_stack.pop();
			}

			// Remove '(' from the stack 
			expr_stack.pop();
		}

		// -------------------------------------------------------
		// CASE : '+', '-'. '*', '/', or '%'. Supported operators.
		//			Check precedence and pop or add to output.
		// -------------------------------------------------------
		else {

			if (isOperator(expr_stack.peek())) {
				while (precedence((infixExpr.c_str())[ndx])
					<= precedence((expr_stack.peek().c_str())[0])) {
					output += expr_stack.peek();
					expr_stack.pop();
				}
				string temp1 = "";
				temp1 += infixExpr[ndx];
				// Push the operator at this point 
				expr_stack.push(temp1);
			}
		}
	}
	return output;
}

//**********************************************************************//
// This infix to prefix convertor.										// 
// pre:  User provided infix string expression.							//
// return: returns a string formatted in prefix format					//
//**********************************************************************//
string infixToPrefix(string infixExpr)
{
	// 1.  Reverse infix string
	// 2.  Flip parens (because they are reversed)
	// 3.  Get prefix
	// 4.  Reverse prefix

	// 1.  Reverse infix string
	reverse(infixExpr.begin(), infixExpr.end());
	// 2.  Flip parens (because they are reversed)
	int exprSize = infixExpr.size();
	for (size_t ndx = 0; ndx < exprSize; ndx++) {
		if (infixExpr[ndx] == '(') {
			infixExpr[ndx] = ')';
			ndx++;
		}
		else if (infixExpr[ndx] == ')') {
			infixExpr[ndx] = '(';
			ndx++;
		}
	}
	// 3.  Get prefix
	string prefix = convertToPrefix(infixExpr);
	// 4.  Reverse prefix
	reverse(prefix.begin(), prefix.end());

	return prefix;
}

//**********************************************************************//
// This is the helper function for infix to prefix conversion.			// 
// pre:  Reversed infix string expression.								//
// return: returns a string formatted in prefix format.					//
//**********************************************************************//
string convertToPrefix(string infixExpr)
{
	infixExpr = '(' + infixExpr + ')';
	int exprSize = infixExpr.size();
	Stack<string> expr_stack;
	string output;

	for (int ndx = 0; ndx < exprSize; ndx++) {
		// -------------------------------------------------------
		// CASE : ' ' delimiter
		// -------------------------------------------------------
		if (isspace(infixExpr[ndx])) {
			output += infixExpr[ndx];
		}
		// -------------------------------------------------------
		// CASE : Any digit (base 10) [0123456789]
		// -------------------------------------------------------
		else if (isdigit(infixExpr[ndx])) {
			output += infixExpr[ndx];
		}

		// -------------------------------------------------------
		// CASE : '(', Parens handled specially.  In this case 
		//        push it to the stack.                     
		// -------------------------------------------------------
		else if (infixExpr[ndx] == '(')
			expr_stack.push("(");

		// -------------------------------------------------------
		// CASE : ')', Parens handled specially.  If ‘)’, pop and 
		//        output until an ‘(‘ is encountered. 
		// -------------------------------------------------------
		// 
		else if (infixExpr[ndx] == ')') {

			while (expr_stack.peek() != "(") {
				output += expr_stack.peek();
				expr_stack.pop();
			}
			// Remove '(' from the stack 
			expr_stack.pop();
		}
		// -------------------------------------------------------
		// CASE : '+', '-'. '*', '/', or '%'. Supported operators.
		// -------------------------------------------------------
		else {

			if (isOperator(expr_stack.peek())) {
				while (precedence((infixExpr.c_str())[ndx])
					< precedence((expr_stack.peek().c_str())[0])) {
					output += expr_stack.peek();
					expr_stack.pop();
				}
				string temp1 = "";
				temp1 += infixExpr[ndx];
				// Push current Operator on stack 
				expr_stack.push(temp1);
			}
		}
	}
	return output;
}

//**********************************************************************//
// This is the helper function for input validation.					// 
// pre:  User provided string.											//
// return: True if operators are lesser than operands.					//
//**********************************************************************//
bool	inputValidationOp(string input) {
	int ndx(0);
	int intCount(0);
	int operatorCount(0);
	while (input[ndx]) {
		if (isdigit(input[ndx])) {
			while (isdigit(input[ndx])) {
				ndx++;
			}
			intCount++;
		}
		else if (input[ndx] == '+' ||
			input[ndx] == '-' ||
			input[ndx] == '*' ||
			input[ndx] == '/' ||
			input[ndx] == '%')
		{
			ndx++;
			operatorCount++;
		}
		else
			ndx++;
	}
	if (!(intCount - 1 == operatorCount)){
		cout << "****Error. Operators need to be only one more "
			 << "than operands.****\n";
			 // << "****Enter a valid expression****\n";
		return false;
	}
	else
		return true;
}

//**********************************************************************//
// This is the helper function for balancedParentheses.				// 							
// return: True if parentheses match.									//
//**********************************************************************//
bool checkPair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	return false;
}

//**********************************************************************//
// This is the helper function for input validation						// 
// pre:  User provided infix expression.								//
// return: True if braces are matched.									//
//**********************************************************************//
bool balancedParentheses(string exp)
{
	Stack<char>  braces;
	for (size_t ndx = 0; ndx < exp.length(); ndx++)
	{
		if (exp[ndx] == '{' || exp[ndx] == '[' || exp[ndx] == '}' || exp[ndx] == ']') {
			cout << "****Invalid Braces used, please use '(' and ')' only****\n";
			return false;
		}
		else if (exp[ndx] == '(')
			braces.push(exp[ndx]);
		else if (exp[ndx] == ')')
		{
			if (braces.isEmpty() || !checkPair(braces.peek(), exp[ndx]))
				return false;
			else
				braces.pop();
		}
	}
	return braces.isEmpty() ? true : false;
}

// Function to evaluate Postfix expression and return a result.
// This is base 10 interger math only
int EvaluatePostfix(string postfixExpr)
{
	// Declare an integer stack using our 'Stack' template. 
	Stack<int> myStack;

	// Our evaluation loop -- scan each character in the from left. 
	size_t postfixExprSize(postfixExpr.length());
	for (size_t ndx = 0; ndx < postfixExprSize; ndx++) {

		// -------------------------------------------------------
		// CASE : ' ' delimiter
		// -------------------------------------------------------
		// If character is a delimitter, move on. 
		if (postfixExpr[ndx] == ' ')  // check for blank de-limiter
			continue;  // Go to start of loop for another iteration....

		// -------------------------------------------------------
		// CASE : '+', '-'. '*', '/', or '%'. Supported operators.
		// -------------------------------------------------------
		// If character is operator, pop two elements from stack, perform operation and push the result back. 
		else if (IsOperator(postfixExpr[ndx])) {
			// Pop two operands. 
			int operand2(0);
			int operand1(0);

			// rhs
			operand2 = myStack.peek();
			myStack.pop();

			// lhs
			operand1 = myStack.peek();
			myStack.pop();

			// Perform operation
			int result = PerformOperation(postfixExpr[ndx], operand1, operand2);

			//Push back result of operation on stack. 
			myStack.push(result);
		}
		// -------------------------------------------------------
		// CASE : Any digit (base 10) [0123456789]
		// -------------------------------------------------------
		else if (isdigit(postfixExpr[ndx])) {
			// Extract the numeric operand from the string.  We generate an integer here.
			int operand = 0;

			// Parse the integer up to next nondigit, advance ndx.
			size_t  subNdx(0);
			operand = stoi(postfixExpr.substr(ndx), &subNdx);
			ndx += subNdx - 1;  // adv. ndx by sizeof operand and backstep.

			// Backstep the index becasue of outer loop scanning (ndx).
			//ndx--;

			// Push operand on stack. 
			myStack.push(operand);
		}
	}
	// If expression is in correct format, myStacktack will finally have one element. This will be the output. 
	return myStack.peek();
}

int EvaluatePrefix(string prefixExpr)
{
	// Declaring a myStacktack from myStacktandard template library in C++. 
	Stack<string> myStack;

	int prefixExprSize(prefixExpr.length());
	for (int ndx = 0; ndx < prefixExprSize; ndx++) {

		// -------------------------------------------------------
		// CASE : ' ' delimiter
		// -------------------------------------------------------
		// If character is a delimitter, move on. 
		if (prefixExpr[ndx] == ' ')
			continue;

		// -------------------------------------------------------
		// CASE : '+', '-'. '*', '/', or '%'. Supported operators.
		// -------------------------------------------------------
		// If character is operator, pop two elements from stack, perform 
		// operation and push the result back. 
		else if (IsOperator(prefixExpr[ndx])) {
			string temp("");
			temp += prefixExpr[ndx];
			myStack.push(temp);
		}
		// -------------------------------------------------------
		// CASE : Any digit (base 10) [0123456789]
		// -------------------------------------------------------
		else if (isdigit(prefixExpr[ndx])) {
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
			int op2(0);

			// Parse the integer up to next nondigit, advance ndx.
			// This part is input expression processing...
			size_t  subNdx(0);
			op2 = stoi(prefixExpr.substr(ndx), &subNdx);
			ndx += subNdx - 1;  // adv. ndx by sizeof operand and backstep.

			// ...whereas this part is processing back to back operands.
			// 'op2' operand2 is carried forward to this next loop.
			//
			// The basic operation of this loop :
			//
			// LOOP if stack not empty and next item is an integer
			//    1.  parse the integer (peek-then-pop).
			//    2.  parse the following operator (peek-then-pop).
			//    3.  calc intermediate result.
			//    4.  if next stack item is another operator or empty stack exit loop.
			// ENDLOOP
			while (!myStack.isEmpty() &&
				isdigit((myStack.peek().c_str())[0])) {
				int op1 = stoi(myStack.peek());
				myStack.pop();
				char opr = myStack.peek().c_str()[0];
				myStack.pop();
				op2 = PerformOperation(opr, op1, op2);
			}
			// push th result as a string top the stack
			myStack.push(to_string(op2));
		} // end else if check for numeric
	} // end for loop evaluating prefix expr
	return stoi(myStack.peek());
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return true;

	return false;
}

// Function to perform an operation and return output. 
// its pretty basic, pass in an lhs (operator1), rhs (operator2),
// and the operator (op)
int PerformOperation(char op, int operand1, int operand2)
{
	if (op == '+')
		return operand1 + operand2;
	else if (op == '-')
		return operand1 - operand2;
	else if (op == '*')
		return operand1 * operand2;
	else if (op == '/')
		return operand1 / operand2;
	else if (op == '%')
		return operand1 % operand2;
	else cout << "Unexpected Error \n";
	return -1;
}
