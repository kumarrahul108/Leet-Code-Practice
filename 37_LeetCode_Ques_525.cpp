// Leet-Code : Q.No => 525 => Contiguous Array  -> 16th March 2024 


    // prefix SUm + hashing (map)


    // 1.******* Using C++ ******* 

    int findMaxLength(vector<int>& nums) 
    {
        // Number of elements in the input vector
        int n = nums.size();

        // HashMap to store the running sum and its corresponding index
        unordered_map<int, int> mp;

        // Initialize variables to keep track of sum, maximum subarray length with equal 0s and 1s
        int sum = 0;
        int subArrayLength = 0;

        // Iterate through the input vector
        for(int i=0;i<n;i++)
        {
            // Update the running sum
            sum += nums[i] == 0 ? -1 : 1;

             // If the running sum becomes 0, it means subarray from index 0 to 'i' has equal number of 0s and 1s
            if(sum == 0)
            {
                subArrayLength = i + 1;  // Update the maximum subarray length
            }

            // If the running sum is encountered before, calculate the length of subarray with equal 0s and 1s
            else if(mp.find(sum) != mp.end())
            {
                subArrayLength = max(subArrayLength , i - mp[sum]);  // Update the maximum subarray length
            }

            // If running sum is not encountered before, store its index in the map
            else 
            {
                mp[sum] = i;
            }
        } 

        return subArrayLength;  
    }



    // ***** 2. Using Java ******* 

    public int findMaxLength(int[] nums) 
    {
        int n = nums.length;

        int sum = 0;
        int length = 0;

        Map<Integer, Integer> mp = new HashMap<>();

        for(int i=0;i<n;i++)
        {
            sum += nums[i] == 0 ? -1 : 1;

            if(sum == 0)
            {
                length = (i+1);
            }
            else if(mp.containsKey(sum))
            {
                length = Math.max(length , i - mp.get(sum));
            }
            else 
            {
                mp.put(sum,i);
            }
        }

        return length;
    }


