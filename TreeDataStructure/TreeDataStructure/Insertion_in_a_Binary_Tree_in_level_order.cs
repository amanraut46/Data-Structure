using System;
using System.Collections.Generic;
namespace TreeDataStructure
{
    public class Node
    {
        public int item;
        public Node left,right;
        public Node(int item)
        {
            this.item=item;
        }
    }
    public class Insertion_in_a_Binary_Tree_in_level_order
    {
        public static void inorder(Node root)
        {
            Node top=root;
            if (top!=null)
            {
                inorder(top.left);
                Console.Write(top.item +" ");
                inorder(top.right);
            }
        }
        static void delete(Node root, int key)
        {
            if (root == null)
                return;

            if (root.left == null &&
               root.right == null)
            {
                if (root.item == key)
                {
                    root = null;
                    return;
                }
                else
                    return;
            }

            Queue<Node> q = new Queue<Node>();
            q.Enqueue(root);
            Node temp = null, keyNode = null;

            // Do level order traversal until
            // we find key and last node.
            while (q.Count!=0)
            {
                temp = q.Peek();
                q.Dequeue();

                if (temp.item == key)
                    keyNode = temp;

                if (temp.left != null)
                    q.Enqueue(temp.left);

                if (temp.right != null)
                    q.Enqueue(temp.right);
            }

            if (keyNode != null)
            {
                int x = temp.item;
                deleteDeepest(root, temp);
                keyNode.item = x;
            }
        }
        static void deleteDeepest(Node root,
                          Node delNode)
        {
            Queue<Node> q = new Queue<Node>();
            q.Enqueue(root);

            Node temp = null;

            // Do level order traversal until last node
            while (q.Count!=0)
            {
                temp = q.Peek();
                q.Dequeue();

                if (temp == delNode)
                {
                    temp = null;
                    return;

                }
                if (temp.right != null)
                {
                    if (temp.right == delNode)
                    {
                        temp.right = null;
                        return;
                    }
                    else
                        q.Enqueue(temp.right);
                }

                if (temp.left != null)
                {
                    if (temp.left == delNode)
                    {
                        temp.left = null;
                        return;
                    }
                    else
                        q.Enqueue(temp.left);
                }
            }
        }
        public static void insertNode(Node temp,int key)
        {
            if (temp==null)
            {
                temp=new Node(key);
                return;
            }
            if (temp.left==null)
            {
                temp.left=new Node(key);
            }
            else
            {
                temp.right=new Node(key);
            }
        }
        public static Node root;
        static void Main()
        {
            root = new Node(10);
            root.left = new Node(11);
            root.left.left = new Node(7);
            root.left.right = new Node(12);
            root.right = new Node(9);
            root.right.left = new Node(15);
            root.right.right = new Node(8);

            Console.WriteLine("Inorder traversal " +
                             "before deletion:");
            inorder(root);

            int key = 11;
            delete(root, key);

            Console.WriteLine("\nInorder traversal " +
                             "after deletion:");
            inorder(root);

            Console.ReadLine();


        }
    }
}