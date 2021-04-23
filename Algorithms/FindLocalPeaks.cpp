vector<int> solve(vector<int>& nums) {
    
    
    vector<int> rami;
    if(nums.size() == 1)
    {
        return rami;
    }
    int count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        count++;
        if(nums[i + 1] < nums[i] && nums[i - 1] < nums[i])
        {
            rami.push_back(i);
            count = 0;
        }
        
        
        
    }

    return rami;
}
