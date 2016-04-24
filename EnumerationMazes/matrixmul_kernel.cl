
/* kernel.cl 
 * Matrix multiplication: C = A * B.
 * Device code.
 */
 
// OpenCL Kernel
/*
__kernel void
matrixMul(__global float* C, 
          __global float* A,  
          int wA)
{
//  printf("Bhavya1");
  
  int tx = get_global_id(0); 
   int ty = get_global_id(1);
 
   // value stores the element that is 
   // computed by the thread
   float value = 0;
   for (int k = 0; k < wA; ++k)
   {

      float elementA = A[ty * wA + k];
//      printf("BHAVYA %f", elementA);
   }
 
   // Write the matrix to device memory each 
   // thread writes one element
   C[ty * wA + tx] = value; 
}
*/
int init(){
	return 0;
}
int intPow(int x, float y)
{
    int result = 1;
    int i=0;
    for (i = 0; i < y; i++)
        result *= x;
    return result;
}

__kernel void matrixMul(__global int *C, __global int* A, int size, __global int* sizeAr){//, __global int VHMatinOneInt){

//    printf("%d", size);
//    C[0] = init();
    int idx = get_global_id(0);
    int i=0;
	
	if(idx < size){
		for(i = 0; i < sizeAr[i] ; i++){
			printf("HERE");
			//printf("BHAVYA");
			//printf(" %dbb",A[i]);
			//if(idx<size){
			//printf(" %d-size \n", size);
			
			C[idx] = C[idx] + intPow(2, A[i+sizeAr[idx]]);
			printf("C[%d]-%d",idx,C[idx]);
			
			//printf("idx- %d  \n",idx);
											//printf("%d yoyo\n", C[0]);
		} 
    }
   
//    barrier(CLK_LOCAL_MEM_FENCE | CLK_GLOBAL_MEM_FENCE);
}
