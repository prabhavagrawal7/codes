int numberOfPoints(vector<vector<int>> &nums)
    {
        vector<int> store(101);
        for (int i = 0; i < nums.size(); i++)
        {
            store[nums[i][0] - 1] += 1;
            store[nums[i][1]] -= 1;
        }
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            store[i] += store[i-1]; 
        }
        
        for (int i = 0; i < store.size(); i++)
        {
            if (store[i