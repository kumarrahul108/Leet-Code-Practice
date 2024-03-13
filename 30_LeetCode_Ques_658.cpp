// Leet-Code : Q.No => 658 => Find K Closest Elements -> 13th March 2024 


    //  2 pointer + Binary search 


    // 1.******* Using C++ *******


    // A. *** Approach -1 *** 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int l = 0;
        int h = arr.size() - 1;

        // Binary search loop to narrow down the search range.
        while((h-l) >= k)
        {
            // Compare distances of the current low and high elements from x.
            if(x - arr[l]  >  arr[h] - x)
            {
                l++;   // Move low pointer to the right.
            }
            // If distance from high element to x is greater than or equal to distance from low element to x.
            else 
            {
                h--;   // Move high pointer to the left.
            }
        } 

        /*    
        // Construct the result vector with the k closest elements.
        vector<int> ans;
        for(int i=l;i<=h;i++)
        {
            ans.push_back(arr[i]);
        }   

        return ans;  // Return the vector containing the k closest elements
        */ 

        return vector<int>(arr.begin()+l , arr.begin()+h+1);

        /* 
            arr.begin(): This returns an iterator pointing to the beginning of the arr vector.
            arr.begin() + l: This moves the iterator l positions forward from the beginning of the arr vector. It   effectively points to the element at index l.
            arr.begin() + h + 1: This moves the iterator h + 1 positions forward from the beginning of the arr vector. It effectively points to the element immediately after the element at index h.

            So, arr.begin() + l points to the starting position of the subsequence in arr,
             and arr.begin() + h + 1 points to the position just after the end of the subsequence in arr.
              By passing these iterators as arguments to the vector<int> constructor, a new vector is constructed containing the elements between these iterators, which corresponds to the subsequence [arr[l], arr[h]] from the original arr vector.
        
        */
    }



    // B. **** Approach - 2 **** 
    // Function to find the lower bound of a given integer x in a sorted array arr.
    int lowerBound(vector<int>& arr,int x)
    {
        int start = 0;
        int end = arr.size()-1;

        int ans = end;  // Initialize the answer with the end index (default if x is greater than any element).

        // Binary search loop to find the lower bound.
        while(start <= end)
        {
            int mid = (start+end)/2;

            // If the middle element is greater than or equal to x, update ans and search in the left half.
            if(arr[mid] >= x)
            {
                ans = mid;
                end = mid-1;
            }
            else if(x > arr[mid])
            {
                start = mid + 1;        
            }
             // If x is greater than the middle element, search in the right half.
            else 
            {
                end = mid - 1;  // Move the start pointer to the right.
            }
        } 
        return ans; // Return the lower bound index.
    } 

    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int h = lowerBound(arr,x);
        int l = h-1;

        // Adjust the pointers to select the k closest elements.
        while(k--)
        {
            // If l goes out of bounds, move h to the right.
            if(l < 0)
            {
                h++;
            }
            // If h goes out of bounds, move l to the left.
            else if(h >= arr.size())
            {
                l--;
            }
            // If the element at l is closer to x, move l to the left.
            else if(x - arr[l]  > arr[h] - x)
            {
                h++;
            }
            // Otherwise, move h to the right.
            else 
            {
                l--;
            }
        }

        // Construct and return the vector containing the k closest elements.
        return vector<int>(arr.begin()+l+1,arr.begin()+h);
    }




    // 2. ***** Using Java ****** 

    public List<Integer> findClosestElements(int[] arr, int k, int x) 
    {
        int low = 0;
        int high = arr.length - 1;

        while((high-low) >= k)
        {
            if(x - arr[low] > arr[high] - x)
            {
                low++;
            }
            else 
            {
                high--;
            }
        } 

        List<Integer> vec = new ArrayList<>();

        for(int i=low;i<=high;i++)
        {
            vec.add(arr[i]);
        }   

        return vec;
    }


