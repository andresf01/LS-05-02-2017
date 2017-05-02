run: compile
	mpirun -np 4 --hostfile machinefile ./mpiex
compile:
	mpicc mpiEx3.c -o mpiex
clean:
	rm -rf mpiex
