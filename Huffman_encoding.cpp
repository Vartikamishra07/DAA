// Program to implement Huffman Encoding using a greedy strategy

#include <bits/stdc++.h>
using namespace std;

struct HuffmanNode 
{
    char data;                  // Input character
    int frequency;              // Frequency of the character
    HuffmanNode *left, *right;  // Left and right children

    HuffmanNode(char data, int frequency) 
    {
        left = right = nullptr;
        this->data = data;
        this->frequency = frequency;
    }
};

struct Compare // Comparator to order the min-heap (priority queue)
{
    bool operator()(HuffmanNode* left, HuffmanNode* right) 
    {
        return left->frequency > right->frequency;
    }
};

void printCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) 
{
    if (!root) return; // Function to print the Huffman codes

    if (!root->left && !root->right)  // If this node is a leaf node, it contains a character
    {
        huffmanCodes[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    printCodes(root->left, code + "0", huffmanCodes); // Traverse left and right subtrees
    printCodes(root->right, code + "1", huffmanCodes);
}

// Function to build the Huffman tree and print codes
void buildHuffmanTree(const string& text) 
{
    // Count the frequency of each character
    unordered_map<char, int> frequencyMap;  
    for (char ch : text) 
    {
        frequencyMap[ch]++;
    }

    //Create a priority queue (min-heap) and create a leaf node for each character and add it to the priority queue
    priority_queue<  HuffmanNode*, vector<HuffmanNode*>, Compare> pq; 
    for (auto pair : frequencyMap) 
    {
        pq.push(new HuffmanNode(pair.first, pair.second)); 
    }

    // Iterate until there is only one node left in the priority queue
    while (pq.size() > 1) 
    {
        // Remove two nodes of the highest priority (lowest frequency)
        HuffmanNode* left = pq.top();  
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes' frequencies
        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        // Add the new node to the priority queue
        pq.push(newNode);
    }

    // The remaining node is the root of the Huffman tree and traverse the Huffman tree and store the codes in a map
    HuffmanNode* root = pq.top();
    unordered_map<char, string> huffmanCodes;
    printCodes(root, "", huffmanCodes);

    // Print the encoded string
    cout << "\nEncoded string: ";
    for (char ch : text) 
    {
        cout << huffmanCodes[ch];
    }
    cout << endl;
}

int main() 
{
    string text;
    cout << "Enter text to encode using Huffman Encoding: ";
    getline(cin, text);
    buildHuffmanTree(text);
    return 0;
}