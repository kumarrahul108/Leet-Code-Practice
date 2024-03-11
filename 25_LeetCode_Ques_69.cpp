// Leet-Code : Q.No => 69 => Sqrt(x) -> 11th March 2024 


    // binary search apply -> mid * mid 


    // 1. Using C++

    int mySqrt(int x) 
    {
        int start = 0;
        int end = x;
        int ans = 0;  // Variable to store the result

        long long int mid = start + (end-start)/2;  // Midpoint calculation (cast to long long to avoid overflow)

        while(start <= end)
        {
            // If the square of mid is equal to x, we found the square root
            if((mid * mid) == x)
            {
                return mid;
            }
            // If the square of mid is greater than x, reduce the search range to the left side
            else if((mid*mid) > x)
            {
                end = mid-1;
            }
            // If the square of mid is less than x, update the potential answer and increase the search range to the right side
            else 
            {
                ans = mid;
                start = mid+1;
            }

            mid = (start + end)/2;  // Recalculate the midpoint
        }

        return ans;   // Return the result
    }


    // 2. Using Java 

    public int mySqrt(int x)  
    {
        long start = 1;
        long end = x;
        long ans = 0;

        while(start <= end)
        {
            long mid = start + (end - start)/2;

            if(mid*mid == x)
            {
                ans = (int)mid;
                break;
            }
            else if(mid*mid < x)
            {
                start = mid+1;
                ans = mid;
            }
            else
            {
                end = mid-1;
            }
        }
        return (int)ans;
    }