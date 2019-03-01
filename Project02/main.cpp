#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> symbols(
    {"Ac", "Al", "Am", "Sb", "Ar", "As", "At", "Ba", "Bk", "Be", "Bi", "Bh",
     "B",  "Br", "Cd", "Ca", "Cf", "C",  "Ce", "Cs", "Cl", "Cr", "Co", "Cn",
     "Cu", "Cm", "Ds", "Db", "Dy", "Es", "Er", "Eu", "Fm", "Fl", "F",  "Fr",
     "Gd", "Ga", "Ge", "Au", "Hf", "Hs", "He", "Ho", "H",  "In", "I",  "Ir",
     "Fe", "Kr", "La", "Lr", "Pb", "Li", "Lv", "Lu", "Mg", "Mn", "Mt", "Md",
     "Hg", "Mo", "Mc", "Nd", "Ne", "Np", "Ni", "Nh", "Nb", "N",  "No", "Og",
     "Os", "O",  "Pd", "P",  "Pt", "Pu", "Po", "K",  "Pr", "Pm", "Pa", "Ra",
     "Rn", "Re", "Rh", "Rg", "Rb", "Ru", "Rf", "Sm", "Sc", "Sg", "Se", "Si",
     "Ag", "Na", "Sr", "S",  "Ta", "Tc", "Te", "Ts", "Tb", "Tl", "Th", "Tm",
     "Sn", "Ti", "W",  "U",  "V",  "Xe", "Yb", "Y",  "Zn", "Zr", "Zr"});

vector<string> combination;

vector<string> wordsInList;

vector<string> wordsOutList;

bool wordIsInList(string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return (find(wordsInList.begin(), wordsInList.end(), s) != wordsInList.end());
}

void generateCombinations(int offset, int k) {
  if (k == 0) {
    stringstream ss;
    for (int i = 0; i < combination.size(); i++) {
      ss << combination[i];
    }
    if (wordIsInList(ss.str())) {
      wordsOutList.push_back(ss.str());
      cout << "wordsOutList add: " << ss.str() << endl;
    }
    return;
  }
  for (int i = offset; i <= symbols.size() - k; ++i) {
    combination.push_back(symbols[i]);
    generateCombinations(i + 1, k - 1);
    combination.pop_back();
  }
}

int main() {
  ifstream wordsIn("sixLetterWords.txt");
  string tmp;
  while (wordsIn) {
    wordsIn >> tmp;
    wordsInList.push_back(tmp);
  }
  wordsIn.close();

  generateCombinations(0, 3);

  ofstream wordsOut("sixLetterWordsFromSymbols.txt");
  if (wordsOut.is_open()) {
    for (int i = 0; i < wordsOutList.size(); i++) {
      if (i % 3 == 0)
        wordsOut << "\n";
      wordsOut << wordsOutList[i] << " ";
    }
    wordsOut.close();
  }

  return 0;
}
