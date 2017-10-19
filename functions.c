#include <stdbool.h>
#include <malloc.h>

typedef struct Cell{
        char tuple[5];
        int id;
        struct Cell *nextCell;
}Cell;

/*
 * The struct cellContainer will have a linked list of cells, every
 * and the cantity of cells that it has.

typedef struct cellContainer{
        CellContainer *array;
        int cant;
}cellContainer;
*/

/*
 * The function will create a cell with all the genetic behaviours
 * that were read on the file input.ini with its respective position on the
 * universe.
*/

Cell *createCell(char ch1, char ch2, char ch3, char ch4, char ch5, int cellId)
{
        Cell *newCell = (Cell *)malloc(sizeof(Cell));
        newCell->id = cellId;
        newCell->tuple[0] = ch1;
        newCell->tuple[1] = ch2;
        newCell->tuple[2] = ch3;
        newCell->tuple[3] = ch4;
        newCell->tuple[4] = ch5;
        newCell->nextCell = NULL;
        return newCell;
}

/*
 * This function will create a 2d array of empty Cells
*/
Cell ***createUniverse(int rows, int column)
{
        Cell ***universe;
        universe = (Cell ***)malloc(rows * sizeof(Cell **));
        for (int i = 0; i < rows; i++){
                universe[i] = (Cell**)malloc(sizeof(Cell*)*column);
        }

        // Declaring all the Cells empty
        for (int i = 0; i < rows; i++){
                for (int i2 = 0; i2 < column; i2++)
                        universe[i][i2] = NULL;
        }
        return universe;
}

void printAllCantities(Cell ***universe, int rows, int column)
{
        for(int i = 0; i < rows; i++)
                for(int i2 = 0; i2 < column; i2++)
                        printf("%s",universe[i][i2]);
}


void addToUniverse(Cell ***universe, Cell *newCell, int x, int y)
{
        universe[y][x] = newCell; 
}

//void addToUniverse(Cell *universe, Cell *cell, int x, int y)
//{
//        return
//}

/*
 * This function will kill all the cells that has less precedence than others
*/
//bool containerPolice(Cell container)
//{
//        if(container->cant > 2) return true;
//        else return false;
//}