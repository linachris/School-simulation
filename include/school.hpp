#pragma once
#include <iostream> 
#include "list.hpp"
using namespace std;

/******************** Classes ********************/
class Student;
class Teacher;
class Yard;
class Stairs;
class Floor;
class Corridor;
class Classroom;
class School;

/******************** Student ********************/
class Student {
    const string name;
    const int floor_num;
    const int classroom_num;
    string curr_pos; 
public:
    Student(const string nam, const int fl, const int cl_num);
    ~Student();
    string get_name();
    int get_floor_num();
    int get_classroom_num();
    string get_position();
    void set_position(const string);
    void print();
};

/******************** Teacher *********************/
class Teacher {
    const string name;
    const int floor_num;
    const int classroom_num;
    bool inTheClassroom;
public:
    Teacher(const string nam, const int fl, const int cl_num);
    ~Teacher();
    string get_name();
    int get_floor_num();
    int get_classroom_num();
    bool isInClassroom();
    void set_position(const bool);
    void print();
};

/******************** Yard ********************/
class Yard {
    const unsigned int capacity;
    List* yard_students;
    School* const sch; 
public:
    Yard(const unsigned int Cyard, School* const);
    ~Yard();
    bool enter(Student*);
    Student* exit();
    void print();
    unsigned int get_capacity();
    unsigned int get_current();
    bool isFull();
    List* get_yardstuds();
};

/******************** Stairs ********************/
class Stairs {
    const unsigned int capacity;
    List* stairs_students;
public:
    Stairs(const unsigned int Cstair);
    ~Stairs();
    bool enter(Student*);
    Student* exit();
    void print();
    unsigned int get_capacity();
    unsigned int get_current();
    bool isFull();
    List* get_stairstuds();
};

/******************** Floor ********************/
class Floor {
    const int number;       // 3 floors
    Corridor* corr;         
    Classroom** clsroom;    
    List* floor_students;
    Teacher* teacher;
public:
    Floor(const unsigned int Ccorr, const unsigned int Cclass, const int fl_num);    
    ~Floor();
    void enter(Student*);
    void print();
    void place(Teacher*);
    unsigned int get_current();
    Corridor* get_corr();
    Classroom* get_clsr(int classr_num);
};

/******************** Corridor ********************/
class Corridor {
    const unsigned int capacity;
    Floor* const flr;   
    List* corr_students;
public:
    Corridor(const unsigned int Ccorr, Floor* const);
    ~Corridor();
    bool enter(Student*);
    Student* exit();
    void print();
    unsigned int get_current();
    bool isFull();
    List* get_corrstuds();
    Floor* get_flr();
};

/******************** Classroom ********************/
class Classroom {
    const unsigned int capacity; 
    const int number;   // 6 classrooms
    List* class_students;
    Teacher* teach;
    bool teacherInClass;
public:
    Classroom(const unsigned int Cclass, const int class_num);
    ~Classroom();
    bool enter(Student*);
    void place(Teacher*);
    void print();
    unsigned int get_capacity();
    unsigned int get_current();
    bool teachIsInClass();
    bool isFull();
};

/******************** School ********************/
class School {
    Yard* yrd;
    Stairs* stair;
    Floor** flr;
    List* school_list;    // every student enters school at first 
    Student* to_exit_school();
public:
    School(const unsigned int Cclass, const unsigned int Cyard, const unsigned int Cstair, const unsigned int Ccorr);
    ~School();
    void enter(Student*);   // Enters one student at a time, in school 
    void enter(Student**, unsigned int start_index, unsigned int studs_num);  // Gathers and enters students at the same time
    void place(Teacher*);
    void print();
    List* get_sch_list();
    unsigned int get_curr();
};