#include <stdio.h> 
#include <stdilib.h>
struct student{
          int id,year,numofborrow;
          char author[20];
          char bookname[20];
          char borrow[20];
     };

int main(int argc, char* argv[]) 
{ 
   struct book rec;
   FILE *fp;
   if (argc != 2) { 
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      return 1; 
   }
   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, "Error Open File\n");
      return 2;
	  printf("-------------bookquery---------\n");
	  printf("0: list of all books, 1: list of available books");
   printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "BookID", "BookName", "Author", "Year", "Numofborrow", "Borr    ow");

   while (fread(&rec, sizeof(rec), 1, fp) > 0)
      if (rec.id != 0)

		  printf("%d %s %s %d %d %s", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, rec.borrow    );

   printf("-----------------------------------\n");
   fclose(fp);
   return 0;

   }

