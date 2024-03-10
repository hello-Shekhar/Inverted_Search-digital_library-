#include"invert_search.h"


void display_data(Wlist *head[])
{
    printf("-------------------------------------------------------------------------------------------\n");

    printf("Index\t\tWord\t\tFilecount\t\tFilename\t\tWordcount\n"); 
    for(int i=0;i<27;i++)
    {
	Wlist *temp=head[i];
	//Traversing through the list upto last last node of main node
	while(temp!=NULL)
	{

	    printf("[%d]\t\t[%s]\t\t%dfile(s)\t\t", i, temp->word, temp->nfile);
	    Hlist * Hhead=temp->wlink;
	    //Traversing through sub node
	    while(Hhead!=NULL)
	    {
		printf("%s\t\t%d\t\t",Hhead->file_data, Hhead->nword);
		Hhead=Hhead->hlink;
	    }
	    printf("\n");
	    //Upating temp
	    temp=temp->link;
	}
    }
    printf("-------------------------------------------------------------------------------------------\n");
}

