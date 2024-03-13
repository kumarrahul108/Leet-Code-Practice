// Leet-Code : Q.No => 2485 => Find the Pivot Integer -> 13th March 2024 


    //  prefix sum approach  +  total sum formula -> n(n+1)/2


    // 1.******* Using C++ *******


    // A. **** Prefic Sum Approach **** 
    int pivotInteger(int n) 
    {
        // Base case: If there's only one integer in the range, it's the pivot integer.
        if(n == 1)
        {
            return 1;
        }

        // Arrays to store left and right cumulative sums.
        vector<int> Lsum(n + 1, 0);
        vector<int> Rsum(n + 1, 0);

        // Compute left cumulative sums up to index i.
        for (int i = 1; i <= n; i++) 
        {
            Lsum[i] = Lsum[i - 1] + i;
        }

        // Initialize Rsum[n] with n, as it's the last element of the array.
        Rsum[n] = n;

        // Compute right cumulative sums from index n-1 down to 1.
        for (int i = n-1; i >= 1; i--) 
        {
            Rsum[i] = Rsum[i+1] + i;
        }

        // Iterate through the range and find the pivot integer.
        for (int i = 1; i <= n; i++) 
        {
            if (Lsum[i] == Rsum[i]) 
            {
                return i;  // i is the pivot integer.
            }
        }

        return -1;   // If no pivot integer is found, return -1. 
    }



    // B. **** SUm Formula Approach **** 
    int pivotInteger(int n) 
    {
        int totalSum = 0;
        int leftSum = 0;

        // Calculate the total sum of integers from 1 to n
        for (int i = 1; i <= n; ++i) 
        {
            totalSum += i;
        }

        // Iterate through the range and find the pivot integer
        for (int i = 1; i <= n; ++i) 
        {
            // Update left sum
            leftSum += i;

            // Check if current integer is the pivot integer
            if (leftSum == totalSum - leftSum + i) 
            {
                return i; // Return the pivot integer
            }
        }

        // No pivot integer found
        return -1;  
    }




    // 2. ***** Using Java *****  

    public int pivotInteger(int n) 
    {
        int totalSum = 0;
        int leftSum = 0;

        for(int i=1;i<=n;i++)
        {
            totalSum += i;
        }    

        for(int i=1;i<=n;i++)
        {
            leftSum += i;

            if(leftSum == (totalSum - leftSum + i))
            {
                return i;
            }
        }
        return -1;  
    }