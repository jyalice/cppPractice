#include<iostream>
#include<string>
#include<list>
using namespace std;

class Person
{
public: 
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	  int m_Age;
	  int m_Height;
};

// sorting rules: sorting people according to their ages (from younger to older), and for same ages according to their heights (from taller to shorter). 
bool comparePerson(Person& p1, Person& p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}

void printList(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "name: " << it->m_Name << " age: " << it->m_Age << " height: " << it->m_Height << endl;
	}
}

void test01()
{
	list<Person>L1;
	Person p1("PersonA", 35, 175);
	Person p2("PersonB", 45, 180);
	Person p3("PersonC", 40, 170);
	Person p4("PersonD", 25, 190);
	Person p5("PersonE", 35, 160);
	Person p6("PersonF", 35, 200);
	L1.push_back(p1);
	L1.push_back(p2);
	L1.push_back(p3);
	L1.push_back(p4);
	L1.push_back(p5);
	L1.push_back(p6);
	cout << "before sorting" << endl;
	printList(L1);
	L1.sort(comparePerson);
	cout << "after sorting" << endl;
	printList(L1);
}

int main()
{
	test01();
	system("pause");
	return 0;
}