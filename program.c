#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 50

typedef struct {
    char name[10];
    int key;
} file_record;

/* This function adds the relative address to the index for a key */
void create_index(long index[], int key, long rel_add) {
    index[key] = rel_add;
}

/* This function writes a record to the file */
void write_rec(FILE *fp, file_record rec) {
    fwrite(&rec, sizeof(rec), 1, fp);
}

int main() {
    long rel_add;
    int key;
    file_record frec;
    long index[MAX]; /* an index list */
    int n, i;
    FILE *recfile = NULL, *ifile = NULL;

    /* This initializes the index list to all -1 */
    for (i = 0; i < MAX; i++)
        index[i] = -1;

    recfile = fopen("mfile", "w");
    if (recfile == NULL) {
        printf("Error in opening file mfile\n");
        exit(0);
    }

    rel_add = 0;

    do {
        printf("Enter the data value and the key of the record to be added to file mfile\n");
        scanf("%s %d", frec.name, &frec.key);

        while (index[frec.key] != -1) {
            printf("A record with this key value already exists in the file. Enter record key value\n");
            scanf("%s %d", frec.name, &frec.key);
        }

        create_index(index, frec.key, rel_add);
        write_rec(recfile, frec);
        rel_add = ftell(recfile);

        printf("Enter 1 to continue adding records to the file\n");
        scanf("%d", &n);
    } while (n == 1);

    ifile = fopen("index_file", "w");
    if (ifile == NULL) {
        printf("Error in opening file index_file\n");
        exit(0);
    }

    fwrite(index, sizeof(index), 1, ifile); /* Writes the complete index into the index_file */
    fclose(recfile);
    fclose(ifile);

    printf("Enter 1 if you want to retrieve a record\n");
    scanf("%d", &n);

    if (n == 1) {
        ifile = fopen("index_file", "r");
        if (ifile == NULL) {
            printf("Error in opening file index_file\n");
            exit(0);
        }
        fread(index, sizeof(index), 1, ifile); /* Reads the complete index into the index list from the index_file */
        fclose(ifile);

        recfile = fopen("mfile", "r");
        if (recfile == NULL) {
            printf("Error in opening file mfile\n");
            exit(0);
        }
    }

    printf("THE CONTENTS OF THE FILE ARE:\n");
    while (fread(&frec, sizeof(frec), 1, recfile) != 0)
        printf("%s %d\n", frec.name, frec.key);

    do {
        printf("Enter the key of the record to be retrieved\n");
        scanf("%d", &key);
        rel_add = index[key]; /* Gets the relative address of the record from the index list */

        if (fseek(recfile, rel_add, SEEK_SET) != 0) {
            printf("Error\n");
            exit(0);
        }

        fread(&frec, sizeof(frec), 1, recfile);
        printf("The data value of the retrieved record is %s\n", frec.name);

        printf("Enter 1 if you want to retrieve another record\n");
        scanf("%d", &n);
    } while (n == 1);

    fclose(recfile);

    return 0;
}
