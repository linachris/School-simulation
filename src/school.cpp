#include "school.hpp"
#include <cstring>

/******************** Student Functions ********************/

Student::Student(const string nam, const int fl, const int cl_num)
: name(nam), floor_num(fl), classroom_num(cl_num), curr_pos("Out Of School") {
    cout << "A New Student has been created! : \n" 
    << "Name: " << name << ", Floor: " << floor_num << ", Classroom: " << classroom_num << endl; 
}

Student::~Student() {
    cout << "A Student to be destroyed! : \n" 
    << "Name: " << name << ", Floor: " << floor_num << ", Classroom: " << classroom_num
    << ", Currently at: " << curr_pos << endl;     
}

string Student::get_name() {
    return name;
}

int Student::get_floor_num() {
    return floor_num;
}

int Student::get_classroom_num() {
    return classroom_num;
}

string Student::get_position() {
    return curr_pos;
}

void Student::set_position(const string pos) {
    curr_pos = pos;
}

void Student::print() {
    cout << this->get_name() << endl;
}

/******************** Teacher Functions ********************/

Teacher::Teacher(const string nam, const int fl, const int cl_num)
: name(nam), floor_num(fl), classroom_num(cl_num), inTheClassroom(false) {
    cout << "A New Teacher has been created! : \n" 
    << "Name: " << name << ", Floor: " << floor_num << ", Classroom: " << classroom_num << endl; 
}

Teacher::~Teacher() {
    cout << "A Teacher to be destroyed! : \n" 
    << "Name: " << name << ", Floor: " << floor_num << ", Classroom: " << classroom_num << endl;    
}

string Teacher::get_name() {
    return name;
}

int Teacher::get_floor_num() {
    return floor_num;
}

int Teacher::get_classroom_num() {
    return classroom_num;
}

bool Teacher::isInClassroom() {
    return inTheClassroom;
}

void Teacher::set_position(const bool pos) {
    inTheClassroom = pos;
}

void Teacher::print() {
    cout << "The teacher is : " << this->get_name() << endl;
}

/******************** Yard Functions ********************/

Yard::Yard(const unsigned int Cyard, School* const school)
: capacity(Cyard), sch(school) {
    yard_students = new List;
    cout << "A New Yard has been created!\n";
}

Yard::~Yard() {
    delete yard_students;
    cout << "A Yard to be destroyed!\n";
}

bool Yard::enter(Student* stud) {
    if (get_current() < capacity) {
        yard_students->push_back(stud);       
        stud->set_position("In The Yard");       
        cout << stud->get_name() << " enters schoolyard!\n";
        return true;
    }
    else {              // no space in the yard..student waits 
        return false;   // in the building until yard has space
    }
}

Student* Yard::exit() { 
    ListNode* StudtoExitYard = yard_students->get_first();
    cout << StudtoExitYard->stud_info->get_name() << " exits schoolyard!\n";
    return StudtoExitYard->stud_info;
}

//ListNodes hold student's info(name, classroom etc)
void Yard::print() {
    cout << "People in schoolyard are: \n";
    for (ListNode* toPrintStud = yard_students->get_first();
    toPrintStud != NULL; toPrintStud = yard_students->get_next(toPrintStud)) {
        cout << "   "; 
        toPrintStud->stud_info->print();
    }
    cout << endl;
}

unsigned int Yard::get_capacity() {
    return capacity;
}

unsigned int Yard::get_current() {
    return yard_students->get_size();
}

bool Yard::isFull() {
    return (get_current() == get_capacity());
}

List* Yard::get_yardstuds() {
    return yard_students;
}

/******************** Stairs Functions ********************/

Stairs::Stairs(const unsigned int Cstair) 
: capacity(Cstair) {
    stairs_students = new List;
    cout << "New Stairs have been created!\n";
}

Stairs::~Stairs() {
    delete stairs_students;
    cout << "Stairs to be destroyed!\n";
}

bool Stairs::enter(Student* stud) {
    if (get_current() < capacity) {
        stairs_students->push_back(stud);
        stud->set_position("In Stairs");
        cout << stud->get_name() << " enters stairs!\n";
        return true;
    }
    else {
        return false;
    }
}

Student* Stairs::exit() { 
    ListNode* StudtoExitYard = stairs_students->get_first();
    cout << StudtoExitYard->stud_info->get_name() << " exits stairs!\n";
    return StudtoExitYard->stud_info;
}

//ListNodes hold student's info(name, classroom etc)
void Stairs::print() {
    cout << "People in stairs are: \n";
    for (ListNode* toPrintStud = stairs_students->get_first();
    toPrintStud != NULL; toPrintStud = stairs_students->get_next(toPrintStud)) {
        cout << "   "; 
        toPrintStud->stud_info->print();
    }
    cout << endl;
}

unsigned int Stairs::get_capacity() {
    return capacity;
}

unsigned int Stairs::get_current() {
    return stairs_students->get_size();
}

