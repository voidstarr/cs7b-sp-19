/* File: Concentrations.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in
 * your implementation.
 */
#include <iostream>
#include <vector>
using namespace std;

class Grid {
private:
  vector<vector<int>> backingVector;
  int size;

public:
  Grid(int s) {
    size = s;
    backingVector.resize(size);
    for (int i = 0; i < size; i++) {
      backingVector[i].resize(size);
    }
  }

  Grid(initializer_list<initializer_list<int>> il) {
    size = il.size();
    backingVector.resize(size);
    int i = 0;
    for (auto a : il) {
      if (a.size() != size)
        throw "Bad dimensions of initializer_list for Grid! Not square!";
      backingVector[i++] = vector<int>(a);
    }
  }

  bool inBounds(int r, int c) {
    return r < size && c < size && r >= 0 && c >= 0;
  }

  vector<int> &operator[](int i) { return backingVector[i]; }

  bool operator==(Grid &g) {
    if (size != g.getSize())
      return false;

    for (int i = 0; i < backingVector.size(); i++)
      for (int j = 0; j < backingVector[i].size(); j++)
        if (backingVector[i][j] != g.getBackingVector()[i][j])
          return false;

    return true;
  }

  int getSize() { return size; }

  vector<vector<int>> &getBackingVector() { return backingVector; }

  void print() {
    for (int i = 0; i < backingVector.size(); i++) {
      for (int j = 0; j < backingVector[i].size(); j++) {
        cout << backingVector[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};

void dropUnit(Grid &world, int row, int col) {
  if (!world.inBounds(row, col))
    return;

  if (++world[row][col] == 4) {
    world[row][col] = 0;
    dropUnit(world, row + 1, col);
    dropUnit(world, row - 1, col);
    dropUnit(world, row, col + 1);
    dropUnit(world, row, col - 1);
  }
}

int main() {
  Grid before({{0, 0, 0}, {1, 3, 1}, {0, 2, 0}});
  Grid after({{0, 1, 0}, {2, 0, 2}, {0, 3, 0}});

  dropUnit(before, 1, 1);

  if (after == before) {
    cout << "after == before" << endl;
  }
}

/* * * * * * Tests Below This Point * * * * *
 //  Create a simple source grid.
    Grid before  {
        { 3, 3, 3 },
        { 3, 0, 3 },
        { 3, 3, 3 }
    };
    Grid after  {
        { 3, 3, 3 },
        { 3, 1, 3 },
        { 3, 3, 3 }
    };

    dropUnit(before, 1, 1);
    before == after; // The above call changes 'before.'

// Non-chaining diffues work.
// Create a simple source grid.
    Grid before  {
        { 0, 0, 0 },
        { 1, 3, 1 },
        { 0, 2, 0 }
    };
    Grid after  {
        { 0, 1, 0 },
        { 2, 0, 2 },
        { 0, 3, 0 }
    };

    dropUnit(before, 1, 1);
    before == after; // The above call changes 'before.'
}

Two diffuses chain.
// Create a simple source grid.
    Grid before  {
        { 0, 0, 0, 0 },
        { 0, 3, 3, 0 },
        { 0, 0, 0, 0 }
    };
    Grid after  {
        { 0, 1, 1, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 1, 0 }
    };

    dropUnit(before, 1, 1);
    before == after; // The above call changes 'before.'
}*/

/* TODO: You will need to add your own tests into this suite of test cases.
 * Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't*
 * test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are
 * some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you
 * have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you
 * wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
