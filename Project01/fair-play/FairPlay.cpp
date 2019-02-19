/* File: PlayingFair.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

string aSequence(int);
string bSequence(int);

string complement(string s, int i) {
    if (i == s.length()) return "";
    stringstream ss;
    if (s[i] == 'A')
        ss << 'B' << complement(s,i+1);
    else if (s[i] == 'B')
        ss << 'A' << complement(s,i+1);
    return ss.str();
}

void error(string s) {
    cout << "error: " << s << endl;
}

string aSequence(int n) {
    if (n == 0) return "A";
    stringstream ss;
    string asdf = bSequence(n-1);
    ss << asdf << complement(asdf, 0);
    return ss.str();
}

string bSequence(int n) {
    if (n == 0) return "B";
    stringstream ss;
    string asdf = aSequence(n-1);
    ss << asdf << complement(asdf, 0);
    return ss.str();
}

int main() {
    cout << aSequence(4) << endl;
}

/* * * * * * Check/Expect Tests Below This Point * * * * *

//Sequences of order 3 are correct.
//Some very basic checks.
aSequence(3) == "ABBABAAB"
bSequence(3) == "BAABABBA"

//Trips error on negative inputs.
// the given expression may call error(). Remember that
//you need to guard against invalid inputs.
aSequence(-137)
bSequence(-137)
} */

/* TODO: You will need to add your own tests into this suite of check/expect test cases. Think about the sorts
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
