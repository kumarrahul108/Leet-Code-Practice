// Leet-Code : Q.No => 33 => Search in Rotated Sorted ARray -> 9th March 2024 


    // pivot index in rotated sorted array 


    // 1. Using C++

    int findPivotIndex(vector<int>& arr)
     {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s <= e) 
        {
            //corner case
            if(s == e) 
            {
                //single element
                return s;
            }

            if(mid+1 < n && arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if(mid-1 >=0 && arr[mid] < arr[mid-1])
            {
                return mid-1;
            }
            else if(arr[s] > arr[mid] ) 
            {
                e = mid - 1;
            }
            else 
            {
                s = mid + 1;
            }    
            
            mid = s + (e-s)/2;
        }
        return -1;

    }

    int binarySearch(vector<int>& arr, int s, int e, int target) 
    {
        int mid = s + (e-s)/2;

        while(s<=e) 
        {
            if(arr[mid] == target) 
            {
                return mid;
            }
            if(target > arr[mid]) 
            {
                s = mid + 1;
            }
            else 
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) 
    {
        int pivotIndex = findPivotIndex(nums);
        // cout << "Pivot Index us: " << pivotIndex << endl;
        int n = nums.size();
        int ans = -1;

        //search in A
        if(target >= nums[0] && target <= nums[pivotIndex]) 
        {
            ans = binarySearch(nums, 0, pivotIndex, target);
        }
        else 
        {
            ans = binarySearch(nums, pivotIndex+1, n-1, target);
        }
        return ans;
    }




    // 2. Using Java 

     public int binarySearch(int arr[],int start,int end,int target)
    {
        while(start <= end)
        {
            int mid = (start + end)/2;

            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[mid] > target)
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }
        return -1;
    }



    int findPivotIndex(int arr[])
    {
        int n = arr.length;
        int start = 0;
        int end = n-1;

        while(start <= end)
        {
            int mid = (start + end)/2;

            if(start == end)
            {
                return start;
            }
            else if((mid+1 < n)  &&  arr[mid] > arr[mid+1])
            {
                return mid;
            }
            else if((mid-1 >= 0)  &&  arr[mid] < arr[mid-1])
            {
                return mid-1;
            }
            else if(arr[start] > arr[mid])
            {
                end = mid - 1;
            }
            else 
            {
                start = mid + 1;
            }
        }
        return -1;
    }


    public int search(int[] nums, int target) 
    {
        int pivotIndex = findPivotIndex(nums);
        int n = nums.length;
        int ans = -1;

        if(target >= nums[0]  &&  target <= nums[pivotIndex])
        {
            ans = binarySearch(nums,0,pivotIndex,target);
        }
        else 
        {
            ans = binarySearch(nums,pivotIndex+1,n-1,target);
        }
        return ans;
    }



