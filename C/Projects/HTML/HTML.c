#include <stdio.h>

#define SIZE_BUFF 5000

void read_c(FILE *,char *);
int main(int argc, char **argv)
{
    /*Array For HTML header and footer*/
    char A[100]="<!DOCTYPE html><html><head><title>";
    char B[100]="</title></head><body><h>";
    char C[100]="</h></body></html>";

    /*Main buffer size*/
    char buffer[SIZE_BUFF];
    char ch;
     int i=0;


    /*checking for the valid argument
    passed through command line*/

    if(argc <= 1)
    {
        printf("Error: \tInvalid Arguments\n");
        printf("Usage: \t /~ ./a.out <.c file> \n");
    }



/*opening the file and
    validating the file
*/
    FILE *cf,*hf;
    cf=fopen(argv[1],"r");
    hf=fopen("code.html","w");

        if(cf==NULL)
        {
            printf("Error: Unable to open the file\n");
        }
    /*Reading the data from
       c file and closing c file*/
   read_c(cf,buffer);
   fclose(cf);
   /*Without numbers of line*/
   if(argv[2]==NULL)
   {
        fwrite(A,1,strlen(A),hf);
          fwrite("code.html",1,9,hf);
         fwrite(B,1,strlen(B),hf);
         fwrite(buffer,1,strlen(buffer),hf);
         fwrite(C,1,strlen(C),hf);
    fclose(hf);
   }
   if(argv[2]!= NULL)
   {

   }
   printf("Source to HTML Conversion done\nFile will be saved as \"code.html\"\n");
return 0;

}
void read_c(FILE *cf,char *buffer)
{
    char ch;
    char l[3]="&lt",g[3]="&gt";
    char breaks[5]="</br>";
    int i=0,j=0,k=0;
     while((ch=fgetc(cf))!= EOF)
    {
        if(ch=='<')
        {
            while(j<3)
            {
                buffer[i]=l[j];
                i++;
                j++;
            }
            j=0;
        continue;
        }
    if(ch=='>')
        {
            while(j<3)
            {
                buffer[i]=g[j];
                i++;
                j++;
            }
        continue;
        }
        if(ch == '\n')
           {
                while(k<5)
                  {
                    buffer[i]=breaks[k];
                    i++;
                    k++;
                  }
            k=0;
            continue;
           }
        buffer[i]=ch;
        i++;
    }
}
