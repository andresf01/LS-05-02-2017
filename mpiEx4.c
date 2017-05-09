// andresf01 file
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, dest, source, count, tag=1;
	int inmsg, outmsg=5;
	MPI_Status Stat;
	int value = 1000;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	int cs = value/(size-1);
	if (rank == 0) {
	  int total = 0;
      int n = size - 1; // Slaves rank

	  // MPI_Send(&rank, 1, MPI_INT, dest, tag, MPI_COMM_WORLD);
	  // MPI_Recv(&inmsg, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);
      while (n > 0) {
        MPI_Recv(&inmsg, 1, MPI_INT, n, tag, MPI_COMM_WORLD, &Stat);
        total = total + inmsg;
        n = n - 1;
	    printf("Working %d \n",Stat.MPI_SOURCE);
	  }
      printf("Valor total suma: %d\n",total);
    }
	else {
      
      int rangeTotal=0;
	  for( int i = cs * (rank - 1) + 1; i <= cs * rank ; i++ )
      {
        rangeTotal = rangeTotal+i;
      }
      printf("rangeTotal: %d\n",rangeTotal);
      MPI_Send(&rangeTotal, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
	}

	// MPI_Get_count(&Stat, MPI_CHAR, &count);
	// printf("Task %d: Received %d (number) from task %d with tag %d \n",
		   // rank, inmsg, Stat.MPI_SOURCE, Stat.MPI_TAG);

	MPI_Finalize();
}
