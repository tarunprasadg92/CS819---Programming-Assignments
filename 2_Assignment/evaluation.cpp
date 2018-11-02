#include "evaluation.h"

// Function to evaluate individual arithmetic operations
int evaluate(int operand_1, int operand_2, char *token)
{
    if (strcmp(token, "+") == 0)
        return operand_1 + operand_2;
    if (strcmp(token, "-") == 0)
        return operand_1 - operand_2;
    if (strcmp(token, "*") == 0)
        return operand_1 * operand_2;
    if (strcmp(token, "/") == 0)
        return operand_1 / operand_2;
}

// Function to convert the infix expression to postfix expression
string infix_to_postfix(string expr)
{
    stack<char> s;
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
            s.push(expr[i]);
            continue;
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == ')')
        {
            while ((!s.empty()) && (s.top() != '('))
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
            continue;
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == '}')
        {
            while ((!s.empty()) && (s.top() != '{'))
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }
        
        // Processing for closing brackets - pop until the matching open brackets
        else if (expr[i] == ']')
        {
            while ((!s.empty()) && (s.top() != '['))
            {
                postfix += s.top();
                postfix += " ";
                s.pop();
            }
            s.pop();
        }

        // Addition / Subtraction operators
        else if ((expr[i] == '+') || (expr[i] == '-')) 
        {
            if (s.empty())
                s.push(expr[i]);
            else
            {
                // If higher priority operators present in stack, pop them
                while ((!s.empty()) && ((s.top() == '*') || (s.top() == '/')))
                {
                    postfix += s.top();
                    postfix += " ";
                    s.pop();
                }
                s.push(expr[i]);
            }                
        }
        
        // Multiplication / Division operators
        else if ((expr[i] == '*') || (expr[i] == '/'))
        {
            if (s.empty())
                s.push(expr[i]);
            else
            {
                while ((!s.empty()) && ((s.top() != '(') || (s.top() != '{') || (s.top() != '[')))
                {
                    break;
                }
                s.push(expr[i]);
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
        postfix += s.top();
        postfix += " ";
        s.pop();
    }
    
    return postfix;
}

// Function to compute the postfix expression and print the result
void postfix_evaluator(string postfix)
{
    // Store postfix expression into stack and compute the result
    stack<string> postfix_expr;
    istringstream iss(postfix);
    string token;
    
    // For every operator/operand on the stack
    while (getline(iss, token, ' '))
    {
        char *convert_token = new char[token.length() + 1];
        strcpy(convert_token, token.c_str());

        // For every operator, pop the last 2 elements in the stack and compute and store the result back into the stack
        if ((strcmp(convert_token,"+") == 0) || (strcmp(convert_token,"-") == 0) || (strcmp(convert_token,"*") == 0) || (strcmp(convert_token,"/") == 0))
        {
            // Extracting the second operand and converting to integer
            const char *op2_str = postfix_expr.top().c_str();
            int op2 = atoi(op2_str);
            postfix_expr.pop();
            
            // Extracting the first operand and converting to integer
            const char *op1_str = postfix_expr.top().c_str();
            int op1 = atoi(op1_str);
            postfix_expr.pop();
            
            // Store the computed result into temporary variable and push back into the stack
            int temp = evaluate(op1, op2, convert_token);

            // Convert int to string and store in stack
            stringstream ss;
            ss << temp;
            postfix_expr.push(ss.str());
        }
        
        // Operands can be pushed directly into the stack
        else
            postfix_expr.push(token);
    }
    
    // Display the final element in the stack - the computed result
    cout << "Result : " << postfix_expr.top() << endl;
}

// Main function - accepts infix expression, generates postfix and computes the result
int main()
{    
    cout << "Enter an expression : ";
    
    string expr;
    getline(cin, expr);
    
    // The process runs on in an infinite loop until the user keys in exit
    while (expr != "exit")
    {
        // If input string is empty, try to get another input from user
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
