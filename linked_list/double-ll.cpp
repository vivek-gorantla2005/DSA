#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class LinkedList {
public:
    Node *head;
    Node *rear;
    LinkedList() {
        head = nullptr;
        Node *rear = nullptr;
    }

    Node* convertArr_ll(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        this->head = new Node(arr[0]);
        Node *temp = head;
        this->rear = head;
        for (int i = 1; i < arr.size(); i++) {
            Node *n = new Node(arr[i]);
            temp->next = n;
            n->prev = temp;
            temp = n;
            rear = rear->next;
        }
        return head; 
    }

    Node *deleteHead(){
        if(this->head == nullptr || this->head->next == nullptr){
            return nullptr;
        }

        Node *temp = head;
        head = temp->next;
        temp->prev = nullptr;
        delete temp;
        return head;
    }

    Node *deleteBack(){
        if(this->head == this->rear || this->rear->prev == nullptr){
            return nullptr;
        }

        Node *temp = this->rear;
        rear = temp->prev;
        rear->next = nullptr;
        delete temp;
        return head;
        
    }

    Node *deleteKele(int k){
        if(head == nullptr){
            return head;
        }
        Node *temp = head;
        while(temp!=nullptr){
            if(temp->data == k){
                break;
            }
            temp = temp->next;
        }

        Node *prevEle = temp->prev;
        Node *nextEle = temp->next;
        if(prevEle == nullptr && nextEle == nullptr){
            return head;
        }
        else if(prevEle == nullptr){
            return this->deleteHead();
        }
        else if(nextEle == nullptr){
            return this->deleteBack();
        }else{
            prevEle->next = temp->next;
            nextEle->prev = prevEle;
            delete temp;
        }
        return head;
    }

    Node *addAtBeg(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            rear = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return head;
    }

    Node *addAtEnd(int data) {
        Node *newNode = new Node(data);
        if (rear == nullptr) {
            head = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        return head;
    }

    Node *addAtKPosition(int data, int k) {
        if (k <= 0) {
            return addAtBeg(data);
        }

        Node *newNode = new Node(data);
        Node *temp = head;
        int count = 0;

        while (temp != nullptr && count < k - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            return addAtEnd(data);
        }

        Node *nextNode = temp->next;
        temp->next = newNode;
        newNode->prev = temp;

        if (nextNode != nullptr) {
            newNode->next = nextNode;
            nextNode->prev = newNode;
        } else {
            rear = newNode;
        }

        return head;
    }

    void traverseFront(){
        Node *temp = this->head;
        while(temp!=nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"\n";
    }

    void traverseBack(){
        Node *temp = this->rear;
        while(temp!=nullptr){
            cout << temp->data << "->";
            temp = temp->prev;
        }
        cout<<"\n";
    }
};

int main(){
    vector<int>arr={1,2,3,4,5};
    LinkedList ll;
    ll.convertArr_ll(arr);
    // ll.deleteHead();
    // ll.deleteBack();
    ll.deleteKele(3);
    // ll.deleteNodeAt_K_position(2);
    ll.addAtBeg(10);
    ll.addAtEnd(20);
    ll.addAtKPosition(12,2);
    ll.traverseFront();
    // ll.traverseBack();
}
