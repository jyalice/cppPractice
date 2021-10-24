#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>
using namespace std;

// group 10 people into 3 departments randomly

#define DEPTA 0
#define DEPTB 1
#define DEPTC 2

class Worker
{
	public:
		Worker(string name, int salary)
		{
			this->m_Name = name;
			this->m_Salary = salary;
		}
		string m_Name;
		int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "Person";
		name += nameSeed[i];
		int salary = rand() % 1000 + 6000;
		Worker worker(name, salary);
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>&v, multimap<int, Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "departmentA: " << endl;
	multimap<int, Worker>::iterator pos = m.find(DEPTA);
	int count = m.count(DEPTA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary: " << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "departmentB: " << endl;
	pos = m.find(DEPTB);
	count = m.count(DEPTB);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary: " << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
	cout << "departmentC: " << endl;
	pos = m.find(DEPTC);
	count = m.count(DEPTC);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "name: " << pos->second.m_Name << " salary: " << pos->second.m_Salary << endl;
	}
	cout << "-------------------------------" << endl;
}

int main()
{
	srand((unsigned int)time(NULL));
	vector<Worker>vWorker;
	createWorker(vWorker);
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	showWorkerByGroup(mWorker);
	system("pause");
	return 0;
}