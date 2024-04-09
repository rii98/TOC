#include <iostream>
using namespace std;

enum States {
    q0,q1,q2,qd
};

int main(){

    string input_tape;
    cout<<"Enter string:";
    cin >> input_tape;
    States current_state = q0;

    for(int i = 0;i<input_tape.size();i++){
        char current = input_tape[i];
        switch(current_state){

            case(q0):
                if(current == 'a') current_state = q1;
                else if(current == 'b') current_state = q2;
                else current_state = qd;
                break;
            case(q1):
                while(i<input_tape.size() && input_tape[i] == 'b') i++;
                if(i<input_tape.size() && input_tape[i] == 'a') current_state = qd;
                break;
            case(q2):
                while(i<input_tape.size() && input_tape[i] == 'a') i++;
                if(i<input_tape.size() && input_tape[i] == 'b') current_state = qd;
                break;
            case qd:
                break;
        }
        if(current_state == qd) break;
    }
    if(current_state == q1 || current_state == q2) cout<<"String is accepted!!!";
    else cout << "String is rejected!!!";
   return 0;
}