#include <algorithm>
#include <string>

using namespace std;

void toLowerCase(string &input) {
   transform(input.begin(), input.end(), input.begin(), ::tolower);
}

int findIndexImpl(string input, string find, bool caseSensitive = true, int start = 0) {
   if (!caseSensitive) {
      toLowerCase(input);
      toLowerCase(find);
   }

   int foundIndex = -1;
   int findLength = find.length();
   int inputLength = input.length();
   int inputLastIndex = input.length() - 1;
   if ( findLength == 0 ) { return foundIndex; }
   if (start < 0 || start > inputLastIndex) { return foundIndex; }

   for (int i=start; i<inputLength; i++) {
      if (input[i] == find[0]) {
         foundIndex = i;
         for (int j=0; j<findLength; j++) {
            int inputAtIndex = i + j;
            if ( inputAtIndex > inputLastIndex ||  input[inputAtIndex] != find[j]) {
               foundIndex = -1;
               break;
            }
         }
         if (foundIndex >=0 ) { return foundIndex; }
      }
   }

   return foundIndex;
}

int findIndex(string input, string find, int start) {
   return findIndexImpl(input, find, true, start);
}

int findIndex(string input, char find, int start) {
   string findString(1, find);
   return findIndexImpl(input, findString, true, start);
}

int findIndex(string input, string find, bool caseSensitive, int start) {
   return findIndexImpl(input, find, caseSensitive, start);
}

int findIndex(string input, char find, bool caseSensitive, int start) {
   string findString(1, find);
   return findIndexImpl(input, findString, caseSensitive, start);
}

int findIndex(string input, string find, bool caseSensitive = true) {
   return findIndexImpl(input, find, caseSensitive);
}

int findIndex(string input, char find, bool caseSensitive = true) {
   string findString(1, find);
   return findIndexImpl(input, findString, caseSensitive);
}

