#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest transformation sequence from startWord to targetWord
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Create a queue to store {word, current number of transformations}
        queue<pair<string, int>> q;
        
        // Start BFS traversal by pushing the start word with initial step count as 1
        q.push({startWord, 1});

        // Create a set from the wordList to facilitate quick lookups and deletion
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Remove the startWord from the set as it's already visited
        st.erase(startWord);

        // BFS traversal
        while (!q.empty()) {
            string word = q.front().first;  // Current word
            int steps = q.front().second;   // Number of transformations so far
            q.pop();

            // If we reach the target word, return the number of transformations
            if (word == targetWord) 
                return steps;

            // Try all possible one-letter transformations
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];  // Save the original character

                // Try replacing each character of 'word' with letters 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;  // Replace the character

                    // If the transformed word is in the set, it's a valid word to proceed
                    if (st.find(word) != st.end()) {
                        st.erase(word);  // Mark this word as visited by erasing from the set
                        q.push({word, steps + 1});  // Add the transformed word to the queue with incremented steps
                    }
                }

                word[i] = original;  // Restore the original character after trying all transformations
            }
        }

        // If no transformation sequence is possible, return 0
        return 0;
    }
};

int main() {
    // Sample word list and start/target words
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;

    // Call the function to get the number of transformations
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);

    // Output the result
    cout << ans << endl;

    return 0;
}
