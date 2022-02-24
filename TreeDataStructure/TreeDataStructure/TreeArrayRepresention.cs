using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class TreeArrayRepresention
    {
       static char[] tree = new char[100];
       public static void AddRoot(char k)
       {
            tree[0]= k;
       }
       public static void LeftNode(char key,int root)
       {
           int i= (root * 2) + 1;
            if (tree[root] ==' ')
            {
                Console.Write("Can't set child at {0}, no parent found\n", i);
            }
            else
            {
                tree[i] = key;
            }
       }
        public static void RIghtNode(char key, int root)
        {
            int i = (root * 2) + 2;
            if (tree[root] == ' ')
            {
                Console.Write("Can't set child at {0}, no parent found\n", i);
            }
            else
            {
                tree[i] = key;
            }
        }
        public static void InOrderTravels()
        {
            for (int i = 0; i <tree.Length-1 ; i++)
            {
                if (tree[i]!=' ')
                {
                    Console.Write(tree[i]);
                }
                else
                {
                    Console.Write("-");
                }
            }
        }
        public static void Main()
        {
            AddRoot('A');
            LeftNode('B', 0);
            RIghtNode('C', 0);
            LeftNode('D', 1);
            RIghtNode('E', 1);
            InOrderTravels();
            Console.ReadLine();

        }
    }
}
