#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int choice, stdGrade, numOfStud;
    int sum = 0;
    int highest = 0;
    int lowest = 100;
	string fileName, stdName;
	string x;


	
	const int PROCESS = 1;
	const int QUIT = 2;
	fstream myFile;
	cout << "\nCourse Summary App ..." << endl;

	do
	{
		
		cout << "\nChoose one of the following options" << endl
			<< "\t1. Process Grades Summary report." << endl
			<< "\t2. Quit." << endl
			<< "Option: ";
		cin >> choice;

		switch (choice)
		{
		case PROCESS: 

			cout << "\nGrades Summary Report ... " << endl;
			cout << "\nEnter the Name of the File" << endl;
			cin >> fileName;

			
			myFile.open(fileName, ios::in);

			if (myFile)
			{
				
				cout << "\nList of Students ..." << endl << endl
					
					<< setw(20) << left << "Name"
					<< setw(5) << left << "Grade" << endl;
				const int FIELDWIDTH = 35;
				for (int i = 0; i < FIELDWIDTH; i++)
					cout << '-';
				cout << endl;


                myFile.seekg(75);
				while (!myFile.eof())
				{
					myFile.ignore();
					getline(myFile, stdName);
                    numOfStud ++;
					myFile >> stdGrade;
                    sum = sum + stdGrade;
                    if (stdGrade > highest)
                    {
                        highest= stdGrade;
                    }
					if (stdGrade < lowest)
                    {
                        lowest = stdGrade;
                    }
					cout 
						<< setw(20) << left << stdName
						<< setw(5) << left << stdGrade << endl;


				}
                double average = sum/numOfStud;
                    cout << "Highest Grade :" << highest<<endl
                         << "Lowest Grade :" << lowest<<endl
                         <<"Average Grade :" << average<<endl;
				// Close file
				myFile.close();
			}
			else
				cout << " Fatal Error ... Could not open file " << fileName << "." << endl;
			break;
		case QUIT: 
			cout << "\nGood Bye ..." << endl << endl;
			break;
		default: 

			cout << "Error ... Invalid option. Try again" << endl;
		}
	} while (choice != QUIT);

	return 0;
}


	
