// Leet-Code : Q.No => 2958 => Length of Longest SubArray With at Most K Frequency => 31st March 2024 


    //  using sliding window approach    



    // 1.******* Using C++ *******


    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        // Initialize variables
        int ans = 0;
        int left = 0, right = 0;    // Pointers for the sliding window technique

        // Map to store the frequency of elements in the current window
        unordered_map<int,int> mp;

        // Sliding window approach 
        while(right < nums.size())
        {
            // Insert the value at index 'right' into the map and increment its frequency 
            mp[nums[right]]++;

            // If the frequency of the newly inserted element exceeds 'k', shrink the window from the left
            if(mp[nums[right]] > k)
            {
                // Shrink the window from the left until the frequency of nums[right] becomes less than or equal to k
                while(nums[left] != nums[right])
                {
                    // Decrement the frequency of nums[left] and move the left pointer to the right
                    mp[nums[left]]--;
                    left++;
                }

                // After exiting the loop, decrement the frequency of nums[left] one more time 
                // to ensure the frequency becomes less than or equal to k
                mp[nums[left]]--;

                // Move the left pointer to the right to exclude the element at left from the current window
                left++;
            }

            // Update the maximum length of the subarray satisfying the condition
            ans = max(ans, right - left + 1);

            // Move the 'right' pointer to the right
            right++;
        }

        // Return the maximum length
        return ans;
    }



    // 2.******* Using Java *******

    public int maxSubarrayLength(int[] nums, int k) 
    {
        // initialse variables
        int left = 0, right = 0 , ans = 0;

        // map to store freq.
        HashMap<Integer,Integer> mp = new HashMap<>();

        // sliding window 
        while(right < nums.length)
        {
            // insert into map 
            mp.put(nums[right] , mp.getOrDefault(nums[right],0) + 1);

            if(mp.get(nums[right]) > k)
            {
                while(nums[left] != nums[right])
                {
                    mp.put(nums[left], mp.get(nums[left]) - 1);
                    left++;
                }

                mp.put(nums[left], mp.get(nums[left]) - 1);

                left++;
            }

            ans = Math.max(ans , right - left + 1);

            right++;
        }

        return ans;
    }
