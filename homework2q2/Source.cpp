// 2. Write a prefix stack and show how it works (in main).
#include<iostream>
#include "myStack.h"
using namespace std;

void evaluateExpression(string exp) {
	stackType <double> stack(100);	//creating a stack of size 100 to hold doubles because our calculations may result in floating point numbers

	//reading the string backwards for prefix notation
	for (int i = exp.length() - 1; i >= 0; i--) {
		if (isdigit(exp[i]))
			stack.push(exp[i] - '0');	//if a numeric value found then add to the stack
		else {
			double topVal = stack.top();	//value of the top element in the stack gets assigned
			stack.pop();	//removing the top element

			if (stack.isEmptyStack())	//if the stack is empty
				cout << "Nothing to calculate!" << endl;
			else {
				//if there are more numeric chars or operands present
				double valBelowTop = stack.top();	//the next numeric char gets assigned
				stack.pop();	//removing the element after assignment

				//dealing with the operands
                switch (exp[i])  //check char
                {
                case '+':                      //add when "+" is found
                    stack.push(valBelowTop + topVal);
                    break;
                case '-':                      //subtract when "-" is found
                    stack.push(valBelowTop - topVal);
                    break;
                case '*':                       //multiply when "*" is found
                    stack.push(valBelowTop * topVal);
                    break;

                case '/':                       //divide when "/" is found
                    if (topVal != 0)               //the denominator can't be 0
                        stack.push(valBelowTop / topVal);
                    else
                    {
                        cout << "Division by 0 is invalid"; //gives error message
                    }
                    break;
                default:
                    cout << "Illegal operator!";  //if the the valid operands not found
                }
			}
		}
	}
    //display result
    cout << stack.top() << endl;
}

int main() {
    string input = "+9*26";
    //string input = "-+235";
    //string input = "-+*23*549";
    evaluateExpression(input);
}