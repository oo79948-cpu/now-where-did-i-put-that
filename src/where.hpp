#include <string>

using namespace std;

void toLowerCase(string &input);

int findIndexImpl(string input, string find, bool caseSensitive = true, int start = 0);

int findIndex(string input, string find, int start);

int findIndex(string input, char find, int start);

int findIndex(string input, string find, bool caseSensitive, int start);

int findIndex(string input, char find, bool caseSensitive, int start);

int findIndex(string input, string find, bool caseSensitive = true);

int findIndex(string input, char find, bool caseSensitive = true);

