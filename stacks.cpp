#include <iostream>

using namespace std; 


class  Node {
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};


class Stack {
    private:
        Node* top;
        int height;
    public:
        Stack(int value) {
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }
        
        void printStack() {
            Node* temp = top;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getTop() {
            cout << "Top: "  << top->value << endl;
        }
        
        void getHeight() {
            cout << "Height: " << height << endl;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            if (height==0) return INT8_MIN;
            Node* temp = top;
            int deleted_node = top->value;
            top = top->next;
            delete temp;
            height--;
            return deleted_node;

        }

        

};


int main() {
    Stack* myStack = new Stack(5);
    // myStack->getTop();
    // myStack->getHeight();
    int deleted_node = myStack->pop();
    cout << deleted_node << endl;
    int deleted_node2 = myStack->pop();
    cout << deleted_node2 << endl;
    // myStack->printStack();

}