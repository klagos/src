#include <stdbool.h>
#include <malloc.h>

typedef struct Cell{
        int x,y;
        char tuple[5];
        int id;
        bool alive; //arreglar
}Cell;

/*
 * The struct cellContainer will have an dynamic array of cells, every 
 * cellContainer will be added into our universe.
*/
typedef struct cellContainer{
        Cell *array;
}cellContainer;

/*
 * The function createCell will create a cell with all the genetic behaviours
 * that were read on the file input.ini with its respective position on the
 * universe.
*/

Cell *createCell(char ch1, char ch2, char ch3, char ch4, char ch5, int posx, int posy, int cellId)
{
        Cell *newCell = (Cell *)malloc(sizeof(Cell));
        newCell->x = posx;
        newCell->y = posy;
        newCell->id = cellId;
        newCell->alive = true;
        newCell->tuple[0] = ch1;
        newCell->tuple[1] = ch2;
        newCell->tuple[2] = ch3;
        newCell->tuple[3] = ch4;
        newCell->tuple[4] = ch5;
        return newCell;
}

cellContainer **createUniverse(int rows, int column)
{
        cellContainer **universe;
        universe = (cellContainer **)malloc(rows * sizeof(cellContainer *));
        for (int i = 0; i < rows; i++)
                universe[i] = (cellContainer*)malloc(sizeof(cellContainer)*column);
        return universe;

}

//void addToUniverse(Cell *universe, Cell *cell, int x, int y)
//{
//        return
//}
//
//void verifySize(cellContainer *array)
//{
//
//}