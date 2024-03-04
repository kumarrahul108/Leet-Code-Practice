
// Leet-Code : Q.No => 724 => Find Pivot Index-> 4th March 2024 


    // 1. Using C++


    // A. brute force apparoach
    int pivotIndex(vector<int>& nums)  
    {
        int n = nums.size();
        // traverse whole array
        for(int i=0;i<n;i++)
        {
            int lsum = 0;
            int rsum = 0;

            // lsum 
            for(int j=0;j<i;j++)
            {
                lsum += nums[j];
            }   

            // rsum
            for(int j=i+1;j<n;j++)
            {
                rsum += nums[j];
            }

            // comparison 
            if(lsum == rsum)
            {
                return i;
            }
        }
        return -1;
    }


    // B. Prefix Sum Approach
    int pivotIndex(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> Lsum(n,0);
        vector<int> Rsum(n,0);

        // store Lsum array elements 
        for(int i=1;i<n;i++)
        {
            Lsum[i] = Lsum[i-1] + nums[i-1];
        }

        // store Rsum array elements
        for(int i=n-2;i>=0;i--)
        {
            Rsum[i] = Rsum[i+1] + nums[i+1];
        }

        // Comparison 
        for(int i=0;i<n;i++)
        {
            if(Lsum[i] == Rsum[i])
            {
                return i;   // pivot index 
            }
        }

        return -1;    // if pivot not present in array
    }





    // 2. Using Java 

    // Prefic Sum Approach
    public int pivotIndex(int[] nums) 
    {
        int n = nums.length;
        int Lsum[] = new int[n];
        int Rsum[] = new int[n];

        // store in Lsum array
        for(int i=1;i<n;i++)
        {
            Lsum[i] = Lsum[i-1] + nums[i-1];
        }

        // store in Rsum array
        for(int i=n-2;i>=0;i--)
        {
            Rsum[i] = Rsum[i+1] + nums[i+1];
        }

        // Comparison     
        for(int i=0;i<n;i++)
        {
            if(Lsum[i] == Rsum[i])
            {
                return i;    // pivot index
            }
        }

        return -1;   // no pivot elelment present 
    }



