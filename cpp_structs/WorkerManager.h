#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


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

//manager class
class WorkerManager
{
private:
	//vector of structs
	vector<Worker> records;
	void resetAccumulator(string &accumulator, int &Field);
public:
	int listLastIndex();
	bool checkRecordIdRange(int recordId);
	void editRecord(int recordId);
	void deleteRecord(int recordId);
	void addRecord();
	void listRecords();
	void saveRecords();
	void loadRecords();
	Worker getRecord(int id) { return records[id]; };
	WorkerManager() { records.clear(); };
};

Worker collectRecordData();
string workerToStr(Worker dat);
void printRecord(Worker toPrint);