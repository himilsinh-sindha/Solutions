class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Initialize the index i for iteration
        int i = 0;

        // Calculate the total amount of chalk needed for one complete round
        // Using accumulate to sum up all elements in the chalk array.
        // 0LL ensures the sum is treated as long long to avoid overflow.
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);

        // Use the remainder of k after dividing by the sum of chalk.
        // This reduces k to the equivalent chalk requirement within one round.
        k = k % sum;

        // Iterate over each student (chalk array)
        for (int i = 0; i < chalk.size(); ++i) {
            // If the current student doesn't have enough chalk left (k < chalk[i]),
            // that student will need to replace the chalk. Return the index.
            if (k < chalk[i]) {
                return i;
            }
            // Subtract the current student's chalk usage from k.
            k -= chalk[i];
        }

        // If no student was found (this point won't be reached due to logic),
        // return the index (although this return statement is not necessary).
        return i;
    }
};
