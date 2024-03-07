// Leet-Code : Q.No => 977 => Square of a Sorted Array -> 7th March 2024 

    // Array ka Sorting 
    

    // 1. Using C++

    vector<int> sortedSquares(vector<int>& nums) 
    {
        // Square each element of the vector
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = nums[i] * nums[i];
        }    

        // Sort the vector in non-decreasing order
        sort(nums.begin(),nums.end());

        // Return the sorted vector
        return nums;
    }



    // 2. Using Java 

    public int[] sortedSquares(int[] nums) 
    {
        // square 
        for (int i=0; i<nums.length; i++) 
        {
            nums[i] = nums[i]*nums[i];            
        }

        // sort 
        Arrays.sort(nums);

        // return sorted array
        return nums;
    }


    // OR 

    public int[] sortedSquares(int[] nums) 
    {
        int n = nums.length;
        int[] result = new int[n];
        
        // Initialize two pointers: one for the negative part of the array (left) and one for the positive part (right)
        int left = 0;
        int right = n - 1;
        
        // Iterate from the end of the result array to the beginning
        for (int i = n - 1; i >= 0; i--) 
        {
            // Square the numbers at both ends of the input array
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            // Compare the squares and add the larger one to the result array
            if (leftSquare > rightSquare) 
            {
                result[i] = leftSquare;
                left++;
            } 
            else 
            {
                result[i] = rightSquare;
                right--;
            }
        }
        
        return result; 
    }

