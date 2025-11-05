#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array A: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    stack<int> S;
    int expected = 1;

    for (int i = 0; i < n; i++) {
   
        S.push(A[i]);

        while (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        }
    }

    if (S.empty()) cout << "Yes, possible to sort into B" << endl;
    else cout << "No, not possible" << endl;

    return 0;
}
