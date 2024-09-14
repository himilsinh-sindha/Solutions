class Solution {
public:
   int maxArea(vector<int> &arr)
{
    vector<int> maximum(2);
    vector<int> temp1(2);
    vector<int> temp2(2);
    int j;
    int max1;
    int max2;
    int maxValue;
    maximum[1] = 1;
    maximum[0] = min(arr[0], arr[1]);
    maxValue = maximum[0] * maximum[1];

    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            temp1[1] = j - i;
            temp1[0] = min(arr[i], arr[j]);

            temp2[1] = j + 1 - i;
            temp2[0] = min(arr[j + 1], arr[i]);


            max1 = temp1[0] * temp1[1];
            max2 = temp2[0] * temp2[1];

            if (maxValue < max(max1, max2))
            {

                maxValue = max(max1, max2);
            }
        }
    }

    return maxValue;
}
};