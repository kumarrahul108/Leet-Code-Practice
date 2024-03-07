// Leet-Code : Q.No => 852 => Peak Index in a Mountain Array -> 7th March 2024 

    // Binary Serach 


    // 1. Using C++

    int peakIndexInMountainArray(vector<int>& arr)  
    {
        // Initialize the start and end indices for binary search
        int start = 0;
        int end = arr.size() - 1;

        // Perform binary search to find the peak index
        while(start < end)
        {
            // Calculate the middle index
            int mid = start + (end-start)/2;

            // Check if the middle element is the peak
            if(arr[mid] > arr[mid+1]  &&  arr[mid] > arr[mid-1])
            {
                return mid;
            }

            // If the middle element is less than the next element, move to the right half of the array
            else if(arr[mid] < arr[mid+1])
            {
                start = mid + 1;
            }

            // If the middle element is greater than the next element, move to the left half of the array
            else
            {
                end = mid;
            }
        }

        // Return the start index if no peak is found
        return start;       
    }



    // 2. Using Java 

    public int peakIndexInMountainArray(int[] arr) 
    {
        int start = 0;  
        int end = arr.length -1;

        while(start < end)
        {
            int mid = start + (end-start)/2;

            if(arr[mid] > arr[mid+1]  && arr[mid] > arr[mid-1])
            {
                return mid;
            }

            else if(arr[mid] < arr[mid+1])
            {
                start = mid + 1;
            }
            
            else 
            {
                end = mid;
            }
        } 

        return start;   
    }
