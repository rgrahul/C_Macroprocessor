#include<stdio.h>
#include<string.h>
   FILE *fp,*fw;
    int countdef=0;
    int c,expanding=0;
    char lbl[20],opc[20],opr[20];
char name[10][10]={"","","","","","","","","",""},arg[10][100]={"","","","","","","","","",""},def[10][4096];
int main (){
 
    int counter=99;
    int j;
    j=0;
    fp = fopen("sic_xecode.c","r");
    fw = fopen("expanded.c","w");
  //  rewind(fp);
    while(1){// c = fgets(fp);
        j++;
        if( feof(fp) ){break ;
        }// printf("%c\n%d", c,j);
        fscanf(fp,"%s %s %s",lbl,opc,opr);
        write_to_file();
       // fprintf(fw,lbl);
      //  fprintf(fw,opc);
       // fprintf(fw,opr);  
	
        counter=search(opc);
        if(counter!=99)
        {
        write_to_file(1,counter);
   	printf("\nok\n");

   	//printf("\n%s\n",def[counter]);
		//fprintf(fp,def[counter]);
		//printf("%s %s %s",lbl,opc,opr);
		//fprintf(fp, "\nTesting...\n");	
		//fwrite("\nTesting...\n", 1, 1024, fp);	
        }
        if(strcmp(opc,"MACRO")==0){    //*name[countdef]=lbl;
            //    *arg[countdef]=opr;
            strcat(arg[countdef], opr);
            strcat(name[countdef], lbl);
            //printf("\n%s\n",*arg[countdef]);
            //printf("%s",*arg[countdef++]);
            while(strcmp(opc,"MEND")!=0)     
               {          
                 fscanf(fp,"%s %s %s",lbl,opc,opr);
                 write_to_file();
                strcat(def[countdef], lbl);
                strcat(def[countdef], " ");
                strcat(def[countdef], opc);
                strcat(def[countdef], " ");
                strcat(def[countdef], opr);
                strcat(def[countdef], " ");
                strcat(def[countdef], "\n");                
                //printf("%s %s %s",lbl,opc,opr);
            }
            //printf("\n%s\n",name[countdef]);
           // printf("\n%s\n",arg[countdef]);
           // printf("\n%s\n",def[countdef++]);
           countdef++;
        }//printf("%s %s %s",lbl,opc,opr);
        //printf("\n___%d",j);
    }//printf("\n%s\n",def[countdef]);
    //printf("\n%s\n",*name[countdef]);
   // search("RDBUFF");
	//printf("\n%s\n",def[countdef-1]);
//   printf("%d",strlen("aaa zz b"));
    fclose(fp);
}
int search(char *macro_name)
{
	int i;
	//printf("%d %s",strcmp(macro_name,name[0]),macro_name);
	//printf("%d",countdef);
	for(i=0;i<countdef;i++)
	{
		if(strcmp(macro_name,name[i])==0)
		{
			//printf("\n---\n");
			//printf("%d %s",i,macro_name);
//			printf("%s %d",name[i],i);
			//printf("\n---\n");
			return i;
		}
	}
	return 99;
}
int write_to_file(check_Expand,counter)
{
	if(check_Expand==1)
	{
		fprintf(fw, def[counter]);
		return 2;
	}
	fprintf(fw, lbl);
	fprintf(fw, " ");
	fprintf(fw, opc);
	fprintf(fw, " ");	
	fprintf(fw, opr);
	fprintf(fw, "\n");
	return 1;
}
