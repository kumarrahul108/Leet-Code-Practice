
// Leet-Code : Q.No => 532 => K-diff Pairs in an Array -> 12th March 2024 


    //  2 pointer + binary serach 


    // 1.******* Using C++ *******


    // A.****** 2-Pointer Approach ****** 
    int findPairs(vector<int>& nums, int k) 
    {
        int i = 0;
        int j = 1;  

        // Sort the input array
        sort(nums.begin(),nums.end());

        // Initialize a set to store pairs of numbers that have a difference of k
        set<pair<int,int>> ans;  

        // Iterate through the sorted array
        while(j < nums.size())
        {
            // Calculate the difference between the current pair of numbers
            int diff = nums[j] - nums[i];

            // If the difference is equal to k, insert the pair into the set
            if(diff == k)
            {
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }

            // If the difference is greater than k, move the left pointer
            else if(diff > k)
            {
                i++;
            }

            // If the difference is less than k, move the right pointer
            else 
            {
                j++;
            }

            // Handle the case where i == j to avoid infinite loop
            if(i == j)
            {
                j++;
            }
        }

        // Return the number of unique pairs in the set
        return ans.size();    
    }



    // B. ****** Binary Search Approach ****** 

    int binarySearch(vector<int> &nums,int start,int x)
    {
        int end = nums.size() - 1;

        while(start <= end)
        {
            int mid = (start + end)/2;

            if(nums[mid] == x)
            {
                return mid;
            }
            else if(x > nums[mid])
            {
                start = mid + 1;
            }
            else 
            {
                end = mid - 1;
            }
        }
        return -1;
    }

    int findPairs(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());  // Sort the input vector
        set<pair<int,int>> ans;   // Initialize a set to store unique pairs

        // Iterate through the sorted vector
        for(int i=0;i<nums.size();i++)
        {
            // Perform binary search to find the target value nums[i] + k
            // Starting the search from index i + 1 to avoid duplicates
            if(binarySearch(nums,i+1,nums[i]+k) != -1)
            {
                // If target value is found, insert the pair into the set
                ans.insert({nums[i],nums[i]+k});
            }
        }

        return ans.size(); // Return the number of unique pairs
    }





    // 2. ******  Using Java *******

    // Function to find pairs in the array with a difference of k
    public int findPairs(int[] nums, int k) 
    {
        int i = 0;
        int j = 1;

        // Sort the input array
        Arrays.sort(nums);

        // Initialize a set to store pairs of numbers that have a difference of k
        Set<Pair<Integer, Integer>> ans = new HashSet<>();

        // Iterate through the sorted array
        while (j < nums.length) 
        {
            // Calculate the difference between the current pair of numbers
            int diff = nums[j] - nums[i];

            // If the difference is equal to k, insert the pair into the set
            if (diff == k) 
            {
                ans.add(new Pair<>(nums[i], nums[j]));
                i++;
                j++;
            }

            // If the difference is greater than k, move the left pointer
            else if (diff > k) 
            {
                i++;
            }

            // If the difference is less than k, move the right pointer
            else 
            {
                j++;
            }

            // Handle the case where i == j to avoid an infinite loop
            if (i == j) 
            {
                j++;
            }
        }

        // Return the number of unique pairs in the set
        return ans.size();
    }


