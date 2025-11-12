#include <iostream>
using namespace std;

class Heap {
public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        size++;
        arr[size] = val;
        int i = size;
        while (i > 1 && arr[i/2] < arr[i]) {
            swap(arr[i/2], arr[i]);
            i = i / 2;
        }
    }

    void heapify(int n, int i) {
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if (left <= n && arr[left] > arr[largest])
            largest = left;
        if (right <= n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(n, largest);
        }
    }

    void heapSort() {
  
        int n = size;
        while (n > 1) {
            swap(arr[1], arr[n]); 
            n--;
            heapify(n, 1);
        }
    }
};

int main() {
    Heap h;
    h.insert(4);
    h.insert(10);
    h.insert(3);
    h.insert(5);
    h.insert(1);

    h.heapSort();

    cout << "Sorted in Increasing Order: ";
    for (int i = 1; i <= h.size; i++)
        cout << h.arr[i] << " ";
}