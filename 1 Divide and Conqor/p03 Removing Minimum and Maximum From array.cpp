class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int maxIndex = 0, minIndex = 0;
        int mini = INT_MAX, maxi = INT_MIN ;
		
        for (int i = 0; i < n; i++){

            if(nums[i] < mini){
                mini = nums[i];
                minIndex = i;
            }
            if(nums[i]>maxi){
                maxi=nums[i]; 
                maxIndex=i;
            }
        }
     
        int front = max(maxIndex, minIndex) + 1;
        int back = n - min(minIndex, maxIndex);
        int frontBack = (min(minIndex, maxIndex) + 1) + (n - max(minIndex, maxIndex));
		
       return min(min(front, back), frontBack);
        
    }
};
