using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class TreeInfo
    {
        public int diameter { get; set; }
        public int height { get; set; }

        public TreeInfo(int diameter,int height)
        {
            this.diameter = diameter;
            this.height = height;
        }
    }
    public class DiameterTree
    {
        static void Main()
        {
            Tree tree = new Tree(1);
            tree.Left = new Tree(3);
            tree.Right = new Tree(2);
            tree.Left.Left = new Tree(7);
            tree.Left.Left.Left = new Tree(8);
            tree.Left.Left.Left .Left= new Tree(9);
            tree.Left.Right = new Tree(4);
            tree.Left.Right.Right = new Tree(5);
            tree.Left.Right .Right.Right= new Tree(6);
            int n = BinaryTreeDiameter(tree);
            Console.WriteLine(n);
            Console.ReadLine();
        }  
        public static int BinaryTreeDiameter(Tree tree)
        {
            return getTreeInfo(tree).diameter;
        }

        private static TreeInfo getTreeInfo(Tree tree)
        {
            if (tree==null)
            {
                return new TreeInfo(0, 0);
            }
            TreeInfo leftTreeInfo = getTreeInfo(tree.Left);
            TreeInfo rightTreeInfo = getTreeInfo(tree.Right);

            int longestPathThroughRoot = leftTreeInfo.height + rightTreeInfo.height;
            int maxDiameterSofar = Math.Max(leftTreeInfo.diameter, rightTreeInfo.diameter);

            int currentDiameter = Math.Max(longestPathThroughRoot, maxDiameterSofar);
            int currentHeight = 1 + Math.Max(leftTreeInfo.height, rightTreeInfo.height);

            return new TreeInfo(currentDiameter, currentHeight);
        }
    }
}
