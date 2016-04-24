using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EnumerationMazes
{
    class EnumerateVMat
    {

        private List<List<int>> results = new List<List<int>>();

        public List<List<int>> Results
        {
            get { return results; }
        }

        public void combinations(List<int> arr, int len, int startPosition, List<int> result)
        {
            if (len == 0)
            {
                List<int> resultIndex = new List<int>();
                foreach (int item in result)
                {
                    //Console.Write(item + " ");
                    resultIndex.Add(item);
                }
                //Console.WriteLine();
                results.Add(resultIndex);
                return;
            }
            for (int i = startPosition; i <= arr.Count - len; i++)
            {
                result[result.Count - len] = arr[i];
                combinations(arr, len - 1, i + 1, result);
            }
        }
    }
}
