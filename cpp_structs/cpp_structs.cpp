#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "WorkerManager.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;

//function decalartions
int requestIntInput(string textRequest);

int main()
{	
	WorkerManager wMgr;
	
	while (true)
	{
		bool wannaExit = false;
		int selection = requestIntInput("SELECT OPERATION: 1 - Add record; 2 - Edit record; 3 - Delete record; 4 - List records; 5 - Print Record; 6 - Save; 7 - Load; 0 - Exit");
		int userInputInt = 0;

		switch (selection)
		{
		case 1:
		{
			wMgr.addRecord();
			break;
		}
		case 2:
		{
			userInputInt = requestIntInput("Input record ID to edit or -1");
			if (userInputInt != -1)
			{
				wMgr.editRecord(userInputInt);
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
				wMgr.deleteRecord(userInputInt);
			}
			else
			{
				cout << "Cancelling operation.\n";
			}
			break;
		}
		case 4:
		{
			wMgr.listRecords();
			break;
		}
		case 5:
		{
			userInputInt = requestIntInput("Input record ID to print or -1\n");
			if (userInputInt != -1)
			{
				printRecord(wMgr.getRecord(userInputInt));
			}
			else
			{
				cout << "Cancelling operation.\n";
			}
			break;
		}
		case 6:
		{
			wMgr.saveRecords();
			break;
		}
		case 7:
		{
			wMgr.loadRecords();
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