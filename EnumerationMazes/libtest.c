/*#include <stdio.h>

void print(const char *message){
	printf("%s\\n", message);
}*/

#include <stdio.h>
#include <stdlib.h>
	#include <fcntl.h>
	#include <unistd.h>

#include <CL/cl.h>

     
#define WA 1024
#define HA 1024
#define WB 1024

#define HB WA
#define WC WB
#define HC HA

    /*int print(const char *message)
    {
    	printf("%s\\n", message);
    	fflush(stdout);

	    cl_device_id device_id = NULL;

	    cl_context context = NULL;
	    cl_command_queue command_queue = NULL;
	    cl_mem memobj = NULL;
	    cl_program program = NULL;
	    cl_kernel kernel = NULL;
	    cl_platform_id platform_id = NULL;
	    cl_uint ret_num_devices;
	    cl_uint ret_num_platforms;
	    cl_int ret;
	     
	    char string[MEM_SIZE];
	     
	    FILE *fp;
	    char fileName[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/hello.cl";
	    char *source_str;
	    size_t source_size;
	     
	 //   /* Load the source code containing the kernel
	    fp = fopen(fileName, "r");
	    if (!fp) {
		    fprintf(stderr, "Failedddd to load kernel.\n");
		    exit(1);
	    }
	    source_str = (char*)malloc(MAX_SOURCE_SIZE);
	    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	    fclose(fp);
	     
	 //   /* Get Platform and Device Info 
	    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);
	     
	 //   /* Create OpenCL context 
	    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	     
	    /* Create Command Queue 
	    command_queue = clCreateCommandQueue(context, device_id, 0, &ret);
	     
	    /* Create Memory Buffer 
	    memobj = clCreateBuffer(context, CL_MEM_READ_WRITE, MEM_SIZE * sizeof(char), NULL, &ret);
	     
	    /* Create Kernel Program from the source 
	    program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);
	     
	    /* Build Kernel Program 
	    ret = clCreateBufferBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	     
	    /* Create OpenCL Kernel 
	    kernel = clCreateKernel(program, "hello", &ret);
	     
	    /* Set OpenCL Kernel Parameters 
	    ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&memobj);
	     
	    /* Execute OpenCL Kernel 
	    ret = clEnqueueTask(command_queue, kernel, 0, NULL,NULL);
	     
	    /* Copy results from the memory buffer 
	    ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0, MEM_SIZE * sizeof(char), string, 0, NULL, NULL);
	     
	    /* Display Result 
	    puts(string);
	     
	    /* Finalization 
	    ret = clFlush(command_queue);
	    ret = clFinish(command_queue);
	    ret = clReleaseKernel(kernel);
	    ret = clReleaseProgram(program);
	    ret = clReleaseMemObject(memobj);
	    ret = clReleaseCommandQueue(command_queue);
	    ret = clReleaseContext(context);
	    fflush(stdout);
	    free(source_str);
	     
	    return 0;
    }
*/

    void randomMemInit(int* data, int size)
{
   int i;

   for (i = 0; i < size; ++i)
   	data[i] = rand() / (int)RAND_MAX;
}