bool Stairs::isFull() {
    return (get_current() == get_capacity());
}

List* Stairs::get_stairstuds() {
    return stairs_students;
}

/******************** Floor Functions ********************/

Floor::Floor(const unsigned int Ccorr, const unsigned int Cclass, const int fl_num)
: number(fl_num) {
    floor_students = new List;
    cout << "Floor: " << number << " has been created!\n";
    corr =  new Corridor(Ccorr, this);

    // Allocating space for each one of the 6 classrooms
    // and giving them a number between [1,6]
    clsroom = new Classroom*[6];
    for (int i = 0; i < 6; i++) 
        clsroom[i] = new Classroom(Cclass, i+1);
}

Floor::~Floor() {
    for (int i = 0; i < 6; i++) 
        delete clsroom[i];
    delete[] clsroom;    
    delete corr;
    delete floor_students;
    cout << "Floor: \"" << number << "\" to be destroyed!\n";
}

void Floor::enter(Student* stud) {
    cout << stud->get_name() << " enters floor!\n";
    stud->set_position("In The Floor");
}

void Floor::print() {
    cout << "Floor number \"" << number << "\" contains: \n";
    corr->print();     
    for (int i = 0; i < 6; i++)
        clsroom[i]->print();
    cout << endl;
}

void Floor::place(Teacher* teacher) {
    clsroom[teacher->get_classroom_num()-1]->place(teacher);
}

unsigned int Floor::get_current() {
    return floor_students->get_size();
}

Corridor* Floor::get_corr() {
    return this->corr;
}

Classroom* Floor::get_clsr(int classr_num) {
    return clsroom[classr_num-1]; 
}

/******************** Corridor Functions ********************/
Corridor::Corridor(const unsigned int Ccorr, Floor* const fl)
: capacity(Ccorr), flr(fl) {
    corr_students = new List;
    cout << "A New Corridor has been created!\n";
}

Corridor::~Corridor() {
    delete corr_students;
    cout << "A Corridor to be destroyed!\n";
}

bool Corridor::enter(Student* stud) {
    if (get_current() < capacity) {
        flr->enter(stud);           // a student enters the floor first before entering the corridor
        corr_students->push_back(stud);      
        stud->set_position("In The Corridor");       
        cout << stud->get_name() << " enters corridor!\n";
        return true;
    }
    else                            // no space in the corridor..return to the stairs
        return false;
} 

Student* Corridor::exit() {
    ListNode* StudtoExitCorr = corr_students->get_first();
    cout << StudtoExitCorr->stud_info->get_name() << " exits corridor!\n";
    return StudtoExitCorr->stud_info;
}

void Corridor::print() {
    cout << "People in corridor are: \n";
    for (ListNode* toPrintStud = corr_students->get_first();
    toPrintStud != NULL; toPrintStud = corr_students->get_next(toPrintStud)){
        cout << "   "; 
        toPrintStud->stud_info->print();
    }
}

unsigned int Corridor::get_current() {
    return corr_students->get_size();
}

bool Corridor::isFull() {
    return (get_current() == capacity);
}

List* Corridor::get_corrstuds() {
    return corr_students;
}

Floor* Corridor::get_flr() {
    return flr;
}

/******************** Classroom Functions ********************/

Classroom::Classroom(const unsigned int Cclass, const int class_num) 
: capacity(Cclass), number(class_num), teacherInClass(false) {
    class_students = new List;
    cout << "Classroom: " << number << " has been created!\n";
}

Classroom::~Classroom() {
    delete class_students;
    cout << "Classroom: " << number << " to be destroyed!\n";
}

bool Classroom::enter(Student* stud) {
    if (teacherInClass)       // teacher already in, student cannot enter
        return false;       
    else if(get_current() < (capacity-1)) {   // capacity -1(teacher)
        class_students->push_back(stud);
        stud->set_position("In Classroom");
        cout << stud->get_name() << " enters classroom!\n";
        return true;
    }
    else
        return false;
}

void Classroom::place(Teacher* teacher) {
    teach = teacher; 
    teach->set_position(true);  // is in the classroom
    teacherInClass = true;
}

unsigned int Classroom::get_capacity() {
    return capacity;
}

unsigned int Classroom::get_current() {
    return class_students->get_size();
}

bool Classroom::teachIsInClass() {
    return teacherInClass;
}

bool Classroom::isFull() {
    return ((get_current() == (get_capacity()-1)) || (teachIsInClass()));
}

void Classroom::print() {
    cout << "People in class \"" << number << "\" are: \n";
    cout << "   "; 
    if (teacherInClass)
        teach->print();
    else 
        cout << "No teacher here\n";
    for (ListNode* toPrintStud = class_students->get_first();
    toPrintStud != NULL; toPrintStud = class_students->get_next(toPrintStud)){
        cout << "   "; 
        toPrintStud->stud_info->print();
    }
}

