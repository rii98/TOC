

#include <iostream>
#include <stack>
using namespace std;
enum States
{
    q0,
    q1,
    qf
};

States next_state(States current_state, char tos, char current, stack<char> &s)
{
    switch (current_state)
    {
    case (q0):
        if (current == 'e' && tos == 'e')
        {
            s.push('$');
            current_state = q1;
        }
    case (q1):
        if (current == 'a' && (tos == '$' || tos == 'a'))
        {
            s.push(current);
            return q1;
        }
        else if (current == 'b' && (tos == '$' || tos == 'b'))
        {
            s.push(current);
            current_state = q1;
        }
        else if (current == 'a' && tos == 'b' || current == 'b' && tos == 'a')
        {
            s.pop();
            current_state = q1;
        }

        else if (current == '\0' && tos == '$')
        {
            s.pop();
            current_state = qf;
        }

    case qf: // just because compiler was throwing error 
        break;
    }

    return current_state;
}
int main()
{

    stack<char> s;
    s.push('e'); // e is eplsion and indicates empty stack

    string input;

    cout << "Enter string: ";
    cin >> input;

    States current_state = q0;

    char current = 'e';

    current_state = next_state(current_state, s.top(), current, s);
   

    for (int i = 0; i <= input.size(); i++)
    {
        current = input[i];
        current_state = next_state(current_state, s.top(), current, s);
    }
    if (current_state == qf)
    {
        cout << "String is accepted!!!";
    }
    else
    {
        cout << "String is rejected!!!";
    }

    return 0;
}