#include <stdio.h>

int main ()
{
   FILE *fp;

   int c,expanding=0;
char lbl[20],opc[20],opr[20];
   int j;
  j=0;
   fp = fopen("sic_xecode.c","r");
while(1)
   {
    //  c = fgets(fp);
j++;
      if( feof(fp) )
      { 
          break ;
      }
   //   printf("%c\n%d", c,j);
 fscanf(fp,"%s %s %s",lbl,opc,opr);
 printf("%d\t ",strcmp(opc,"END"));
/*while(strcmp(opc,"END")!=0)
{
	printf("%s %s %s",lbl,opc,opr);
}*/
//printf("%s %s %s",lbl,opc,opr);

	//printf("\n___%d",j);
   }
fclose(fp);

}
