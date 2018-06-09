/*
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

bool canSit(vector<bool> row, unsigned int num_people){

  bool prev = false; // Previous to first is considered false
  bool next;
  int ii = 0;

  if (num_people == 0) return true;

  // When using a loop where the increment is not constant,
  // always use a while loop, this will avoid bugs that come up
  // from auto-loop writting etc. 
  while (ii < row.size()) {
    // Next to last is considered false
    next = (ii + 1) < row.size() ? row[ii+1] : false;
    /*
     * Table of possible cases:
     * prev  | curr  | next  | Action | next ii    |Case
     * ______|_______|_______|________|____________|____
     * false | false | false | sit    | ii = ii + 2| 'A' *
     * false | false | true  | no-sit | ii = ii + 3| 'B' *
     * false | true  | false | no-sit | ii = ii + 2| 'C'
     * false | true  | true  | no-sit | ii = ii + 3| 'D' *
     * true  | false | false | no-sit | ii = ii + 1| 'E' *
     * true  | false | true  | no-sit | ii = ii + 3| 'F' *
     * true  | true  | false | no-sit | ii = ii + 2| 'G'
     * true  | true  | true  | no-sit | ii = ii + 3| 'H' *
     */
    if ((row[ii] == false) && (next == false)) {
      if (prev == false) {
	// Case 'A'
	if(--num_people == 0) return true;
	ii += 2;
      } else {
	// Case 'E'	
	ii++;
      }
    } else if (next == true) {
      // Cases 'B', 'D', 'F', 'H'
      ii += 3;
    } else {
      // Cases 'C', 'G' 
      ii += 2;
    }
    if (ii >= row.size()) break;
    // Set prev for next iteration if any
    prev = row[ii - 1];
  }

  return false;

}

// Test setup

bool test0[] = {}; // Can sit one
vector<bool> test0V(test0, test0 + sizeof(test0)/sizeof(bool));

bool test1[] = {false}; // Can sit one
vector<bool> test1V(test1, test1 + sizeof(test1)/sizeof(bool));

bool test2[] = {false, false}; // Can sit one
vector<bool> test2V(test2, test2 + sizeof(test2)/sizeof(bool));

bool test3[] = {false, false, false}; // Can sit two
vector<bool> test3V(test3, test3 + sizeof(test3)/sizeof(bool));

bool test4[] = {false, true, false, true}; // Can sit zero
vector<bool> test4V(test4, test4 + sizeof(test4)/sizeof(bool));

bool test5[] = {false, false, true, false, false}; // Can sit two
vector<bool> test5V(test5, test5 + sizeof(test5)/sizeof(bool));


int main() {

  // Run several examples and test cases
  cout << "Running test0V sitting 1 people, expected result FALSE; got "
       << canSit(test0V, 1)
       << endl;


  cout << "Running test1V sitting 1 people, expected result TRUE; got "
       << canSit(test1V, 1)
       << endl;

  cout << "Running test1V sitting 0 people, expected result TRUE; got "
       << canSit(test1V, 0)
       << endl;

  cout << "Running test1V sitting 2 people, expected result FALSE; got "
       << canSit(test1V, 2)
       << endl;

  cout << "Running test1V sitting 20 people, expected result FALSE; got "
       << canSit(test1V, 20)
       << endl;


  // Test2

  cout << "Running test2V sitting 1 people, expected result TRUE; got "
       << canSit(test2V, 1)
       << endl;

  cout << "Running test2V sitting 2 people, expected result FALSE; got "
       << canSit(test2V, 2)
       << endl;


  // Test 3


  cout << "Running test3V sitting 1 people, expected result TRUE; got "
       << canSit(test3V, 1)
       << endl;

  cout << "Running test3V sitting 2 people, expected result TRUE; got "
       << canSit(test3V, 2)
       << endl;

  cout << "Running test3V sitting 3 people, expected result FALSE; got "
       << canSit(test3V, 3)
       << endl;

  // Test 4

  cout << "Running test4V sitting 1 people, expected result FALSE; got "
       << canSit(test4V, 1)
       << endl;

  // Test 5

  cout << "Running test5V sitting 2 people, expected result TRUE; got "
       << canSit(test5V, 2)
       << endl;

}
