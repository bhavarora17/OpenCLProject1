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
int passArray(int *array, int size, int sizeArray[])
{
	int k = 0;
	
	
	int **twoDArr = (int **)malloc(size * sizeof(int*)); 
	//fflush(stdout);
//	printf("Bhav %d", size);
	int counter = 0;
	if(k==1)    
	printf("TESTING---------123");
		for(int i=0;i<size;i++){
			twoDArr[i] = (int*)malloc(sizeArray[i] * sizeof(int));
			for(int j=0; j<sizeArray[i]; j++){
				twoDArr[i][j]=array[counter++];
				if(k==1)
				printf("%d - %d \n", counter, twoDArr[i][j]);
			}
			//printf("\n------------------------- \n ");
		}
 //   printf("TEST123");

	const int elements = size;   
	
//	for(int i=0; i< elements && i<10; i++){
//		printf("%d", array[i]);
//	}
    
    // Compute the size of the data 
    size_t datasize = sizeof(int)*elements;
    size_t datasizeVHMat = sizeof(int);
	if(k==1)
	printf("-5 TEST \n");
	fflush(stdout);


	FILE *fpTxt;
	FILE *fpBin;
    char fileName[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavTxt.txt";
    char fileName1[] = "/home/bhavya/Downloads/Enumeration/EnumerationMazes/bhavBin.bin";
//	    char *source_str;
//	    size_t source_size;
	     
//	    /* Load the source code containing the kernel
  



  /*  fpTxt = fopen(fileName, "w");
    fpBin = fopen(fileName, "wb");
    if (!fpTxt) {
	    fprintf(stderr, "Failedddd to load TextFile.\n");
	    exit(1);
    }*/


/*    if (!fpBin) {
	    fprintf(stderr, "Failedddd to load BinaryFile.\n");
	    exit(1);
    }*/

   int err;                            // error code returned from api calls

   cl_device_id device_id;             // compute device id 
   cl_context context;                 // compute context
   cl_command_queue commands;          // compute command queue
   cl_program program;                 // compute program
   cl_kernel kernel;                   // compute kernel

    // OpenCL device memory for matrices
   cl_mem d_A;
   cl_mem d_sizeAr;
   cl_mem d_C;

   // set seed for rand()
   srand(2014);
	if(k==1)
 	printf("-4 TEST \n");
	fflush(stdout);

   //Allocate host memory for matrices A and B
   unsigned int size_A = 1;
   unsigned int mem_size_A = sizeof(int) * (counter);//datasize;//sizeof(float) * size_A;
   int* h_A = (int*) malloc(mem_size_A);
   if(k==1)
   	printf("-3 TEST \n");
	fflush(stdout);

   
   //unsigned int size_sizeArr = sizeArray;
   unsigned int mem_size_sizeAr = sizeof(int) * (size);//(counter);
   int* h_sizeAr = (int*) malloc(mem_size_sizeAr);
 if(k==1)
 	printf("-2.5 TEST \n");
	fflush(stdout);

/*   unsigned int size_B = WB * HB;
   unsigned int mem_size_B = sizeof(float) * size_B;
   float* h_B = (float*) malloc(mem_size_B);*/

   //Initialize host memory
   
   //randomMemInit(h_A, size_A);

   counter=0;
   for(int i = 0; i < elements; i++) {
		for(int j=0;j<sizeArray[i];j++){
			//printf("-2.25 TEST \n");
			fflush(stdout);
			h_A[counter] = array[counter];
			counter++;
			//printf("%d",h_A[i][j]);
			//B[i] = i;
		}
    }
if(k==1)
	printf("-2 TEST \n");
	fflush(stdout);
	unsigned int size1 = sizeof(int) * (size); 
    
    int *startingPoint = (int*)malloc(size1);
	if(k==1)
	printf("-1.5 TEST \n");
	fflush(stdout);

    startingPoint[0]=0;
    for(int i=1; i<size; i++){
	//	printf("-1.25 TEST \n");
	//	fflush(stdout);
		startingPoint[i]=startingPoint[i-1]+sizeArray[i]+1;
		printf("StartingPoint - %d \n",startingPoint[i]);
	}
	if(k==1)
		printf("-1 TEST \n");
	fflush(stdout);

	
	for(int i=0; i <size; i++){
		h_sizeAr[i]=startingPoint[i];
//		printf("%d -sizeAr",h_sizeAr[i]);
    }

    //printf("BHAVYA123");
    //fflush(stdout);
    //printf("%d",h_sizeAr[size-1]);
    //fflush(stdout);
    //printf("BHAVYA456");
    //fflush(stdout);

//   randomMemInit(h_B, size_B);
 
   //Allocate host memory for the result C
   
   //unsigned int size_C = WC * HC;
   unsigned int mem_size_C = sizeof(int) * size;
   int* h_C = (int*) malloc(mem_size_C);
	if(k==1)
   printf("Initializing OpenCL device...\n"); 

   cl_uint dev_cnt = 0;
   clGetPlatformIDs(0, 0, &dev_cnt);
	
   cl_platform_id platform_ids[100];
   clGetPlatformIDs(dev_cnt, platform_ids, NULL);
   cl_uint numDevices = 0;
   cl_device_id *devices = NULL;
	
	if(k==1)
	printf("1 TEST \n");
	fflush(stdout);
   // Connect to a compute device
   int gpu = 1;
   //err = clGetDeviceIDs(platform_ids[0], gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
   
    err = clGetDeviceIDs(
        platform_ids[0], 
        CL_DEVICE_TYPE_ALL, 
        0, 
        NULL, 
        &numDevices);
if(k==1)
	printf("2 TEST \n");
	fflush(stdout);


    // Allocate enough space for each device
    devices = 
        (cl_device_id*)malloc(
            numDevices*sizeof(cl_device_id));

    // Fill in devices with clGetDeviceIDs()
    err = clGetDeviceIDs(
        platform_ids[0], 
        CL_DEVICE_TYPE_ALL,        
        numDevices, 
        &device_id, 
        NULL);
if(k==1)
	printf("3 TEST \n");
	fflush(stdout);

   if (err != CL_SUCCESS)
   {
       printf("Error: Failed to create a device group!\n");
       fflush(stdout);
       return EXIT_FAILURE;
   }
  
  if(k==1)
  	printf("4 TEST \n");
	fflush(stdout);

   // Create a compute context 
   context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if(k==1)
    printf("4.5 TEST \n");
	fflush(stdout);
   if (!context)
   {
       printf("Error: Failed to create a compute context!\n");
       fflush(stdout);
       return EXIT_FAILURE;
   }
if(k==1)
	printf("5 TEST \n");
	fflush(stdout);

   // Create a command commands
   commands = clCreateCommandQueue(context, device_id, 0, &err);
   if (!commands)
   {
       printf("Error: Failed to create a command commands!\n");
       return EXIT_FAILURE;
   }
if(k==1)
	printf("6 TEST \n");
	fflush(stdout);

   // Create the compute program from the source file
   char *KernelSource;
   long lFileSize;

   lFileSize = LoadOpenCLKernel("/home/bhavya/Downloads/Enumeration/EnumerationMazes/matrixmul_kernel.cl", &KernelSource);
   if( lFileSize < 0L ) {
       perror("File read failed");
       return 1;
   }
   if(k==1)
   	printf("7 TEST \n");
	fflush(stdout);


   program = clCreateProgramWithSource(context, 1, (const char **) & KernelSource, NULL, &err);
   if (!program)
   {
       printf("Error: Failed to create compute program!\n");
       return EXIT_FAILURE;
   }
   if(k==1)
   	printf("8 TEST \n");
	fflush(stdout);


   // Build the program executable
   err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
   if (err != CL_SUCCESS)
   {
       size_t len;
       char buffer[2048];
       printf("Error: Failed to build program executable!\n");
       clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
       printf("%s\n", buffer);
       exit(1);
   }
if(k==1)
	printf("9 TEST \n");
	fflush(stdout);

   // Create the compute kernel in the program we wish to run
   //
   kernel = clCreateKernel(program, "matrixMul", &err);
   if (!kernel || err != CL_SUCCESS)
   {
       printf("Error: Failed to create compute kernel!\n");
       exit(1);
   }
   if(k==1){
   	printf("9 TEST \n");
	fflush(stdout);
}

   // Create the input and output arrays in device memory for our calculation
   d_C = clCreateBuffer(context, CL_MEM_READ_WRITE, mem_size_C, NULL, &err);
   d_A = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, mem_size_A, h_A, &err);
   d_sizeAr = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, mem_size_sizeAr, h_sizeAr, &err);
