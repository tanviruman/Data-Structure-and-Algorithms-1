#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList) {
        // Push all values of wordList into a set to make deletion faster.
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Creating a queue to store sequences of words
        queue<vector<string>> q;
        q.push({beginWord});

        // A vector to store the words being currently used on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
       
        // A vector to store the resultant transformation sequences.
        vector<vector<string>> ans;
        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            // When we move to the next level, erase words used in the previous level
            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear(); // Clear the previous level's used words
            }

            string word = vec.back();

            // If the end word is reached, store the sequence.
            if (word == endWord) {
                if (ans.empty() || ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }

            // Transform the current word by changing each character to 'a' to 'z'
            for (int i = 0; i < word.size(); i++) {   
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.count(word) > 0) { 
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};

// Comparator function to sort the answer lexicographically if needed
bool comp(vector<string> a, vector<string> b) {
    string x = "", y = "";
    for (string i : a) x += i;
    for (string i : b) y += i;
    return x < y;
}

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.empty()) {
        cout << -1 << endl;  // No sequence found
    } else {
        // Optionally sort the answer lexicographically
        sort(ans.begin(), ans.end(), comp);
        for (const auto& sequence : ans) {
            for (const auto& word : sequence) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
