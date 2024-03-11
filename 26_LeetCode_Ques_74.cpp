// Leet-Code : Q.No => 74 => Search a 2D Matrix -> 11th March 2024 


    // binary search apply : convert 2d index into 1 d index 


    // 1. Using C++

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        // Get the number of rows and columns in the matrix
        int row = matrix.size();
        int col = matrix[0].size();
        int n = row * col;  // Total number of elements in the matrix

        // Initialize binary search range
        int start = 0;
        int end = (n-1);
        int mid = (start + end)/2;

        // Binary search loop
        while(start <= end)
        {
            // Convert the 1D index to 2D indices (rowIndex, colIndex)
            int rowIndex = mid / col;
            int colIndex = mid % col;

            // Get the element at the current index
            int curr = matrix[rowIndex][colIndex];

            if(curr == target)
            {
                return true;
            }
            else if(curr < target)
            {
                // move right
                start = mid + 1;
            }
            else 
            {
                // move left
                end = mid - 1;
            }

            // Update the midpoint for the next iteration
            mid = (start + end)/2;
        }

        // If the target is not found, return false
        return false;    
    }


    // 2. Using Java 

    public boolean searchMatrix(int[][] matrix, int target) 
    {
        int row = matrix.length;
        int col = matrix[0].length;
        int n = row * col;

        int start = 0;
        int end = n-1;
        int mid = (start+end)/2;

        while(start <= end)
        {
            int rowIndex = mid / col;
            int colIndex = mid % col;
            int curr = matrix[rowIndex][colIndex];

            if(curr == target)
            {
                return true;
            }
            else if(curr <  target)
            {
                start = mid +1;
            }
            else 
            {
                end = mid -1;
            }

            mid = (start+end)/2;
        }  
        return false;
    }
