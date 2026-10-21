#include <stdio.h>
#include <stdlib.h>
struct student{
       int id,year,numofborrow;
         char author[20];
         char bookname[20];
          char borrow[20];
   };

  int main(int argc, char* argv[]){
     struct book rec;
     FILE *fp;
 
     if (argc != 2) {
        fprintf(stderr, "How to use: %s FileName\n",argv[0]);
        exit(1);
     }
 
     fp = fopen(argv[1], "wb");
     printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "BookID", "BookName", "Author", "Year", "Numofborrow", "Borrow");
      while (scanf("%d %s %s %d %d %s", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, rec.borrow    )== 6)
        fwrite(&rec, sizeof(rec), 1, fp);
 
     fclose(fp);
     exit(0);
 }
