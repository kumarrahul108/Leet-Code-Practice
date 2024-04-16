// Leet-Code : Q.No => 239 => Sliding Window Maximum => 16th April 2024 


    //  


    // 1.******* Using C++ *******

    vector<int> maxSlidingWindow(vector<int>& nums, int k)  
    {
        deque<int> d1;
        vector<int> ans;

        // Process the first window
        for (int i = 0; i < k; i++) 
        {
            int element = nums[i];
            while (!d1.empty() && nums[d1.back()] <= element) 
            {
                d1.pop_back();
            }
            d1.push_back(i);
        }

        // Process subsequent windows
        for (int i = k; i < nums.size(); i++) 
        {
            ans.push_back(nums[d1.front()]);

            while (!d1.empty() && i - d1.front() >= k) 
            {
                d1.pop_front();
            }

            while (!d1.empty() && nums[d1.back()] <= nums[i]) 
            {
                d1.pop_back();
            }
            d1.push_back(i);
        }

        // Handle the last window
        if (!d1.empty()) 
        {
            ans.push_back(nums[d1.front()]);
        }

        return ans;
    }    






    // 2.******* Using Java *******