#include <stdio.h>
#include <stdlib.h>
struct student{
          int id,year,numofborrow;
         char author[20];
          char bookname[20];
          char borrow[20];
    };
int main(int argc, char *argv[])
{
   struct book rec;
   int id;
   char borrow;
   FILE *fp;
		
   if (argc != 2) {
      fprintf(stderr, "How to use: %s FileName\n", argv[0]);
      exit(1);
   }

   if ((fp = fopen(argv[1], "rb")) == NULL ) {
      fprintf(stderr, "Erroe Open File\n");
      exit(2);
   }do {
   printf("0 bookId: borrow book, 1 bookId: return book");
   if (scanf("%d", &id) == 1) {
      fseek(fp, (id - START_ID) * sizeof(rec), SEEK_SET);
      if ((fread(&rec, sizeof(rec), 1, fp) > 0)&&(rec.id != 0)) {
          printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "BookID", "BookName", "Author", "Year", "Numofborrow", "Borrow");

		  printf(" ");
         scanf("%s", &rec.borrow);
         fseek(fp, -sizeof(rec), SEEK_CUR);
         fwrite(&rec, sizeof(rec), 1, fp);
      } else printf("Record %d none\n", id);
   } else printf("Input Error\n");

   printf("Continue? (Y/N)");
   scanf(" %c",&c);
} while (c == 'Y');
fclose(fp);
exit(0);
}



