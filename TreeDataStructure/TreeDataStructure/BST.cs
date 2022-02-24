using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class BST
    {
        public static Node root;
        public static void Main()
        {
            root = new Node(67);
            root.left = new Node(34);
            root.right = new Node(80);
            root.left.left = new Node(12);
            root.left.left.left = new Node(10);
            root.left.right = new Node(45);
            root.left.right.left = new Node(38);
            root.left.right.right = new Node(60);

            root.right.left = new Node(78);
            root.right.right = new Node(95);
            root.right.right.left = new Node(86);

            insertElement(root,200);

            Console.WriteLine("Preorder");
            preorder(root);
            Console.WriteLine("\nInordertravesal");
            inordertravesal(root);
            Console.WriteLine("\nPostordertraversal");
            postordertraversal(root);

            if (searchelement(root, 45) > 0)
                Console.WriteLine("\nElement found");
            if (minelementis(root)>-1)
            {
                Console.WriteLine("Minimum item in tree is {0}", minelementis(root));
            }
            if (maxelement(root)>-1)
            {
                Console.WriteLine("Maximum item in tree is {0}", maxelement(root));
            }
            del_nrec(root, 10);
            Console.ReadLine();
        }

        private static Node del_nrec(Node root, int v)
        {
            Node ptr, prev;
            ptr = root;
            prev = null;

            while (ptr!=null)
            {
                if (v==ptr.item)
                {
                    break;
                }
                prev = ptr;
                if (v<ptr.item)
                {
                    ptr = ptr.left;
                }
                else
                {
                    ptr = ptr.right;
                }
            }
            if (ptr==null)
            {
                Console.WriteLine("Key Not present in tree");
            }
            else if (ptr.left!=null && ptr.right!=null)
            {
                root = case_c(root, prev, ptr);
            }
            else if (ptr.left!=null)
            {
                root = case_b(root, prev, ptr);
            }
            else if (ptr.right!=null)
            {
                root = case_b(root, prev, ptr);
            }
            else
            {
                root = case_a(root, prev, ptr);
            }
            return root;
        }

        private static Node case_a(Node root, Node prev, Node ptr)
        {
            if (prev==null)
            {
                root = null;
            }
            else if (ptr==prev.left)
            {
                prev.left = null;
            }
            else
            {
                prev.right = null;
            }
            return root;
        }

        private static Node case_b(Node root, Node prev, Node ptr)
        {
            Node child;

            if (ptr.left!=null)
            {
                child = ptr.left;
            }
            else 
            {
                child = ptr.right;
            }
            if (prev==null)
            {
                root = null;
            }
            else if (ptr==prev.left)
            {
                prev.left = child;
            }
            else
            {
                prev.right = child;
            }
            return root;


        }

        private static Node case_c(Node root, Node prev, Node ptr)
        {
            throw new NotImplementedException();
        }

        private static Node insertElement(Node ptr, int v)
        {
            
            if (ptr==null)
            {
                ptr = new Node(v);
                ptr.left = null;
                ptr.right = null;
            }
            else if (v < ptr.item)
            {
                ptr.left= insertElement(ptr.left, v);
            }
            else if (v>ptr.item)
            {
               ptr.right= insertElement(ptr.right, v);
            }
            else
            {
                Console.Write("Duplicate Element");
            }
            return ptr;
        }

        private static int minelementis(Node root)
        {
            Node top = root;
            if (top == null)
            {
                return -1;
            }
            else if (top.left==null)
            {
                return top.item;
            }
            else
            {
                return minelementis(top.left);
            }

        }
        private static int maxelement(Node root)
        {
            Node top = root;
            if (top == null)
            {
                return -1;
            }
            else if (top.right == null)
            {
                return top.item;
            }
            else
            {
                return maxelement(top.right);
            }
        }

        private static int  searchelement(Node root, int v)
        {
            if (root==null)
            {
                Console.WriteLine("\nTree is empty");
                return 0;
            }
            else
            {
                if (root.item==v)
                {
                    
                    return 1;
                }
                else if (v < root.item)
                {
                  return  searchelement(root.left, v);
                }
                else
                {
                  return  searchelement(root.right, v);
                }
            }
        }

        private static void postordertraversal(Node root)
        {
            Node temp = root;
            if (temp!=null)
            {
                postordertraversal(temp.left);
                postordertraversal(temp.right);
                Console.Write(temp.item+" ");
            }
        }

        private static void inordertravesal(Node root)
        {
            Node temp = root;
            if (temp!=null)
            {
                inordertravesal(temp.left);
                Console.Write(temp.item+" "); 
                inordertravesal(temp.right);
            }
        }

        private static void preorder(Node root)
        {
            Node temp = root;
            if (temp!=null)
            {
                Console.Write(temp.item+" ");
                preorder(root.left);
                preorder(root.right);
            }
        }
    }
}
