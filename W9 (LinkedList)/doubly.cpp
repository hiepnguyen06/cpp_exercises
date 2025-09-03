#include <bits/stdc++.h>

class Node {
   private:
    int value;
    Node* next;
    Node* prev;

   public:
    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
    void linkNode(Node* next = nullptr, Node* prev = nullptr) {
        this->next = next;
        this->prev = prev;
    }
    friend void printForward(Node* head);
    friend void printBackward(Node* tail);
    friend void insertNode(Node*& head, Node*& tail, Node* priorNode, Node* newNode);
    friend void deleteNode(Node*& head, Node*& tail, Node* delNode);
    friend void swapNodes(Node*& head, Node*& tail, Node* first, Node* second);
};

void printForward(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value;
        current = current->next;
        if (current) std::cout << " --> ";
    }
    std::cout << "\n";
}

void printBackward(Node* tail) {
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->value;
        current = current->prev;
        if (current) std::cout << " --> ";
    }
    std::cout << "\n";
}

void insertNode(Node*& head, Node*& tail, Node* priorNode, Node* newNode) {
    if (!priorNode) {
        // Insert at head
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = priorNode;
        if (priorNode->next) {  // if not tail
            newNode->next = priorNode->next;
            newNode->next->prev = newNode;
        }
        priorNode->next = newNode;
    }

    if (!newNode->next) tail = newNode;
}

void deleteNode(Node*& head, Node*& tail, Node* delNode) {
    // if delNode is HEAD
    if (!delNode->prev) {
        delNode->next->prev = nullptr;
        head = delNode->next;
    }

    // if delNode is TAIL
    if (!delNode->next) {
        delNode->prev->next = nullptr;
        tail = delNode->prev;
    }

    // Generic cases
    if (delNode->next) delNode->next->prev = delNode->prev;
    if (delNode->prev) delNode->prev->next = delNode->next;
}

void swapNodes(Node*& head, Node*& tail, Node* first, Node* second) {
    
}

int main() {
    Node* nodeA = new Node(8);
    Node* nodeB = new Node(5);
    Node* nodeC = new Node(3);
    Node* nodeD = new Node(6);

    Node* head = nodeA;
    Node* tail = nodeD;
    nodeA->linkNode(nodeB);
    nodeB->linkNode(nodeC, nodeA);
    nodeC->linkNode(nodeD, nodeB);
    nodeD->linkNode(nullptr, nodeC);

    // Printing forward
    std::cout << "Printing forward" << std::endl;
    printForward(head);

    // Printing backward
    std::cout << "Printing backward" << std::endl;
    printBackward(tail);

    // Inserting nodes
    std::cout << "Inserting new nodes" << std::endl;
    Node* newNode = new Node(90);
    insertNode(head, tail, nodeC, newNode);
    printForward(head);

    Node* newNodeB = new Node(2000);
    insertNode(head, tail, nullptr, newNodeB);
    printForward(head);

    Node* newNodeC = new Node(1000);
    insertNode(head, tail, nodeD, newNodeC);
    printForward(head);

    // Deleting nodes
    std::cout << "Deleting nodes" << std::endl;
    deleteNode(head, tail, newNode);
    deleteNode(head, tail, newNodeB);
    deleteNode(head, tail, nodeB);
    printForward(head);

    delete nodeA, nodeB, nodeC, nodeD, newNode, newNodeB, newNodeC;

    return -1;
}
