
// Leet-Code : Q.No => 189 => Rotate Array -> 2nd March 2024 


    // 1. Using C++

    // Approach - 1
    void rotate(vector<int>& nums , int k)  
    {
        // Base Case
        if(k == 0)
        {
            return;
        }

        int n = nums.size();   // size of array nums
        int K = k % n;         // to keep value of K inside size range of nums vector 
        vector<int> temp(n);   // Allocate temp vector with size n

        // Copy the last K elements to temp
        for(int i=0;i<K;i++)
        {
            temp[i] = nums[n-K+i];
        }

        // Shift the remaining elements by K positions to the right 
        for(int i = n-1;i>=K;i--)
        {
            nums[i] = nums[i-K];
        }

        // Copy elements from temp to the beginning of nums
        for(int i=0;i<K;i++)
        {
            nums[i] = temp[i];
        }
    }


    // Approach - 2
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();  // size of array
        vector<int> ans(n);   // create new array to store

        for(int idx=0;idx<n;idx++)
        {
            int newIndex = (idx + k) % n;  // formula to get newIndex after rotation
            ans[newIndex] = nums[idx];  // placing value to new Index obtained
        }

        nums = ans;  // equate nums array to ans array
    }




    // 2. Using Java 


    public void rotate(int[] nums, int k) 
    {
        int n = nums.length;
        int ans[] = new int[n];

        for(int i=0;i<n;i++)
        {
            int newIdx = (i+k)%n;
            ans[newIdx] = nums[i];
        }

        // Copy the elements of ans back to nums
        System.arraycopy(ans, 0, nums, 0, n);    // utility func of Java 

        /*
        // Copying array elements from ans to nums
        for(int i=0;i<n;i++)
        {
           nums[i] = ans[i];
        }
        */
    }


    // Note :
        /*
        In Java, arrays are passed by reference, meaning that when you assign a new array to the parameter nums, 
        it only changes the local reference inside the function and does not affect the original array outside the function.

        The System.arraycopy() method is a utility method in Java used to efficiently copy data from one array to another

        System.arraycopy(ans, 0, nums, 0, n); represents:

        ans: The source array from which elements will be copied.
        0: The starting index in the ans array from where the copying will begin.
        nums: The destination array where the elements will be copied.
        0: The starting index in the nums array where the elements will be copied to.
        n: The number of elements to be copied.
        
        
        */



