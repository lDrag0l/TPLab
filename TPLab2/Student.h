#include <string>

using namespace std;

typedef struct GradeNode {
    int grade;
    GradeNode* next;
} GradeNode;

class Student {
private:
    string surname;
    string initials;
    GradeNode* grades = NULL;

public:
    Student();
    Student(string sSurname, string sInitials, GradeNode* sGrades);
    Student(const Student& student);
    ~Student();

    string getSurname() const;
    string getInitials() const;
    string getGrades() const;
    float getAvgGrade();

    void setSurname(const string& sSurname);
    void setInitials(const string& sInitials);
    void addGrade(int grade);
    int popGrade();

    string printInfo();
    void edit();
    void save();

};
