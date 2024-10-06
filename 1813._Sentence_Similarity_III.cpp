class Solution {
public:
    // Helper function to convert a sentence string into a vector of words
    vector<string> convert(string x) {
        x += " ";  // Append a space to the end of the string to extract the last word
        vector<string> ans;  // Vector to store the words
        string word = "";     // Temporary string to hold the current word

        // Loop through each character in the string
        for(auto i : x) {
            if(i == ' ') {  // If we encounter a space, the word is complete
                ans.push_back(word);  // Add the word to the vector
                word = "";            // Reset the word for the next iteration
            }
            else {
                word += i;  // Add the character to the current word
            }
        }
        return ans;  // Return the vector of words
    }

    // Function to check if two sentences are similar
    bool areSentencesSimilar(string x, string y) {
        // Ensure x is the longer string (if not, swap them)
        if(x.length() < y.length()) swap(x, y);

        // Convert both sentences into vectors of words
        vector<string> vx, vy;
        vx = convert(x);
        vy = convert(y);

        int cnt = 0;  // Counter to count matching words from the start

        // Check how many words match from the beginning
        for(int i = 0; i < vy.size(); i++) {
            if(vx[i] == vy[i]) cnt++;  // If words match, increment the counter
            else break;                // Stop if words don't match
        }

        // Initialize index pointers to the end of both word vectors
        int ind = vx.size() - 1;
        int r = vy.size();

        // Check how many words match from the end
        for(int i = vy.size() - 1; i >= 0; i--) {
            if(vy[i] == vx[ind]) {  // If the words at the end match
                ind--;              // Move the index pointer for vx
                r = i;              // Update the pointer r for vy
            }
            else break;  // Stop if words don't match
        }

        // The sentences are similar if the number of matching words from the start
        // and the end together covers the entire second sentence (vy)
        return r <= cnt;
    }
};
