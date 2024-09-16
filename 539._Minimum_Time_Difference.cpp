class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;

        // Convert time points to minutes
        for(auto i: timePoints){
            int h = ((i[0] - '0') * 10 + (i[1] - '0')) * 60;
            int m = (i[3] - '0') * 10 + (i[4] - '0');
            minutes.push_back(h + m);
        }

        // Sort the time points in minutes
        sort(minutes.begin(), minutes.end());

        // Initialize the minimum difference to a large value
        int minDiff = INT_MAX;

        // Find the minimum difference between consecutive time points
        for(int i = 0; i < minutes.size() - 1; i++) {
            minDiff = min(minDiff, abs(minutes[i] - minutes[i + 1]));
        }

        // Handle the circular time difference between the last and first time points
        int circularDiff = 1440 - (minutes.back() - minutes.front()); // 1440 = 24 * 60
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};
