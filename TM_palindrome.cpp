#include <iostream>
using namespace std;
enum States {q0,q1,q2,q3,q4,q5,qf,qr};
int main(){
    string input;
    cout << "Enter the string: ";
    cin >> input;
    States current_state = q0;
    int i = 0;
    input = input + 'B';
    while (true){
        if (current_state == qf || current_state == qr)
            break;
        switch (current_state){
        case q0:
            if (input[i] == 'a'){
                input[i] = 'X';
                i++;
                current_state = q1;
            }
            else if (input[i] == 'b'){
                input[i] = 'Y';
                i++;
                current_state = q2;
            }
            else if(input[i] == 'X' || input[i] == 'Y'){
                current_state = qf;
                i++;
            }
            else{
                current_state = qr;
            }
            break;
        case q1:
            while (input[i] == 'a' || input[i] == 'b')
                i++;
            if (input[i] == 'B' || input[i] == 'X' || input[i] == 'Y'){
                i--;
                current_state = q3;
            }
            else
                current_state = qr;
            break;
        case q2:
            while (input[i] == 'a' || input[i] == 'b')
                i++;
            if (input[i] == 'B' || input[i] == 'Y' || input[i] == 'X'){
                i--;
                current_state = q4;
            }
            else
                current_state = qr;
            break;
        case q3:
            if (input[i] == 'a'){
                input[i] = 'X';
                i--;
                current_state = q5;
            }
            else if(input[i] == 'X' || input[i] == 'Y'){
                current_state = qf;
                i++;
            }
            else
                current_state = qr;
            break;
        case q4:
            if(input[i] == 'b'){
                input[i] = 'Y';
                i--;
                current_state = q5;
            }
            else if(input[i] == 'X' || input[i] == 'Y'){
                current_state = qf;
                i++;
            }
            else
                current_state = qr;
            break;
        case q5:
            while (input[i] == 'a' || input[i] == 'b')
                i--;
            if(input[i] == 'X' || input[i] == 'Y'){
                i++;
                current_state = q0;
            }
            else current_state = qr;
            break;
        case qf:
        case qr:
            break;
        }
        cout<<input<<endl;
    }
    if (current_state == qf)
        cout << "String is accepted." << endl;
    else
        cout << "String is rejected." << endl;
    return 0;
}