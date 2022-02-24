using System;
using System.Collections.Generic;
using System.Text;

namespace TreeDataStructure
{
    public class Tree
    {
        public int Data { get; set; }
        public Tree Left { get; set; }

        public Tree Right { get; set; }

        public Tree(int alpha)
        {
            Data = alpha;
        }
    }
}
