#include"invert_search.h"
int update_data(Wlist *head[],Slist **f_head)
{
    char filename[100];
    int empty;
    printf("Enter the filename do you want to add in database : ");
    scanf("%s", filename);
    //Checking for file validation
    //Checking file is .txt or not
    if(strstr(filename,".txt")==NULL)
    {
	printf("Error : Please provide a file of type .txt\n");
	return FAILURE;
    }
    //Checking whether file is present in linked list or not
    Slist *temp=*f_head;
    while(temp!=NULL)
    {
	if(strcmp(temp->file_data,filename)==0)
	{
	    printf("Error : File : %s is already present in linkedlist\n",filename);
	    return FAILURE;	   
	}
	temp=temp->link;
    }
    //Checking file is empty or not
    empty=file_empty(filename);
    if(empty==FILE_NOTPRESENT)
    {
	printf("The file %s is not available\n",filename);
	return FAILURE;
    }
    else if(empty==FILE_EMPTY)
    {
	printf("The file %s is Empty\n",filename);
	return FAILURE;
    }
    else
    {
	//Calling function to update database
	if(update(filename,head)==SUCCESS)
	{
	    return SUCCESS;
	}
	else
	{
	    return FAILURE;
	}
    }
}

//Function to update the data from file to database
int update(char * filename, Wlist *head[])
{   
    char word[100];
    char token[50];
    int count=0;
    int var=0;
    char file_name[50];
    int wordcount=0;
    int filecount=0;
    //Opening file in read mode
    FILE *fptr=fopen(filename,"r");
    rewind(fptr);
    if(fptr==NULL)
    {
	printf("ERROR to open file\n");
	return FAILURE;
    }
    //Read the data from file
    while(fscanf(fptr,"%s",word)!=EOF)
    {
	//Checking data format
	if(word[0]=='#')
	{
	    //Extracting data from file 
	    count=atoi(strtok(word,";#"));
	    strcpy(token,(strtok(NULL,";#")));
	    var=atoi(strtok(NULL,";#"));
	    filecount=var;
	    //Checking hashtable is null or not
	    if(head[count]==NULL)
	    {
		Wlist *main_node=malloc(sizeof(Wlist));
		if(main_node==NULL)
		{
		    return FAILURE;
		}
		else
		{
		    //Storing extracted data to main node
		    main_node->nfile=var;
		    strcpy(main_node->word,token);
		    main_node->wlink=NULL;
		    main_node->link=NULL;
		    strcpy(file_name,(strtok(NULL,";#")));
		    wordcount=atoi(strtok(NULL,";#"));
		    Hlist *sub_node=malloc(sizeof(Hlist));
		    if(sub_node==NULL)
		    {
			return FAILURE;
		    }
		    else
		    {
			//Extracting data to sub node
			strcpy(sub_node->file_data,file_name);
			sub_node->nword=wordcount;
			sub_node->hlink=NULL;
			main_node->wlink=sub_node;
		    }
		    Hlist *temp=sub_node;
		    //Sub node created filecount times
		    while(--filecount)
		    {
			Hlist *sub_node=malloc(sizeof(Hlist));
			if(sub_node==NULL)
			{
			    return FAILURE;
			}
			else
			{
			    //Storing file name to sub node
			    strcpy(file_name,(strtok(NULL,";#")));
			    wordcount=atoi(strtok(NULL,";#"));
			    strcpy(sub_node->file_data,file_name);
			    sub_node->nword=wordcount;
			    sub_node->hlink=NULL;
			    temp->hlink=sub_node;
			    temp=sub_node;
			}
		    }
		}
		//Establishing link hashtable with main node
		head[count]=main_node;
	    }
	    //If hashtable is not null
	    else
	    {
		Wlist *main_temp=head[count];
		Wlist *prev_main=NULL;
		//Traversing through main node
		while(main_temp!=NULL)
		{
		    prev_main=main_temp;
		    main_temp=main_temp->link;
		}
		Wlist *main_node=malloc(sizeof(Wlist));
		if(main_node==NULL)
		{
		    return FAILURE;
		}
		else
		{
		    //Storing data to main node
		    main_node->nfile=var;
		    strcpy(main_node->word,token);
		    main_node->link=NULL;
		    main_node->wlink=NULL;
		    strcpy(file_name,(strtok(NULL,";#")));
		    wordcount=atoi(strtok(NULL,";#"));
		    Hlist *sub_node=malloc(sizeof(Hlist));
		    if(sub_node==NULL)
		    {
			return FAILURE;
		    }
		    else
		    {
			//Storing data to sub node
			strcpy(sub_node->file_data,file_name);
			sub_node->nword=wordcount;
			sub_node->hlink=NULL;
			main_node->wlink=sub_node;
		    }
		    Hlist *temp=sub_node;
		    //Creating sub node filecount times
		    while(--filecount)
		    {
			Hlist *sub_node=malloc(sizeof(Hlist));
			if(sub_node==NULL)
			{
			    return FAILURE;
			}
			else
			{
			    //Storing data to sub node
			    strcpy(file_name,(strtok(NULL,";#")));
			    wordcount=atoi(strtok(NULL,";#"));
			    strcpy(sub_node->file_data,file_name);
			    sub_node->nword=wordcount;
			    sub_node->hlink=NULL;
			    temp->hlink=sub_node;
			    temp=sub_node;
			}
		    }
		}
		//Establishing link between hashtable and main node
		prev_main->link=main_node;
	    }
	}
    }
    return SUCCESS;
}
int file_empty(char*filename)
{
    FILE*fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
	return FILE_NOTPRESENT;
    }
    fseek(fptr,0L,SEEK_END);
    if(ftell(fptr)<=1)
    {
	return FILE_EMPTY;
    }
    return SUCCESS;
}
