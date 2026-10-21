 #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>
   #include <fcntl.h>
    struct student{
         int id,year,numofborrow;
         char author[20];
         char bookname[20];
         char borrow[20];
  };
  int main(int argc, char *argv[])
  {
     int fd, id;
 	char bookname[20];
      char c;
     struct book;
     if (argc < 2) {
        fprintf(stderr, "How to use : %s file\n", argv[0]);
        exit(1);
     }
     if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(2);
     }
 
     do {
       printf("\input name of book:");
        if (scanf("%s", &bookname) == 1) {
           lseek(fd, (id-START_ID)*sizeof(record), SEEK_SET);
            if ((read(fd, (char *) &record, sizeof(record)) > 0) && (record.id != 0))
            printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "BookID", "BookName", "Author", "Year", "Numofborrow", "Borrow");

			else printf("Record %d Null\n", id);
        } else printf("Input Error");
        printf("Continue?(Y/N)");
        scanf(" %c", &c);
     } while (c=='Y');
    close(fd);
     exit(0);
  }


