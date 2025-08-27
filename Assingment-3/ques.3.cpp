#include <iostream>
#include <string>
#include <stack>        
using namespace std;
   bool balancebracket(string s){
    stack<char> st;
    for(int i=0; i<s.length();i++) {
        if (st.empty() || s[i]=='[' || s[i]=='{' || s[i]=='(')
        {
            st.push(s[i]);
        }
        else
        {
            if(s[i]==']')
            {
                if (st.top()=='[')
                {
                    st.pop();

                }
                else { return false;}
            }

            else if(s[i]=='}')
            {
                if (st.top()=='{')
                {
                    st.pop();
                }
                else{return false;}

            }

            else {
                if (st.top()=='(')
                {
                    st.pop();
                }
                else { return false;}
            }
        }
    }
    if(st.empty()==false)
    {
        return true;
    }

   }
int main() {
   string s= "[{}]";

   bool ans = balancebracket(s);
   if(ans==true)
   {
    cout<<1;

   }
   else{cout<<0;}

    return 0;
}