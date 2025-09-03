#include <iostream>

class Node {
    friend class LinkedList;

   private:
    int value;
    Node* next;
    Node* prev;

   public:
    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

class LinkedList {
   private:
    Node* head;
    int size;

   public:
    LinkedList(int val) {
        head = new Node(val);
        size = 1;
    }

    void deleteNode(Node* delNode) {
        // Connect prevNode to nextNode
        if (delNode->prev) {
            delNode->prev->next = delNode->next;
        }

        // Connect nextNode to prevNode
        if (delNode->next) {
            delNode->next->prev = delNode->prev;
        }

        // Appoint new head
        if (delNode == head) {
            head = delNode->next;
        }

        delete delNode;
        size--;
    }

    void swapNodes(Node* nodeA, Node* nodeB) {
        // swap at head

        // swap at tail
    }

    Node* insertNode(int value, Node* prevNode = nullptr) {
        Node* newNode = new Node(value);
        // Insert node to HEAD
        if (prevNode == nullptr) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            // Generic cases
            newNode->next = prevNode->next;
            if (prevNode->next != nullptr) {
                prevNode->next->prev = newNode;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
        }
        return newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " --> ";
            current = current->next;
        }
        std::cout << "\n";
    }

};

int main() {
    LinkedList* linkedList = new LinkedList(4);
    Node* a = linkedList->insertNode(3);
    Node* b = linkedList->insertNode(8, a);
    Node* c = linkedList->insertNode(5, b);

    linkedList->display();
    
    linkedList->deleteNode(c);
    linkedList->display();
}
