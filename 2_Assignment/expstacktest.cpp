#include "expstack.h"

#include<assert.h>
#include<string.h>
#include<sstream>
#include<stdlib.h>

using namespace std;

EmptyStackException EmptyStackEx;

// Function to evaluate individual arithmetic operations
int evaluate(int operand_1, int operand_2, string token)
{
    if (token == "+")
        return operand_1 + operand_2;
    if (token == "-")
        return operand_1 - operand_2;
    if (token == "*")
        return operand_1 * operand_2;
    if (token == "/")
        return operand_1 / operand_2;
}

// Function to convert the infix expression to postfix
string infix_to_postfix(string expr)
{
    expstack s;
    string postfix;
    string number;
        
    // Traversing over every entity in the given infix expression
    for (int i = 0; i < expr.length(); i++)
    {
        // Neglect blank spaces
        if (expr[i] == ' ')
        {
            continue;
        }
        
        // Processing for opening paranthesis
        else if ((expr[i] == '(') || (expr[i] == '{') || (expr[i] == '['))
        {
            s.push(string(1, expr[i]));
            continue;
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == ')')
        {
            while ((!s.empty()) && (s.getTop() != "("))
            {
                postfix += s.getTop();
                postfix += " ";
                s.pop();
            }
            s.pop();
            continue;
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == '}')
        {
            while ((!s.empty()) && (s.getTop() != "{"))
            {
                postfix += s.getTop();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == ']')
        {
            while ((!s.empty()) && (s.getTop() != "["))
            {
                postfix += s.getTop();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }

        // Addition / Subtraction operators
        else if ((expr[i] == '+') || (expr[i] == '-')) 
        {
            if (s.empty())
            {
                s.push(string(1, expr[i]));
            }
            else
            {
                // If higher priority operators present in stack, pop them
                while ((!s.empty()) && ((s.getTop() == "*") || (s.getTop() == "/")))
                {
                    postfix += s.getTop();
                    postfix += " ";
                    s.pop();
                }
                s.push(string(1, expr[i]));
            }                
        }
        
        // Multiplication / Division operators
        else if ((expr[i] == '*') || (expr[i] == '/'))
        {
            if (s.empty())
            {
                s.push(string(1, expr[i]));
            }
            else
            {
                while ((!s.empty()) && ((s.getTop() != "(") || (s.getTop() != "{") || (s.getTop() != "[")))
                {
                    break;
                }
                s.push(string(1, expr[i]));
            }                
        }
        
        // Operands - with local loop to handle multiple digits
        else
        {
            while (isdigit(expr[i]))
            {
                number += expr[i];
                if (i < expr.length())
                    i++;
                else
                    break;
            }
            postfix += number;
            postfix += " ";
            number.clear();
            i--;
        }          
    }
    
    // Pop out the remaining operators in the stack
    while (!s.empty())
    {
        postfix += s.getTop();
        postfix += " ";
        s.pop();
    }
    
    return postfix;
}

void postfix_evaluator(string postfix)
{
    // Conversion of postfix expression to be stored into stack and computing the result
    expstack postfix_expr;
    istringstream iss(postfix);
    string token;
    
    // Each operator/operand identified exclusively through space delimiter added in the previous step
    while (getline(iss, token, ' '))
    {
        // For every operator, pop the last 2 elements in the stack and compute and store the result back into the stack
        if ((token == "+") || (token == "-") || (token == "*") || (token == "/"))
        {
            // Extracting the second operand and converting to integer
            const char *op2_str = postfix_expr.getTop().c_str();
            int op2 = atoi(op2_str);
            postfix_expr.pop();
            
            // Extracting the first operand and converting to integer
            const char *op1_str = postfix_expr.getTop().c_str();
            int op1 = atoi(op1_str);
            postfix_expr.pop();
            
            // Store the computed result into temporary variable and push back into the stack
            int temp = evaluate(op1, op2, token);

            stringstream ss;
            ss << temp;
            
            postfix_expr.push(ss.str());
        }
        
        // Operands can be pushed directly into the stack
        else
            postfix_expr.push(token);
    }
    
    // Display the final element in the stack as it is the needed result
    cout << "Result : " << postfix_expr.getTop() << endl;
}

int main()
{   
    cout << "Enter an expression : ";
    
    string expr;
    getline(cin, expr);
    
    // The process runs on in an infinite loop until the user keys in exit
    while (expr != "exit")
    { 
        // If input string is empty, try to get another string from the user
        if (expr.empty())
        {
            cout << "Enter an expression : ";
            getline(cin, expr);
            continue;
        }
        
        // Convert the given infix expression to postfix expression
        string postfix = infix_to_postfix(expr);
        cout << "Postfix Expression : " << postfix << endl;
        
        // Compute the postfix expression and print the result
        postfix_evaluator(postfix);        
        
        // Loop again to get another expression from the user
        cout << "Enter an expression : ";
        getline(cin, expr);
    }
    
    return 0;
}
