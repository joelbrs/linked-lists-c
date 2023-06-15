#include <stdio.h>
#include <stdlib.h>

#define TRUE 0
#define FALSE 1

#ifndef __SLLIST__
#define __SLLIST__

typedef struct _slnode_ SLNode;

typedef struct _sllist_ SLList;

SLList *sllCreate();

int sllInsertFirst(SLList *l, void *data);

void *sllGetFirst(SLList *l);

SLNode *sllRemoveFirst(SLList *l);

int sllInsertLast(SLList *l, void *data);

void *sllGetLast(SLList *l);

int sllSize(SLList *l);

int sllDestroy(SLList *l);

int sllInsertAfterPEsimo(SLList *l, int p, void *data);

void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *));

void *sllQueryRemove(SLList *l, void *key, int (*cmp)(void *, void *));

int sllInserftAfterSpecQuery(SLList *l, void *key, void *data,
                             int (*cmp)(void *, void *));

int sllInsertBefSpec(SLList *l, void *key, void *data,
                     int (*cmp)(void *, void *));

#endif