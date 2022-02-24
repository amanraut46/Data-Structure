using System;
using System.Collections.Generic;
using System.Text;

namespace Graph_Data_Structure
{
    public class GraphMatrixCurd
    {
        public static int n = 100;
        public static int max_edge, vertex;
        public static int[,] graph = new int[n, n];
        public static void Create_Graph()
        {
            int  orgin, destination;
            Console.WriteLine("Enter the vertex");

            vertex = int.Parse(Console.ReadLine());
            max_edge = vertex * (vertex - 1);

            for (int i= 0; i <= max_edge; i++)
            {
                Console.WriteLine("Enter the origin and destionation");
                orgin = int.Parse(Console.ReadLine());
                destination = int.Parse(Console.ReadLine());

                if (orgin==-1 && destination==-1)
                {
                    break;
                }
                if (orgin>=vertex || orgin<0 || destination<0 || destination>= vertex)
                {
                    Console.WriteLine("Inavlid edge");
                    i--;
                }
                graph[orgin, destination] = 1;
            }
        }
        public static void Main()
        {
            int origin, destination;
            Create_Graph();
            Console.WriteLine("1:Insert an edge");
            Console.WriteLine("2:Delete an edge");
            Console.WriteLine("3:Print Graph");
            Console.WriteLine("4:Exit");
            Console.WriteLine("Enter your choice");
            int choice = int.Parse(Console.ReadLine());
            bool valid = true;
            while (valid)
            {
                switch (choice)
                {
                    case 1:
                        Console.WriteLine("Enter the origin");
                        origin = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter the destination");
                        destination = int.Parse(Console.ReadLine());
                        insert(origin, destination);
                        break;
                    case 2:
                        Console.WriteLine("Enter the origin");
                        origin = int.Parse(Console.ReadLine());
                        Console.WriteLine("Enter the destination");
                        destination = int.Parse(Console.ReadLine());
                        delete(origin, destination);
                        break;
                    case 3:
                        printGraph();
                        break;
                    case 4:
                        valid = false;
                        break;
                }
            }
            Console.ReadLine();
        }

        private static void printGraph()
        {
            for (int i = 0; i <=vertex-1; i++)
            {
                for (int j = 0; j <=vertex-1; j++)
                {
                    Console.Write(graph[i, j] + " ");
                }
                Console.WriteLine();
            }
        }

        private static void delete(int origin, int destination)
        {
            if (origin < 0 || origin >= vertex || destination < 0 || destination >= vertex)
            {
                Console.WriteLine("This edge is not exits");
            }
            else
            {
                graph[origin, destination] = 0;
            }
        }

        private static void insert(int origin, int destination)
        {
            if (origin<0 || origin>=vertex)
            {
                Console.WriteLine("Origin vertix does not exits");
               
            }
            else if (destination<0 || destination>=vertex)
            {
                Console.WriteLine("Destination vertix does not exits");
            }
            else
            {
                graph[origin, destination] = 1;
            }
        }
    }
}
