using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class NodeTree
    {
        public int key;
        public NodeTree left;
        public NodeTree right;

        public NodeTree(int key)
        {
            this.key = key;
            left = null;
            right = null;
        }
    }
    public class InsertNodes
    {

        public static void InOrderTraversal(NodeTree nodeTree)
        {
            if (nodeTree!=null)
            {
                InOrderTraversal(nodeTree.left);
                Console.Write(nodeTree.key + " ");
                InOrderTraversal(nodeTree.right);
            }
        }

        public static void InsertNode(int key,NodeTree node)
        {
            NodeTree newnode = new NodeTree(key);
            if (node==null)
            {
                node = newnode;
                return;
            }
            Queue<NodeTree> treenode = new Queue<NodeTree>();
            treenode.Enqueue(node);

            while (treenode.Count!=0)
            {
                NodeTree temp = treenode.Peek();
                treenode.Dequeue();

                if (temp.left==null)
                {
                    temp.left = newnode;
                    break;
                }
                else
                {
                    treenode.Enqueue(temp.left);
                }

                if (temp.right==null)
                {
                    temp.right = newnode;
                    break;
                }
                else
                {
                    treenode.Enqueue(temp.right);
                }
            }
        }
        public static int FindMax(NodeTree tree)
        {
            if (tree==null)
            {
                return int.MinValue;
            }
            int res = tree.key;
            int lress = FindMax(tree.left);
            int rress = FindMax(tree.right);

            if (lress>rress)
            {
                res = lress;
            }
            if (lress<rress)
            {
                res = rress;
            }
            return res;
        }
        public static int GetSize(NodeTree node)
        {
            if (node==null)
            {
                return 0;
            }
            else
            {
                return (GetSize(node.left) + 1 + GetSize(node.right));
            }
        }
        public static void PrintLevelOrder(NodeTree tree)
        {
            Queue<NodeTree> node = new Queue<NodeTree>();
            node.Enqueue(tree);
            while (node.Count!=0)
            {
                NodeTree temp = node.Dequeue();

                Console.Write(temp.key + " ");

                if (temp.left!=null)
                {
                    node.Enqueue(temp.left);
                }
                if (temp.right!=null)
                {
                    node.Enqueue(temp.right);
                }
            }
        }
        public static NodeTree root;
        public static void Main()
        {
            root = new NodeTree(10);
            root.left = new NodeTree(11);
            root.left.left = new NodeTree(7);
            root.right = new NodeTree(9);
            root.right.left = new NodeTree(15);
            root.right.right = new NodeTree(8);
            
            Console.Write(
            "Inorder traversal before insertion:");
            InOrderTraversal(root);
            Console.Write(
            "PrintLevelOrder  before insertion:");
            PrintLevelOrder(root);
            Console.WriteLine("\nGet Size {0}", GetSize(root));
            int key = 12;
            InsertNode(key,root);

            Console.Write(
                "\nInorder traversal after insertion:");
            InOrderTraversal(root);
            Console.Write(
            "PrintLevelOrder  before insertion:");
            PrintLevelOrder(root);
            

            Console.WriteLine("\nGet Size {0}", GetSize(root));

            Console.WriteLine("\nGet Max={0}", FindMax(root));

            Console.ReadLine();
        }
    }

    
}
