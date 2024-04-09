#include <iostream>
#include <stack>
using namespace std;

enum States {q0,q1,q2,qf,qr};
States next_state(States current_state, char tos, char current, stack<char> &s){
    switch (current_state){
    case q0:
        if (current == 'e' && tos == 'e'){
            current_state = q1;
            s.push('$');
        }
        break;
    case q1:
        if (current == 'a' && (tos == 'a' || tos == '$')){
            current_state = q1;
            s.push(current);
        }
        else if (current == 'c' && (tos == 'a' || tos == '$')){
            current_state = q2;
        }
        else current_state = qr;
        break;
    case q2:
        if (current == 'b' && tos == 'a'){
            current_state = q2;
            s.pop();
        }
        else if (current == '\0' && tos == '$')
        {
            current_state = qf;
            s.pop();
        }
        else current_state = qr;
    case qf:
    case qr:
        break;
    }
    return current_state;
}

int main()
{
    stack<char> s;
    s.push('e'); // 'e' represents empty stack
    string input;
    cout << "Enter string: ";
    cin >> input;
    States current_state = q0;
    char current = 'e';
    current_state = next_state(current_state, s.top(), current, s);
    for (int i = 0; i <= input.size(); i++){
        char current = input[i];
        current_state = next_state(current_state, s.top(), current, s);
        if (current_state == qr)
            break;
    }
    if (current_state == qf)
        cout << "String is accepted!!!" << endl;
    else
        cout << "String is rejected!!!" << endl;
    return 0;
}