if(k==1){
		printf("10 TEST \n");
	fflush(stdout);
}
	
	cl_uint initVoxelValue = 0;
	err = clEnqueueFillBuffer(commands, d_C, &initVoxelValue, sizeof(cl_uint), 0, 1*sizeof(cl_uint), 0, NULL, NULL);
	if(err != CL_SUCCESS) {
		perror("Couldn't fill a buffer object");
		exit(1);
	}
if(k==1){
   	printf("11 TEST \n");
	fflush(stdout);
}
   
   if (!d_A ||!d_C || !d_sizeAr)
   {
       printf("Error: Failed to allocate device memory!\n");
       exit(1);
   }    
    
//   printf("Running matrix multiplication for matrices A (%dx%d) and B (%dx%d) ...\n", WA,HA,WB,HB); 

   //Launch OpenCL kernel
   size_t localWorkSize[2], globalWorkSize[2];
 
   err = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&d_C);
   err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&d_A);
//   err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&d_B);
   err |= clSetKernelArg(kernel, 2, sizeof(int), (void *)&elements);
   err |= clSetKernelArg(kernel, 3, sizeof(int), (void *)&d_sizeAr);
if(k==1){
	printf("12 TEST \n");
	fflush(stdout);
}

   if (err != CL_SUCCESS)
   {
       printf("Error: Failed to set kernel arguments! %d\n", err);
       exit(1);
   }
 
   localWorkSize[0] = 1;
   localWorkSize[1] = 1;
   globalWorkSize[0] = 1;
   globalWorkSize[1] = 1;
   
