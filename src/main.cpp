#include <iostream>
#include <time.h>
#include "ids.hpp"
#include "school.hpp"
using namespace std;

// return a random number between [1,num_of_students]
inline unsigned int random_students_index(int num_of_students) {
    return rand() % num_of_students + 1;
}

// return a random number between [0,num_of_teachers]
inline unsigned int random_teacher_index(int num_of_teachers) {
    return rand() % (num_of_teachers + 1);
}

 // suffling and array of students
inline void shuffle(Student** array, int n) {
	for (int i = 0; i < n; i++) {
		int j = i + rand() / (RAND_MAX / (n - i) + 1);
		Student* t = array[j];
		array[j] = array[i];
		array[i] = t;
	}
}

 // suffling and array of teachers
inline void shuffle(Teacher** array, int n) {
	for (int i = 0; i < n; i++) {
		int j = i + rand() / (RAND_MAX / (n - i) + 1);
		Teacher* t = array[j];
		array[j] = array[i];
		array[i] = t;
	}
}

int main(int argc, char const *argv[]) {
    
    srand(time(NULL));

    if (argc != 5) {
        cerr << "\nError!\nCorrect Usage:" << argv[0]
        << " <Classroom capacity> <Yard capacity> <Stairs capacity> <Corridor capacity> "
        << endl;
        return 1;
    }

    unsigned int Cclass = atoi(argv[1]);
    unsigned int Cyard = atoi(argv[2]);
    unsigned int Cstair = atoi(argv[3]);
    unsigned int Ccorr = atoi(argv[4]);

    // Let's say : Entering School Students:36 and Teachers:18(1 for each classroom).
    // Each classroom will hold 2 students
    // Initialize the array now, and shuffle after
    Student** students = new Student*[36];
    for (unsigned int i = 0; i < 36 ; i++) 
        students[i] = new Student(studentInfo[i].name, studentInfo[i].floor_num, studentInfo[i].clsr_num);

    cout << endl;

    Teacher** teachers = new Teacher*[18];
    for (unsigned int i = 0; i < 18; i++)
        teachers[i] = new Teacher(teacherInfo[i].name, teacherInfo[i].floor_num, teacherInfo[i].clsr_num);

    cout << endl;

    // shuffling the arrays, for students and teachers to enter/place school randomly
    shuffle(students, 36);
    shuffle(teachers, 18);

    // creating a school, for students and teachers to enter
    School* school = new School(Cclass, Cyard, Cstair, Ccorr);

    unsigned int num_of_students = 36; 
    unsigned int num_of_teachers = 18;
    unsigned int stud_index = 0, teach_index = 0;

    while ((num_of_students != 0) && (num_of_teachers != 0)) {
        // random amount of students and teachers enter school/are placed in classrooms
        // and since the arrays are suffled, random students/teachers enter too
        unsigned int rand_studs_enter = random_students_index(num_of_students);
        unsigned int rand_teach_enter = random_teacher_index(num_of_teachers);
        
        // students enter school and try to reach their classroom.
        // if there's in no space somewhere, students wait there till it's freed up
        school->enter(students, stud_index, rand_studs_enter);
        
        // teachers are placed in their classroom - (if !=0)
        for (unsigned int i = teach_index; i < rand_teach_enter; i++)
            school->place(teachers[i]);
        
        num_of_students -= rand_studs_enter;    // update students left to enter
        num_of_teachers -= rand_teach_enter;    // update teachers left to place
        stud_index += rand_studs_enter;         // update the index of the array of students left to enter
        teach_index += rand_teach_enter;        // update the index of the array of teachers left to enter
    }

    cout << "\nPrinting School:...\n";
    school->print();

    delete school;

    for (unsigned int i = 0; i < 18; i++)
        delete teachers[i];
    delete[] teachers;
    
    for (unsigned int i = 0; i < 36; i++)
        delete students[i];
    delete[] students;

    return 0;
}