/******************** School Functions ********************/

School::School(const unsigned int Cclass, const unsigned int Cyard, const unsigned int Cstair, const unsigned int Ccorr) {
    cout << "A New School has been created!\n";
    school_list = new List;
    yrd = new Yard(Cyard, this);
    stair = new Stairs(Cstair);
    
    // Allocating space for each one of the 3 floors
    // and giving them a number between [1,3]
    flr = new Floor*[3];
    for (int i = 0; i < 3; i++) 
        flr[i] = new Floor(Ccorr, Cclass, i+1);
}

School::~School() {
    for (int i = 0; i < 3; i++) 
        delete flr[i];
    delete[] flr;    
    
    delete stair;
    delete yrd;
    delete school_list;
    cout << "A School to be destroyed!\n";
}

void School::enter(Student* stud) {
    cout << stud->get_name() << " enters school!\n";
    school_list->push_back(stud);   // always enter the school bld
    stud->set_position("In The School");
}

// Takes an array of students and given the start index, enters the next studs_num in school
void School::enter(Student** studs, unsigned int start_index, unsigned int studs_num) { 
    
    for (unsigned int i = 0; i < studs_num; i++)
        enter(studs[i+start_index]);    
    cout << endl;

    // Students entering the yard(and exiting the school), as many as possible.
    // The rest students, wait in the School, to enter the yard with the next group of studs.
    // The first studs to enter school,are the first able to leave school and enter yard
    for (unsigned int i = 0, sch_curr = get_curr(); (i < sch_curr) && (i < yrd->get_capacity()); i++) {
        Student* studToEnterYard = to_exit_school();
        bool to_rem_from_school = false;
        if(studToEnterYard->get_position().compare("In The School") == 0)   // remove from school list only if the student was waiting in school.
            to_rem_from_school = true;
        yrd->enter(studToEnterYard);
        if (to_rem_from_school)
            get_sch_list()->pop_front();

    }
    cout << endl;
    
    // Students exiting the yard, and entering the stairs, as many as possible.
    // The rest students, wait in the Yard
    for (unsigned int i = 0, to_exit = yrd->get_current(); i < to_exit; i++) {     
        Student* studToEnterStairs = yrd->exit();
        if(!(stair->enter(studToEnterStairs))) {
            yrd->get_yardstuds()->pop_front();
            cout << "Stairs are full! Again, ";     
            yrd->enter(studToEnterStairs);          // stair:full -> stud enters the yard as the last one
        }
        else
            yrd->get_yardstuds()->pop_front();      // else enters stairs & is removed from yard

    }
    cout << endl;

    // All Students exit the stairs, and enter the floor's corridor they belong to.
    // If the corridor is full -> they return to the stairs and wait there
    for (unsigned int i = 0, to_exit = stair->get_current(); i < to_exit; i++) {     
        Student* studToEnterCorr = stair->exit();
        if(!(flr[studToEnterCorr->get_floor_num()-1]->get_corr()->enter(studToEnterCorr))) {
            stair->get_stairstuds()->pop_front();
            cout << "Corridor " << studToEnterCorr->get_floor_num() << " is full! Again, ";     
            stair->enter(studToEnterCorr); // corr:full -> stud enters the stairs as the last one
        }
        else
            stair->get_stairstuds()->pop_front();   // else enters floor & is removed from stairs
    }
    cout << endl;

    // Students from each corridor[1,3], exit the corridor and enter their classroom, if possible.
    // If the classroom is full -> they return to the corridor and wait there!   
    for (unsigned int i = 0; i < 3; i++) {
        Corridor* currentCorr = flr[i]->get_corr();
        for (unsigned int j = 0, to_exitstuds = currentCorr->get_current(); j < to_exitstuds; j++) {
            Student* studToEnterClassr = currentCorr->exit();
            Classroom* clsrmToEnter = currentCorr->get_flr()->get_clsr(studToEnterClassr->get_classroom_num());
            if(!(clsrmToEnter->enter(studToEnterClassr))) {
                currentCorr->get_corrstuds()->pop_front();
                cout << "Student can't enter the classroom anymore! Again, ";     
                currentCorr->enter(studToEnterClassr);      // cannot enter classroom       
            }
            else
                currentCorr->get_corrstuds()->pop_front();  // else enters classroom & is removed from corridor
        }
    }
    cout << endl;
}

void School::place(Teacher* teacher) {
    flr[teacher->get_floor_num()-1]->place(teacher);
}

Student* School::to_exit_school() {
    ListNode* StudtoExitSchool = school_list->get_first();
    return StudtoExitSchool->stud_info;
}

void School::print() {
    cout << "School life consists of: \n";
    yrd->print();
    stair->print();
    for (int i = 0; i < 3; i++)
        flr[i]->print();
}

List* School::get_sch_list() {
    return school_list;
}

unsigned int School::get_curr() {
    return school_list->get_size();
}