#pragma once
#include <string>
#include <assert.h>
using namespace std;

class Student;

struct ListNode {
    ListNode* next_node;
    Student* stud_info;   // Each ListNode holds a Student as its data
};

class List {
    ListNode* dummy_node;
    ListNode* last_node;
    unsigned int size;
    ListNode* create_lnode(Student*);
    void destroy_lnode(ListNode*);
public:
    List();
    ~List();
    unsigned int get_size() const;
    void push_back(Student*);    // inserts a student at the end of the list
    void pop_front();                     // removes the (first)student from the list's start
    bool isEmpty(); 
    Student* get_studentInfo(ListNode*);
    ListNode* get_first() const;
    ListNode* get_last() const;
    ListNode* get_next(ListNode*) const;

};










