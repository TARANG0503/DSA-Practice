using System;
public class GFG
{
 
  // Max # of persons in the party
  static readonly int N = 8;
 
  // Person with 2 is celebrity
  static int[,] MATRIX = { { 0, 0, 1, 0 },
                           { 0, 0, 1, 0 },
                           { 0, 0, 0, 0 },
                           { 0, 0, 1, 0 } };
 
  static int knows(int a, int b) { return MATRIX[a,b]; }
 
  // Returns -1 if celebrity
  // is not present. If present,
  // returns id (value from 0 to n-1).
  static int findCelebrity(int n)
  {
 
    // the graph needs not be constructed
    // as the edges can be found by
    // using knows function
 
    // degree array;
    int[] indegree = new int[n];
    int[] outdegree = new int[n];
 
    // query for all edges
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int x = knows(i, j);
 
        // set the degrees
        outdegree[i] += x;
        indegree[j] += x;
      }
    }
 
    // find a person with indegree n-1
    // and out degree 0
    for (int i = 0; i < n; i++)
      if (indegree[i] == n - 1 && outdegree[i] == 0)
        return i;
 
    return -1;
  }
 
  // Driver code
  public static void Main(String[] args)
  {
    int n = 4;
    int id = findCelebrity(n);
    if (id == -1)
      Console.Write("No celebrity");
    else
      Console.Write("Celebrity ID " + id);
  }
}