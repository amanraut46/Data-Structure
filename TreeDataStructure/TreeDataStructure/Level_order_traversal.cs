using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class Level_order_traversal
    {
        static Node root;
        static Queue<Node> q = new Queue<Node>();
        static void Main()
        {
            root = new Node(20);
            root.left = new Node(12);
            root.right = new Node(29);
            root.left.left = new Node(10);
            root.left.right = new Node(15);
            root.left.left.right = new Node(11);

            root.right.left = new Node(25);
            root.right.left.left = new Node(22);
            root.right.right = new Node(45);
            root.right.right.left = new Node(40);
            root.right.right.right = new Node(66);

            level_order_traversal(root);
            Console.WriteLine("\nHeight of tree:"+height(root));
            Console.ReadLine();
        }

        private static int height(Node root)
        {
            Node top = root;
            if (top==null)
            {
                return 0;

            }
            int h_left = height(top.left);
            int h_right = height(top.right);

            if (h_left > h_right)
                return 1 + h_left;
            else
                return 1 + h_right;
        }

        private static void level_order_traversal(Node root)
        {
            Node top = root;
            if (top==null)
            {
                Console.WriteLine("Tree is empty");
                return;
            }
            q.Enqueue(top);
            while (q.Count!=0)
            {
                top = q.Dequeue();
                Console.Write(top.item+" ");

                if (top.left!=null)
                {
                    q.Enqueue(top.left);
                }
                if (top.right!=null)
                {
                    q.Enqueue(top.right);
                }
            }
            
        }
    }
}
