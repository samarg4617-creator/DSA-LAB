#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) cin >> temp[i];

    int ans[n];
    for (int i = 0; i < n; i++) ans[i] = 0;

    Stack st; // stack will store indices

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop all days with temperature less than or equal to current day's temperature
        while (!st.isEmpty() && temp[st.peek()] <= temp[i]) {
            st.pop();
        }

        // If stack not empty, top of stack is the next warmer day
        if (!st.isEmpty()) {
            ans[i] = st.peek() - i;
        }

        // Push current day index onto stack
        st.push(i);
    }

    cout << "Answer array: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
