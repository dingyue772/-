#pragma once
#include <iostream>
#include <algorithm>
#include <deque>
#include "Student.h"
#include <fstream>
#include <typeinfo>
#include <string>
using namespace std;
class Department {
private:
	deque<Student> ds;
	string m_Speciality;
public:
	//���캯��
	Department(){}
	Department(string speciality);
	//��������
	void Sort();//�Ե�ǰ����ѧ������sum_score����
	void output_tofile();//��ѧ����Ϣд���ļ�
	void input_fromfile();//������ѧ����Ϣ���ļ�����
	//�������еĹ���ģ��ʵ��
	void Add();//�ṩ���ѧ����Ϣ����
	void Check();//�ṩ��ѯ��ǰרҵϵͳ��ѧ����Ϣ����
	void Delete();//�ṩɾ����ǰרҵ��ĳѧ��ѧ����Ϣ�Ĺ���
	void Change();//�޸�ѧ����Ϣ�Ĺ���
	void Clear();//���������ѧ����Ϣ���
	//��������
	~Department() {
		ds.shrink_to_fit();
	}
};