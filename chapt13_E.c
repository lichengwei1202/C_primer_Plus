/*第1题*/

#define LIM_ch13_E1 1024
int ch13_E1(void)
{
    char fn[LIM_ch13_E1];
    char ch;
    int count=0; 
    FILE *fp;
    printf("Which file do you want to open:\n");
    scanf("%s",fn);

    if((fp=fopen(fn, "r"))==NULL)
    {
        printf("Cannot open the file: %s", fn);
        exit(EXIT_FAILURE);
    }

    while ((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);

    printf("the file:%s has %d charactors",fn,count);

    return 0;

}

/*第2题*/
int ch13_E2(int argc, int *argv[])
{
    char temp[LIM_ch13_E1];
    FILE *copy;
    FILE *orign;
    if (argc!=3)
    {
        printf("wrong input.\n");
        exit(EXIT_FAILURE);
    }

    if ((orign=fopen(argv[1],"rb"))==NULL||(copy=fopen(argv[2],"wb"))==NULL)
    {
        printf("cannot open the file\n");
        exit(EXIT_FAILURE);        
    }

    size_t byte;
    while((byte=fread(temp,sizeof(char),LIM_ch13_E1,orign))>0)
    {
        fwrite(temp,sizeof(char),byte,copy);
    }
    fclose(copy);
    fclose(orign);

    return 0;
    
    
}

/*第3题*/
#define NAME_LIM 100
int ch13_E3(void)
{
    char ch;
    char orign[NAME_LIM];
    char copy[NAME_LIM];
    FILE *or, *cy;
    printf("which file you want to copy?\n");
    scanf("%s", orign);
    
    if ((or=fopen(orign,"r"))==NULL)
    {
        printf("cannot open %s.",orign);
        exit(EXIT_FAILURE);
    }
    printf("The name of the copied file?\n");
    scanf("%s", copy);
    if ((cy=fopen(copy,"w"))==NULL)
    {
        printf("cannot open %s.",copy);
        exit(EXIT_FAILURE);
    }
    
    while ((ch=getc(or))!=EOF)
    {
        putc(toupper(ch),cy);
    }
    fclose(or);
    fclose(cy);

    return 0;

}

/*第4题*/
int ch13_E4(int argc, char *argv[])
{
    FILE *fp;
    char buf[LIM_ch13_E1];
    if (argc<2)
    {
        printf("no file chosed\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 1; i < argc; i++)
    {
        if ((fp=fopen(argv[i],"r"))==NULL)
        {
            printf("Cannot open %s",argv[i]);
        }
        
        size_t byte;
        while ((byte=fread(buf,sizeof(char),LIM_ch13_E1,fp))>0)
        {
            fwrite(buf,sizeof(char),byte,stdout);
        }
        fprintf(stdout,"\n\n");
        fclose(fp);
    }

    return 0;
}

/*第5题*/
int ch13_E5(int argc, char *argv[])
{
    FILE *fp,*or;
    char buf[LIM_ch13_E1];
    if (argc<2)
    {
        printf("no file chosed\n");
        exit(EXIT_FAILURE);
    }

    if ((or=fopen(argv[1],"a+"))==NULL)
    {
        printf("Cannot open %s",argv[1]);
        exit(EXIT_FAILURE);
    }

    if (setvbuf(or,NULL,_IOFBF,LIM_ch13_E1)!=0)
    {
        printf("Cannot produce a buffer\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 2; i < argc; i++)
    {
        if ((fp=fopen(argv[i],"r"))==NULL)
        {
            printf("Cannot open %s",argv[i]);
            exit(EXIT_FAILURE);
        }
        if (setvbuf(fp,NULL,_IOFBF,LIM_ch13_E1)!=0)
        {
            printf("Cannot produce a buffer\n");
            exit(EXIT_FAILURE);
        }

        size_t byte;
        while ((byte=fread(buf,sizeof(char),LIM_ch13_E1,fp))>0)
        {
            fwrite(buf,sizeof(char),byte,or);
        }
        if (ferror(fp)!=0)
        {
            printf("Error in reading %s",argv[i]);
        }

        if (ferror(or)!=0)
        {
            printf("Error in reading %s",argv[1]);
        }

        fclose(fp);
    }
    return 0;
}

/*第6题*/
#define LIM_NAME 40
int ch13_E6(void)
{
    FILE *or,*rd;
    char name[LIM_NAME];
    char copy_name[LIM_NAME];
    char buf[LIM_ch13_E1];
    char ch;
    int count=0;
    int LEN_NAME;
    printf("Please chose the file you need to reduce:\n");
    scanf("%s",name);

    if ((or=fopen(name,"r"))==NULL)
    {
        fprintf(stdout,"cannot open the file %s",name);
        exit(EXIT_FAILURE);
    }
    LEN_NAME = strlen(name);
    strncpy(copy_name,name,LEN_NAME-4);
    copy_name[LEN_NAME-4]='\0';
    strcat(copy_name,".red");

    if ((rd=fopen(copy_name,"w"))==NULL)
    {
        fprintf(stdout,"cannot open the file %s",copy_name);
        exit(EXIT_FAILURE);
    }
    size_t bytes;
    while ((ch=getc(or))!=EOF)
    {
        if (ferror(or)!=0)
        {
            printf("error in reading");
            exit(EXIT_FAILURE);
        }
        
        if (count++%3==0)
        {
            putc(ch,rd);
        }
        
    }
    
    fclose(rd);
    fclose(or);

    return 0;
}


/*第7题*/
int ch13_E7(int argc, char *argv[])
{
    FILE *first, *second;
    char buf1[LIM_ch13_E1],buf2[LIM_ch13_E1];
    char *fs,*sd;
    int lens1=0,lens2=0;
    


    if (argc<3)
    {
        printf("Please input two file name.");
        exit(EXIT_FAILURE);
    }
    
    if((first=fopen(argv[1],"r"))==NULL)
    {
        printf("cannot open the file.");
        exit(EXIT_FAILURE);
    }

    if((second=fopen(argv[2],"r"))==NULL)
    {
        printf("cannot open the file.");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf1,LIM_ch13_E1,first)!=NULL)
    {
        lens1++;
    }

    while (fgets(buf2,LIM_ch13_E1,second)!=NULL)
    {
        lens2++;
    }
    rewind(first);
    rewind(second);

    if (lens1>=lens2)
    {
        while (fgets(buf1,LIM_ch13_E1,first)!=NULL)
        {
            
            fputs(buf1,stdout);
            if (fgets(buf2,LIM_ch13_E1,second)!=NULL)
            {
                fputs(buf2,stdout);
            }
            
        }
        
    }
    else
    {
        while (fgets(buf2,LIM_ch13_E1,second)!=NULL)
        {
            if (fgets(buf1,LIM_ch13_E1,first)!=NULL)
            {
                fputs(buf1,stdout);
            }
            fputs(buf2,stdout);
            
        }
    }
    
    fclose(first);
    fclose(second);

    return 0;
}

/*第8题*/
int ch13_E8(int argc, char *argv[])
{
    char ch;
    FILE *fp;
    char buf[LIM_ch13_E1];
    int count;
    char c;

    strcpy(buf,"");
    if (strlen(argv[1])>1)
    {
        printf("too many input, please input a single char");
        exit(EXIT_FAILURE);
    }
    ch=*argv[1];
    if (argc<2)
    {
        printf("Please input the char you want to search and the file you want to be checked.");
        exit(EXIT_FAILURE);
    }
    else if (argc==2)
    {
        printf("you does not chose a file, we will search the standard input file.\n");
        printf("Please input a string.\n");
        while ((c=getchar())!='\n')
        {
            if (c==ch)
            {
                count++;
            }
        }
        
        
        printf("standard input has %d %c",count,ch);
        return 0;
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            count=0;
            if ((fp=fopen(argv[i], "r"))==NULL)
            {
                printf("cannot open %s",argv[i]);
                exit(EXIT_FAILURE);
            }

            while ((c=getc(fp))!=EOF)
            {
                if (c==ch)
                {
                    count++;
                }
                
            }
            printf("%s has %d %c\n",argv[i],count,ch);
            fclose(fp);
            
        }
        return 0;
    }
    
    
}

/*第9题*/
int get_number(FILE *fp);
int ch13_E9(void)
{
    FILE *fp;
    char word[LIM_ch13_E1];
    int count=0;
    char buf[LIM_ch13_E1];
    int line_count=0;
    if((fp=fopen("wordy.txt", "a+"))==NULL)
    {
        printf("cannot open wordy");
        exit(EXIT_FAILURE);
    }
    rewind(fp);

    while (fgets(buf,LIM_ch13_E1,fp)!=NULL)
    {
        line_count++;
    }
    rewind(fp);
    puts("please enter the words.(# to quit)");
    
    while ((fscanf(stdin, "%40s", word)==1)&&(word[0]!='#'))
    {
        count++;
        fprintf(fp,"%d-%s\n",count+line_count,word);
    }
    
    puts("File contents:");
    rewind(fp);
    while ((fscanf(fp,"%s",word))==1)
    {
        puts(word);
    }
    puts("done\n");
    
    fclose(fp);
}

int get_number(FILE *fp)
{
    int i=0;
    char temp[LIM_ch13_E1];
    rewind(fp);

    while (fgets(temp,LIM_ch13_E1,fp)!=NULL)
    {
        i++;
    }

    return i;
    
}

/*第10题*/
int ch13_E10()
{
    FILE *fp;
    char name[LIM_ch13_E1];
    char buf[LIM_ch13_E1];
    long int position;
    printf("Please input the file name.\n");
    scanf("%s",name);

    if ((fp=fopen(name,"r"))==NULL)
    {
        printf("cannot open the file\n");
        exit(EXIT_FAILURE);
    }

    printf("where do you need to start?\n");

    while (scanf("%ld",&position)==1&&position>0)
    {
        fseek(fp,position,SEEK_SET);

        if (fgets(buf,LIM_ch13_E1,fp)!=NULL)
        {
            fputs(buf,stdout);
        }
        printf("where do you need to start?\n");
    }
    fclose(fp);

    return 0;
    
    
    

}