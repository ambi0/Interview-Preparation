/*
 * Write a function that given the heads of two intersecting singly-linked lists returns the node where the lists meet.
 *
 * Assume node is of the form:   
 *   struct Node {
 *       int val_;
 *       Node* next_;
 *       Node (int val) {
 *           val_ = val;
 *           next_ = nullptr;
 *       }
 *   };
 *
 * You may assume that an intersection point will always exist 
 *
 * Expected Runtime: O(n)
 * Expected Memory:  O(1)
 */

#include <iostream>

struct Node {
    int val_;
    Node* next_;
    Node(int val = 0){
        val_ = val;
        next_ = nullptr;
    }
};

int len_linkedList(Node*);
Node* find_intersect_point(Node*, Node*);

int main(){
    Node* intersect_node = new Node(117);
    
    Node h1;
    h1.next_ = new Node(10);
    h1.next_->next_ = intersect_node;

    Node h2;
    h2.next_ = new Node(20);
    h2.next_->next_ = new Node(8);
    h2.next_->next_->next_ = new Node(5);
    h2.next_->next_->next_->next_ = new Node(125);
    h2.next_->next_->next_->next_->next_ = intersect_node;
    
    auto n = find_intersect_point(&h1, &h2);
    std::cout << n->val_ << std::endl;
}

int len_linkedList(Node* head){
    int i = 0;
    while(head != nullptr){
        head = head->next_;
        ++i;
    }
    return i;
}

Node* find_intersect_point(Node* list1, Node* list2){
    int length1 = len_linkedList(list1);
    int length2 = len_linkedList(list2);

    if(length1 > length2){
        for(int i = 0; i < length1 - length2; ++i)
            list1 = list1->next_;
    }
    else{
        for(int i = 0; i < length2 - length1; ++i)
            list2 = list2->next_;
    }
    while(list1 != list2){
        list1 = list1->next_;
        list2 = list2->next_;
    }
    return list1;
}