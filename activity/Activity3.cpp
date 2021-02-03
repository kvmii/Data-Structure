#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Job {
	int id;
	string name;
	int page;
	
	static int count;

public:
	Job(const string& u, int p) : name(u), page(p), id(++count){}

	friend ostream& operator<<(ostream& os, const Job& j) 
	{
		os << "id: " << j.id << "�����: " << j.name << "������ ��: " << j.page << "��";
		return os;
	}
};

int Job::count = 0;

template <size_t n>

class Printer {
	queue<Job> jobs;

public:


	bool addNewJob(const Job job) {
		if (jobs.size() == n) {
			cout << "��⿭�� �� á���ϴ�!" << endl;
			return false;
		}
		else {
			jobs.push(job);
			cout << job << "�� �߰� �Ǿ����ϴ�" << endl;
			return true;
		}

	}

	void printing() {
		while (!jobs.empty()) {
			cout << jobs.front() << "�� �μ����Դϴ�." << endl;
			jobs.pop();
		}
	}

};

int main() {
	Printer<5> printer;

	Job j1("����", 10);
	Job j2("����", 4);
	Job j3("����", 5);
	Job j4("����", 7);
	Job j5("ä��", 8);
	Job j6("�ÿ�", 10);

	printer.addNewJob(j1);
	printer.addNewJob(j2);
	printer.addNewJob(j3);
	printer.addNewJob(j4);
	printer.addNewJob(j5);
	printer.addNewJob(j6);
	printer.printing();

	printer.addNewJob(j6);
	printer.printing();
	system("PAUSE");
}