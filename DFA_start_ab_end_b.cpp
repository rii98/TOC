#include <iostream>
using namespace std;
enum States {q0,q1,q2,qf,qd};

int main()
{
    string input;
    bool valid_input;

    // This code make sure input contains either a or b only.
    do{
    valid_input = true;
    fflush(stdin);
    cout<<"Enter string:";cin >> input;
    for(int i = 0;i<input.size();i++){
        if(input[i] != 'a' && input[i] != 'b') {
            cout<<"String must contain a & b only."<<endl;
            valid_input = false;
        }
    }
    }while(!valid_input);

    States current_state = q0;

    for(int i = 0;i<input.size();i++)
    {
        char current_ch = input[i];
        switch(current_state){
            case q0:
                if(current_ch == 'a') current_state = q1;
                else current_state = qd;
                break;
            case q1:
                if(current_ch == 'b')
                    current_state = qf;
                else current_state = qd;
                break;
            case qf:
                if(current_ch == 'a') current_state = q2;
                break;
            case q2:
                if(current_ch == 'b') current_state = qf;
                break;
            case qd:
                break;
        }
        if(current_state == qd) break;
    }
    if(current_state == qf){
        cout<<"String is accepted!!!";
    }else cout<<"String is rejected!!!";
    return 0;
}