#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(const string& s) {
    unordered_map<char, int> freq;
    queue<char> q;

    for (char ch : s) {
        if (ch == ' ') continue;  

        freq[ch]++;
        q.push(ch);
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";
}

int main() {
    string line;
    for (int i = 0; i < 2; i++) {
        getline(cin, line);
        firstNonRepeating(line);
    }

    return 0;
}