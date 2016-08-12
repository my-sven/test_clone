#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


// 结构体作为map的key 时需排序结构体元素
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
		if (num < other.num)        //num按升序排序
		{
			return true;
		}
		else if (num == other.num)  //如果num相同，按name升序排序
		{
			return name < other.name;
		}
		return false;
	}
}Student;


// map 的key和value为结构体
void test_struct_map()
{
	map<Student, Student> m_ss;
	
	Student stu;
	stu.num = 22;
	stu.name = "bb";
	
	m_ss.insert(pair<Student, Student>(stu, stu));
}

// map 的key为结构体时的find
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

//this is test 1
//this is test 2