long LoadOpenCLKernel(char const* path, char **buf)
{
    FILE  *fp;
    size_t fsz;
    long   off_end;
    int    rc;

    /* Open the file */
    fp = fopen(path, "r");
    if( NULL == fp ) {
        return -1L;
    }

    /* Seek to the end of the file */
    rc = fseek(fp, 0L, SEEK_END);
    if( 0 != rc ) {
        return -1L;
    }

    /* Byte offset to the end of the file (size) */
    if( 0 > (off_end = ftell(fp)) ) {
        return -1L;
    }
    fsz = (size_t)off_end;

    /* Allocate a buffer to hold the whole file */
    *buf = (char *) malloc( fsz+1);
    if( NULL == *buf ) {
        return -1L;
    }

    /* Rewind file pointer to start of file */
    rewind(fp);

    /* Slurp file into buffer */
    if( fsz != fread(*buf, 1, fsz, fp) ) {
        free(*buf);
        return -1L;
    }

    /* Close the file */
    if( EOF == fclose(fp) ) {
        free(*buf);
        return -1L;
    }


    /* Make sure the buffer is NUL-terminated, just in case */
    (*buf)[fsz] = '\0';

    /* Return the file size */
    return (long)fsz;
}
    

  /*  void passArray(int array[], int size)
    {
    	//int i=0;
    	//for(i=0; i< size; i++){
    	//	printf("%d bhavya", array[i]);
    	//	fflush(stdout);
    	//}
		
//    	StreamWriter textFile = new StreamWriter("pkim.txt");
//        BinaryWriter bwFile = new BinaryWriter(new FileStream("pkim", FileMode.Create));


		FILE *fpTxt;
		FILE *fpBin;
	    char fileName[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavTxt";
	    char fileName1[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavBin";
//	    char *source_str;
//	    size_t source_size;
	     
//	    /* Load the source code containing the kernel
	    fpTxt = fopen(fileName, "w");
	    fpBin = fopen(fileName, "wb");
	    if (!fpTxt) {
		    fprintf(stderr, "Failedddd to load TextFile.\n");
		    exit(1);
	    }
	    if (!fpBin) {
		    fprintf(stderr, "Failedddd to load BinaryFile.\n");
		    exit(1);
	    }
//	    source_str = (char*)malloc(MAX_SOURCE_SIZE);
//	    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	   
/*    	int VHMatinOneInt = 0;					This is what I have commented!!!!!!!!!!!!!!!!!!!!!!1
        //foreach (int item in result)
          //              //textFile.Write(item+" ");
        int i=0;
        for(i = 0; i < size; i++){
          	VHMatinOneInt += intPow(2, array[i]);
        }
        fwrite(&VHMatinOneInt, sizeof(VHMatinOneInt), 1, fpTxt);        ENTER COMMENT HERE MULTILINE END
        
        //textFile.Write(VMatinOneInt);
        //textFile.WriteLine();


        
		 // This code executes on the OpenCL host
    
    // Host data
    int *A = NULL;  // Input array
    //int B = NULL;  // Input array
    int *VHMatinOneInt = 0;
    int *C = NULL;  // Output array
    
    // Elements in each array
    const int elements = size;   
    
    // Compute the size of the data 
    size_t datasize = sizeof(int)*elements;
    size_t datasizeVHMat = sizeof(int);

    // Allocate space for input/output data
    A = (int*)malloc(datasize);
    //B =	 (int*)malloc(datasize);
    C = (int*)malloc(datasize);						//---------------------CHECK------------------------
    // Initialize the input data
    for(int i = 0; i < elements; i++) {
        A[i] = array[i];
        //B[i] = i;
    }

    // Use this to check the output of each API call
    cl_int status;  
     
    //-----------------------------------------------------
    // STEP 1: Discover and initialize the platforms
    //-----------------------------------------------------
    
    cl_uint numPlatforms = 0;
    cl_platform_id *platforms = NULL;
    
    // Use clGetPlatformIDs() to retrieve the number of 
    // platforms
    status = clGetPlatformIDs(0, NULL, &numPlatforms);
 
    // Allocate enough space for each platform
    platforms =   
        (cl_platform_id*)malloc(
        	numPlatforms*sizeof(cl_platform_id));
 
    // Fill in platforms with clGetPlatformIDs()
    status = clGetPlatformIDs(
    	numPlatforms, 
    	platforms, 
    	NULL);

    //-----------------------------------------------------
    // STEP 2: Discover and initialize the devices
    //----------------------------------------------------- 
    
    cl_uint numDevices = 0;
    cl_device_id *devices = NULL;

    // Use clGetDeviceIDs() to retrieve the number of 
    // devices present
    status = clGetDeviceIDs(
        platforms[0], 
        CL_DEVICE_TYPE_ALL, 
        0, 
        NULL, 
        &numDevices);

    // Allocate enough space for each device
    devices = 
        (cl_device_id*)malloc(
            numDevices*sizeof(cl_device_id));

    // Fill in devices with clGetDeviceIDs()
    status = clGetDeviceIDs(
        platforms[0], 
        CL_DEVICE_TYPE_ALL,        
        numDevices, 
        devices, 
        NULL);

    if (status != CL_SUCCESS)
   {
       printf("Error: Failed to create a device group!\n");
       //return EXIT_FAILURE;
   }

    //-----------------------------------------------------
    // STEP 3: Create a context
    //----------------------------------------------------- 
    
    cl_context context = NULL;

    // Create a context using clCreateContext() and 
    // associate it with the devices
    context = clCreateContext(
        NULL, 
        numDevices, 
        devices, 
        NULL, 
        NULL, 
        &status);

    //-----------------------------------------------------
    // STEP 4: Create a command queue
    //----------------------------------------------------- 
    
    cl_command_queue cmdQueue;

    // Create a command queue using clCreateCommandQueue(),
    // and associate it with the device you want to execute 
    // on
    cmdQueue = clCreateCommandQueue(
        context, 
        devices[0], 
        0, 
        &status);

    //-----------------------------------------------------
    // STEP 5: Create device buffers
    //----------------------------------------------------- 
    
    cl_mem bufferA;  // Input array on the device
    cl_mem bufferVHMat;  // Input array on the device
    cl_mem bufferC;  // Output array on the device

    // Use clCreateBuffer() to create a buffer object (d_A) 
    // that will contain the data from the host array A
    bufferVHMat = clCreateBuffer(
        context, 
        CL_MEM_READ_ONLY,                         
        datasizeVHMat, 
        NULL, 
        &status);

    // Use clCreateBuffer() to create a buffer object (d_B)
    // that will contain the data from the host array B
    bufferA = clCreateBuffer(
        context, 
        CL_MEM_READ_ONLY,                         
        datasize, 
        NULL, 
        &status);

    // Use clCreateBuffer() to create a buffer object (d_C) 
    // with enough space to hold the output data
    bufferC = clCreateBuffer(											//----------------------------------CHECK------------------------
        context, 
        CL_MEM_WRITE_ONLY,                 
        datasize, 
        NULL, 
        &status);
    
    //-----------------------------------------------------
    // STEP 6: Write host data to device buffers
    //----------------------------------------------------- 
    
    // Use clEnqueueWriteBuffer() to write input array A to
    // the device buffer bufferA
    
    status = clEnqueueWriteBuffer(
        cmdQueue, 
        bufferA, 
        CL_FALSE, 
        0, 
        datasize,                         
        A, 
        0, 
        NULL, 
        NULL);
    
    // Use clEnqueueWriteBuffer() to write input array B to 
    // the device buffer bufferVHMat
    status = clEnqueueWriteBuffer(
        cmdQueue, 
        bufferVHMat, 
        CL_FALSE, 
        0, 
        datasizeVHMat,                                  
        VHMatinOneInt, 
        0, 
        NULL, 
        NULL);

    //-----------------------------------------------------
    // STEP 7: Create and compile the program
    //----------------------------------------------------- 
     
    // Create a program using clCreateProgramWithSource()


	    FILE *fp;
	    char fileName2[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/sample.cl";
	    char *source_str;
	    size_t source_size;
	     
	//    /* Load the source code containing the kernel
	    fp = fopen(fileName2, "r");
	    if (!fp) {
		    fprintf(stderr, "Failedddd to load kernel.\n");
		    exit(1);
	    }
	    source_str = (char*)malloc(MAX_SOURCE_SIZE);
	    source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	    fclose(fp);


    cl_program program = clCreateProgramWithSource(
        context, 
        1, 
        (const char**)&source_str,                                 
        (const size_t *)&source_size, 
        &status);

    // Build (compile) the program for the devices with
    // clBuildProgram()
    status = clBuildProgram(
        program, 
        numDevices, 
        devices, 
        NULL, 
        NULL, 
        NULL);
   
    //-----------------------------------------------------
    // STEP 8: Create the kernel
    //----------------------------------------------------- 

    cl_kernel kernel = NULL;

    // Use clCreateKernel() to create a kernel from the 
    // vector addition function (named "vecadd")
    kernel = clCreateKernel(program, "kruskal", &status);

    //-----------------------------------------------------
    // STEP 9: Set the kernel arguments
    //----------------------------------------------------- 
    
    // Associate the input and output buffers with the 
    // kernel 
    // using clSetKernelArg()
    status  = clSetKernelArg(
        kernel, 
        0, 
        sizeof(cl_mem), 
        &bufferA);
    status |= clSetKernelArg(
        kernel, 
        1, 
        sizeof(cl_mem), 
        &bufferVHMat);
    /*status |= clSetKernelArg(
        kernel, 
        2, 
        sizeof(cl_mem), 
        &bufferC);   												 ENTER MULTILINE END HERE

    //-----------------------------------------------------
    // STEP 10: Configure the work-item structure
    //----------------------------------------------------- 
    
    // Define an index space (global work size) of work 
    // items for 
    // execution. A workgroup size (local work size) is not 
    // required, 
    // but can be used.
    size_t globalWorkSize[1];    
    // There are 'elements' work-items 
    globalWorkSize[0] = elements;

    //-----------------------------------------------------
    // STEP 11: Enqueue the kernel for execution
    //----------------------------------------------------- 
    
    // Execute the kernel by using 
    // clEnqueueNDRangeKernel().
    // 'globalWorkSize' is the 1D dimension of the 
    // work-items
    status = clEnqueueNDRangeKernel(
        cmdQueue, 
        kernel, 
        1, 
        NULL, 
        globalWorkSize, 
        NULL, 
        0, 
        NULL, 
        NULL);

    //-----------------------------------------------------
    // STEP 12: Read the output buffer back to the host
    //----------------------------------------------------- 
    
    // Use clEnqueueReadBuffer() to read the OpenCL output  
    // buffer (bufferC) 
    // to the host output array (C)
    
    clEnqueueReadBuffer(
        cmdQueue, 
        bufferVHMat, 
        CL_TRUE, 
        0, 
        datasizeVHMat, 
        VHMatinOneInt, 
        0, 
        NULL, 
        NULL);

    // Verify the output


	fwrite(&bufferVHMat, sizeof(bufferVHMat), 1, fpBin);
    fwrite(&VHMatinOneInt, sizeof(VHMatinOneInt), 1, fpBin);
       

/*    bool result = true;
    for(int i = 0; i < elements; i++) {
        if(C[i] != i+i) {
            result = false;
            break;
        }
    }
    if(result) {
        printf("Output is correct\n");
    } else {
        printf("Output is incorrect\n");
    }											ENTER MULTILINE END HERE

    //-----------------------------------------------------
    // STEP 13: Release OpenCL resources
    //----------------------------------------------------- 
    
    // Free OpenCL resources
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQueue);
    clReleaseMemObject(bufferA);
    clReleaseMemObject(bufferVHMat);
    clReleaseMemObject(bufferC);
    clReleaseContext(context);

    // Free host resources
    free(A);
//	    free(B);
    free(C);
    free(platforms);
    free(devices);

    printf("Bhavya1");
    fflush(stdout);

        //bwFile.Write(VMatinOneInt);
                    //Console.Write(VMatinOneInt);
                    //Console.WriteLine();
                    //textFile.WriteLine();
                   
                    //Console.Write("HMat: ");
                    //textFile.Write("HMat: ");
        /*int HMatinOneInt = 0;
        foreach (int item in result2)
                    //textFile.Write(item+" ");
            HMatinOneInt += intPow(2, item);
            textFile.Write(HMatinOneInt);
            textFile.WriteLine();
            bwFile.Write(HMatinOneInt);					ENTER MULTILINE END HERE
        fclose(fpTxt);
        fclose(fpBin);
    }*/
//int main(int argc, char** argv)
int passArray(int array[], int size)
{
//	printf("Bhav %d", size);

	const int elements = size;   
    
    // Compute the size of the data 
    size_t datasize = sizeof(int)*elements;
    size_t datasizeVHMat = sizeof(int);


	FILE *fpTxt;
	FILE *fpBin;
    char fileName[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavTxt.txt";
    char fileName1[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavBin.bin";
//	    char *source_str;
//	    size_t source_size;
	     
//	    /* Load the source code containing the kernel
    fpTxt = fopen(fileName, "w");
    fpBin = fopen(fileName, "wb");
    if (!fpTxt) {
	    fprintf(stderr, "Failedddd to load TextFile.\n");
	    exit(1);
    }
    if (!fpBin) {
	    fprintf(stderr, "Failedddd to load BinaryFile.\n");
	    exit(1);
    }


   return 0;

}