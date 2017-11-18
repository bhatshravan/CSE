
#include<stdio.h>
#include<conio.h>
    void read(char str[],char pat[],char rep[])
    {
        printf("\nEnter a string:\n");
        gets(str);
        printf("\nEnter a pattern string:\n");
        gets(pat);
        printf("\nEnter a replace string:\n");
        gets(rep);
    }
    void patreplace(char str[],char pat[],char rep[],char ans[])
    {
        printf("\n");
        int i,j,k,l,m,flag=0,f2;
        i=j=k=l=m=f2=0;
        for(i=0;str[i-1]!='\0';i++)
        {
            if(str[i]==pat[j])
            {
                printf("s1");
                while(str[i]==pat[j])
                {
                    if(pat[j]=='\0')
                    {
                        f2=1;
                        printf("SAME\n");
                    }
                    else
                    {
                        ++i;
                        ++j;
                    }
                }
                f2=0;
            }
            else
            {
                j=0;
            }
            ans[k]=str[i];
            ++k;
        }
        puts(ans);
    }
    void main()
    {
        char str[100], pat[100], rep[100], ans[100];
        system("color a");
        printf("Read main string,pattern and replace string:\n");
        read(str,pat,rep);
        patreplace(str,pat,rep,ans);
    }

