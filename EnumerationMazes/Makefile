.PHONY: EnumerateVMat.cs

all: run

EnumerateVMat.exe: EnumerateVMat.cs
	@mcs EnumerateVMat.cs

clean:
	@rm -f EnumerateVMat.exe

run: EnumerateVMat.exe
	@mono EnumerateVMat.exe
