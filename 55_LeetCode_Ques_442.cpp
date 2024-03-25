// Leet-Code : Q.No => 442 => Find All Duplicates in an Array => 25th March 2024 


    //  mapping + -ve Index method 


    // 1.******* Using C++ *******


    // ***** A. Negative Index Approach ******** 
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> result; // Result vector to store duplicate numbers
        for (int i = 0; i < nums.size(); ++i) 
        {
            int index = abs(nums[i]) - 1; // Get the index corresponding to the number
            if (nums[index] < 0) 
            { // If the number at index is negative, it means it's seen before
                result.push_back(index + 1); // Add the duplicate number to the result
            }
            else 
            {
                nums[index] = -nums[index]; // Mark the number as seen by negating it
            }
        }
        return result; // Return the vector containing duplicate numbers    
    }



    // ******* B. Mapping Concept ******** 

    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;  // vector tpo store the ans 
        map<int,int> freqMap;  // Map to store frequency of elements

        // Count the frequency of each element in the array
        for(int num : nums)
        {
            freqMap[num]++;
        }

        // Iterate through the frequency map to find duplicates
        for(auto pair : freqMap)
        {
            // If frequency is greater than 1, add the element to the result vector
            if(pair.second >  1)
            {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }



    // 2.******* Using Java *******

    public List<Integer> findDuplicates(int[] nums) 
    {
        List<Integer> result = new ArrayList<>(); // Result list to store duplicate numbers
        Map<Integer, Integer> freqMap = new HashMap<>(); // Map to store frequency of elements

        // Count the frequency of each element in the array
        for (int num : nums) 
        {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        // Iterate through the frequency map to find duplicates
        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) 
        {
            // If frequency is greater than 1, add the element to the result list
            if (entry.getValue() > 1) 
            {
                result.add(entry.getKey());
            }
        }

        return result;
    }