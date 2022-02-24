using System;
using System.Collections.Generic;
using System.Text;

namespace Graph_Data_Structure
{
    public class BFS
    {
        public static void Main()
        {
            int v = 4;
            LinkedList<int>[] adj = new LinkedList<int>[v];
            for (int i = 0; i < v; i++)
            {
                adj[i] = new LinkedList<int>();
            }
            AddEge(adj,0,1);
            AddEge(adj, 0, 2);
            AddEge(adj, 2, 0);
            AddEge(adj, 2, 3);
            AddEge(adj, 1, 2);
            AddEge(adj, 3, 3);

            for (int i = 0; i < adj.Length; i++)
            {
                Console.WriteLine("\nAdjacency list of vertex " + i);
                Console.Write("head");

                foreach (var item in adj[i])
                {
                    Console.Write(" -> " + item);
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }

        private static void AddEge(LinkedList<int>[] adj,int u, int v)
        {
            adj[u].AddLast(v);
            adj[v].AddLast(u);
        }
    }
}
