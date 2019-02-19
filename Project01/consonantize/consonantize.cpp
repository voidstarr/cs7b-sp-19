/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include <string> 
#include <iostream>
#include <ctype.h>
#include <sstream>

using namespace std;

bool isConsonant(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' 
                    || c == 'u' || c == 'y');
}

string consonatizeHelper(string s, int idx) {
    
    if (idx == s.length()) return "";
    if (isalpha(s[idx]) && isConsonant(s[idx])) {
        stringstream ss;
        ss << (char)toupper(s[idx]) << consonatizeHelper(s ,idx+1);
        return ss.str();
    }
    return consonatizeHelper(s, idx+1);
}
string consonantize(string s) {
    return consonatizeHelper(s, 0);
}

int main() {
    cout << consonantize("lowercase") << endl;
    cout << consonantize("uppercase")  << endl; 
    cout << consonantize("2.718281828459045")  << endl;
    cout << consonantize("'Hi, Mom!'")  << endl;
    cout << consonantize("A") << endl;
    cout << consonantize("+") << endl;
    cout << consonantize("Q") << endl;

}

/* * * * * * Test Cases * * * * *

consonantize("lowercase") == "LWRCS"
consonantize("uppercase") == "PPRCS"

//Check if it handles non-letter characters properly.
consonantize("2.718281828459045") == ""
consonantize("'Hi, Mom!'") == "HMM"

//Check that it handles single-character inputs.
consonantize("A") == ""
consonantize("+") == ""
consonantize("Q") == "Q"
} */

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






