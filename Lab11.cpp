/*****************************************************************************************
Project Name: Lab 11
Name: Kristopher Lowell
Date Completed: 8/10/2018
Purpose: Fill a vector with integers then remove certain integers using an iterator and
remove_if. Then fill a STL map with 5 students name's and grade and remove a record.
*****************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>

using namespace std;

int calculate_sum(vector <int> *arr);
bool isEven(int number);

int main(int argc, char *argv[])
{
	srand((unsigned)time(0));											// Starting a random number process
	int number;
	vector <int> arr;

	cout << "Original vector:" << endl;									// Filling a vector with 30 integers

	for (int i = 0; i < 30; i++)
	{
		number = rand();
		arr.push_back(number);
		cout << arr[i] << " ";
	}

	cout << endl << endl;
		
	arr.erase(arr.begin() + 2);											// Removing the 3rd element alone
	arr.erase(arr.begin() + 3, arr.begin() + 7);						// Removing the 5th through 8th elements

	cout << "Removed 3rd, 5th, 6th, 7th, and 8th elements:" << endl;
	for (unsigned i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	cout << "Sum = " << calculate_sum(&arr) << endl << endl;			// Calculating the sum of the remaining numbers

	vector<int>::iterator pEnd;											// Removing even numbers, remove_if stores the remaining numbers 
	pEnd = remove_if(arr.begin(), arr.end(), isEven);					// from arr.begin() to pEnd, from pEnd to arr.end() is the original
																		// integers in their original position. remove_if does not alter size or capacity.
	cout << "Removed all even numbers: " << endl;
	for (vector<int>::iterator i = arr.begin(); i != pEnd; i++)			// Since the end of guarenteed odd numbers is unknown, we must use an iterator to
		cout << *i << " ";												// index throug the vector

	cout << endl << endl;

	arr.clear();														// Clearing vector for safe measure

	map <string, int> student;
	string name;

	for (unsigned i = 1; i <= 5; i++)									// Filling a map with user-entry names and grades of students
	{
		cout << "Enter student #" << i << "'s name: ";
		cin >> name;
		cout << "Enter student #" << i << "'s grade: ";
		cin >> number;
		cout << endl;

		student.insert(pair <string, int>(name, number));
	}

	student.erase("Jack");												// Since names are the key value, we can simply erase a record with the name "Jack"

	for (map<string, int>::iterator itr = student.begin(); itr != student.end(); itr++)		// Printing a map requires using an iterator
		cout << itr->first << "\t" << itr->second << endl;

	return 0;
}

int calculate_sum(vector <int> *arr)
{
	int sum = 0;

	for (unsigned i = 0; i < arr->size(); i++)
		sum += arr->at(i);

	return sum;
}

bool isEven(int number)
{
	return ((number % 2) == 0);
}