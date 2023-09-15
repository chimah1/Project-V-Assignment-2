#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
	string FirstName;
	string LastName;

};

int main()
{

	vector<STUDENT_DATA> StudentDataVector;


	ifstream StudentDataFile;
	StudentDataFile.open("StudentData.txt");

	string line;
	
	while (getline(StudentDataFile, line))
	{
		size_t Delimiter = line.find(",");
		if (Delimiter != std::string::npos) 
		{
			STUDENT_DATA Student;
			Student.FirstName = line.substr(0, Delimiter);
			Student.LastName = line.substr(Delimiter + 1);
			StudentDataVector.push_back(Student);
		}
	}
	StudentDataFile.close();
	
	for (const STUDENT_DATA& student : StudentDataVector) {
		cout << "FirstName: " << student.FirstName << 
			" Last Name: " << student.LastName << std::endl;
	}

	return 1;
}