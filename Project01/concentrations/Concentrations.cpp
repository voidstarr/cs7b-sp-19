/* File: Concentrations.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include <vector>
using namespace std;

typedef vector<vector<int> > Grid;

void dropUnit(Grid& world, int x, int y);

void dropUnit(Grid& world, int row, int col) {

}

int main() {

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

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */
