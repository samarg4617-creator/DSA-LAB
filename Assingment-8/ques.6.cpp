#include <iostream>
using namespace std;

class MaxPriorityQueue {
    int arr[100];
    int size;

public:
    MaxPriorityQueue() {
        size = 0;
        arr[0] = -1;
    }

    void push(int val) {
        size++;
        arr[size] = val;
        int i = size;
        while (i > 1 && arr[i/2] < arr[i]) {
            swap(arr[i/2], arr[i]);
            i = i / 2;
        }
    }

    void pop() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while (true) {
            int left = 2*i, right = 2*i+1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest]) largest = left;
            if (right <= size && arr[right] > arr[largest]) largest = right;

            if (largest == i) break;

            swap(arr[i], arr[largest]);
            i = largest;
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[1];
    }

    bool empty() {
        return size == 0;
    }

    void display() {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << "Max Priority Queue: ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;
    pq.pop();

    cout << "After pop: ";
    pq.display();
}