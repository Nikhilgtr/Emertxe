#include<stdio.h>
#include<ctype.h>
#include<string.h>
void keyw(char *p);

int i=0;

char keys[32][10]={"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};


int main(int argc, char **argv)
{
	char ch,str[25],seps[15]=" \t\n,;(){}[]#\"<>",oper[]="!%^&*-+=~|.<>/?";
	int j;
	char fname[50];
	if(argc==1)
    {
        printf("Error: \tInvalid Argument\n");
        printf("Usage: \t~/ ./a.out <.c file>\n");

    }
	FILE *f1;
f1 = fopen(argv[1],"r");

	if(f1==NULL)
	{
	 printf("file not found");
	 return 0;
	}
    if(f1 != NULL)
    {
        printf("Open\t: %s : Success\n",argv[1]);

    }
        printf("Parsing\t: %s : Started\n\n",argv[1]);
        while((ch=fgetc(f1))!=EOF)
            {
                for(j=0;j<=14;j++)
                    {
                        if(ch==oper[j])
                        {
                            printf("Operator\t: %c\n",ch);

                            str[i]='\0';
                            keyw(str);
                        }
                    }

                for(j=0;j<=14;j++)
                    {
                        if(i==-1)
                            break;
                        if(ch==seps[j])
                            {
                                if(ch=='#')
                                    {
                                        printf("Header File\t: ");
                                        while(ch!='>')
                                        {
                                            printf("%c",ch);
                                            ch=fgetc(f1);
                                        }
                                        printf("%c\n",ch);
                                        i=-1;
                                    break;
                                    }
                                if(ch=='"')
                                    {
                                        printf("Literal \t: \"");
                                        do
                                        {
                                            ch=fgetc(f1);
                                            printf("%c",ch);
                                        }while(ch!='"');
                                        printf("\n");
                                        i=-1;
                                        break;
                                    }
                                str[i]='\0';
                                keyw(str);
                            }
                        }
            if(i!=-1)
                {
                    str[i]=ch;
                    i++;
                }
            else
            i=0;
	}
    printf("\nParsing\t: %s : Done\n\n",argv[1]);
}
void keyw(char *p)
{
int k,flag=0;
for(k=0;k<=31;k++)
{
if(strcmp(keys[k],p)==0)
{
printf("Keyword         : %s\n",p);

flag=1;
break;
}
}
if(flag==0)
{
if(isdigit(p[0]))
{
printf("Literal \t: %s\n",p);

}
else
{
//if(p[0]!=13&&p[0]!=10)
if(p[0]!='\0')
{
printf("Identifier\t: %s\n",p);

}
}
}
i=-1;
}
