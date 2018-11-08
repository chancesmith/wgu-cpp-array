#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int ROSTER_SIZE = 5;
const int DAYS_IN_COURSE_SIZE = 3;

#pragma region Student
class Student
{
public:
  ~Student() {}
  Student()
  {
    studentId = "";
    firstName = "";
    lastName = "";
    numOfDaysToComplete = {0, 0, 0}; // ****
  };
  Student(string StudentId, string FirstName, string LastName, int NumberOfDays0, int NumberOfDays1, int NumberOfDays2)
  {
    studentId = StudentId;
    firstName = FirstName;
    lastName = LastName;
    numOfDaysToComplete[] = {NumberOfDays0, NumberOfDays1, NumberOfDays2};

    return;
  };
  void setStudentId(string StudentId) { studentId = StudentId; }
  void setFirstName(string FirstName) { firstName = FirstName; }
  void setLastName(string LastName) { lastName = LastName; }
  void setNumOfDaysToComplete(int numberOfDays[]) { numOfDaysToComplete = numberOfDays; } // ****
  string getStudentId() { return studentId; }
  string getFirstName() { return firstName; }
  string getLastName() { return lastName; }
  int *getNumOfDaysToComplete() { return numOfDaysToComplete; } // ****

private:
  string studentId;
  string firstName;
  string lastName;
  int numOfDaysToComplete;
};
#pragma endregion

#pragma region Roster
class Roster
{

public:
  void add(string studentID, string firstName, string lastName, int daysInCourseArray, string degree)
  {
    Student student;
    student.setStudentId(studentID);
    student.setFirstName(firstName);
    student.setLastName(lastName);
    student.setLastName(lastName);
    student.setNumOfDaysToComplete(daysInCourseArray); // ****

    currentPosition += 1;
    classRosterArray[currentPosition] = student;
  }
  void printAverageDaysInCourse(string studentId)
  {

    bool studentFound = false;
    int studentIndex = 0;

    for (int i = 0; i < currentPosition; i += 1)
    {
      if (classRosterArray[i].getStudentId() == studentId)
      {
        studentFound = true;
        studentIndex = i;
      }
    }

    std::cout << "Showing average days in course:" << endl;
    if (studentFound)
    {
      int sum = 0;
      int daysInCourseArray = classRosterArray[studentIndex].getNumOfDaysToComplete(); // ****

      for (int i = 0; i < DAYS_IN_COURSE_SIZE; i += 1)
      {
        sum += daysInCourseArray; // ****
      }

      int avg = sum / DAYS_IN_COURSE_SIZE;

      cout << "Student " << studentId << ": averages " << avg << " days in course" << endl;
    }
    else
    {
      // expected: the above line should print a message saying such a student with this ID was not found.
      std::cout << "Such a student with this ID was not found. 🤷‍♂️" << endl
                << endl;
    }
  }

private:
  Student classRosterArray[ROSTER_SIZE];
  int currentPosition = 0;
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
        singleStudentData[0],                                                                 // student id
        singleStudentData[1],                                                                 // fname
        singleStudentData[2],                                                                 // lname
        {stoi(singleStudentData[5]), stoi(singleStudentData[6]), stoi(singleStudentData[7])}, // course 1,2,3 // ****
        singleStudentData[8]                                                                  // degree
    );
  } // END loop through studentData[]

  classRoster.printAverageDaysInCourse("A3");

  return 0;
}
