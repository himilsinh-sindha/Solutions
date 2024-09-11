class Solution {
public:
    // Function to calculate the minimum number of bit flips to convert 'start' to 'goal'
    int minBitFlips(int start, int goal) {
        
        // XOR operation between start and goal will give a number where all differing bits are set to 1
        int req = start ^ goal; 

        // Counter to count the number of bits that need to be flipped
        int cnt = 0;

        // Loop through the bits of 'req' and count the set bits (1s)
        while (req > 0) {

            // Check if the least significant bit of 'req' is set (i.e., if it is 1)
            if (req & 1) 
                cnt++;  // Increment the count if the bit is set

            // Right shift 'req' by 1 to check the next bit in the next iteration
            req = req >> 1;
        }

        // Return the total count of set bits, which represents the minimum bit flips
        return cnt;
    }
};
