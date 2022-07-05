#include "Department.h"

//�����õ�ν��
class MyCompare {
public:
	bool operator()(Student& s1, Student& s2)
	{
		if (s1.get_Score() != s2.get_Score())
			return s1.get_Score() > s2.get_Score();
		else
			return s1.get_Id() < s2.get_Id();
	}
};
Department::Department(string speciality):m_Speciality(speciality)
{
}
//������
void Department::Sort()
{

	sort(ds.begin(), ds.end(), MyCompare());
	int i = 1;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
		it->set_Rank(i);
		it->set_Comment();
		i++;
	}

}

void Department::output_tofile()
{
	ofstream outfile;
	outfile.open("student.txt", ios::out);
	if (!outfile.is_open())
	{
		cout << "student.txt��ʧ��" << endl;
		return;
	}
	int flag = 0;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
		if (it->get_Id() != "\0")
			flag = 1;
	}
	if (flag) {
		outfile << "רҵ\t" << "\t" << "ѧ��\t" << "����\t" << "�ۺ����۷���\t" << "����\t" << "����" << endl;
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++) {
			if (it->get_Id() != "\0")
				outfile << *it;
		}
		outfile.close();
	}
	
}

void Department::input_fromfile()
{
	ifstream infile;
	infile.open("student.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "student.txt��ʧ��" << endl;
		return;
	}
	int flag = 1;
	while (!infile.eof())
	{
		if (flag) {
			string butter;
			getline(infile, butter);
			flag = 0;
		}
		Student stu;
		infile >> stu;
		if(stu.get_Id() != "\0")
		ds.push_back(stu);
		//cout << stu;
	}
	infile.close();
}

void Department::Add()
{
	string id;
	string name;
	double s1, s2, s3, s4;
	string speciality = m_Speciality;
	cout << "ѧ�ţ�";
	cin >> id;
	while (id.size() != 10)
	{
		cout << "ѧ��ӦΪ10λ,����������";
		cin >> id;
	}
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
		if (it->get_Id() == id ) {
			cout << "ѧ�������������������";
			cin >> id;
			it = ds.begin();
		}
	cout << "������";
	cin >> name;
	cout << "ѧ�ּ���";
	cin >> s1;
	while (s1 < 0 || s1 > 100) {
		cout << "��������ȷ��ѧ�ּ�";
		cin >> s1;
	}
	cout << "�ճ���Ϊ�֣�";
	cin >> s2;
	while (s2 < 0 || s2 > 100) {
		cout << "��������ȷ���ճ���Ϊ��";
		cin >> s2;
	}
	cout << "���Է�չ�֣�";
	cin >> s3;
	while (s3 < 0 || s3 > 2) {
		cout << "��������ȷ�ĸ��Է�չ�֣�����Ϊ2�֣�";
		cin >> s1;
	}
	cout << "�༶�����֣�";
	cin >> s4;
	while (s4 <= 0 || s4 > 100) {
		cout << "��������ȷ�İ༶������";
		cin >> s4;
	}
	Score score(s1, s2, s3, s4);
	Student stu(name, id, speciality, score);
	ds.push_back(stu);
	//cout << "��ǰ��������" << ds.size() << "��ѧ������Ϣ" << endl;
}

void Department::Check()
{
	cout << "*************************" << endl;
	cout << "***    " << "1. ѧ�Ų�ѯ" << "    ***" << endl;
	cout << "***    " << "2. ������ѯ" << "    ***" << endl;
	cout << "***    " << "3. ������ѯ" << "    ***" << endl;
	cout << "***    " << "4. ���۲�ѯ" << "    ***" << endl;
	cout << "***    " << "5. ȫ����ѯ" << "    ***" << endl;
	cout << "*************************" << endl;
	cout << "����������Ҫ�Ĳ�ѯ��ʽ" << endl;
	int flag;
	cin >> flag;
	system("cls");
	switch (flag) {
	case 1:
	{
		string id;
		cout << "����������Ҫ��ѯ��ѧ��" << endl;
		cin >> id;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Id() == id) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 2:
	{
		string name;
		cout << "����������Ҫ��ѯ������" << endl;
		cin >> name;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Name() == name) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 3:
	{
		int rank;
		cout << "����������Ҫ��ѯ������" << endl;
		cin >> rank;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Rank() == rank) {
				cout << *it << endl;
				break;
			}
		break;
	}
	case 4:
	{
		string comment;
		cout << "����������Ҫ��ѯ������" << endl;
		cin >> comment;
		system("cls");
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
			if (it->get_Comment() == comment) {
				cout << *it << endl;
			}
		break;
	}
	case 5:
	{
		for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
				cout << *it << endl;
		break;
	}
	default:
	{
		cout << "�������Ӧ����ѡ�����ϲ�ѯ��ʽ" << endl;
		break;
	}
	}
}

void Department::Delete()
{
	cout << "����������Ҫɾ����ѧ����ѧ��" << endl;
	string id;
	cin >> id;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
	{
		it->set_Id("\0");
	}
}

void Department::Change()
{
	cout << "��������Ҫ�޸ĵ�ѧ����ѧ��" << endl;
	string id;
	cin >> id;
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
	{
		cout << "1";
		if (id == it->get_Id())
		{
			cout << "�������ѧ���޸�֮�����Ϣ" << endl;
			string id;
			string name;
			double s1, s2, s3, s4;
			string speciality = m_Speciality;
			cout << "ѧ�ţ�";
			cin >> id;
			while (id.size() != 10)
			{
				cout << "ѧ��ӦΪ10λ,����������";
				cin >> id;
			}
			for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
				if (it->get_Id() == id) {
					cout << "ѧ�������������������";
					cin >> id;
					it = ds.begin();
				}
			cout << "������";
			cin >> name;
			cout << "ѧ�ּ���";
			cin >> s1;
			while (s1 < 0 || s1 > 100) {
				cout << "��������ȷ��ѧ�ּ�";
				cin >> s1;
			}
			cout << "�ճ���Ϊ�֣�";
			cin >> s2;
			while (s2 < 0 || s2 > 100) {
				cout << "��������ȷ���ճ���Ϊ��";
				cin >> s2;
			}
			cout << "���Է�չ�֣�";
			cin >> s3;
			while (s3 < 0 || s3 > 2) {
				cout << "��������ȷ�ĸ��Է�չ�֣�����Ϊ2�֣�";
				cin >> s1;
			}
			cout << "�༶�����֣�";
			cin >> s4;
			while (s4 <= 0 || s4 > 100) {
				cout << "��������ȷ�İ༶������";
				cin >> s4;
			}
			Score score(s1, s2, s3, s4);
			Student stu(name, id, speciality, score);
			*it = stu;
		}
		cout << "�޸����" << endl;
		return;
	}
	cout << "���޴���" << endl;
}

void Department::Clear()
{
	for (deque<Student>::iterator it = ds.begin(); it != ds.end(); it++)
		it->set_Id("\0");
	cout << "ѧ����Ϣ�����" << endl;
	system("pause");
}


