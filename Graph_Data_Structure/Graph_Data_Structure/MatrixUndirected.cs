using System;
using System.Collections.Generic;
using System.Text;

namespace Graph_Data_Structure
{
    public class MatrixUndirected
    {
        static int n = 100;
        static int[,] array = new int[n, n];

        public static void Main()
        {
            Console.WriteLine("Enter the number of edge");
            int edge = int.Parse(Console.ReadLine());
            for (int i = 0; i < edge; i++)
            {
                Console.WriteLine("Enter origin and destionation");

                int origin = int.Parse(Console.ReadLine());
                int desti = int.Parse(Console.ReadLine());

                array[origin, desti] = 1;
                array[desti, origin] = 1;
            }
            Console.WriteLine("Graph");
            for (int i = 0; i < edge; i++)
            {
                for (int j = 0; j < edge; j++)
                {
                    Console.Write(array[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}
