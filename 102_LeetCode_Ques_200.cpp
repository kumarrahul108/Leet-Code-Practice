// Leet-Code : Q.No => 200 => Number of Island => 19th April 2024 


    //  array traversal + dfs (depth first serach)



    // 1.******* Using C++ *******


    void helper(vector<vector<char>>& grid, int i, int j)
    {
        // Base case:
        // If the current position (i, j) is out of grid bounds,
        // or the cell is not part of an island ('0' or already visited '1'),
        // return without further exploration.
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        // Mark the current cell as visited by changing it to '0'
        grid[i][j] = '0';

        // Explore adjacent cells recursively: up, down, left, right
        helper(grid, i + 1, j); // down
        helper(grid, i - 1, j); // up
        helper(grid, i, j + 1); // right
        helper(grid, i, j - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        // Base case: If the grid is empty or has no columns, return 0 islands
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }       

        int numOfIsland = 0; // Counter for the number of islands

        // Traverse through each cell of the grid
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                // If the current cell is part of an unvisited island ('1')
                if(grid[i][j] == '1')
                {
                    // Increment the number of islands
                    numOfIsland++;
                    
                    // Explore the entire island using DFS (depth-first search)
                    helper(grid, i, j);
                }
            }
        }

        // Return the total number of islands found
        return numOfIsland;
    }





    // 2.******* Using Java *******

    public void helper(char[][] grid, int i, int j)
    {
        // base case 
        if(i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] != '1')
        {
            return;
        }

        // mark as visisted
        grid[i][j] = '0';

        // recurssion 
        helper(grid,i+1,j);   // up
        helper(grid,i-1,j); // down
        helper(grid,i,j+1);  // right
        helper(grid,i,j-1);  // left
    }

    public int numIslands(char[][] grid) 
    {
        // base case 
        if(grid.length == 0 || grid == null)
        {
            return 0;
        }    

        int noOfIsland = 0;

        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j] == '1')
                {
                    noOfIsland++;
                    helper(grid,i,j);
                }
            }
        }

        return noOfIsland;
    }

