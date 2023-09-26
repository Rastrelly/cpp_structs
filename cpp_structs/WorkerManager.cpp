#include "WorkerManager.h"

Worker collectRecordData()
{
	cout << "Enter name:" << std::endl;
	string tName = "";
	getline(cin, tName);
	cout << "Enter age:\n";
	float tAge;
	string tAgeStr = "";
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

string workerToStr(Worker dat)
{
	string prep;

	prep += dat.name;
	prep += ';';
	prep += dat.division;
	prep += ';';
	prep += std::to_string(dat.age).c_str();
	prep += ';';
	prep += std::to_string(dat.salary).c_str();
	prep += ';';

	return prep;
}

void printRecord(Worker toPrint)
{
	cout << "Name: " << toPrint.name
		<< "; Age = " << toPrint.age
		<< "; Division = " << toPrint.division
		<< "; Salary = " << toPrint.salary << "\n";
}

int WorkerManager::listLastIndex()
{
	return records.size() - 1;
}

bool WorkerManager::checkRecordIdRange(int recordId)
{
	return recordId >= 0 && recordId <= listLastIndex();
}

void WorkerManager::editRecord(int recordId)
{
	if (checkRecordIdRange(recordId))
	{
		records[recordId] = collectRecordData();
	}
	else
	{
		cout << "Error, wrong index provided!\n";
	}
}

void WorkerManager::deleteRecord(int recordId)
{
	if (checkRecordIdRange(recordId))
	{
		records.erase(records.begin() + recordId);
	}
	else
	{
		cout << "Error, wrong index provided!\n";
	}
}

void WorkerManager::addRecord()
{
	records.push_back(collectRecordData());
}

void WorkerManager::listRecords()
{
	cout << "Printing record list:\n";
	int l = listLastIndex();
	for (int i = 0; i <= l; i++)
	{
		cout << i << ") " << records[i].name << "\n";
	}
}

void WorkerManager::saveRecords()
{
	std::ofstream dataWriter("workerDatabase.txt");
	string cWorker = "";
	for (int i = 0; i < records.size(); i++)
	{
		cWorker = workerToStr(records[i]);
		dataWriter << cWorker;
	}
	dataWriter.close();
}

void WorkerManager::resetAccumulator(string &accumulator, int &Field)
{
	accumulator = "";
	Field += 1;
	if (Field > 3) Field = 0;
}


void WorkerManager::loadRecords()
{

	records.clear();

	std::ifstream dataReader("workerDatabase.txt");
	string cLine = "", fullText = "";

	while (std::getline(dataReader, cLine))
	{
		fullText += cLine;
	}

	dataReader.close();

	int l = fullText.length();

	string accumulator = ""; //accumulates symbols
	int Field = 0; //0 - name, 1 - division, 2 - age, 3 - salary
	Worker cWorker = { "",0.0f,0,"" }; //empty Worker truct

	for (int i = 0; i < l; i++)
	{
		char cSymbol = fullText[i];
		if (cSymbol != ';')	accumulator += cSymbol;
		else
		{
			switch (Field)
			{
			case 0:
			{
				cWorker.name = accumulator;
				resetAccumulator(accumulator, Field);
				break;
			}
			case 1:
			{
				cWorker.division = accumulator;
				resetAccumulator(accumulator, Field);
				break;
			}
			case 2:
			{
				cWorker.age = atof(accumulator.c_str());
				resetAccumulator(accumulator, Field);
				break;
			}
			case 3:
			{
				cWorker.salary = atoi(accumulator.c_str());
				resetAccumulator(accumulator, Field);
				records.push_back(cWorker);
				break;
			}
			}
		}
	}
}