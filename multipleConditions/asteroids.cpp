
#include <iostream>
#include <vector>

using namespace std;

enum Direction {
  Left,
  Right,
};


struct Asteroid {
  Direction dir;
  unsigned int mass;
};

int numHits(vector<struct Asteroid> a) {

  int hits = 0;
  int largest_mass_going_right = 0;

  for (vector<struct Asteroid>::reverse_iterator it = a.rbegin();
       it != a.rend(); it++) {
    if (it->dir == Left) {
      if (it->mass > largest_mass_going_right) {
	// Largest going right got destroyed by this one
	largest_mass_going_right = 0;
	hits++;
      } else {
	// Destroyed by mass coming right
      }

    } else {
      if (it->mass > largest_mass_going_right) {
	largest_mass_going_right = it->mass;
      }
    }

  }
  return hits;
}


struct Asteroid arr1[] = {{Left, 10}};// 1 hit
vector<struct Asteroid> arr1V(arr1, arr1 + sizeof(arr1)/sizeof(struct Asteroid ));
struct Asteroid arr2[] = {{Right, 10}};// 0 hit
vector<struct Asteroid> arr2V(arr2, arr2 + sizeof(arr2)/sizeof(struct Asteroid ));

struct Asteroid arr3[] = {{Right, 10}, {Right, 20}};// 0 hit
vector<struct Asteroid> arr3V(arr3, arr3 + sizeof(arr3)/sizeof(struct Asteroid ));
struct Asteroid arr4[] = {{Right, 10}, {Left, 20}}; // 1 hit
vector<struct Asteroid> arr4V(arr4, arr4 + sizeof(arr4)/sizeof(struct Asteroid ));
struct Asteroid arr5[] = {{Left, 10}, {Right, 20}}; // 0 hit
vector<struct Asteroid> arr5V(arr5, arr5 + sizeof(arr5)/sizeof(struct Asteroid ));
struct Asteroid arr6[] = {{Left, 10}, {Right, 5}};  // 1 hit
vector<struct Asteroid> arr6V(arr6, arr6 + sizeof(arr6)/sizeof(struct Asteroid ));
struct Asteroid arr7[] = {{Left, 10}, {Left, 20}};// 2 hit
vector<struct Asteroid> arr7V(arr7, arr7 + sizeof(arr7)/sizeof(struct Asteroid ));


struct Asteroid arr8[] = {{Right, 10}, {Right, 20}, {Right, 10}};// 0 hit
vector<struct Asteroid> arr8V(arr8, arr8 + sizeof(arr8)/sizeof(struct Asteroid ));

// Possible interesting combinations of 3
/*
 * L R R (two options mass of R bigger or smaller) *
 * L R L (two options mass of R bigger or smaller)
 * L L R (several options mass of R bigger or smaller)
 * R L L Non interesting
 * R R L Non interesting
 * R L R (two options mass of R bigger or smaller)
 *
 * L(M1) R(M2) L(M3) R(M4)  M3 > M4 and M4 > M1 and M1 > M2
 */

struct Asteroid arr9[] = {{Left, 10}, {Right, 20}, {Right, 10}};// 0 hit
vector<struct Asteroid> arr9V(arr9, arr9 + sizeof(arr9)/sizeof(struct Asteroid ));

struct Asteroid arr10[] = {{Left, 10}, {Right, 2}, {Right, 8}};// 1 hit
vector<struct Asteroid> arr10V(arr10, arr10 + sizeof(arr10)/sizeof(struct Asteroid ));

struct Asteroid arr11[] = {{Left, 10}, {Right, 2}, {Left, 8}};// 2 hit
vector<struct Asteroid> arr11V(arr11, arr11 + sizeof(arr11)/sizeof(struct Asteroid ));

struct Asteroid arr12[] = {{Left, 5}, {Right, 2}, {Left, 8}, {Right, 6}};// 2 hit
vector<struct Asteroid> arr12V(arr12, arr12 + sizeof(arr12)/sizeof(struct Asteroid ));

int main() {

  cout << "Testing arr1, expected hits = 1, got = " << numHits(arr1V) << endl;
  cout << "Testing arr2, expected hits = 0, got = " << numHits(arr2V) << endl;
  cout << "Testing arr3, expected hits = 0, got = " << numHits(arr3V) << endl;
  cout << "Testing arr4, expected hits = 1, got = " << numHits(arr4V) << endl;
  cout << "Testing arr5, expected hits = 0, got = " << numHits(arr5V) << endl;
  cout << "Testing arr5, expected hits = 1, got = " << numHits(arr6V) << endl;
  cout << "Testing arr7, expected hits = 2, got = " << numHits(arr7V) << endl;
  cout << "Testing arr8, expected hits = 0, got = " << numHits(arr8V) << endl;
  cout << "Testing arr9, expected hits = 0, got = " << numHits(arr9V) << endl;
  cout << "Testing arr10, expected hits = 1, got = " << numHits(arr10V) << endl;
  cout << "Testing arr11, expected hits = 2, got = " << numHits(arr11V) << endl;
  cout << "Testing arr12, expected hits = 2, got = " << numHits(arr12V) << endl;

}