if(k==1){
   printf("TEST");
	fflush(stdout);
}
   err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);
    if(k==1){
   printf("TESTFINISH");
	fflush(stdout); 
   }
   if (err != CL_SUCCESS)
   {
       printf("Error: Failed to execute kernel! %d\n", err);
       exit(1);
   }
  
   //Retrieve result from device
   err = clEnqueueReadBuffer(commands, d_C, CL_TRUE, 0, mem_size_C, h_C, 0, NULL, NULL);

   if (err != CL_SUCCESS)
   {
       printf("Error: Failed to read output array! %d\n", err);
       exit(1);
   }
   clFinish(commands);
//   fflush(stdout);
 
   //print out the results
/*
   printf("\n\nMatrix C (Results)\n");
   int i;
   for(i = 0; i < size_C; i++)
   {
      printf("%f ", h_C[i]);
      if(((i + 1) % WC) == 0)
      printf("\n");
   }
   printf("\n");
*/




 //  	printf("%d", *h_C);
   	fflush(stdout);
//	fwrite(&h_C, sizeof(h_C), 1, fpBin);




//   	fwrite(&h_C, sizeof(h_C), 1, fpBin);

//   	printf("%d", *h_C);
    
//   	fclose(fpTxt);
//   	fclose(fpBin);
  
 // 	printf("Matrix multiplication completed...\n"); 

   //Shutdown and cleanup
	if(k==1){
	printf("NEWTEST");
	fflush(stdout);
	clFinish(commands);
}
if(k==1){
printf("NEWTEST7 \n");
	fflush(stdout);
	clFinish(commands);
   }
   free(h_A);
   
   if(k==1){
   printf("NEWTEST6 \n");
	fflush(stdout);
   }
   free(h_sizeAr);
if(k==1){
   printf("NEWTEST5 \n");
	fflush(stdout);
   }
   free(h_C);
  
   if(k==1){
   printf("NEWTEST4 \n");
	fflush(stdout);
 }
   clReleaseMemObject(d_A);
   printf("NEWTEST3 \n");
	fflush(stdout);
   clReleaseMemObject(d_C);
  
  if(k==1){ 
   printf("NEWTEST2 \n");
	fflush(stdout);
   }
   clReleaseMemObject(d_sizeAr);
   if(k==1){
   printf("NEWTEST1 \n");
	fflush(stdout);   
}
 
   clReleaseProgram(program);
 if(k==1){
   printf("NEWTEST1 \n");
	fflush(stdout);   
}
   clReleaseKernel(kernel);
   printf("NEWTEST0.5 \n");
	fflush(stdout);   

   clFinish(commands);
 if(k==1){
   printf("NEWTEST0.25 \n");
	fflush(stdout);   
}
   clReleaseCommandQueue(commands);
if(k==1){
   printf("NEWTEST0.125 \n");
	fflush(stdout);   
}

   clReleaseContext(context);
if(k==1){
   printf("NEWTEST0.0625 \n");
	fflush(stdout);   
}
   return 0;

}
