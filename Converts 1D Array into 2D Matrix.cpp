class Solution {
public:
    // Function to construct a 2D array from a 1D array
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Create an empty 2D vector to store the result
        vector<vector<int>> ans;

        // If the size of the original array is not equal to m * n, return an empty array
        if(original.size() != m * n) 
            return ans;

        // Index to track position in the original 1D array
        int index = 0;

        // Loop through each row
        for(int i = 0; i < m; i++) {
            // Temporary vector to store the current row
            vector<int> temp;

            // Loop through each column to fill the row
            for(int j = 0; j < n; j++) {
                // Add the current element from the original array to the row
                temp.push_back(original[index]);

                // Move to the next element in the original array
                index++;
            }

            // Add the filled row to the 2D result array
            ans.push_back(temp);
        }

        // Return the constructed 2D array
        return ans;
    }
};
