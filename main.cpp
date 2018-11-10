#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int ROSTER_SIZE = 5;
const int DAYS_IN_COURSE_SIZE = 3;

#pragma region Student
class Student
{
private:
  string studentId;
  string firstName;
  string lastName;
  int numOfDaysToComplete[3];

public:
  ~Student() {}
  Student()
  {
    studentId = "";
    firstName = "";
    lastName = "";
    numOfDaysToComplete[0] = 0;
    numOfDaysToComplete[1] = 0;
    numOfDaysToComplete[2] = 0;
  }
  Student(string StudentId, string FirstName, string LastName, int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    studentId = StudentId;
    firstName = FirstName;
    lastName = LastName;
    numOfDaysToComplete[0] = NumberOfDays0;
    numOfDaysToComplete[1] = NumberOfDays1;
    numOfDaysToComplete[2] = NumberOfDays2;
  }
  void setStudentId(string StudentId) { studentId = StudentId; }
  void setFirstName(string FirstName) { firstName = FirstName; }
  void setLastName(string LastName) { lastName = LastName; }
  void setNumOfDaysToComplete(int numberOfDays1, int numberOfDays2, int numberOfDays3)
  {
    numOfDaysToComplete[0] = numberOfDays1;
    numOfDaysToComplete[1] = numberOfDays2;
    numOfDaysToComplete[2] = numberOfDays3;
  }
  string getStudentId() { return studentId; }
  string getFirstName() { return firstName; }
  string getLastName() { return lastName; }
  int *getNumOfDaysToComplete() { return numOfDaysToComplete; }
};
#pragma endregion

#pragma region Roster
class Roster
{

public:
  ~Roster() {}
  Roster()
  {
    currentPosition = -1;
  }
  void add(string studentID, string firstName, string lastName, int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    Student *student;
    student = new Student();
    if (student != nullptr)
    {
      student->setStudentId(studentID);
      student->setFirstName(firstName);
      student->setLastName(lastName);
      student->setLastName(lastName);
      student->setNumOfDaysToComplete(NumberOfDays0, NumberOfDays1, NumberOfDays2);
    }

    currentPosition += 1;
    classRosterArray[currentPosition] = student;
  }
  void printAverageDaysInCourse(string studentId)
  {

    bool studentFound = false;
    int studentIndex = 0;

    for (int i = 0; i < currentPosition + 1; i += 1)
    {
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
      // expected: the above line should print a message saying such a student with this ID was not found.
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
  const string studentData[] =
      {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY"};

  // Create an instance of the Roster class called classRoster.
  Roster classRoster;
  const int MAX_ATRIBUTES = 9;

  // Add each student to classRoster.
  for (const string &student : studentData)
  {
    string singleStudentData[MAX_ATRIBUTES];
    int i = -1;

    istringstream ss(student);
    while (!ss.eof())
    {
      i += 1;
      string x;
      getline(ss, x, ','); // split string by comma
      singleStudentData[i] = x;
    }

    // TODO: convert degree to enum and pass into pass Roster.add()
    classRoster.add(
        singleStudentData[0],       // student id
        singleStudentData[1],       // fname
        singleStudentData[2],       // lname
        stoi(singleStudentData[5]), // course 1
        stoi(singleStudentData[6]), // course 2
        stoi(singleStudentData[7])  // course 3
    );
  } // END loop through studentData[]

  classRoster.printAverageDaysInCourse("A2");

  return 0;
}
