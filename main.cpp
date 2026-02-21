#include <iostream>

#include "src/where.hpp"

using namespace std;

void print(string input, char singleCharacter) {
  cout << "Character '" << singleCharacter <<"' is at index " << findIndex(input, singleCharacter) << " in \"" << input << "\"" << endl;
}

void print(string input, string find) {
  cout << "Substring \"" << find <<"\" is at index " << findIndex(input, find) << " in \"" << input << "\"" << endl;
}

void print(string input, char singleCharacter, bool caseSensitive) {
  string caseString = caseSensitive ? "case-sensitive" : "case-insensitive";
  cout << "Character '" << singleCharacter <<"' is at index " << findIndex(input, singleCharacter, caseSensitive) << " in \"" << input << "\" (" << caseString << ")" << endl;
}

void print(string input, string find, bool caseSensitive) {
  string caseString = caseSensitive ? "case-sensitive" : "case-insensitive";
  cout << "Substring \"" << find <<"\" is at index " << findIndex(input, find, caseSensitive) << " in \"" << input << "\" (" << caseString << ")" << endl;
}

void print(string input, char singleCharacter, int start) {
  cout << "Character '" << singleCharacter <<"' is at index " << findIndex(input, singleCharacter, start) << " in \"" << input << "\" when starting at " << start << " index" << endl;
}

void print(string input, string find, int start) {
  cout << "Substring \"" << find <<"\" is at index " << findIndex(input, find, start) << " in \"" << input << "\" when starting at " << start << " index" << endl;
}

int main() {
  string input = "The quick brown fox";
  print(input, 'e');
  print(input, "e");
  print(input, ' ');
  print(input, "quick");
  print(input, "qUick");
  print(input, "quiet");

  print(input, 'E', false);
  print(input, 'E', true);
  print(input, ' ', true);
  print(input, "qUiCk",false);
  print(input, "qUiCk",true);
  print(input, "quiet", false);

  print(input, 'e');
  print(input, 'e', 0);
  print(input, 'e', 1);
  print(input, 'e', 2);
  print(input, 'e', 3);
  print(input, 'e', 500);
}
