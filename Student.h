#pragma once
#include <iostream>
#include <string>
#include "Score.h"
using namespace std;

class Student
{
private:
	string m_Name;
	string m_Id;
	string m_Speciality;
	Score m_Score;
	int m_Rank;
	string m_Comment;
public:
	
	//���Է���
	Student() {}
	Student(string name, string id, string speciality, Score score);
	//get�෽��
	string get_Name();
	string get_Id();
	string get_Speciality();
	double get_Score();
	void display_scores();
	int get_Rank();
	string get_Comment();
	//���������
	friend ostream& operator<< (ostream& out, Student& st);
	friend istream& operator>> (istream& in, Student& st);
	//set�෽��
	void set_Rank(int rank);
	void set_Comment();
	void set_Name(string name);
	void set_Id(string id);
	void set_Sepciality(string speciality);
	void set_Score(double score);
};