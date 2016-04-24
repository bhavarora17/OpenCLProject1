using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EnumerationMazes
{
    class EnumerateHMat
    {
        //private KruskalAlgo kruskal = new KruskalAlgo();
        private List<int> unionFindStructureFromVMat = new List<int>();
        private List<List<int>> results = new List<List<int>>();
        private bool acceptEdge = true;
        private int widthIndex;
        private int heightIndex;

        public List<List<int>> Results
        {
            get { return results; }
        }

        public EnumerateHMat(List<int> vmatIndex, int width, int height)
        {
            widthIndex = width;
            heightIndex = height;

            KruskalAlgo kruskal = new KruskalAlgo(Enumerable.Repeat(-1, widthIndex * heightIndex).ToList());
            //kruskal.UnionFindStructure = Enumerable.Repeat(-1, widthIndex * heightIndex).ToList();

            foreach (int item in vmatIndex)
            {
                int endPt1 = item;
                int endPt2 = item + width;
                int endPt1Root = kruskal.Find(endPt1);
                int endPt2Root = kruskal.Find(endPt2);
                if (endPt1Root != endPt2Root)
                {
                    kruskal.union(endPt1Root, endPt2Root);
                }
            }
            unionFindStructureFromVMat = kruskal.UnionFindStructure;
            //foreach (int item1 in unionFindStructureFromVMat)
            //    Console.Write(item1 + " ");
            //Console.WriteLine();
        }

        public void combinations(List<int> arr, int len, int startPosition, List<int> result)
        {
			Console.WriteLine ("TEST-INSIDE COMB C#1");
			if (len == 0)
            {
				Console.WriteLine ("TEST-INSIDE COMB C#2");
                List<int> resultIndex = new List<int>();
				Console.WriteLine ("TEST-INSIDE COMB C#2.5");
                KruskalAlgo kruskal = new KruskalAlgo(unionFindStructureFromVMat);
				Console.WriteLine ("TEST-INSIDE COMB C#2.75");
				//kruskal.UnionFindStructure = unionFindStructureFromVMat;
                acceptEdge = true;

                foreach (int item in result)
                {
					Console.WriteLine ("TEST-INSIDE COMB C#3");
                    int endPt1 = item / (widthIndex - 1) * widthIndex + item % (widthIndex - 1);
                    int endPt2 = endPt1 + 1;
                    int endPt1Root = kruskal.Find(endPt1);
                    int endPt2Root = kruskal.Find(endPt2);
					Console.WriteLine ("TEST-INSIDE COMB C#3.5");
					if (endPt1Root != endPt2Root)
                    {
						Console.WriteLine ("TEST-INSIDE COMB C#3.6");
                        kruskal.union(endPt1Root, endPt2Root);
						Console.WriteLine ("TEST-INSIDE COMB C#3.65");
                        resultIndex.Add(item);
						Console.WriteLine ("TEST-INSIDE COMB C#3.7");
                    }
                    else
                        acceptEdge = false;
					Console.WriteLine ("TEST-INSIDE COMB C#3.75");
                }
                if(acceptEdge)
                    results.Add(resultIndex);
				Console.WriteLine ("TEST-INSIDE COMB C#4");
				return;
            }
			Console.WriteLine ("TEST-INSIDE COMB C#5");
			for (int i = startPosition; i <= arr.Count - len; i++) {
				result [result.Count - len] = arr [i];
				combinations (arr, len - 1, i + 1, result);
			}

        }
    }
}