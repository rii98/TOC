#include <iostream>
using namespace std;

char St[100];
int tos = -1;

void push(char a)
{
  tos += 1;
  St[tos] = a;
}

void pop()
{
  tos -= 1;
}

int main()
{
  string s, c_state = "q0";
  char inp;
  cout << "Implementation of PDA that accepts odd palindrome" << endl;
  cout << "Enter string: ";
  cin >> s;
  int i = 0, r = 0;
  while ((inp = s[i++]) != '\0')
  {
    if (c_state == "q0" && (inp == 'a' || inp=='b'))
    {
      cout << "a pushed into stack" << endl;
      push(inp);
    }
    else if(c_state=="q0" && inp=='c'){
      cout<<"c has been read"<<endl;
      c_state="q1";
    }
    else if ( c_state == "q1" && inp == 'b' && St[tos] == 'b')
    {
      cout << "b popped from stack" << endl;
      c_state = "q1";
      pop();
    }
    else if ( c_state == "q1" && inp == 'a' && St[tos] == 'a')
    {
      cout << "a popped from stack" << endl;
      c_state = "q1";
      pop();
    }
    else
    {
      r = 1;
      break;
    }
  }
  if (tos == -1 && r == 0)
  {
    cout << "Accepted" << endl;
  }
  else
  {
    cout << "Rejected" << endl;
  }

  return 0;
}
