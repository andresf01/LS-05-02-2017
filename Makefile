run: compile
	mpirun -np 4 --hostfile machinefile ./mpiex
compile:
	mpicc mpiEx2a.c -o mpiex
clean:
	rm -rf mpiex
