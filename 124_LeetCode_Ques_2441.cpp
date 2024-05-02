// Leet-Code : Q.No => 2441 => Largest Positive Integer That Exists With Its Negative => 2nd May


    //  2 pointer + binary search + array + sortings    


    // 1.******* Using C++ *******  


    // *** approach -1  *****

    int findMaxK(vector<int>& nums) 
    {
        // sort the array
        sort(nums.begin(),nums.end());

        // create 2 pointer 
        int left = 0;
        int right = nums.size() - 1;

        int maxK = INT_MIN; 

        // traverse the array 
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum == 0)
            {
                maxK = max(maxK , nums[right]); 
                left++;
                right--;
            }
            else if(sum < 0)
            {
                left++;
            }
            else if(sum > 0)
            {
                right--;
            }
        } 

        return maxK != numeric_limits<int>::min() ? maxK : -1;  

        /*
        If maxK has been updated from its initial value, return maxK, which represents the maximum element among pairs of elements that sum up to zero in the array.
        If maxK remains equal to the minimum possible integer value (indicating that no such pair was found), return -1 to signify that no such pair exists.
        */
    }



    // *** approach - 2 *** 


    int findMaxK(vector<int>& nums) 
    {
        // sort the array
        sort(nums.begin(),nums.end()); 

        int n = nums.size();  // size of array

        // traverse the array
        for (int i = n-1; i >= 0; i--) 
        {
            // check no > 0 & serach -ve of that no using binary serach stl in the same array
            if (nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i])) 
            {
                // if found return that no.
                return nums[i];
            }
        }
        return -1;  // If no such pair found
    }






    // 2.******* Using Java *******  


    public int findMaxK(int[] nums) 
    {
        // sort the array 
        Arrays.sort(nums);

        // 2 pointer
        int left = 0;
        int right = nums.length - 1;

        // intilaise max value     
        int maxK = Integer.MIN_VALUE;

        // traverse the array 
        while(left < right)
        {
            int sum = nums[left] + nums[right];

            if(sum == 0)
            {
                maxK = Math.max(maxK , nums[right]);
                left++;
                right--;
            }
            else if(sum < 0)
            {
                left++;
            }
            else if(sum > 0)
            {
                right--;
            }
        }

        // if(maxK == Integer.MIN_VALUE)
        // {
        //     return -1;
        // }
        // else 
        // {
        //     return maxK;
        // }

        return maxK != Integer.MIN_VALUE ? maxK : -1; 
    }