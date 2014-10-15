#include <stdio.h>
#include <string.h>
int main ()
{
   FILE *fp;
int countdef=0;
   int c,expanding=0;
char lbl[20],opc[20],opr[20];
char *name[10][10],*arg[10][10],def[10][4096];
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
if(strcmp(opc,"MACRO")==0)
{
*name[countdef]=lbl;
*arg[countdef]=opr;
strcpy(def[countdef],  lbl);
	//printf("%s",*arg[countdef++]);
while(strcmp(opc,"MEND")!=0)
	{
	
	 fscanf(fp,"%s %s %s",lbl,opc,opr);
	strcat(def[countdef], lbl);
	strcat(def[countdef], opc);
	strcat(def[countdef], opr);
	printf("%s %s %s",lbl,opc,opr);
	}
}

//printf("%s %s %s",lbl,opc,opr);

	//printf("\n___%d",j);
   }
printf("%s",def[countdef++]);
fclose(fp);

}
