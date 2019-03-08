#include <SFML/Graphics.hpp>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

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

vector<string> generatedCombos;

vector<string> wordsOutList;

void drawGrid(vector<vector<string>> vvs) {
  int columns = 3;
  int rows = 3;

  RenderWindow window(VideoMode(800, 800), "Scrabble Chemistry BS");
  RectangleShape grid[columns][rows];

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
    }

    window.clear();
    for (int i = 0; i < columns; i++) {
      float xpos = 5.0f + (200.0f * i);
      for (int j = 0; j < rows; j++) {
        float ypos = 5.0f + (200.0f * j);
        Vector2f cellSize(200.0f, 200.0f);
        // cout << "cellPos x: " << xpos << " y: " << ypos << endl;
        Vector2f cellPos(xpos, ypos);
        grid[i][j].setSize(cellSize);
        grid[i][j].setOutlineColor(Color::Blue);
        grid[i][j].setOutlineThickness(5.0f);
        grid[i][j].setPosition(cellPos);
        window.draw(grid[i][j]);

        Font font;
        Text txt;
        if (!font.loadFromFile("sing_14l.ttf")) {
          cout << "font won't load, you did something wrong" << endl;
        }
        txt.setFont(font);
        txt.setCharacterSize(56);
        // TODO: grab string from resultant vector of sudoku word finder thing
        txt.setString(vvs[i][j]);
        //txt.setString("ayy lmao");
        txt.setFillColor(Color::Red);
        float xshift = 100.0f - txt.getLocalBounds().width / 2;
        float yshift = 100.0f - txt.getLocalBounds().height / 2;

        Vector2f txtPos(xpos + xshift, ypos + yshift);
        txt.setPosition(txtPos);
        window.draw(txt);
      }
    }

    window.display();
  }
}

bool wordIsInList(string s) {
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return (find(wordsInList.begin(), wordsInList.end(), s) != wordsInList.end());
}

void generateCombinations(int offset, int k) {
  if (k == 0) {
    stringstream ss;
    for (int i = 0; i < combination.size(); i++) {
      transform(combination[i].begin(), combination[i].end(),
                combination[i].begin(), ::tolower);
      ss << combination[i];
    }

    generatedCombos.push_back(ss.str());
    return;
  }
  for (int i = offset; i <= symbols.size() - k; ++i) {
    combination.push_back(symbols[i]);
    generateCombinations(i + 1, k - 1);
    combination.pop_back();
  }
}

bool gridComplete(vector<vector<string>> vvs) {
  for (int i = 0; i < 3; i++) {
    stringstream ss;
    for (int j = 0; j < 3; j++) {
      ss << vvs[i][j];
      if (j == 2) {
        if (!wordIsInList(ss.str())) {
          return false;
        }
        ss.str("");
      }
    }
  }
  for (int j = 0; j < 3; j++) {
    stringstream ss;
    for (int i = 0; i < 3; i++) {
      ss << vvs[i][j];
      if (j == 2) {
        if (!wordIsInList(ss.str())) {
          return false;
        }
        ss.str("");
      }
    }
  }
  return true;
}

void generateGrid(vector<vector<string>> &vvs) {
  // TODO: find some 3x3 combination of chem symbols that
  // create words in all directions in a sudoku like fashion

  vector<string> symbolsInScrabbleWords;
  for (int i = 0; i < wordsOutList.size(); i++) {
    symbolsInScrabbleWords.push_back(wordsOutList[i].substr(0, 2));
    symbolsInScrabbleWords.push_back(wordsOutList[i].substr(1, 2));
    symbolsInScrabbleWords.push_back(wordsOutList[i].substr(3, 2));
  }

  sort(symbolsInScrabbleWords.begin(), symbolsInScrabbleWords.end());
  symbolsInScrabbleWords.erase(
      unique(symbolsInScrabbleWords.begin(), symbolsInScrabbleWords.end()),
      symbolsInScrabbleWords.end());

  /*
  {i, j, k}
  {l, m, n}
  {o, p, q}
  */
  for (int i = 0; i < symbolsInScrabbleWords.size(); i++) {
    for (int j = 0; j < symbolsInScrabbleWords.size(); j++) {
      for (int k = 0; k < symbolsInScrabbleWords.size(); k++) {
        for (int l = 0; l < symbolsInScrabbleWords.size(); l++) {
          for (int m = 0; m < symbolsInScrabbleWords.size(); m++) {
            for (int n = 0; n < symbolsInScrabbleWords.size(); n++) {
              for (int o = 0; o < symbolsInScrabbleWords.size(); o++) {
                for (int p = 0; p < symbolsInScrabbleWords.size(); p++) {
                  for (int q = 0; q < symbolsInScrabbleWords.size(); q++) {
                    vvs[0][0] = symbolsInScrabbleWords[i];
                    vvs[0][1] = symbolsInScrabbleWords[j];
                    vvs[0][2] = symbolsInScrabbleWords[k];
                    vvs[1][0] = symbolsInScrabbleWords[l];
                    vvs[1][1] = symbolsInScrabbleWords[m];
                    vvs[1][2] = symbolsInScrabbleWords[n];
                    vvs[2][0] = symbolsInScrabbleWords[o];
                    vvs[2][1] = symbolsInScrabbleWords[p];
                    vvs[2][2] = symbolsInScrabbleWords[q];
                    if (gridComplete(vvs)) {
                      return;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

int main() {
  // read in scrabble words
  ifstream wordsIn("sixLetterWords.txt");
  string tmp;
  while (wordsIn) {
    wordsIn >> tmp;
    wordsInList.push_back(tmp);
  }
  wordsIn.close();

  // generate words from three chemical symbols
  generateCombinations(0, 3);

  // find intersection between generatedCombos vector, and
  // wordsIn vector
  sort(generatedCombos.begin(), generatedCombos.end());
  sort(wordsInList.begin(), wordsInList.end());
  set_intersection(generatedCombos.begin(), generatedCombos.end(),
                   wordsInList.begin(), wordsInList.end(),
                   back_inserter(wordsOutList));

  cout << "intersection size: " << wordsOutList.size() << endl;

  // write the scrabble words that are composed of chemical symbols
  // to a file
  ofstream wordsOut("sixLetterWordsFromSymbols.txt");
  if (wordsOut.is_open()) {
    for (int i = 0; i < wordsOutList.size(); i++) {
      wordsOut << wordsOutList[i] << ((0 == (i + 1) % 3) ? '\n' : ' ');
    }
    wordsOut.close();
  }

  vector<vector<string>> gridSymbols;
  gridSymbols.resize(3);
  for (int i = 0; i < 3; i++) {
    vector<string> vs;
    vs.resize(3);
    gridSymbols[i] = vs;
  }
  generateGrid(gridSymbols);

  drawGrid(gridSymbols);
  return 0;
}
