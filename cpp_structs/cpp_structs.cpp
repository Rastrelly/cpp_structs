#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::string;

//struct declaration
struct Worker
{
	string name;
	float age;
	int salary;
	string division;
};

//function decalartions
int requestIntInput(string textRequest);
int listLastIndex(vector<Worker> vRecords);
Worker collectRecordData();
bool checkRecordIdRange(int recordId, vector<Worker> vRecords);
void editRecord(int recordId, vector<Worker> &vRecords);
void deleteRecord(int recordId, vector<Worker> &vRecords);
void addRecord(vector<Worker> &vRecords);
void printRecord(Worker toPrint);
void listRecords(vector<Worker> vRecords);

//vector of structs
vector<Worker> records;

int main()
{
	while (true)
	{
		bool wannaExit = false;
		int selection = requestIntInput("SELECT OPERATION: 1 - Add record; 2 - Edit record; 3 - Delete record; 4 - List records; 5 - Print Record; 0 - Exit");
		int userInputInt = 0;

		switch (selection)
		{
		case 1:
		{
			addRecord(records);
			break;
		}
		case 2:
		{
			userInputInt = requestIntInput("Input record ID to edit or -1");
			if (userInputInt != -1)
			{
				editRecord(userInputInt,records);
			}
			else
			{
				cout << "Cancelling operation.\n";
			}
			break;
		}
		case 3:
		{
			userInputInt = requestIntInput("Input record ID to delete or -1\n");
			if (userInputInt != -1)
			{
				deleteRecord(userInputInt, records);
			}
			else
			{
				cout << "Cancelling operation.\n";
			}
			break;
		}
		case 4:
		{
			listRecords(records);
			break;
		}
		case 5:
		{
			userInputInt = requestIntInput("Input record ID to print or -1\n");
			if (userInputInt != -1)
			{
				printRecord(records[userInputInt]);
			}
			else
			{
				cout << "Cancelling operation.\n";
			}
			break;
		}
		case 0:
		default:
		{
			cout << "Exitting...\n";
			wannaExit = true;
		}
		}

		if (wannaExit) break;

	}

	system("pause");
}

//function implementations

int requestIntInput(string textRequest)
{
	cout << textRequest << "\n";
	string userInputStr;
	getline(cin, userInputStr);
	return atoi(userInputStr.c_str());
}

int listLastIndex(vector<Worker> vRecords)
{
	return vRecords.size() - 1;
}

Worker collectRecordData()
{
	cout << "Enter name:" << std::endl;
	string tName="";
	getline(cin, tName);
	cout << "Enter age:\n";
	float tAge;
	string tAgeStr="";
	getline(cin, tAgeStr);
	tAge = atof(tAgeStr.c_str());
	cout << "Enter salary:\n";
	int tSalary;
	string tSalaryStr = "";
	getline(cin, tSalaryStr);
	tSalary = atoi(tSalaryStr.c_str());
	cout << "Enter division:\n";
	string tDivision = "";
	getline(cin, tDivision);

	return { tName, tAge, tSalary, tDivision };
}

bool checkRecordIdRange(int recordId, vector<Worker> vRecords)
{
	return recordId >= 0 && recordId <= listLastIndex(vRecords);
}

void editRecord(int recordId, vector<Worker> &vRecords)
{
	if (checkRecordIdRange(recordId, vRecords))
	{
		vRecords[recordId] = collectRecordData();
	}
	else
	{
		cout << "Error, wrong index provided!\n";
	}
}

void deleteRecord(int recordId, vector<Worker> &vRecords)
{
	if (checkRecordIdRange(recordId, vRecords))
	{
		vRecords.erase(vRecords.begin() + recordId);
	}
	else
	{
		cout << "Error, wrong index provided!\n";
	}
}

void addRecord(vector<Worker> &vRecords)
{
	vRecords.push_back(collectRecordData());
}

void printRecord(Worker toPrint)
{
	cout << "Name: " << toPrint.name
		<< "; Age = " << toPrint.age
		<< "; Division = " << toPrint.division
		<< "; Salary = " << toPrint.salary << "\n";
}

void listRecords(vector<Worker> vRecords)
{
	cout << "Printing record list:\n";
	int l = listLastIndex(vRecords);
	for (int i = 0; i <= l; i++)
	{
		cout << i << ") " << vRecords[i].name << "\n";
	}
}
