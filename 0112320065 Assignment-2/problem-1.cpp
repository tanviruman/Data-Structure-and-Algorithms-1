#include <iostream>
#include <cstring>
#define MAX 200

using namespace std;

int arr[MAX];

int top = -1;

void push(int value)
{
    if (top >= MAX - 1)
        {
        cout << "Stack Overflow\n";
        return;
    }

      top++;
    arr[top] = value;
}

int pop()
 {
    if (top < 0)
        {
        cout << "Stack Underflow\n";
        return -1;
    }

    return arr[top--];
}

bool isOperator(char symbol)

{
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/';
}

int calculate(const char* expression)
{
    int i = 0;

    int OP1, OP2, result;

    while (expression[i] != '\0')
        {
        char symbol = expression[i];

        if (symbol >= '0' && symbol <= '9') {

            push(symbol - '0');
        }

        else if (isOperator(symbol))

            {
            if (top < 1)

            {
                cout << "Not enough operands\n";

                return -1;
            }


            OP2 = pop();
            OP1 = pop();


            switch (symbol)

            {
                case '-': result = OP1 - OP2; break;

                case '+': result = OP1 + OP2; break;

                case '*': result = OP1 * OP2; break;

                case '/':

                    if (OP2 == 0)
                        {
                        cout << "Division by zero\n";
                        return -1;
                    }

                    result = OP1 / OP2; break;
            }


            push(result);

        }
        else if (symbol != ' ')
            {

            cout << "Invalid Operators\n";
            return -1;
        }

        i++;
    }


    if (top != 0)

        {
        cout << "Invalid Expression\n";
        return -1;
    }

    return pop();
}

int main()
{
    char expression[MAX];

    cout << "Enter a postfix expression: ";

    cin.getline(expression, MAX);

    int result = calculate(expression);

    if (result != -1)

        {
        cout << "Result = " << result << "\n";
    }

    return 0;
}
