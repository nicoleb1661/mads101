
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool patternMatch(const string & s, const string & re) {

  /* Possible combinations:
   * 
   * String | Pattern   | Action                | Case
   *________|___________|_______________________|
   *   V    |    V      | match, s++ re++       | A +
   *   V    |    X      | mismatch, return false| B +
   *   V    |    ?      | match, s++ re++       | C +
   *   V    |    *X     | match, s++            | D
   *   V    |    *V     | match, s++, re +=2    | E +
   *   V    |    *?V    | match, s++, re +=3    | F +
   *   V    |    *?X    | match, s++            | G +
   *   V    |    *?<end>| match, done!          | H +
   *   V    |    *<end> | match, done!          | I +
   */

  unsigned int ndx_s = 0;
  unsigned int ndx_re = 0;

  while ((ndx_s < s.size()) && (ndx_re < re.size())) {

    // Assume * and ? are not in string
    if ((s[ndx_s] == re[ndx_re]) || (re[ndx_re] == '?')) {
      // Case A, C
      ndx_s++;
      ndx_re++;
    } else if (re[ndx_re] == '*') {
      if (ndx_re == re.size() - 1) {
	// Case I
	return true;
      } else if (re[ndx_re+1] == '?') {
	if (ndx_re == re.size() - 2) {
	  // Case H
	  return true;
	} else if (s[ndx_s] == re[ndx_re+2]) {
	  // Case F
	  ndx_s++;
	  ndx_re += 3;
	} else {
	  // Case G
	  ndx_s++;	  
	}
      } else if (s[ndx_s] == re[ndx_re+1]) {
	// Case E
	ndx_s++;
	ndx_re += 2;
      } else {
	// Case D
	ndx_s++;
      }
    } else {
      // Case B
      return false;
    }
  }
  
  // Skip wildcards at the end of re
  while (ndx_re < re.size() && re[ndx_re] == '*') ndx_re++;

  if (ndx_s == s.size() && (ndx_re >= re.size())) {
    return true;
  } else {
    // Failed to match entire string or pattern in re
    return false;
  }

} 








const string test1("abc");

string test0[] = {"a?c", "a*?c", "*", "?c", "?c?", "???",
		  "*bc", "a?c", "abc?", "abc*", "*abc", "?b?", "", "a?",
                  "?*", "?*bc"};
vector<string> test0V(test0, test0 + sizeof(test0)/sizeof(string));

// Problem: match a string to a simple regular expression that supports ?
// and *
// ? matches any single character.
// * matches a sequence of any characters or none.

int main() {

  for (vector<string>::iterator it = test0V.begin();
       it != test0V.end(); it++) {
    cout << "Testing RE=\'" << *it << "\' against string=\'" << test1 << 
      "\'";
    cout << " RESULT = " << (patternMatch(test1, *it) ? "MATCH" : "MISMATCH")
	 << endl;
  }

}
