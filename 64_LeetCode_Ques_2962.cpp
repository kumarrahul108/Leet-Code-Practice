// Leet-Code : Q.No => 2962 => Count Subarrays Where Max Element Appears at Least K Times => 30th March 2024 


    //  using sliding window approach    


    // 1.******* Using C++ *******


    // **** approacxh - 1 ****

    long long countSubarrays(vector<int>& nums, int k) 
    {
        // Find the maximum element in the array
        long long int max_num = *max_element(nums.begin(),nums.end());
        
        // Initialize variables
        long long int left = 0,right = 0;   // Pointers for the sliding window
        long long ans = 0;      // Variable to store the result
        long long count = 0;    // Counter for the occurrence of the maximum element


        // Sliding window approach
        while(right<nums.size())
        {
            // Increment the count if the current element is the maximum element
            if(nums[right] == max_num)
            {
                count++;
            }
            
            // Shrink the window until the count becomes less than k
            while(count>=k)
            {
                // Decrement the count if the left element of the window is the maximum element
                if(nums[left]==max_num)
                {
                    count--;
                }

                // Move the left pointer to the right
                left++;

                // Update the result by adding the count of subarrays from right to the end of the array
                ans += nums.size()-right;
            }    

            // Move the right pointer to the right
            right++;
        }

        // Return the result
        return ans;      
    }



    // **** approacxh - 2 ****

    long long countSubarrays(vector<int>& nums, int k) 
    {
        // max element ko find
        long long int maxi = *max_element(nums.begin(),nums.end()); 

        // initialise variables 
        long long int count = 0, ans = 0, left = 0, right = 0;

        // sliding window approach
        while(right < nums.size())
        {
            // agar right = maxi hua 
            if(nums[right] == maxi)
            {
                count++;
            }

            // k - count ho gaya 
            while(count >= k)
            {
                // agar left = maxi
                if(nums[left] == maxi)
                {
                    count--;
                }

                left++;   // left ko move 

                ans += nums.size() - right;   // store answer
            }

            right++;    // right ko move 
        } 

        return ans;
    }




    // 2.******* Using Java *******

    public long countSubarrays(int[] nums, int k) 
    {
        // maximum element find karo 
        long maxi = Integer.MIN_VALUE;
        for(int e : nums)
        {
            if(e > maxi)
            {
                maxi = e;
            }
        }

        // initilaise 
        long ans = 0, count = 0;
        int left = 0, right = 0;

        // sliding window approach 
        while(right < nums.length)
        {
            // agar right = maxi
            if(nums[right] == maxi)
            {
                count++;
            } 

            // k- count 
            while(count >= k)
            {
                // agar left = maxi 
                if(nums[left] == maxi)
                {
                    count--;
                }

                left++;

                ans += nums.length - right;
            }

            right++;
        }

        return ans;
    }