 #include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;


bool wordPattern(string pattern, string s) {

    vector<string> words;
    string temp;

    stringstream ss(s);

    while(ss >> temp) {
        words.push_back(temp);
    }


    if(pattern.length() != words.size())
        return false;


    unordered_map<char,string> charToWord;
    unordered_map<string,char> wordToChar;


    for(int i = 0; i < pattern.length(); i++) {

        char ch = pattern[i];
        string word = words[i];


        if(charToWord.count(ch)) {

            if(charToWord[ch] != word)
                return false;

        }
        else {
            charToWord[ch] = word;
        }



        if(wordToChar.count(word)) {

            if(wordToChar[word] != ch)
                return false;

        }
        else {
            wordToChar[word] = ch;
        }
    }


    return true;
}


int main() {

    string pattern = "abba";
    string s = "dog cat cat dog";


    if(wordPattern(pattern,s))
        cout << "true";
    else
        cout << "false";


    return 0;
}