#include <iostream>

using namespace std;


class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) {
            this->value = value;
        }
};


class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while(temp) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            cout << "Head: " << head->value <<endl;
        }

        void getTail() {
            cout << "Tail: " << tail->value <<endl;
        }

        void getLength() {
            cout << "Length: " << length <<endl;
        }

        void append(int x) {
            Node* newNode = new Node(x);

            if (length < 1) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length ++;
        }

        void deleteLast() {
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            }
            Node* temp = tail;
            tail = temp->prev;
            tail->next = nullptr;
            delete temp;         
            length--;
        }

        void prepend(int x) {
            Node* newNode = new Node(x);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                newNode->prev = nullptr;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {
            if (length == 0) return;
            if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                head = temp->next;
                head->prev = nullptr;
                delete temp;
            }
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;

            Node* temp = head;

            if (index<=length/2) {
                for (int i=0; i<index; i++) {
                    temp = temp->next;
                }
            }
            else {
                temp = tail;
                for (int i=length-1; i>index; i--) {
                    temp = temp->prev;
                }
            }
            return temp;
        }

        bool set(int index, int value) {
            Node* temp =  get(index);

            if (temp){
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value) {
            if (index<0 || index >length) return false;

            if (index==0){
                prepend(value);
                return true;
            }
            if (index==length){
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* prev = get(index-1);

            newNode->next = prev->next;
            newNode->prev = prev;
            prev->next = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index<0 || index >= length) return;
            if (index==0) return deleteFirst();
            if (index==length-1) return deleteLast();

            Node* temp = get(index);

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }


};


int main() {
    
    DoublyLinkedList* DLL = new DoublyLinkedList(1);
    DLL->append(2);
    DLL->append(3);
    DLL->append(4);
    DLL->append(5);

    DLL->deleteNode(-1);


    
    DLL->printList();

}