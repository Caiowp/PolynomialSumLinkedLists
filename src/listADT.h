/*
 * listADT.h
 *
 *  Created on: 6 de jun. de 2023
 *      Author: t00l
 */
#include <stdbool.h>

//List ADT Type Defintions
typedef struct node NODE;

typedef struct list LIST;

//Prototype Declarations LIST*
int compare(int* argu1, int* argu2);
LIST* createList (int (*compare) (int* argu1, int* argu2));
void destroyList (LIST* list);
void printList(LIST* list);
int addNode (LIST* pList, int* coeff, int* expo);
bool removeNode (LIST* pList, int* keyPtr, int** dataOutPtr);
void removeNodesByCoef(LIST* list, int coefToRemove);
bool searchList (LIST* pList, int* pArgu, int** pDataOut);
static bool retrieveNode (LIST* pList, int* pArgu, int** dataOutPtr);
bool traverse (LIST* pList, int fromWhere, int** dataOutPtr);
int listCount (LIST* pList);
bool emptyList (LIST* pList);
bool fullList (LIST* pList);
static bool _insert (LIST* pList, NODE* pPre, int* coeff, int* power);
static void _delete (LIST* pList, NODE* pPre, NODE* pLoc, int** dataOutPtr);
static bool _search (LIST* pList, NODE** pPre, NODE** pLoc, int* pArgu);
