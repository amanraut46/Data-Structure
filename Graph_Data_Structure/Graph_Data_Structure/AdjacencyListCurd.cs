using System;
using System.Collections.Generic;
using System.Text;

namespace Graph_Data_Structure
{
    public class Vertex
    {
        public int Data { get; set; }
        public Vertex NextVertex { get; set; }

        public Edge FirstEges { get; set; }

        public Vertex(int data)
        {
            this.Data = data;
        }
    }
    public class Edge
    {
        public Vertex Destination { get; set; }
        public Edge NextEdge { get; set; }
    }
    public class AdjacencyListCurd
    {
        public static Vertex start = null;
        public static Edge edge = null;

        static void Main()
        {
            insertVertex(1);
            insertVertex(2);
            deleteVerex(2);
            Display();
            Console.ReadLine();
        }

        private static void deleteVerex(int v)
        {
            Vertex temp;
           
            if (start==null)
            {
                Console.WriteLine("No vertex to be deleted");

            }
            if (start.Data == v)
            {
                temp = start;
                start = start.NextVertex;
            }
            else
            {
                Vertex ptr = start;
                while (ptr.NextVertex != null)
                {
                    if (ptr.NextVertex.Data == v)
                    {
                        break;
                    }
                    ptr = ptr.NextVertex;
                }
                if (ptr.NextVertex == null)
                {
                    Console.WriteLine("Vertiex not found");
                }
                else
                {
                    temp = ptr.NextVertex;
                    ptr.NextVertex = temp.NextVertex;
                }
            }

           // Edge p = temp.FirstEges;
        }

        public static void insertVertex(int u)
        {
            Vertex new_vertex = new Vertex(u);
            new_vertex.FirstEges = null;
            new_vertex.NextVertex = null;

            if (start==null)
            {
                start = new_vertex;
            }
            else
            {
                Vertex p = start;
                while (p.NextVertex!=null)
                {
                   p= p.NextVertex;
                }
                p.NextVertex = new_vertex;
            }

        }
        public static void Display()
        {
            Vertex v;
            Edge q;
            v = start;
            while (v!=null)
            {
                Console.WriteLine(v.Data);
                q = v.FirstEges;
                while (q!=null)
                {
                    Console.WriteLine(q.Destination.Data);
                }
                Console.WriteLine();
                v = v.NextVertex;
            }
        }
    }
}
