#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparison object to be used in the priority queue (min-heap)
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to print the Huffman codes
void printCodes(Node* root, string str) {
    if (!root)
        return;
    // If it's a leaf node (contains a character)
    if (root->ch != '\0')
        cout << root->ch << ": " << str << endl;
  printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build the Huffman Tree and generate Huffman codes
void huffmanEncoding(unordered_map<char, int> freqMap) {
    // Create a priority queue (min-heap) to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    // Iterate until the heap contains only one node (the root)
    while (minHeap.size() != 1) {
        // Remove the two nodes of the highest priority (lowest frequency)
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        // Create a new internal node with these two nodes as children
        // The frequency of the new node is the sum of the frequencies of the two nodes
        Node *sumNode = new Node('\0', left->freq + right->freq);
        sumNode->left = left;
        sumNode->right = right;
        // Add the new node to the priority queue
        minHeap.push(sumNode);
    }
    // The remaining node is the root of the Huffman Tree
    Node* root = minHeap.top();
    // Print Huffman codes using the Huffman tree
    cout << "Huffman Codes:" << endl;
    printCodes(root, "");
}
int main() {
// Example frequency map of characters
unordered_map<char, int> freqMap;
int n;
cout << "Enter the number of characters: ";
cin >> n;
cout << "Enter characters and their frequencies:" << endl;
for (int i = 0; i < n; ++i) {
char ch;
int freq;
cin >> ch >> freq;
freqMap[ch] = freq;
}
// Perform Huffman Encoding
huffmanEncoding(freqMap);
return 0;
}
