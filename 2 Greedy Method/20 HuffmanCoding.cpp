#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode *left, *right;
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) const {
        return lhs->freq > rhs->freq;
    }
};

HuffmanNode* buildHuffmanTree(map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;
    for (auto& pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();
        HuffmanNode* parent = new HuffmanNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
    }
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    string text;
    cout << "Enter the Message: ";
    cin >> text;
    int n = text.size();
    map<char, int> freq;
    for (int i = 0; i < n; i++)
        freq[text[i]]++;
    float totalFreq = 0;
    for (map<char,int>::iterator i = freq.begin(); i != freq.end(); i++)
        totalFreq += i->second;
    HuffmanNode* root = buildHuffmanTree(freq);
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);
    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }
    int codeLen = 0;
    int messageLen = 0;
    for (auto& pair : huffmanCodes) {
        codeLen += (pair.second).size();
        messageLen += freq[pair.first] * (pair.second).size();
    }
    cout << "Message Length: " << messageLen << endl;
    cout << "Average Message Length: " << messageLen / totalFreq << endl;
    int tableSize = freq.size() * 8 + codeLen;
    cout << "Table Size: " << tableSize << endl;
    cout << "Total Size: " << messageLen + tableSize << endl;
    return 0;
}
