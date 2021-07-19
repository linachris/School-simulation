#include "school.hpp"
#include <string>

struct ArrayPersonData {
    string name;
    int floor_num;
    int clsr_num;
};

// Each Classroom: 2Students - each Floor: 6Classrooms - School: 3Floors
struct ArrayPersonData studentInfo[36] = {
	{ .name = "Amelia",  .floor_num = 1, .clsr_num = 1 },
	{ .name = "Atticus",  .floor_num = 1, .clsr_num = 1 },
	{ .name = "Cora",  .floor_num = 1, .clsr_num = 2 },
	{ .name = "Felix",  .floor_num = 1, .clsr_num = 2 },
	{ .name = "Luna",  .floor_num = 1, .clsr_num = 3 },
	{ .name = "Matthew",  .floor_num = 1, .clsr_num = 3 },
	{ .name = "Arizona",  .floor_num = 1, .clsr_num = 4 },
	{ .name = "Sebastian",  .floor_num = 1, .clsr_num = 4 },
	{ .name = "Maeve",  .floor_num = 1, .clsr_num = 5 },
	{ .name = "Ethan",  .floor_num = 1, .clsr_num = 5 },
	{ .name = "Caroline",  .floor_num = 1, .clsr_num = 6 },
	{ .name = "William",  .floor_num = 1, .clsr_num = 6 },
	{ .name = "Phoebe",  .floor_num = 2, .clsr_num = 1 },
	{ .name = "Elijah",  .floor_num = 2, .clsr_num = 1 },
	{ .name = "Maisie",  .floor_num = 2, .clsr_num = 2 },
	{ .name = "Tobias",  .floor_num = 2, .clsr_num = 2 },
	{ .name = "Rebecca",  .floor_num = 2, .clsr_num = 3 },
	{ .name = "Nathaniel",  .floor_num = 2, .clsr_num = 3 },
	{ .name = "Genevieve",  .floor_num = 2, .clsr_num = 4 },
	{ .name = "Jacob",  .floor_num = 2, .clsr_num = 4 },
	{ .name = "Hazel",  .floor_num = 2, .clsr_num = 5 },
	{ .name = "Isaac",  .floor_num = 2, .clsr_num = 5 },
	{ .name = "Evelyn",  .floor_num = 2, .clsr_num = 6 },
	{ .name = "Owen",  .floor_num = 2, .clsr_num = 6 },
	{ .name = "Maia",  .floor_num = 3, .clsr_num = 1 },
	{ .name = "Wesley",  .floor_num = 3, .clsr_num = 1 },
	{ .name = "Esme",  .floor_num = 3, .clsr_num = 2 },
	{ .name = "Nathan",  .floor_num = 3, .clsr_num = 2 },
	{ .name = "Naomi",  .floor_num = 3, .clsr_num = 3 },
	{ .name = "Harry",  .floor_num = 3, .clsr_num = 3 },
	{ .name = "Kristen",  .floor_num = 3, .clsr_num = 4 },
	{ .name = "Oliver",  .floor_num = 3, .clsr_num = 4 },
	{ .name = "Abigail",  .floor_num = 3, .clsr_num = 5 },
	{ .name = "Callum",  .floor_num = 3, .clsr_num = 5 },
	{ .name = "Jade",  .floor_num = 3, .clsr_num = 6 },
	{ .name = "Miles",  .floor_num = 3, .clsr_num = 6 },
};

struct ArrayPersonData teacherInfo[18] = {
	{ .name = "Daenerys",  .floor_num = 1, .clsr_num = 1 },
	{ .name = "Jaime",  .floor_num = 1, .clsr_num = 2 },
	{ .name = "Cersei",  .floor_num = 1, .clsr_num = 3 },
	{ .name = "Ned",  .floor_num = 1, .clsr_num = 4 },
	{ .name = "Rhaegar",  .floor_num = 1, .clsr_num = 5 },
	{ .name = "Sansa",  .floor_num = 1, .clsr_num = 6 },
	{ .name = "Aerys",  .floor_num = 2, .clsr_num = 1 },
	{ .name = "Tyrion",  .floor_num = 2, .clsr_num = 2 },
	{ .name = "Tywin",  .floor_num = 2, .clsr_num = 3 },
	{ .name = "Arya",  .floor_num = 2, .clsr_num = 4 },
	{ .name = "Bran",  .floor_num = 2, .clsr_num = 5 },
	{ .name = "Sandor",  .floor_num = 2, .clsr_num = 6 },
	{ .name = "Aegon",  .floor_num = 3, .clsr_num = 1 },
	{ .name = "Joffrey",  .floor_num = 3, .clsr_num = 2 },
	{ .name = "Euron",  .floor_num = 3, .clsr_num = 3 },
	{ .name = "Theon",  .floor_num = 3, .clsr_num = 4 },
	{ .name = "Oberyn",  .floor_num = 3, .clsr_num = 5 },
	{ .name = "Jorah",  .floor_num = 3, .clsr_num = 6 },
};
