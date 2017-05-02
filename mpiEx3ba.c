// andresf01 file
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, dest, source, count, tag=1;
	int inmsg, outmsg=5;
	MPI_Status Stat;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if (rank == 0) {
	  dest = 1;
	  source = 5;
	  MPI_Send(&rank, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	  MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
	 }
	else {
	  dest = (rank + 1)%size;
	  source = (rank % size) - 1;
	  MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
	  MPI_Send(&rank, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	 }

	MPI_Get_count(&Stat, MPI_CHAR, &count);
	printf("Task %d: Received %d (number) from task %d with tag %d \n",
		   rank, inmsg, Stat.MPI_SOURCE, Stat.MPI_TAG);

	MPI_Finalize();
}
