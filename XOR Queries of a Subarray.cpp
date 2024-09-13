class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        
        // Precompute the XOR for each element from the start up to the current position.
        // arr[i] will now hold the XOR of all elements from arr[0] to arr[i].
        for (int i = 1; i < n; i++) {
            arr[i] ^= arr[i-1]; // Update arr[i] to hold the prefix XOR value.
        }

        // Process each query
        for (auto i : queries) {
            int left = i[0];   // Starting index of the subarray
            int right = i[1];  // Ending index of the subarray

            // If left is 0, the result is just arr[right] because we want XOR from the beginning.
            if (left == 0) {
                ans.push_back(arr[right]); 
            } else {
                // XOR of the subarray from arr[left] to arr[right] is calculated as:
                // prefixXOR[right] ^ prefixXOR[left-1]
                ans.push_back(arr[left-1] ^ arr[right]);
            }
        }

        return ans;  // Return the final list of XOR results for all queries
    }
};
