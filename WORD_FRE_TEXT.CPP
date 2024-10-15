// Problem: Word Frequency in Text
// Description
// Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words. 
// Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
// Input
// The TEXT (each word of the TEXT has length <= 20)

// Output
// Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order. 

// Example
// Input
// abc  def abc 
// abc abcd def 

// Output 
// abc 3
// abcd 1
// def 2

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    string s;
    map<string, int> cnt;
    while (cin >> s){
        string word = "";
        for (int i = 0; i < s.length(); i++){
            if (isalpha(s[i])) word += tolower(s[i]);
            else {
                if (word != "") cnt[word]++;
                word = "";
            }
        }
        if (word != "") cnt[word]++;
    }

    for (auto it = cnt.begin(); it != cnt.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}