#include "list.hpp"

// Initializing the list with a dummy node(simplifies the algo's)
List::List() : size(0) {
    dummy_node = new ListNode;
    dummy_node->next_node = NULL;
    last_node = dummy_node;     // empty list == dummy is also the last node
}

// Deleting every list's node
List::~List() {
    ListNode* to_del = dummy_node;
    while (to_del != NULL) {
        ListNode* next_lnode = to_del->next_node;
        destroy_lnode(to_del);
        to_del = next_lnode;
    }
}

ListNode* List::create_lnode(Student* student) {
    ListNode* lnode = new ListNode;
    lnode->stud_info = student;
    return lnode;
}

void List::destroy_lnode(ListNode* list_node) {
    delete list_node;
}

unsigned int List::get_size() const {
    return size;
}

// inserting a student at the end of the list
void List::push_back(Student* student) {
    size++;
    ListNode* to_insert = create_lnode(student); 
    last_node->next_node = to_insert;    // insert after the last node
    last_node = to_insert;      // change the existing last node
    to_insert->next_node = NULL;     // point to the end of the list
} 

// removing a student from the start of the list
void List::pop_front() {
    if (!isEmpty()) {
        ListNode* to_remove = dummy_node->next_node;
        assert(to_remove != NULL);

        dummy_node->next_node = to_remove->next_node;
        destroy_lnode(to_remove);    
        
        // update size of list and last_node
        if (last_node == to_remove)     // then the list is empty
            last_node = dummy_node;
    }
        size--;     
}

bool List::isEmpty() {
    return (size == 0);
}

Student* List::get_studentInfo(ListNode* lnode) {
    return lnode->stud_info;
}

ListNode* List::get_first() const {
    return dummy_node->next_node;
}

ListNode* List::get_last() const {
    return last_node;
}

ListNode* List::get_next(ListNode* lnode) const {
    return lnode->next_node;
}