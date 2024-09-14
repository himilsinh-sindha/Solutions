class Solution {
public:
    int maxArea(vector<int> &arr)
{
    vector<int> max(2);
    vector<int> temp1(2);
    vector<int> temp2(2);
    int j;
    max[1] = 1;
    if(arr[0]<arr[1]) {
    max[0] = arr[0];
    }
    else{
        max[0] = arr[1];
    }
    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size()-1; j++)
        {
            temp1[1] = j - i;
            if (arr[i] > arr[j])
            {
                temp1[0] = arr[j]; 
                
            }
            else
            {
                temp1[0] = arr[i];
                
            }

                temp2[1] = j + 1 - i;
            if (arr[i] > arr[j + 1])
            {
                temp2[0] = arr[j+1];
               
            }
            else
            {
                temp2[0] = arr[i];
                
             }

            if (temp1[0] * temp1[1] > temp2[0] * temp2[1])
            {
                if (max[0] * max[1] < temp1[0] * temp1[1])
                {

                    max[0] = temp1[0];
                    max[1] = temp1[1];
                }
                
            }
            else
            {

                if (max[0] * max[1] < temp2[0] * temp2[1])
                {
                    max[0] = temp2[0];
                    max[1] = temp2[1];
                }
                
            }
        }
    }

    return max[0] * max[1];
}
};