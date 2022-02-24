using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
	public class BinaryTree
	{
		public int value;
		public BinaryTree left = null;
		public BinaryTree right = null;

		public BinaryTree(int value)
		{
			this.value = value;
		}
	}
    public class TreeInfomation
    {
        public bool isBalanced { get; set; }
		public int	height { get; set; }

        public TreeInfomation(bool isBalanced,int height)
        {
			this.isBalanced = isBalanced;
			this.height = height;
        }
	}
	public class Class1
	{
		public static bool HeightBalancedBinaryTree(BinaryTree tree)
		{
			// Write your code here.
			TreeInfomation treeinfo = getTreeInfo(tree);
			return treeinfo.isBalanced;
		}

        private static TreeInfomation getTreeInfo(BinaryTree tree)
        {
            if (tree==null)
            {
				return new TreeInfomation(true, -1);
            }

			TreeInfomation leftsubtreeInfo = getTreeInfo(tree.left);
			TreeInfomation rightsubtreeInfo = getTreeInfo(tree.right);
			bool isBalanced = leftsubtreeInfo.isBalanced && rightsubtreeInfo.isBalanced
					&& Math.Abs(leftsubtreeInfo.height - rightsubtreeInfo.height)<=1;

			int height = Math.Max(leftsubtreeInfo.height, rightsubtreeInfo.height)+1;
			return new TreeInfomation(isBalanced, height);
		}

        public static void Main()
        {
			BinaryTree root = new BinaryTree(1);
			root.left = new BinaryTree(2);
			root.right = new BinaryTree(3);
			root.right.right = new BinaryTree(6);
			root.left.left = new BinaryTree(4);
			root.left.right = new BinaryTree(5);
			root.left.right.left = new BinaryTree(7);
			root.left.right.right = new BinaryTree(8);

			Console.WriteLine(HeightBalancedBinaryTree(root));

			Console.ReadLine();
		}
	}
}
