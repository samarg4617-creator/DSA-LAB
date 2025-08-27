#include <iostream>
#include <string>
#include <stack>
using namespace std;
//Given a string, reverse it using STACK. For example “DataStructure” should be output as “erutcurtSataD.” 

void reverse( string s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++) {
        st.push(s[i]);
    }
   int n= st.size();
   string reversed ="";
    while(!st.empty())
    {
        reversed= reversed+ st.top();
        st.pop();
    }
     cout << "Original string: " << s << endl;
    cout << "Reversed string: " << reversed << endl;
}
int main() {
    string str="DataStructure";
    reverse(str);

    return 0;
}