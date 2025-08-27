#include <iostream>
#include <string>
#include <stack>
using namespace std;      
int evaluatePostfix(string expr) {
    stack<int> st;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        
        if (c == ' ') continue;

        if (isdigit(c)) {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter postfix expression: ";
    getline(cin, expr);  
    cout << "Result = " << evaluatePostfix(expr) << endl;
    return 0;
}