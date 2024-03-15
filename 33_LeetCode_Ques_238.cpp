// Leet-Code : Q.No => 238 => Product of Array Except Self =>  -> 15th March 2024 


    //   Using prefix Sum Approah 


    // 1.******* Using C++ *******

    // *** Brute Force *** 
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++) 
        {
            int p = 1; // Initialize product for each element
            for(int j = 0; j < n; j++) 
            {
                if(i != j)   // Exclude the current element
                { 
                    p *= nums[j]; // Multiply the current product by the element at nums[j]
                }
            }
            ans.push_back(p); // Push the product of all elements except the current one
        }
        return ans;    
    }


    //  *** prefix sum approach  **** 
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();

        // Initialize vectors to store left and right product lists
        vector<int>left(n,1);
        vector<int>right(n,1);   // Initialize with 1 with n size


        // Calculate the product of elements to the left of each element
        // left[0] = 1;
        for(int i=1; i<n; i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }

        // Calculate the product of elements to the right of each element
        // right[n-1] = 1;
        for(int i=n-2; i>=0; i--)
        {
           right[i] = right[i+1]*nums[i+1];
        }

        // Calculate the final result by multiplying left and right products
        vector<int>result(n);
        for(int i=0; i<n; i++)
        {
           result[i] = left[i]*right[i];
        }
       
        return result;    
    }



    // *** 2. Using Java ***** 

    public int[] productExceptSelf(int[] nums) 
    {
        int n = nums.length;

        int left[] = new int[n];
        int right[] = new int[n];

        left[0] = 1;
        for(int i=1;i<n;i++)
        {
            left[i] = left[i-1] * nums[i-1];
        } 

        right[n-1] = 1;
        for(int i=n-2;i>=0;i--)
        {
            right[i] = right[i+1] * nums[i+1];
        }   

        int ans[] = new int[n];
        for(int i=0;i<n;i++)
        {
            ans[i] = left[i] * right[i];
        }

        return ans;
    }

