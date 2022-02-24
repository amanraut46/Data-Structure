using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class Traversal
    {
        public static void SearchElement(Tree root,char item)
        {
            if (root!=null)
            {
                if (root.Data == item)
                    Console.WriteLine("Element found");
                else
                {

                    SearchElement(root.Left,item);
                    SearchElement(root.Right,item);
                }
            }
            
        }
        public static void PreOder(Tree root)
        {
            if (root != null)
            {
                Console.Write(root.Data + " ");
                PreOder(root.Left);
                PreOder(root.Right);
            }
        }
        public static void Inorder(Tree root)
        {
            if (root != null)
            {
                Inorder(root.Left);
                Console.Write(root.Data + " ");
                Inorder(root.Right);
            }
        }
        public static void PostOrder(Tree root)
        {
            if (root != null)
            {
                PostOrder(root.Left);
                PostOrder(root.Right);
                Console.Write(root.Data + " ");

            }
        }
        public static void Main()
        {
            Tree root = new Tree('A');
            Tree l = new Tree('B');
            Tree ll = new Tree('D');

            Tree lr = new Tree('E');
            Tree lrl = new Tree('H');
            Tree lrr = new Tree('I');

            Tree r = new Tree('C');
            Tree rl = new Tree('F');
            Tree rr = new Tree('G');
            Tree rrl = new Tree('J');

            root.Left = l;
            root.Right = r;

            l.Left = ll;
            l.Right = lr;
            ll.Left = null;
            ll.Right = null;

            lr.Left = lrl;
            lr.Right = lrr;

            r.Left = rl;
            r.Right = rr;
            rr.Left = rrl;

            Console.WriteLine("PreOder");
            PreOder(root);
            Console.WriteLine();
            Console.WriteLine("Inorder");
            Inorder(root);
            Console.WriteLine();
            Console.WriteLine("PostOrder");
            PostOrder(root);
            Console.WriteLine();

            SearchElement(root, 'E');

            Console.ReadLine();
        }
    }
}
