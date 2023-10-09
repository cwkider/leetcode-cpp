#include <iostream>
#include <vector>
#include <string>

using namespace std;

void qsortforword(vector<string>& words, int start, int end);
void printstringvector(vector<string> words);

/*
* 1 <= s.length <= 104
* 1 <= words.length <= 5000
* 1 <= words[i].length <= 30
* s and words[i] consist of lowercase English letters.
*/
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    int wordlng = words[0].length();
    int totalwordslng = wordlng * words.size();
    if (s.length() < totalwordslng) return ret;

    printstringvector(words);
    qsortforword(words, 0, words.size()-1);
    cout << endl;
    printstringvector(words);
}

void qsortforword(vector<string>& words, int start, int end) {
    if (start >= end) return;

    string min, max;
    min = words[start];
    max = words[end];

    if (min > max) {
        min = words[end];
        max = words[start];
    }

    string pivot = words[(start + end) / 2];
    if (min > pivot) pivot = min;
    if (max < pivot) pivot = max;

    int l = start;
    int r = end;

    while (l <= r) {
        while (words[l] < pivot) ++l;
        while (words[r] > pivot) --r;

        if (l <= r) {
            if (l < r) {
                string temp = words[l];
                words[l] = words[r];
                words[r] = temp;
            }
            ++l;
            --r;
        }
    }

    qsortforword(words, start, r);
    qsortforword(words, l, end);
}


void printstringvector(vector<string> words) {
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i];
        if (i < words.size() - 1) cout << " ";
    }
}

void run00030() {
    string s;
    vector<string> words;

    s = "wordgoodgoodgoodbestword";
    words = { "word", "good", "best", "word" };
    findSubstring(s, words);
}