#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Popped: " << q.front() << "\n";
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element: " << stack.top() << "\n";  
    stack.pop();  
    cout << "Top element: " << stack.top() << "\n";
    stack.pop();  

    cout << "Top element: " << stack.top() << "\n";  
    stack.pop();  
    stack.pop(); 
    return 0;
}
