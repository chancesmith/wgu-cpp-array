#include <iostream>
#include <string>
using namespace std;

const int ROSTER_SIZE = 5;
const int DAYS_IN_COURSE_SIZE = 3;

#pragma region Student
class Student
{
private:
  string studentId;
  int numOfDaysToComplete[3];

public:
  ~Student() {}
  Student()
  {
    studentId = "";
    numOfDaysToComplete[0] = 0;
    numOfDaysToComplete[1] = 0;
    numOfDaysToComplete[2] = 0;
  }
  Student(string StudentId, int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    studentId = StudentId;
    numOfDaysToComplete[0] = NumberOfDays0;
    numOfDaysToComplete[1] = NumberOfDays1;
    numOfDaysToComplete[2] = NumberOfDays2;
  }
  void setStudentId(string StudentId) { studentId = StudentId; }
  void setNumOfDaysToComplete(int numberOfDays1, int numberOfDays2, int numberOfDays3)
  {
    numOfDaysToComplete[0] = numberOfDays1;
    numOfDaysToComplete[1] = numberOfDays2;
    numOfDaysToComplete[2] = numberOfDays3;
  }
  string getStudentId() { return studentId; }
  int *getNumOfDaysToComplete() { return numOfDaysToComplete; }
};
#pragma endregion

#pragma region Roster
class Roster
{

public:
  ~Roster() {}
  Roster() { currentPosition = -1; }
  void add(string studentID, int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    Student *student;
    student = new Student();
    student->setStudentId(studentID);
    student->setNumOfDaysToComplete(NumberOfDays0, NumberOfDays1, NumberOfDays2);
    currentPosition += 1;
    classRosterArray[currentPosition] = student;
  }
  void printAverageDaysInCourse(string studentId)
  {
    bool studentFound = false;
    int studentIndex = 0;

    // loop through students
    for (int i = 0; i < currentPosition + 1; i += 1)
    {
      std::cout << "student:" << classRosterArray[i]->getStudentId() << " >> " << studentId << '\n';
      if (classRosterArray[i]->getStudentId() == studentId)
      {
        studentFound = true;
        studentIndex = i;
      }
    }

    cout << "Showing average days in course:" << endl;
    if (studentFound)
    {
      int sum = 0;
      int *daysInCourseArray = classRosterArray[studentIndex]->getNumOfDaysToComplete();

      for (int i = 0; i < DAYS_IN_COURSE_SIZE; i += 1)
        sum += daysInCourseArray[i];

      int avg = sum / DAYS_IN_COURSE_SIZE;

      cout << "Student " << studentId << ": averages " << avg << " days in course" << endl;
    }
    else
    {
      cout << "Such a student with this ID was not found. 🤷‍♂️" << endl
           << endl;
    }
  }

private:
  Student *classRosterArray[ROSTER_SIZE];
  int currentPosition;
};
#pragma endregion

int main()
{
  Roster classRoster;

  classRoster.add("A1", 30, 35, 40);
  classRoster.add("A2", 50, 30, 40);
  classRoster.add("A3", 20, 40, 33);

  classRoster.printAverageDaysInCourse("A3");

  return 0;
}
