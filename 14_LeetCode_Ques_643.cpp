
// Leet-Code : Q.No => 643 => Maximum Average Sub-Array - I -> 6th March 2024 


    // 1. Using C++

    // Brute force 
    double findMaxAverage(vector<int>& nums, int k) 
    {
        int maxSum = INT_MIN; // Initialize the maximum sum with the smallest possible integer value

        int i = 0; // Initialize the start index of the window
        int j = k - 1; // Initialize the end index of the window

        // Iterate until the end index of the window reaches the end of the array
        while (j < nums.size()) 
        {
            int sum = 0; // Initialize the sum of elements within the current window

            // Calculate the sum of elements within the current window
            for (int y = i; y <= j; y++) 
            {
                sum += nums[y];
            }

            // Update the maximum sum found so far
            maxSum = max(maxSum, sum);

            // Move the window by incrementing both start and end indices
            i++;
            j++;
        } 

        // Calculate the maximum average by dividing the maximum sum by k (convert k to double to avoid integer division)
        double maxAvg = maxSum / (double) k;

        return maxAvg; // Return the maximum average
    }



    // Sliding Window   

    double findMaxAverage(vector<int>& nums, int k) 
    {
       int n = nums.size();
       int sum = 0;

        // Calculate sum of the first window of size k
        for(int i=0;i<k;i++)
        {
            sum += nums[i];
        }

        // Initialize the maximum average with the average of the first window
        double maxAvg = (double) sum/k;

        // Slide the window and update the maximum average
        for(int i=k;i<n;i++)
        {
            sum += nums[i] - nums[i - k];       // Update the window sum
            double average = (double) sum / k;  // Calculate the current average
            maxAvg = max(maxAvg, average);     // Update the maximum average
        }

        return maxAvg;
    }





    // 2. USING Java 

        // sliding window approach 
    public double findMaxAverage(int[] nums, int k) 
    {
        int i =0;
        int j = k-1;        
        int sum = 0;

        for(int y=i;y<k;y++)
        {
            sum += nums[y];
        }    

        int maxSum = sum;
        j++;

        while(j < nums.length)
        {
            sum += nums[j++] - nums[i++];
            maxSum = Math.max(maxSum,sum);
        }

        double maxAvg = maxSum /(double)k;

        return maxAvg;
    }



