
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
        int i,m,c,j,count,k;
        i=m=j=count=c=0;
        while(str[c]!='\0')
        {
            if(str[m]==pat[i])
            {
                i++;
                m++;
                if(pat[i]=='\0')
                {
                    count++;
                    for(k=0;rep[k]!='\0';k++,j++)
                    {
                        ans[j]=rep[k];
                    }
                    i=0;
                    c=m;
                }
            }
            else
            {
                ans[j]=str[c];
                j++;
                c++;
                m=c;
                i=0;
            }
        }
        ans[j]='\0';
        if(count==0)
            printf("\nNo pattern string");
        else
            printf("\nResultant string is %s",ans);
    }
    void main()
    {
        char str[100], pat[100], rep[100], ans[100];
        system("color a");
        printf("Read main string,pattern and replace string:\n");
        read(str,pat,rep);
        patreplace(str,pat,rep,ans);
    }

