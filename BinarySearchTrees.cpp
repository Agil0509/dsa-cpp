#include <iostream>

using namespace std;


class Node{
    public:
        int value;
        Node* left;
        Node* right;
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
    private:
        Node* root;
    
    public:
        BinarySearchTree() {
            root = nullptr;
        }

    bool insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return true;
        }
        Node* temp = root;

        while (true) {
            if (newNode->value == temp->value) {
                delete newNode;
                return false;
            };
            if (newNode->value < temp->value){
                if (temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            } else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    bool contains(int value) {
        // if (root == nullptr) return false;
        
        Node* temp = root;

        while (temp != nullptr) {
            if (temp->value == value) return true;
            if (value < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return false;
    }

};


int main() {    BinarySearchTree* BST = new BinarySearchTree();
    bool insert_result = BST->insert(10);
    bool insert_result2 = BST->insert(10);
    bool insert_result3 = BST->insert(11);
    bool insert_reslut4 = BST->insert(12);
    
    bool contain_or_not = BST->contains(9);
    cout << contain_or_not<< endl;
}