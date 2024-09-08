class Solution {
public:
    // Function to find the missing rolls given the observed rolls, desired mean, and number of missing rolls (n)
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        // Calculate the sum of the observed rolls
        int msum = accumulate(rolls.begin(), rolls.end(), 0);

        // Calculate the total sum required for both observed and missing rolls to achieve the desired mean
        // total sum required = mean * (total number of rolls, including observed and missing)
        // nsum is the sum that the missing rolls need to account for
        int nsum = mean * (n + rolls.size()) - msum;

        // Vector to store the missing rolls
        vector<int> ans;

        // Two situations when the result is invalid (i.e., ans should be empty):
        // 1) When nsum is less than n, meaning even if we fill all missing rolls with 1 (minimum value), we can't reach the target sum
        // 2) When nsum is greater than n * 6, meaning even if we fill all missing rolls with 6 (maximum value), we can't reach the target sum
        if (nsum < n || nsum > n * 6) return ans;
        
        else {
            // Calculate the base value for each missing roll
            int value = nsum / n;

            // Calculate the remainder after distributing the base value
            int rem = nsum % n;

            // Distribute the values to the missing rolls
            for (int i = 0; i < n; i++) {
                // If there's remainder left, add 1 to the base value for this roll
                if (rem > 0) {
                    ans.push_back(value + 1);
                    rem--;  // Decrease the remainder
                } 
                // Otherwise, assign the base value to the roll
                else {
                    ans.push_back(value);
                }
            }
        }

        // Return the missing rolls that complete the array
        return ans;
    }
};
