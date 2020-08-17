#include<bits/stdc++.h>
using namespace std;


class TrieNode {
public:
    TrieNode *left, *right;
    TrieNode() {
        left = NULL;
        right = NULL;
    }
};

void insert(TrieNode* root, int val) {
    TrieNode* current = root;
    for(int i=31; i>=0; i--) {
        if(val & (1 << i)) {
            if(root->right == NULL) 
                root->right = new TrieNode();
            root = root->right;
        } else {
            if(root->left == NULL) 
                root->left = new TrieNode();
            root = root->left;
        }
    }
}

int minXor(TrieNode* root, int v) {
    int min_xor = 0;
    TrieNode* current = root;
    int val = 0;
    for(int i=31; i>=0; i--) {
        if(v & (1<<i)) {
            if(current->right != NULL) {
                current = current->right;
                val += (1<<i);
            } else if(current->left != NULL) {
                current = current->left;
            }
        } else {
            if(current->left != NULL) {
                current = current->left;
            } else if(current->right != NULL) {
                current = current->right;
                val += (1<<i);
            } 
        }
    }
    return val^v;
}

int main() {
    int A[] = {25, 10, 2, 8, 5, 3};
    int n = sizeof(A) / sizeof(A[0]);
    int min_xor = INT_MAX;
    
    TrieNode* root = new TrieNode();
    insert(root, A[0]);
    for(int i=1; i<n; i++) {
        int xori = minXor(root, A[i]);
        insert(root, A[i]);
        min_xor = min(min_xor, xori);
    }
    return min_xor;
}
