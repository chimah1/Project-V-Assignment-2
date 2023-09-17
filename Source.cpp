
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//#define _Debug
#ifdef _DEBUG
#endif
#define Pre_Release

struct STUDENT_DATA
{
    string FirstName;
    string LastName;

#ifdef Pre_Release

    string Email;

#endif

};

int main()
{
    STUDENT_DATA Student;
    vector<STUDENT_DATA> StudentDataVector;
    string Filename;

#ifdef Pre_Release

    Filename = "StudentData_Emails.txt";

#else
    Filename = "StudentData.txt";

#endif

    ifstream StudentFile(Filename);

    if (StudentFile.is_open())
    {
        string line;

        while (getline(StudentFile, line))
        {
            size_t Delimiter = line.find(",");
            size_t SecondDelimiter = line.find(",", Delimiter + 1);
            Student.FirstName = line.substr(0, Delimiter);
            Student.LastName = line.substr(Delimiter + 1, SecondDelimiter - Delimiter - 1);
#ifdef Pre_Release

            Student.Email = line.substr(SecondDelimiter + 1);
#endif

            StudentDataVector.push_back(Student);
        }

        StudentFile.close();
#ifdef _DEBUG
        cout << "This is the Standard code running" << endl;
#ifdef Pre_Release
        cout << "This is the Pre_Release code running" << endl;
#endif

        for (const STUDENT_DATA& student : StudentDataVector) {
            cout << "\n" << endl;
            cout << "FirstName: " << student.FirstName << endl;
            cout << "Last Name: " << student.LastName << endl;
#ifdef Pre_Release
            cout << "Email: " << student.Email << endl;
#endif
            cout << "\n" << endl;
        }

#else
        cout << "This is the Release mode" << endl;
#endif

        return 1;
    }

}