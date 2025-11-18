#include <iostream>
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

    void DFSRec(int node, bool visited[]) {
        visited[node] = true;
        cout << node << " ";

        Node* temp = adj[node];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                DFSRec(temp->data, visited);
            }
            temp = temp->next;
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        DFSRec(start, visited);
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "DFS starting from 0: ";
    g.DFS(0);
}
