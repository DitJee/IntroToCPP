// IntroToCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Student
{
	private:
		std::string m_firstName = "";
		std::string m_lastName = "";
		int m_year;
		int m_SID;
	public:
		Student(){}
		Student(const std::string &firstName,
			const std::string &lastName,
			const int year,
			const int SID)
			:	m_firstName(firstName),
				m_lastName(lastName),
				m_year(year),
				m_SID(SID)
		{}

		void PrintInfo() {
			std::cout << m_firstName << " " << m_lastName << " year is " << m_year << " SID is " << m_SID << "\n";
		}
		

};

class Course
{
	private:
		std::vector<Student> m_students;
		std::string m_name;

	public:
		Course(const std::string &name) 
			: m_name(name)
		{

		}
		void  addStudent(const Student &s)
		{
			m_students.push_back(s);
		}

		std::vector<Student> getStudents() 
		{
			return m_students;
		}

		void printCourse() {
			for (auto &student : m_students)
			{
				student.PrintInfo();
			}
		}

		void addStudentFromFile(const std::string &fileName) {
			std::ifstream fIn(fileName);

			std::string first, last;
			int id, grade;
			while (fIn)
			{
				fIn >> first >> last >> id >> grade;
				addStudent(Student(first, last, id, grade));
			}
		}

};


//int main()
//{
//	//Course c("COMP4300");
//	//
//	//Student student1("Dit","Dejphachon",2020, 61317);
//	//Student student2("Dit1","Dejphachon2",2020, 61317);
//	//
//	//c.addStudent(student1);
//	//c.addStudent(student2);
//	//
//	//c.printCourse();
//
//	Course cFile("classFile");
//	cFile.addStudentFromFile("classFile.txt");
//	cFile.printCourse();
//	
//}

