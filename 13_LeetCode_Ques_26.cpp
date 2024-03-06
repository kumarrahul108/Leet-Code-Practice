
// Leet-Code : Q.No => 26 => Remove Duplicates from Sorted Array -> 6th March 2024 


    // 1. Using C++

    int removeDuplicates(vector<int>& nums)     
    {
         int left = 0; // Initialize the index for the current unique element
        int i = 1;    // Initialize the index for iterating through the array

        // Iterate through the array
        while (i < nums.size()) 
        {
            // If the current element is equal to the element at index 'left'
            if (nums[i] == nums[left]) 
            {
                i++; // Move to the next element
            } 
            else 
            {
                left++; // Move to the next position for a new unique element
                swap(nums[left], nums[i]); // Swap the current element with the element at 'left+1'
                i++; // Move to the next element
            }
        }

        // Return the length of the new array with duplicates removed (left+1) 
        return (left + 1);
    }



    // 2. Using Java 

    public int removeDuplicates(int[] nums) 
    {
        int i = 1;
        int left = 0;

        while(i < nums.length)
        {
            if(nums[left] == nums[i])
            {
                i++;
            }
            else  
            {
                nums[++left] = nums[i++];
            }
        }
        return (left+1);
    }