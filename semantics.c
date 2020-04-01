#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "SymTab.h"
#include "IOMngr.h"

extern struct SymTab *table;

void printSymTab() {

  printf("in printSymTab");

  int hasMore = startIterator(table);

  printf("%20s\t%10s\n", "Variable", "Value");


  while (hasMore) {

    int x =
    printf("%20s\t%10d\n", getCurrentName(table), (int)(getCurrentAttr(table)));

    hasMore = nextEntry(table);
  }
}

void storeVar(char * name, int val) {

  printf("\n\nStoring value %d\n\n", val);

  enterName(table, name);

  setCurrentAttr(table, (void *)val);

}

int getVal(char * name) {
  printf("in getVal");

  if (!enterName(table, name)) {
    writeIndicator(getCurrentColumnNum());
    writeMessage("Initialize variable to 0");
    setCurrentAttr(table, (void *) 0);
  }
  return (int) getCurrentAttr(table);
}

int doAdd(int v1, int v2) {
  printf("in doAdd");

  return v1 + v2;
}

int doMult(int v1, int v2) {
  printf("in doMult");

  return v1 * v2;
}

int doNegative(int v1) {
  printf("in doNegative");

  return v1*-1;
}
