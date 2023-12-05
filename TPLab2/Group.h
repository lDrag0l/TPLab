#include <string>
#include "Student.h"

using namespace std;

typedef struct StudentNode {
    Student student;
    StudentNode* next;
} StudentNode;

typedef struct LessonNode {
    string lesson;
    LessonNode* next;
} LessonNode;

class Group {
private:
    int number = -1;
    LessonNode* lessons = NULL;
    StudentNode* students = NULL;

public:
    Group();
    Group(int gNumber, LessonNode* gLesson, StudentNode* gStudent);
    Group(const Group& gCopy);
    ~Group();

    int getNumber();
    string getLessons();
    string getStudents();
    StudentNode* getStudentsNode();

    void setNumber(int gNumber);
    void addLesson(string gLesson);
    void addStudent(Student student);
    float getAvgGrade();
    void removeStudent(int index);

    void printInfo();
    void edit();
    void save();
};
