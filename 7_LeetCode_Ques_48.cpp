
// Leet-Code : Q.No => 48 => Rotate Image -> 3rd March 2024 


    // 1. Using C++


    void rotate(vector<vector<int>>& matrix) 
    {
        // transpose 
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i;j<matrix[i].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        } 

        // reverse each row
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        } 
    }



    // 2. Using Java

    public void reverseArray(int[] array) {
        int left = 0;
        int right = array.length - 1;
        
        while (left < right) 
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            
            left++;
            right--;
        }
    }

    public void rotate(int[][] matrix) 
    {
        int n = matrix.length;
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                // swap
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        // Reverse each row of the transposed matrix
        for (int i = 0; i < n; i++) 
        {
            reverseArray(matrix[i]);
        }
    }
