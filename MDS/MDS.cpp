#include "Headers.hpp"
#include "MDSystemClass.hpp"

#define STEPS 10000
#define N_ATOMS 10
#define CUBE_SIZE 3
#define DIM 3
#define SPEED 2
#define N_THREADS (N_ATOMS <= 8 ? N_ATOMS : 8)

int main()
{
    omp_set_num_threads(8);
    cout << "Start" << endl;
    MDSystem* mdsys = new MDSystem(N_ATOMS, CUBE_SIZE, DIM, SPEED, N_THREADS);
    mdsys->init_system(true);
    clock_t start = clock();
    mdsys->solve(STEPS);
    clock_t end = clock();
    double secs = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Done! " << secs << " sec" << endl;
}