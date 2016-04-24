using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EnumerationMazes
{
    class KruskalAlgo
    {

        private List<int> unionFindStructure;
        public List<int> UnionFindStructure
        {
            //set { unionFindStructure = value; }
            get { return unionFindStructure; }
        }
        public KruskalAlgo(List<int> ufs)
        {
			Console.WriteLine ("TEST-INSIDE COMB C#55");
            unionFindStructure = new List<int>(ufs);
			Console.WriteLine ("TEST-INSIDE COMB C#66");
		}

        public int Find(int x)
        {
            List<int> A = unionFindStructure;
            int i = x;
            while (A[i] > -1) i = A[i];
            return i;
        }

        public void union( int a, int b)
        {
			Console.WriteLine ("KRUSKAL C#1");
            List<int> A = unionFindStructure;
            if (A[a] < A[b]) A[b] = a;
            else if (A[a] > A[b]) A[a] = b;
            else
            {
                A[a] = b;
                A[b] = A[b] - 1;
            }
            unionFindStructure = A;
			Console.WriteLine ("KRUSKAL C#2");
        }
    }
}
