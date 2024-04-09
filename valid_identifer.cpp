#include <iostream>
using namespace std;

enum States
{
    q0,
    qf,
    qd
};
int main()
{

    string input;

    cout << "Enter the string:";
    cin >> input;

    States current_state = q0;

    for (int i = 0; i < input.size(); i++)
    {
        char current = input[i];
        switch (current_state)
        {
        case q0:
            if (current >= 'a' && current <= 'z' || current >= 'A' && current <= 'Z' || current == '_')
                current_state = qf;
            else
                current_state = qd;
            break;
        case qf:
            if (current >= 'a' && current <= 'z' || current >= 'A' && current <= 'Z' || current == '_' || current >= '0' && current <= '9')
                current_state = qf;
            else
                current_state = qd;
        case qd:
            break;
        }
        if (current_state == qd)
            break;
    }
    if (current_state == qf)
        cout << "String is accepted!!!";
    else
        cout << "String is invalid!!!";
    return 0;
}