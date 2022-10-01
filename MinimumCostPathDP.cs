using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;

namespace HackerrankSolutionList
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] Matrix1 = new int[3, 3];
            int[,] Matrix2 = new int[3, 3];

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    Matrix1[x, y] = int.Parse(Console.ReadLine());
                }
            }
            //base case(mendatar/horizontal) == x.
            Matrix2[0, 0] = Matrix1[0, 0];
            Matrix2[0, 1] = Matrix1[0, 1]+  Matrix2[0,0];
            Matrix2[0, 2] = Matrix1[0, 2] + Matrix2[0, 1];
            //end
           //base case(vertikal) == y.
            Matrix2[0, 0] = Matrix1[0, 0];
            Matrix2[1, 0] = Matrix1[1, 0] + Matrix2[0, 0];
            Matrix2[2, 0] = Matrix1[2, 0] + Matrix2[1, 0];
            //end
           //kalkulasi x/mendatar.
            Console.WriteLine();
            Console.WriteLine("tahap 2");
            int X = 1;
            //row 1 from 2 row i must do like this remember in array we use 0 zero index based. 
                if(Matrix2[0,X] < Matrix2[X, 0])
                {
                    Matrix2[X, 1] = Matrix1[X, 1] + Matrix2[0,X];
            }
            else
            {
                Matrix2[X, 1] = Matrix1[X, 1] + Matrix2[X, 0];
            }
                if(Matrix2[0,X+1] < Matrix2[X, 1]){
                Matrix2[X, 2] = Matrix1[X, 2] + Matrix2[0, X + 1];
            }
            else
            {
                Matrix2[X, 2] = Matrix1[X, 2] + Matrix2[X,1];
            }
            //end
            //row 2 from 2 row i must do like this remember in array we use 0 zero index based. 
            int Y = 1;
            //6 < 9
            if (Matrix2[1, Y] < Matrix2[2, 0]){
                Matrix2[Y+1, 1] = Matrix1[Y+1, 1] + Matrix2[1, Y];
            }
            else
            {
                Matrix2[Y + 1, 1] = Matrix1[Y + 1, 1] + Matrix2[2, 0];
            }
            if (Matrix2[1, Y + 1] < Matrix2[Y+1, 1])
            {
                Matrix2[Y+1, 2] = Matrix1[Y+1, 2] + Matrix2[1, Y+1];
            }
          else
           {
                Matrix2[Y+1, 2] = Matrix1[Y+1, 2] + Matrix2[Y+1, 1];
           }

            //end


            Console.WriteLine("Result: ");
            for (int x = 0; x < 3; x++)
            {

                for (int y = 0; y < 3; y++)
                {

                    if (y % 3 == 0)
                    {
                        Console.WriteLine();
                    }

                    Console.Write(Matrix2[x, y]);
                }
            }

            Console.ReadLine();



        }
        static int MaxValue(long result)
        {
            //fibonacci DP
            int[] memo = new int[result + 1];
            memo[0] = 1;
            memo[1] = 1;
            memo[2] = 2;
            for (int x = 3; x <= result; x++)
            {
                memo[x] = memo[x - 1] + memo[x - 2] + memo[x - 3];
            }
            return memo.Last();


        }
    }
}
