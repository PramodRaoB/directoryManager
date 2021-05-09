#include "hash.h"

/*Create Hash Table Struct*/
AliasTableStruct CreateHash(llu size) {
  AliasTableStruct table;

  table = (AliasTableStruct)malloc(sizeof(struct stHT_alias));
  table->table_size = size;
  table->num_elems = 0;
  table->start = (Alias *)malloc(size * sizeof(Alias));

  for (llu i = 0; i < size; i++) {
    strcpy(table->start[i].path, "VALID");
    strcpy(table->start[i].ali, "VALID");
  }

  return table;
}

/*Returns hash value for strings*/
llu HornerHash(char arr[MAX_ALIAS_LENGTH], llu size) {
  llu hash = 0;
  llu len = strlen(arr);

  for (llu i = 0; i < len; i++) {
    hash = (hash * 33 + (llu)arr[i]) % (size);
  }

  return hash;
}

/*Insert Path llu quadratic probing table, qp = quadratic probing*/
AliasTableStruct InsertPathQP(char curr_path[MAX_PATH_LENGTH],
                              char curr_alias[MAX_ALIAS_LENGTH],
                              AliasTableStruct table) {
  Alias *qp = table->start;
  llu size = table->table_size;
  llu hash = HornerHash(curr_alias, size);
  llu temp = hash, val = 1;

  while (strcmp(qp[hash].path, "VALID") != 0) {
    if (strcmp(qp[hash].ali, curr_alias) == 0) {
      red();
      printf("Error: Alias already used.\n");
      reset();
      char ch, buff;
      yellow();
      printf("Replace existing path with new path?(Y/N)\n");
      reset();
      scanf("%c%c", &buff, &ch);
      if (ch == 'Y' || ch == 'y') {
        strcpy(qp[hash].path, curr_path);
        printf("Path for the alias has been updated\n");
        printf("Current Path for the alias '%s' is: %s\n", qp[hash].ali,
               qp[hash].path);
        return table;
      } else {
        yellow();
        printf(
          "Would you like to change the alias for the current path?(Y/N)\n");
        reset();
        char d, buff2;
        scanf("%c%c", &buff2, &d);
        if (d == 'Y' || d == 'y') {
          char dummy[MAX_ALIAS_LENGTH];
          printf("Enter new alias:\n");
          scanf("%s", dummy);
          table = InsertPathQP(curr_path, dummy, table);
          return table;
        } else {
          return table;
        }
      }
    }
    hash = (temp + val * val) % size;
    val++;
  }

  strcpy(qp[hash].path, curr_path);
  strcpy(qp[hash].ali, curr_alias);
  table->num_elems++;
  if (table->num_elems >= size / 2) {
    table = Rehash(table);
  }
  return table;
}

AliasTableStruct Rehash(AliasTableStruct Old) {
  llu old_tablesize = Old->table_size;
  llu new_tablesize = nextPrime(old_tablesize * 2 + 1);

  AliasTableStruct New = CreateHash(new_tablesize);

  for (llu i = 0; i < old_tablesize; i++) {
    if (strcmp(Old->start[i].ali, "VALID") != 0) {
      InsertPathQP(Old->start[i].path, Old->start[i].ali, New);
    }
  }

  /*Freed the old hashtable*/
  DeleteAliasTable(Old);

  return New;
}

/*
Given an Alias, find the alias in a given table
and return the path
*/
char *FindAlias(char *alias, AliasTableStruct table) {
  Alias *qp = table->start;
  llu size = table->table_size;
  llu hash = HornerHash(alias, size);
  llu temp = hash, val = 1;

  while (strcmp(qp[hash].path, "VALID") != 0) {
    if (strcmp(qp[hash].ali, alias) == 0) {
      return qp[hash].path;
    }
    hash = (temp + val * val) % size;
    val++;
  }

  /*
  If there is no path corresponding to the given alias, the function returns
  INVALID
  */
  red();
  printf("Error: No such alias exists\n");
  reset();
  return NULL;
}

void DeleteAliasTable(AliasTableStruct table) {
  free(table->start);
  table->start = NULL;
  free(table);
  table = NULL;
}
