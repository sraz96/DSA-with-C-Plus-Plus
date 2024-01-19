#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int size;
    Node* left;
    Node* right;

    Node(int val) : size(val), left(nullptr), right(nullptr) {}
};

// Comparator for the min-heap
struct CompareNode {
    bool operator()(Node* const& n1, Node* const& n2) {
        return n1->size > n2->size;
    }
};

// Function to build the optimal merge tree and calculate total cost
int optimalMergePattern(vector<int>& files) {
    priority_queue<Node*, vector<Node*>, CompareNode> minHeap;

    for (int file : files) {
        minHeap.push(new Node(file));
    }

    int totalCost = 0;

    // Merge nodes until there is only one node (root) left
    while (minHeap.size() > 1) {
        Node* smallest1 = minHeap.top();
        minHeap.pop();
        Node* smallest2 = minHeap.top();
        minHeap.pop();

        Node* mergedNode = new Node(smallest1->size + smallest2->size);
        totalCost += mergedNode->size;

        mergedNode->left = smallest1;
        mergedNode->right = smallest2;

        minHeap.push(mergedNode);
    }

    return totalCost;
}

void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    vector<int> files = {4, 3, 2, 6,45,23,78};

    cout << "File Sizes: ";
    for (int file : files) {
        cout << file << " ";
    }
    cout << endl;

    int totalCost = optimalMergePattern(files);

    cout << "Optimal Merge Cost: " << totalCost << endl;

    return 0;
}
