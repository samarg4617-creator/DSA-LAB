#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        while (q1.size() > 1) {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        cout << "Popped: " << q1.front() << "\n";
        q1.pop();

        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        while (q1.size() > 1) {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        int topElement = q1.front();
        q2.push(topElement);
        q1.pop();
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues stack;

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