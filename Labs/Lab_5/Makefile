bench: bench.cc asm.s funcs.cc crc64.cc crc64table.h
	g++ -g -O2 -c bench.cc
	g++ -c asm.s
	g++ -g -O2 -mavx2 -c funcs.cc
	g++ -g -O2 -c crc64.cc
	g++ -g bench.o asm.o funcs.o crc64.o -o bench

clean:
	rm *.o bench
	
