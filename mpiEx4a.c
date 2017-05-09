// andresf01 file
#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int size, rank, total, source, count, tag=1;
	int inmsg, outmsg=5;
	MPI_Status Stat;
	int value = 1000;
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int cs = value/size;
    // int total = 0;
	int rangeTotal=0;

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
