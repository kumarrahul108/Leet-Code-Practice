// Leet-Code : Q.No => 463 => Island Perimeter => 18th April 2024 


    //  array + reacurssion (matrix)


    // 1.******* Using C++ *******

    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int perimeter = 0; // Initialize perimeter variable
        int rows = grid.size(); // Get number of rows in the grid
        int cols = grid[0].size(); // Get number of columns in the grid

        // Iterate through each cell in the grid
        for(int i=0; i<rows; i++)    
        {
            for(int j=0; j<cols; j++)
            {
                // If the cell represents land (1)
                if(grid[i][j] == 1)
                {
                    perimeter += 4; // Increment perimeter by 4 (as each land cell contributes 4 sides)

                    // Check adjacent cells to decrement perimeter if adjacent land cells are found
                    // Check left cell
                    if(i > 0 && grid[i-1][j] == 1)
                    {
                        perimeter -= 2; // Decrement perimeter by 2 if left cell is also land
                    }
                    // Check top cell
                    if(j > 0 && grid[i][j-1] == 1)
                    {
                        perimeter -= 2; // Decrement perimeter by 2 if top cell is also land
                    }      
                }  // if
            }  // inner loop
        } // outer loop

        return perimeter; // Return the calculated perimeter
    }






    // 2.******* Using Java *******



    // **** approach - 1 ******

    public int dfs(int[][] grid,int r , int c)
    {
        // base 
        if(r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] == 0)
        {
            return 1;
        }

        if(grid[r][c] == -1)
        {
            return 0;
        }

        grid[r][c] = -1;

        return ( dfs(grid,r+1,c) +
                 dfs(grid,r-1,c) +   
                 dfs(grid,r,c+1) + 
                 dfs(grid,r,c-1));

    }

    public int islandPerimeter(int[][] grid) 
    {
        int rows = grid.length;
        int cols = grid[0].length;
        int perimeter = 0;

        for (int r = 0; r < rows; r++) 
        {
            for (int c = 0; c < cols; c++) 
            {
                if (grid[r][c] == 1) 
                {
                    perimeter += dfs(grid, r, c);
                }
            }
        }

        return perimeter;
    }   



    // **** approach - 2 ******


    public int islandPerimeter(int[][] grid) 
    {
        int peri = 0;
        int rows = grid.length;
        int cols = grid[0].length;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 1)
                {
                    peri += 4;
                    if(i > 0 && grid[i-1][j] == 1)
                    {
                        peri -= 2;
                    }
                    if(j > 0 && grid[i][j-1] == 1)
                    {
                        peri -= 2;
                    }
                }
            }
        }  

        return peri;   
    }