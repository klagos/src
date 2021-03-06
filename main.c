#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include "functions.c"

int main(int argc, const char **argv)
{
        FILE *input = fopen("init.uni", "r");
        int row,column, n_of_cells, id = 0, n_of_line = 1;
        char line[999], lib1[7], lib2[7], lib3[7], lib4[7];
        char ch1,ch2,ch3,ch4,ch5,A,C,T,G;
        void *liba, *libc, *libg, *libt;
        int posx,posy;
        while(fscanf(input, "%[^\n]\n", line) != EOF) {
                if (n_of_line == 1) {
                        sscanf(line, "%d %d", &column, &row);
                        Cell ***universe = createUniverse(row, column);
                        printAllCantities(universe, row, column);
                        //cellContainer **universe = createUniverse(row, column);
                } else if (n_of_line == 2) {
                        sscanf(line, "%c %s", &A, lib1);
                        liba = dlopen(lib1, RTLD_NOW);
                        void(*Abehavior)(char, int*) = dlsym(liba, "genetic_behaviour");
                        if (Abehavior == NULL) {
                        fprintf(stderr, "dlsym: %s\n", dlerror());
                        //exit(EXIT_FAILURE);
                        }
                } else if (n_of_line == 3) {
                        sscanf(line, "%c %s", &T, lib2);
                        libt = dlopen(lib2, RTLD_NOW);
                        void(*Tbehavior)(char, int*) = dlsym(libt, "genetic_behaviour");
                        if (Tbehavior == NULL) {
                        fprintf(stderr, "dlsym: %s\n", dlerror());
                        //exit(EXIT_FAILURE);
                        }
                } else if (n_of_line == 4) {
                        sscanf(line, "%c %s", &C, lib3);
                        libc = dlopen(lib3, RTLD_NOW);
                        void(*Cbehavior)(char, int*) = dlsym(libc, "genetic_behaviour");
                        if (Cbehavior == NULL) {
                        fprintf(stderr, "dlsym: %s\n", dlerror());
                        //exit(EXIT_FAILURE);
                        }
                } else if (n_of_line == 5) {
                        sscanf(line, "%c %s", &G, lib4);
                        libg = dlopen(lib4, RTLD_NOW);
                        void(*Gbehavior)(char, int*) = dlsym(libg, "genetic_behaviour");
                        if (Gbehavior == NULL) {
                        fprintf(stderr, "dlsym: %s\n", dlerror());
                        //exit(EXIT_FAILURE);
                        }
                } else if (n_of_line == 6) {
                        sscanf(line, "%d", &n_of_cells);
                } else {
                        printf("Entro aki");
                        sscanf(line, "%c %c %c %c %c %d %d", &ch1, &ch2, &ch3, &ch4, &ch5, &posx, &posy);
                        Cell *newCell = createCell(ch1, ch2, ch3, ch4, ch5, id);
                        posy = row - posy - 1;
                        addToUniverse(universe, newCell, posx, posy);
                        id++;
                }
                        n_of_line++;
        }
        fclose(input);
    return 0;
}