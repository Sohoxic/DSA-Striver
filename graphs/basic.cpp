// iF THERE ARE N NODES, THEN NO. OF POSSIBLE EDGES ARE N*(N-1)/2, THEN NO. OF POSSIBLE GRAPHS ARE 2^E.
/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

int countingGraphs(int N)
{

    // Declaring 'ans' & 'E'.
    int ans,E;
    
    // Calculating the total number of edges possible in the graph.
    E = (N * (N-1)) / 2;

    // Calculating the total number of graphs.
    ans = 1 << E;

    // Returning 'ans'.
    return ans;
}