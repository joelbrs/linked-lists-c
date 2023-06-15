#include "sLList.h"

typedef struct _slnode_ {
  void *data;
  struct _slnode_ *next;
} SLNode;

typedef struct _sllist_ {
  SLNode *first;
} SLList;

SLList *sllCreate() {
  SLList *l = (SLList *)malloc(sizeof(SLList));

  if (l != NULL) {
    l->first = NULL;
    return l;
  }
  return NULL;
};

int sllInsertFirst(SLList *l, void *data) {
  if (l != NULL) {
    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));
    if (newnode != NULL) {
      newnode->data = data;
      newnode->next = l->first; // l->first == NULL
      l->first = newnode;
      return TRUE;
    }
  }
  return FALSE;
};

void *sllGetFirst(SLList *l) {
  if (l != NULL) {
    return l->first->data;
  }
  return NULL;
};

SLNode *sllRemoveFirst(SLList *l) {
  SLNode *data;
  if (l != NULL) {
    data = l->first;
    l->first = l->first->next;
    return data;
  }
  return NULL;
};

int sllInsertLast(SLList *l, void *data) {
  if (l != NULL) {
    SLNode *newnode = (SLNode *)malloc(sizeof(SLNode));

    if (newnode != NULL) {
      newnode->data = data;
      newnode->next = NULL;

      if (l->first == NULL) {
        l->first = newnode;
      } else {
        SLNode *last = (SLNode *)malloc(sizeof(SLNode));
        if (last != NULL) {
          last = l->first;

          while (last->next != NULL) {
            last = last->next;
          }

          last->next = newnode;
          return TRUE;
        }
      }
    }
  }
  return FALSE;
};

void *sllGetLast(SLList *l) {
  if (l != NULL && l->first != NULL) {
    if (l->first->next == NULL) {
      return l->first->data;
    } else {
      SLNode *last = (SLNode *)malloc(sizeof(SLNode));

      if (last != NULL) {
        while (last->next != NULL) {
          last = last->next;
        }
        return last;
      }
    }
  }
  return NULL;
};

int sllSize(SLList *l) {
  int cont = 0;
  if (l != NULL && l->first != NULL) {
    SLNode *last = (SLNode *)malloc(sizeof(SLNode));

    if (last != NULL) {
      last = l->first;
      cont++;

      while (last->next != NULL) {
        last = last->next;
        cont++;
      }
      return cont;
    }
  }

  return -1;
};

int sllDestroy(SLList *l) {
  if (l != NULL && l->first == NULL) {
    free(l->first);
    free(l);
    return TRUE;
  }
  return FALSE;
};

int sllInsertAfterPEsimo(SLList *l, int p, void *data) {
  SLNode *elmp, *newnode;
  int i = 0;

  if (l != NULL && p >= 0 && l->first != NULL) {
    elmp = (SLNode *)malloc(sizeof(SLNode));

    if (elmp != NULL) {
      elmp = l->first;
      while (i < p && elmp->next != NULL) {
        elmp = elmp->next;
        i++;
      }

      newnode = (SLNode *)malloc(sizeof(SLNode));
      if (newnode != NULL) {
        newnode->data = data;
        newnode->next = elmp->next;
        elmp->next = elmp;
        return TRUE;
      }
    }
  }
  return FALSE;
};

void *sllQuery(SLList *l, void *key, int (*cmp)(void *, void *)) {
  int stat;
  if (l != NULL && l->first != NULL) {
    SLNode *elm = (SLNode *)malloc(sizeof(SLNode));

    if (elm != NULL) {
      elm = l->first;
      stat = cmp(elm->data, key);

      while (elm->next != NULL && stat != TRUE) {
        elm = elm->next;
        stat = cmp(elm->data, key);
      }

      if (stat == TRUE) {
        return elm;
      }
    }
  }

  return NULL;
};

void *sllQueryRemove(SLList *l, void *key, int (*cmp)(void *, void *)) {
  SLNode *elm, *prev = NULL, *data;
  int stat;
  if (l != NULL && l->first != NULL) {
    elm = (SLNode *)malloc(sizeof(SLNode));

    if (elm != NULL) {
      elm = l->first;
      stat = cmp(elm->data, key);

      while (stat != TRUE && elm->next != NULL) {
        prev = elm;
        elm = elm->next;
        stat = cmp(elm->data, key);
      }

      if (stat == TRUE) {
        data = elm->data;

        if (prev == NULL) {
          l->first = elm->next;
        } else {
          prev->next = elm->next;
        }

        free(elm);
        return data;
      }
    }
  }
  return NULL;
};

int sllInserftAfterSpecQuery(SLList *l, void *key, void *data,
                             int (*cmp)(void *, void *)) {
  SLNode *spec, *newnode;
  int stat;
  if (l != NULL && l->first != NULL) {
    spec = (SLNode *)malloc(sizeof(SLNode));

    if (spec != NULL) {
      spec = l->first;
      stat = cmp(spec->data, key);

      while (stat != TRUE && spec->next != NULL) {
        spec = spec->next;
        stat = cmp(spec->data, key);
      }

      if (stat == TRUE) {
        newnode = (SLNode *)malloc(sizeof(SLNode));

        if (newnode != NULL) {
          newnode->data = data;
          newnode->next = spec->next;
          spec->next = newnode;
          return TRUE;
        }
      }
    }
  }

  return FALSE;
};

int sllInsertBefSpec(SLList *l, void *key, void *data,
                     int (*cmp)(void *, void *)) {
  if (l != NULL && l->first != NULL) {
    SLNode *newnode, *prev, *elm;
    int stat;

    elm = (SLNode *)malloc(sizeof(SLNode));
    if (elm != NULL) {
      elm = l->first;
      stat = cmp(elm->data, key);

      while (stat != TRUE && elm->next != NULL) {
        prev = elm;
        elm = elm->next;
        stat = cmp(elm->data, key);
      }

      if (stat == TRUE) {
        newnode->data = data;
        newnode->next = elm;

        if (prev == NULL) {
          l->first = newnode;
        } else {
          prev->next = newnode;
        }
        return TRUE;
      }
    }
  }

  return FALSE;
};
