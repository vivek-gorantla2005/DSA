#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }
    
    Node* ConvertLL2ARR(vector<int>&arr){
        this->head = new Node(arr[0]);
        Node *temp = head;
        for(int i = 1 ; i < arr.size() ; i++){
            Node *newnode = new Node(arr[i]);
            temp->next = newnode;
            temp = newnode;
        }
        return this->head;
    }

    Node *DeleteHead(){
        if(this->head == nullptr || this->head->next == nullptr ){
            return nullptr;
        }
        Node *temp = head;
        this->head = this->head->next;
        delete temp;
        return head;
    }

    Node *deleteTail(){
        if(this->head == nullptr || this->head->next == nullptr){
            return nullptr;
        }

        Node *temp = head;
        while(temp->next->next!=nullptr){
            temp = temp->next;
        }
        Node *store = temp->next;
        temp->next = nullptr;
        delete store;
        return head;
    }

    Node* deleteEle(int ele) {
    if (head == nullptr) return nullptr;

    // Case 1: If head node is the one to delete
    if (head->data == ele) {
        return DeleteHead();
    }

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && curr->data != ele) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Element not found.\n";
        return head; // Element not found
    }

    prev->next = curr->next;
    delete curr;
    return head;
    }

    Node *deletekthEle(int pos){
        if(head == nullptr){
            return head;
        }
        if(pos==1){
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        int cnt = 0;
        Node *curr = head;
        Node *prev = nullptr;
        while(curr!=nullptr){
            cnt++;
            if(cnt == pos){
                prev->next = prev->next->next;
                delete curr;
                break;
            }
            prev= curr;
            curr = curr->next;
        }

        return head;
    }

    int findEle(int ele){
        Node *temp = head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            if(temp->data == ele){
                return cnt;
            }
            temp = temp->next;
        }
        return -1;
    }

    Node *insertk(int k){
        if(k<0 || k>lengthLL()){
            cout << "Invalid position\n";
            return head;
        }
        Node *newnode = new Node(k);
        if(k==0){
            newnode->next = head;
            head = newnode;
            return head;
        }
        Node *temp = head;
        for(int i = 0 ; i < k-1 ; i++){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }

    int lengthLL(){
        Node *temp = head;
        int cnt = 0;
        while(temp!=nullptr){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void printList(){
        Node *temp = this->head;
        while(temp!=NULL){
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};

int main(){
    vector<int>nums= {1,2,3,4,5};
    LinkedList ll;
    ll.ConvertLL2ARR(nums);
    // ll.DeleteHead();
    // ll.deleteTail();
    // ll.deleteEle(10);
    ll.deletekthEle(2);
    ll.printList();
    return 0;
}