#include"invert_search.h"
int search_data(Wlist *head, char *word)
{
    //Check whether empty or not
    if(head==NULL)
    {
	printf("Search word is not available in the database\n");
	return FAILURE;
    }
    //Traversing list
    while(head)
    {
	//Compairing database word with given word
	if(strcmp(head->word, word)==0)
	{
	    printf("Word %s is present in %d file\n", head->word, head->nfile);
	    Hlist *search=head->wlink;
	    //Getting detais of word
	    while(search)
	    {
		printf("In file: %s %d times present\n", search->file_data, search->nword);
		search=search->hlink;
	    }
	    return FAILURE;
	}
	head=head->link;
    }
    printf("Error : Searched data is not found\n");   
}


