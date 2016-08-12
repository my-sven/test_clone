#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


// �ṹ����Ϊmap��key ʱ������ṹ��Ԫ��
typedef struct tagStudent
{
	int num;
	string name;
	
	tagStudent(){}
	
	tagStudent(int i, string str)
	{
		num = i;
		name = str;
	}
	
	bool operator <(const tagStudent& other) const
	{
		if (num < other.num)        //num����������
		{
			return true;
		}
		else if (num == other.num)  //���num��ͬ����name��������
		{
			return name < other.name;
		}
		return false;
	}
}Student;


// map ��key��valueΪ�ṹ��
void test_struct_map()
{
	map<Student, Student> m_ss;
	
	Student stu;
	stu.num = 22;
	stu.name = "bb";
	
	m_ss.insert(pair<Student, Student>(stu, stu));
}

// map ��keyΪ�ṹ��ʱ��find
void test_struct_map_find()
{
	map<Student, Student> m_ss;
	map<Student, Student>::iterator it;
	
	Student s1;
	s1.num = 11;
	s1.name = "aa";
	Student s2(22,"bb");
	
	m_ss.insert(pair<Student,Student>(s1, s1));
	m_ss.insert(pair<Student,Student>(s2, s2));
	
	for(it = m_ss.begin(); it != m_ss.end(); it++)
	{
		cout<<"num: "<<it->first.num<<" name: "<<it->first.name<<endl;
	}
	
	Student s(22,"bb");
	it = m_ss.find(s);
	if(it != m_ss.end())
	{
		cout<<"num: "<<it->first.num<<" name: "<<it->first.name<<endl;
	}
}

void test_multimap()
{
	
}


int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<argc;i++)
	{
		printf("%s\n",argv[i]);
	}	
	
	
	test_struct_map();
	test_struct_map_find();
	
	return 0;
}

