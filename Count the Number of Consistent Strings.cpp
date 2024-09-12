class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> m; // Create a hash map to store allowed characters.
        int cnt = 0; // Initialize a counter to keep track of inconsistent words.
        
        // Store each character from the 'allowed' string into the hash map with value 1.
        for(auto i : allowed) {
            m[i] = 1; // Mark the character as allowed.
        }
        
        // Loop through each word in the 'words' vector.
        for(int i = 0; i < words.size(); i++) {
            // For each word, loop through its characters.
            for(int j = 0; j < words[i].size(); j++) {
                // If the current character is not in the allowed characters map, mark the word as inconsistent.
                if(m.find(words[i][j]) == m.end()) {
                    cnt++; // Increment the inconsistent word counter.
                    break; // Stop checking the rest of the word since it is already inconsistent.
                }
            }
        }

        // Return the total number of consistent words (total words - inconsistent words).
        return words.size() - cnt;
    }
};
