#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Graph {
public:
    int V;       
    Node** adj;    

    Graph(int v) {
        V = v;
        adj = new Node*[V];
        for (int i = 0; i < V; i++)
            adj[i] = NULL;   
    }


    void addEdge(int u, int v, bool directed = false) {
        Node* newNode = new Node(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        if (!directed) {
            Node* newNode2 = new Node(u);
            newNode2->next = adj[v];
            adj[v] = newNode2;
        }
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            Node* temp = adj[node];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "BFS starting from 0: ";
    g.BFS(0);
}
