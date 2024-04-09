#include <iostream>
using namespace std;
enum States {q0,q1,q2,q3,q4,qf,qr};
int main()
{
    string input;
    cout << "Enter the string: ";
    cin >> input;
    States current_state = q0;
    int i = 0;
    input = input + 'B';
    while (true)
    {
        if (current_state == qf || current_state == qr)
            break;

        switch (current_state)
        {
        case q0:
            while(input[i] == 'X' || input[i] == 'Y') i++;
            if (input[i] == 'a')
            {
                input[i] = 'X';
                i++;
                current_state = q1;
            }
            else if(input[i] == 'b'){
                input[i] = 'Y';
                i++;
                current_state = q2;
            }
            else if (input[i] == 'B')
            {
                i++;
                current_state = qf;
            }
            else current_state = qr;
            break;
        case q1:
            while (input[i] == 'a' || input[i] == 'Y')
                i++;
            if (input[i] == 'b')
            {
                input[i] = 'Y';
                i--;
                current_state = q3;
            }
            else
                current_state = qr;
            break;
        case q3:
            while (input[i] == 'a' || input[i] == 'Y')
                i--;
            if (input[i] == 'X')
            {
                i++;
                current_state = q0;
            }
            else
                current_state = qr;
            break;
        case q2:
            while (input[i] == 'X' || input[i] == 'b')
                i++;
            if (input[i] == 'a')
            {
                input[i] = 'X';
                i--;
                current_state = q4;
            }
            else
                current_state = qr;
            break;
        case q4:
             while (input[i] == 'X' || input[i] == 'b')
                i--;
            if(input[i] == 'Y'){
                i++;
                current_state = q0;
            }else{
                current_state = qr;
            }
        case qf:
        case qr:
            break;
        }
    }
    if (current_state == qf)
    {
        cout << "String is accepted." << endl;
    }
    else
    {
        cout << "String is rejected." << endl;
    }
    return 0;
}