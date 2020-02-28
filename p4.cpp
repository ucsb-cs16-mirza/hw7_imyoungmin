#include <iostream>
#include <iomanip>

using namespace std;

/**
 * An undergrad student struct.
 */
struct UndergradStudents
{
	int studentID;
	string firstName;
	string lastName;
	string major;
	double GPA[4];
};

/**
 * Show the data in an array of undergrad students.
 * @param records The array of UndergradStudents instances.
 * @param numrecords Number of records to consider (>=0).
 */
void printRecords( UndergradStudents *records, int numrecords )
{
	cout << setprecision(2) << fixed;
	cout << "These are the student records:" << endl;

	for( int i = 0; i < numrecords; i++ )	// Iterating over each student's record.
	{
		double avg = 0;
		for( double gpa : records[i].GPA )	// Calculating average GPA.
			avg += gpa;
		avg /= 4.0;

		cout << "ID# " << records[i].studentID << ", " 		// Showing student's info.
			 << records[i].lastName << ", " 
			 << records[i].firstName << ", " 
			 << "Major: " << records[i].major << ", "
			 << "Average GPA: " << avg << endl;
	}
}

/**
 * Program main function.
 */
int main()
{
	const int SIZE = 3;
	struct UndergradStudents undergrad[SIZE];

	// Initializations.
	undergrad[0] = { 1, "Joe" , "Shmoe", "EE", { 3.8, 3.3, 3.4, 3.9 } };
	undergrad[1] = { 2, "Macy", "Chen", "CS", { 3.9, 3.9, 4.0, 4.0 } };
	undergrad[2] = { 3, "Patrick","Peter","ME", { 3.8, 3.0, 2.4, 1.9 } };

	// Showing the students' info in the right format.
	printRecords( undergrad, SIZE );

	return 0;
}