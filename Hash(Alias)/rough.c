#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
typedef unsigned long long llu;
/*Stores Hashtable size and alias pointer "start"*/
struct stHT_alias
{
	llu table_size;
	llu num_elems;
	struct alias *start;
};

/*Alias struct contains a string that stores the absolute path and the Alias, another string*/
struct alias
{
	char path[50];
	char ali[20];
};

typedef struct stHT_alias *AliasTableStruct;
typedef struct alias Alias;
typedef unsigned long long llu;


bool __isPrime(llu input) {
  llu x = 4;
  for (llu i = 5; true ; i += x) {
    if (input % i == 0)
      return false;
    llu q = input / i;
    if (q < i)
      return true;
    x ^= 6;
  }
  return true;
}

llu nextPrime(llu input) {
  if (input < 0) return -1;

  switch (input) {
   case 0:
   case 1:
   case 2:
     return 2;
   case 3:
     return 3;
   case 4:
   case 5:
     return 5;
  }

  llu i = input % 6;
  llu x = i < 2 ? 1 : 5;
  input = 6 * (input / 6) + x;
  for (i = (3 + x) / 2; !__isPrime(input); input += i) 
    i ^= 6;

  return input;
}

/*Takes the path and the alias and puts them into a hashtable*/
AliasTableStruct InsertPathQP(char arr1[50], char arr2[20], AliasTableStruct table);

/*Creates hashtable*/
AliasTableStruct CreateHash(llu size);

/*Rehashes the table when it reaches 50% of its max capacity*/
AliasTableStruct Rehash(AliasTableStruct Old);

/*Returns key*/
llu HornerHash(char arr[20], llu size);


/*Create Hash Table Struct*/
AliasTableStruct CreateHash(llu size)
{
    AliasTableStruct table;

    table = (AliasTableStruct)malloc(sizeof(struct stHT_alias));
    table->table_size = size;
    table->start = (Alias *)malloc(size * sizeof(Alias));

    for (llu i = 0; i < size; i++)
    {
        strcpy(table->start[i].path, "VALID");
        strcpy(table->start[i].ali, "VALID");
    }

    return table;
}

/*Returns hash value for strings*/
llu HornerHash(char arr[20], llu size)
{
    llu hash = 0;
    llu len = strlen(arr);

    for (llu i = 0; i < len; i++)
    {
        hash = (hash * 33 + (llu)arr[i]) % (size);
    }

    return hash;
}

/*Insert Path lluo quadratic probing table, qp = quadratic probing*/
AliasTableStruct InsertPathQP(char curr_path[50], char curr_alias[20], AliasTableStruct table)
{
    Alias *qp= table->start;
    llu size= table->table_size;
    llu hash = HornerHash(curr_alias, size);
    llu temp = hash, val = 1;
    
    while (strcmp(qp[hash].path, "VALID") != 0)
    {
        if (strcmp(qp[hash].ali, curr_alias) == 0)
        {
            printf("Alias already used.\n");
            char ch, buff;
            printf("Replace existing path with new path?(Y/N)\n");
            scanf("%c%c", &buff, &ch);
            if (ch == 'Y')
            {
                strcpy(qp[hash].path, curr_path);
                printf("Path for the alias has been updated\n");
                printf("Current Path for the alias '%s' is: %s\n", qp[hash].ali, qp[hash].path);
                return table;
            }
            else
            {
                printf("Would you like to change the alias for the current path?(Y/N)\n");
                char d, buff2;
                scanf("%c%c", &buff2, &d);
                if (d == 'Y')
                {
                    char dummy[20];
                    printf("Enter new alias.\n");
                    scanf("%s", dummy);
                    InsertPathQP(curr_path, dummy, table);
                    return table;
                }
                else
                {
                    return table;
                }
            }
        }
        temp = (hash + val * val) % size;
        val++;
    }

    strcpy(qp[hash].path, curr_path);
    strcpy(qp[hash].ali, curr_alias);
    table->num_elems++;
    if(table->num_elems > size/2)
    {
        table = Rehash(table);
    }
    return table;
}

AliasTableStruct Rehash(AliasTableStruct Old)
{
    llu old_tablesize = Old->table_size;
    llu new_tablesize = nextPrime(old_tablesize * 2 + 1);

    AliasTableStruct New = malloc(sizeof(struct stHT_alias));

    New->table_size = new_tablesize;
    New->start = (Alias *)malloc(new_tablesize * sizeof(Alias));

    for (llu i = 0; i < new_tablesize; i++)
    {
        strcpy(New->start[i].path, "VALID");
        strcpy(New->start[i].ali, "VALID");
    }

    for (llu i = 0; i < old_tablesize; i++)
    {
        if (strcmp(Old->start[i].ali, "VALID") != 0)
        {
            InsertPathQP(Old->start[i].path, Old->start[i].ali, New);
        }
    }

    return New;
}


int main()
{
    AliasTableStruct table;
    table = CreateHash(4);
    int t;
    printf("Enter number of tcs: \n");
    scanf("%d", &t);
    while (t--)
    {
        char arr1[50];
        char arr2[20];
        printf("Enter the path and the alias: \n");
        scanf("%s %s", arr1, arr2);
        table = InsertPathQP (arr1, arr2, table);
        int hash = HornerHash(arr2,table->table_size);
        printf("%s\n%s\n%lld\n%lld\n", table->start[hash].path, table->start[hash].ali,table->num_elems,table->table_size);
    }
}