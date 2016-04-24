using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace EnumerationMazes
{
    class Program
    {
		//[DllImport("libtest.so", EntryPoint="print")]
		[DllImport("libtest1.so", EntryPoint="passArray")]
		//static extern void print(string message);
		static extern void passArray (int[] array, int size, int[] sizeArray);
        


		static int mainThreadId;

		static int k=0;
		static void Main(string[] args)
        {
			//print("Hello World c# => C++");
			// In Main method:
			mainThreadId = System.Threading.Thread.CurrentThread.ManagedThreadId;

			// If called in the non main thread, will return false;



            int width = 5;//int.Parse(args[0]);//4
            int height = 5;//int.Parse(args[1]);//4

            int numberOfElementsVMat = 0;
            int numberOfElementsHMat = 0;

            //for (int i = width - 1; i < height * (width - 1) + 1; i++)
            //{
            //    numberOfElementsHMat = i;
            //    numberOfElementsVMat = height * width - 1 - i;
            //    Console.WriteLine("VMat: " + numberOfElementsVMat + " HMat: " + numberOfElementsHMat);
            //    EnumerateMaze(width, height, numberOfElementsVMat, numberOfElementsHMat);
            //    Console.WriteLine();
            //}

//            StreamWriter textFile = new StreamWriter("pkim.txt");
//            BinaryWriter bwFile = new BinaryWriter(new FileStream("pkim", FileMode.Create));

            for (int i = width - 1; i < height * (width - 1) + 1; i++)
			//for (int i = width - 1; i <= (width - 1) + 1; i++)  //farzi
			{
                numberOfElementsHMat = i;//int.Parse(args[2]);
                numberOfElementsVMat = height * width - 1 - i;//int.Parse(args[2]);
                Console.WriteLine("VMat: " + numberOfElementsVMat + " HMat: " + numberOfElementsHMat+"---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
				EnumerateMaze (width, height, numberOfElementsVMat, numberOfElementsHMat);//, textFile,bwFile);
                Console.WriteLine();
            }

//            textFile.Close();
//            bwFile.Close();
            //Console.ReadKey();
        }

        static int intPow(int x, int y)
        {
            int result = 1;
            for (int i = 0; i < y; i++)
                result *= x;

            return result;
        }

		public static bool IsMainThread()
		{
			return System.Threading.Thread.CurrentThread.ManagedThreadId == mainThreadId;
		}

		static void EnumerateMaze (int width, int height, int numberOfElementsVMat, int numberOfElementsHMat)//, StreamWriter textFile, BinaryWriter bwFile)
		{

			int VIndex = (height - 1) * width;
			int HIndex = (width - 1) * height;

			List<int> VMatIndex = Enumerable.Range (0, VIndex).ToList ();
			List<int> HMatIndex = Enumerable.Range (0, HIndex).ToList ();
			//List<int> HMatSplitStartIndex = new List<int> { 0, 1, 3 };//where split is start
			//List<int> HMatSplitEndIndex = new List<int> {0, 2, 5};//where split is end

			if (IsMainThread()) {
				Console.WriteLine ("TEST C#1");
				EnumerateVMat VMatHandler = new EnumerateVMat ();
				Console.WriteLine ("TEST C#2");
				VMatHandler.combinations (VMatIndex, numberOfElementsVMat, 0, new int[numberOfElementsVMat].ToList ());
				Console.WriteLine ("TEST C#3");
				foreach (List<int> result in VMatHandler.Results) {

					EnumerateHMat HMatHandler = new EnumerateHMat (result, width, height);
					Console.WriteLine ("TEST C#4");
					HMatHandler.combinations (HMatIndex, numberOfElementsHMat, 0, new int[numberOfElementsHMat].ToList ());
					Console.WriteLine ("TEST C#5");
					//  foreach (List<int> result2 in HMatHandler.Results)
					//  {
					//	Console.WriteLine ("FunctionCalled!!!!");
					int VMatSize = VMatHandler.Results.Count;
					int HMatSize = HMatHandler.Results.Count;

					int[] VMatArraySize = new int[VMatHandler.Results.Count];
					int[] HMatArraySize = new int[HMatHandler.Results.Count];
					
					int[][] VMatArray = new int[VMatHandler.Results.Count][];
			


					int totalSizeV = 0;
					for (int i = 0; i < VMatHandler.Results.Count; i++) {
						List<int> sublist = VMatHandler.Results.ElementAt (i);
						VMatArray [i] = new int[sublist.Count];
						VMatArraySize [i] = sublist.Count;
						for (int j = 0; j < sublist.Count; j++) {
							totalSizeV += sublist.Count;
							VMatArray [i] [j] = sublist.ElementAt (j);
						}
					}
					int counter = 0;
					int[] flattened = new int[totalSizeV];
					//Console.WriteLine("YOYO"+totalSizeV);
					for (int i = 0; i < VMatArray.Length; i++) {
						for (int a = 0; a < VMatArray [i].Length; a++) {

							flattened [counter] = VMatArray [i] [a];
							//	Console.WriteLine (counter + "-" +flattened [counter]);
							//Console.WriteLine(VMatArray[i][a]);
							//Console.WriteLine ("Bhavya"+ flattened [counter]);
							counter++;
						}
						//Console.WriteLine("----------------------------------------------------------------");
					}

					int[][] HMatArray = new int[HMatHandler.Results.Count][];

					int totalSizeH = 0;
					for (int i = 0; i < HMatHandler.Results.Count; i++) {
						List<int> sublist = HMatHandler.Results.ElementAt (i);
						HMatArray [i] = new int[sublist.Count];
						HMatArraySize [i] = sublist.Count;
						for (int j = 0; j < sublist.Count; j++) {
							HMatArray [i] [j] = sublist.ElementAt (j);
							totalSizeH += sublist.Count;
							//Console.WriteLine (HMatArray[i][j]);
						}
					}
					counter = 0;
					int[] flattened1 = new int[totalSizeH];
					for (int i = 0; i < HMatArray.Length; i++) {
						for (int a = 0; a < HMatArray [i].Length; a++) {

							flattened1 [counter] = HMatArray [i] [a];
							//Console.WriteLine (counter + "-" +flattened1 [counter]);
							counter++;
						}
						//					Console.WriteLine("--------------------------------------------------------------");
					}

					//Console.WriteLine (VMatArray.Length);
					//Console.WriteLine ("BHAVYA" + VMatHandler.Results.Count);
					//Console.WriteLine ("BHAVYA" + HMatHandler.Results.Count);

					//for (int i = 0; i < VMatArray.Length; i++) {
					//	for (int j = 0; j < VMatArray[i].Length; j++) {
					//		Console.WriteLine (VMatArray [i][j]);
					//	}
					//}
					
					//		int[] arrResult = result.ToArray ();
					//		int[] arrResult2 = result2.ToArray ();
					//		int size1 = arrResult.Length;
//			int size2 = arrResult2.Length;
//			passArray (arrResult, size1);
//			Console.WriteLine();
//			passArray (arrResult2, size2);
					//Console.WriteLine("BHAVYA");
					Console.WriteLine ("BEFORE");
					passArray (flattened, VMatSize, VMatArraySize);
					//Console.WriteLine ();
					passArray (flattened1, HMatSize, HMatArraySize);
					//Console.WriteLine ();
					Console.WriteLine ("AFTER");
//			if (!(k < 2)) {
//				Environment.Exit (0);
//			}
//			k++;
					//Console.Write("VMat: ");
					//textFile.Write("VMat: ");
//                    int VMatinOneInt = 0;
//                    foreach (int item in result)
					//textFile.Write(item+" ");
//                    	VMatinOneInt += intPow(2, item);
//                    textFile.Write(VMatinOneInt);
//                    textFile.WriteLine();
//                    bwFile.Write(VMatinOneInt);
					//Console.Write(VMatinOneInt);
					//Console.WriteLine();
					//textFile.WriteLine();
                   
					//Console.Write("HMat: ");
					//textFile.Write("HMat: ");
//                    int HMatinOneInt = 0;
//                    foreach (int item in result2)
					//textFile.Write(item+" ");
//                        HMatinOneInt += intPow(2, item);
//                    textFile.Write(HMatinOneInt);
//                    textFile.WriteLine();
//                    bwFile.Write(HMatinOneInt);
					//Console.Write(HMatinOneInt);
					//Console.WriteLine();
					//textFile.WriteLine();
//                }
					HMatHandler.combinations(matIndex, numberOfElementsHMat, HMatSplitStartIndex, HMatSplitEndIndex, new int[numberOfElementsHMat].ToList());
				}
			}
		}
    }
}