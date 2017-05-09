// andresf01 file
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, total, source, count, tag=1;
	int inmsg, outmsg=5;
	MPI_Status Stat;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	for( int i = cs * rank + 1; i <= cs * (rank + 1) ; i++ )
	{
	  rangeTotal = rangeTotal+i;
	}
	MPI_Reduce(&rangeTotal, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank==0)
    {
      printf("Valor total suma: %d\n", total);
    }
	MPI_Finalize();
}

void myBcast(void *data, int numelem, int datatype, int root, int communicator)
{
    if ( rank != root )
    {
      MPI_Recv(&inmsg, 1, MPI_INT, root, tag, MPI_COMM_WORLD, &Stat);
    }
    else
    {
      for ( int i = 0; i < size; i++ )
      {
      // for (
	    if ( i != root )
		{
          MPI_Send(&data, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
        }
	  }
    }
}
