#include <iostream>


using namespace std;

struct Node {
    int data;
    Node* next;
};



class LinkedList {
    private:
        Node* head;
        int length;
    public:
        LinkedList() {
            head = nullptr;
            length = 0;
        }
    
        void append(int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            length++;
            return;
        }

        void prepend(int value) {
            if (head == nullptr) {
                Node * newNode = new Node();
                newNode->data = value;
                newNode->next = nullptr;
                head = newNode;
                length++;
                return;
            }
            Node * newNode = new Node();
            newNode->data = value;
            newNode->next = head;
            head = newNode;
            length++;
        }

        void insert(int value, int pos) {
            if ((0 <= pos < length)) {
                cout << "Index (" << pos << ") out of range or negative index" << std::endl;
                return;
            }
            if (pos == 0) {
                prepend(value);
                return;
            }
            if (pos == length - 1){
                append(value);
                return;
            }
            Node* temp = head;
            for (int i = 0; i < pos; i++) {
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void remove(int pos) {
            if (0 >= pos > length) {
                cout << "Index (" << pos << ") out of range or negative index" << std::endl;
                return;
            }
            if (pos == 0) {
                
            }
        }

        void removeValue(int value){
            if (head->data == value) {
                Node* temp = head->next;
                delete head;
                head = temp;
            } else {
                Node*previous = head;
                Node* temp = previous->next;
                while (temp != nullptr) {
                    if (temp->data == value) {
                        previous->next = temp->next;
                        delete temp;
                        return;
                    }
                    previous = previous->next;
                    temp = temp->next;
                }
            }
        }

        void removeAll(int value){

            while (head && head->data == value) {
                Node* temp = head->next;
                delete head;
                head = temp;

            }

            if (!head) return;

            Node*previous = head;
            Node* temp = previous->next;
            while (temp) {
                if (temp->data == value) {
                    previous->next = temp->next;
                    delete temp;
                    temp = previous->next;
                } else {
                    previous = previous->next;
                    temp = temp->next;
                }

            }
            
        }

        bool any(int value) {
            Node* temp = head;
            while (temp) {
                if (temp->data == value) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        bool all(int value) {
            Node* temp = head;
            while (temp) {
                if (temp->data != value) {
                    return false;
                }
                temp = temp->next;
            }
            return true;            
        }

        void print() {
            if (head == nullptr) {
                cout << "List is empty." << std::endl;
            } else {
                Node* temp = head;
                while (temp) {
                    cout << temp->data << "->";
                    temp = temp->next;
                }
                cout << "NULL" << std::endl;
            }
        }

        ~LinkedList() {
            Node* current = head;
            while (current) {
                Node * temp = current;
                current = current->next;
                if (temp) {
                    delete temp;
                }
            }
            head = nullptr;
        }

};

int main() {
    LinkedList list;

    return 0;
    }