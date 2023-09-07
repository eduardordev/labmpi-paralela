#include <stdio.h>
#include <string.h>
#include <mpi.h>

#define MESSTAG 100
#define MAXLEN 100

int main(int argc, char** argv) {
    int rank, num;

    // Iniciar MPI
    MPI_Init(&argc, &argv);

    // Obtener el rank del proceso actual
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Obtener el número total de procesos
    MPI_Comm_size(MPI_COMM_WORLD, &num);

    // Ahora, aquí puedes poner el código con los condicionales:

    if(rank %2 == 0 && rank != num-1)
    {
        char mess[] = "Hello World";
        printf("%i sent %s\n", rank, mess);
        MPI_Send(mess, strlen(mess) + 1, MPI_CHAR, rank+1, MESSTAG, MPI_COMM_WORLD);
    }
    else if (rank % 2 != 0)
    {
        char mess[MAXLEN];
        MPI_Status status;
        MPI_Recv(mess, MAXLEN, MPI_CHAR, rank-1, MESSTAG, MPI_COMM_WORLD, &status);
        printf ("%i received %s\n", rank, mess);
    }

