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
    numOfDaysToComplete[0] = 0;
    numOfDaysToComplete[1] = 0;
    numOfDaysToComplete[2] = 0;
  }
  Student(int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    numOfDaysToComplete[0] = NumberOfDays0;
    numOfDaysToComplete[1] = NumberOfDays1;
    numOfDaysToComplete[2] = NumberOfDays2;
  }
  void setNumOfDaysToComplete(int numberOfDays1, int numberOfDays2, int numberOfDays3)
  {
    numOfDaysToComplete[0] = numberOfDays1;
    numOfDaysToComplete[1] = numberOfDays2;
    numOfDaysToComplete[2] = numberOfDays3;
  }
  int age = 2;
  int *getNumOfDaysToComplete() { return numOfDaysToComplete; }
};
#pragma endregion

#pragma region Roster
class Roster
{

public:
  ~Roster() {}
  Roster() { currentPosition = -1; }
  void add(int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    Student *student;
    student = new Student();
    student->setNumOfDaysToComplete(NumberOfDays0, NumberOfDays1, NumberOfDays2);
    currentPosition += 1;

    classRosterArray[currentPosition] = student;
  }
  void printAverageDaysInCourse()
  {
    cout << "Showing all student average days in course:" << endl;
    // loop through students
    for (int i = 0; i < currentPosition + 1; i += 1)
    {
      int sum = 0;
      int *daysInCourseArray = classRosterArray[i]->getNumOfDaysToComplete();

      for (int i = 0; i < DAYS_IN_COURSE_SIZE; i += 1)
        sum += daysInCourseArray[i];
      // cout << daysInCourseArray[i] << endl;

      int avg = sum / DAYS_IN_COURSE_SIZE;
      cout << "Student: averages " << avg << " days in course" << endl;
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

  classRoster.add(30, 35, 40);
  classRoster.add(50, 30, 40);
  classRoster.add(20, 40, 33);

  classRoster.printAverageDaysInCourse();

  return 0;
}
