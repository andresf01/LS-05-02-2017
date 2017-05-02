run: compile
	mpirun -np 6 --hostfile machinefile ./mpiex
compile:
	mpicc mpiEx3b.c -o mpiex
clean:
	rm -rf mpiex
