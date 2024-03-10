#include"invert_search.h"

int save_data(Wlist *head[])
{
    char save_filename[30];
    printf("Enter the filename you want to save in database\n");
    scanf("%s" ,save_filename);
    //Open the given file in write mode
    FILE *fptr=fopen(save_filename, "w");
    if(fptr==NULL)
    {
	printf("Error : File not available\n");
	return FAILURE;
    }
    for(int i=0;i<27;i++)
    {
	Wlist *temp=head[i];
	//Checking the hashtable is empty or not
	while(temp!=NULL)
	{
	    fprintf(fptr, "#%d;%s;%d;",i,temp->word,temp->nfile);
	    Hlist *sub_temp=temp->wlink;
	    //Traversing through sub node
	    while(sub_temp!=NULL)
	    {
		fprintf(fptr,"%s;%d;",sub_temp->file_data,sub_temp->nword);
		sub_temp=sub_temp->hlink;
	    }
	    fprintf(fptr,"#");
	    fprintf(fptr, "\n");
	    temp=temp->link;
	}
    }
    printf("Database saved successfully in %s\n",save_filename);
    fclose(fptr);
}

