#include <iostream>
using namespace std;

enum States{q0,q1,q2,q3,q4,q5,q6,qf,qd};
int main(){

    string input;
    cout<<"Enter the string:";
    cin >> input;

    States current_state = q0;

    for(int i = 0;i<input.size();i++){

        char current = input[i];

        switch(current_state){
            case q0:
                if(current == 'w') current_state = q1;
                else if(current == 'f') current_state = q5;
                else current_state = qd;     
                break; 
            case q1:
                if(current == 'h') current_state = q2;
                else current_state = qd;     
                break; 
            case q2:
                if(current == 'i') current_state = q3;
                else current_state = qd;     
                break; 
            case q3:
                if(current == 'l') current_state = q4;
                else current_state = qd;     
                break; 
            case q4:
                if(current == 'e') current_state = qf;
                else current_state = qd;     
                break; 
            case q5:
                if(current == 'o') current_state = q6;
                else current_state = qd;     
                break; 
            case q6:
                if(current == 'r') current_state = qf;
                else current_state = qd;     
                break;     
            case qf:
            case qd:
            break;
        }
    }
    if(current_state == qf) cout<<"String accepted!!!";
    else cout<<"String rejected";
    return 0;
}