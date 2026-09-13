#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};



class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while(temp){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            cout << "Head: " << head->value << endl;
        }
        
        void getTail() {
            cout << "Tail: " << tail->value << endl;
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append (int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            length++;   
        }

        void deleteLast() {
            if (length == 0) return;
            Node* pre = head;
            Node* temp = head;
            while(temp -> next) {
                pre = temp;
                temp = temp -> next;
            }
            tail = pre;
            tail->next = nullptr;
            length--;
            if (length == 0) {
                head = nullptr;
                tail = nullptr;
            }
            delete temp;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length ++;
        }

        void deleteFirst() {
            Node* temp = head;
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = temp->next;
            }
            delete temp;
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) {
                return nullptr;
            }
            Node* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }

        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value) {
            if (length == 0) {
                prepend(value);
            }
            if (index == length) {
                append(value);
            } else {
                Node* newNode = new Node(value);
                Node* temp = get(index - 1);

                newNode->next = temp->next;
                temp->next = newNode;
            }
            length++;
            return true;
                            
        }

        void deleteNode(int index) {
            if (length ==0) return;
            Node* temp = get(index);
            Node* pre = get(index-1);
            pre->next = temp->next;
            delete temp;
            length--;
        }

        void reverse() {
            Node* temp = head;
            head = tail;
            tail = temp;
            Node* before = nullptr;
            Node* after = nullptr;
            for (int i=0; i < length; i++){
                after = temp->next;
                temp->next = before;
                before = temp;
                temp = after;
            }

        }

        Node* findMiddleNode() {
            if (head == nullptr) return nullptr;
            if (head == tail) return head;
            Node* slow = head;
            Node* fast = head;
            while(true) {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == tail || fast == tail->next){
                    return slow;}
            }
        }

        bool hasLoop() {
            if (head == nullptr) return false;
            if (head == tail) return true;
            Node* slow = head;
            Node* fast = head;

            while(true) {
                slow = slow->next;
                fast = fast->next->next;
                
                if (slow == fast) return true;
                if (fast == tail || fast == tail->next) return false;
            }
        }
        
        Node* findKthFromEnd(int k) {
            Node* slow = head;
            Node* fast = head;

            while (true) {
                fast = slow;
                for (int i=0; i<k-1; i++) {
                    fast = fast->next;
                    if (fast == nullptr) return nullptr;
                }
                // cout<< fast->value << endl;
                if (fast == tail) return slow;
                slow = slow->next;

            }
        }


        void removeDuplicates() {
            Node* current = head;

            while (current != nullptr) {

                Node* running = current->next;
                Node* deleted = current;

                while(running != nullptr) {

                    if (running->value == current->value) {
                        deleted->next = running->next;
                        delete running;
                        cout << "Deletd" << endl;
                        running = deleted;
                    }
                    deleted = running;
                    running = running->next;
                }
                current = current->next;
            }
        }
        int binaryToDecimal() {
            Node* current = head;
            int num = 0;

            while (current != nullptr) {
                num = 2*num + current->value * 1;
                current = current->next;
            }
            return num;

        }



        void partitionList(int x) {
            if (head == nullptr) return;

            Node* D1 = new Node(0);
            Node* D2 = new Node(0);

            Node* prev_d1 = D1;
            Node* prev_d2 = D2;

            Node* current = head;

            while (current != nullptr) {
                // cout << current->value << endl;
                if (current->value < x) {
                    prev_d1->next = current;
                    prev_d1 = prev_d1->next;
                }
                else{
                    prev_d2->next = current;
                    prev_d2 = prev_d2->next;
                }
                current = current->next;
            }
            prev_d1->next = D2->next;
            prev_d2->next = nullptr;
            delete D2;
            head = D1->next;
            delete D1;
        }

        void reverseBetween(int m, int n) {

            if (head == nullptr) return;

            Node* D = new Node(0);
            D->next = head;

            Node* prev = D;
            for (int i=0; i<m; i++) {
                prev = prev->next;
            }
            
            cout << prev->value << endl;

            Node* current = prev->next;

            

            for (int j=0; j<n-m; j++) {
                cout << j << endl;

                Node* to_move = current->next;
                // prev->next = to_move;
                current->next = to_move->next;
                to_move->next = prev->next;
                prev->next = to_move;
            }
            head = D->next;
            delete D;

        }

        void swapPairs() {
            if (head == nullptr) return;

            Node* D = new Node(0);
            D->next = head;

            Node* first = head;
            Node* second = head->next;
            Node* prev = D;
            // cout << prev->value << endl;
            while (true) {
                // cout << prev->value << endl;
            
                prev->next = second;
                first->next = second->next;
                second->next = first;
                
                if (first ->next == nullptr) break;
                prev = first;
                first = prev->next;
                if (first ->next == nullptr) break;
                second = first->next;
            }
            head = D->next;
            delete D;

        }


};






int main() {
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    // myLinkedList->append(5);
  

    // myLinkedList->printList();
    myLinkedList->swapPairs();
    myLinkedList->printList();

    }
