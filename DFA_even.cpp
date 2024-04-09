#include <iostream>
using namespace std;
enum States {q0,qf};

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

    States current_state = qf;

    for(int i = 0;i<input.size();i++)
    {
        char current_ch = input[i];
        switch(current_state){
            case qf:
                if(current_ch == 'a' || current_ch == 'b') current_state = q0;
                break;
            case q0:
                if(current_ch == 'a' || current_ch == 'b')
                    current_state = qf;
                break;
        }
    }
    if(current_state == qf){
        cout<<"String is accepted!!!";
    }else cout<<"String is rejected!!!";
    return 0;
}