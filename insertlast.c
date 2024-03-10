#include "invert_search.h"
//Function to create linked list to store filename
int insert_at_last(Slist **head, char *filename)
{
 /*1.taking temp pointer and assign to head.
   2.Compare string file data to filename if both are mathing means DUPLICATE
   3.create a node and update link and data part.
   4.if list empty assign head to new node.
   5.if list is not empty traverse at last and assign new node to last node.
  */

    Slist *temp=*head;
    while(temp!=NULL)
    {
	//Checking for duplicare file
	if(strcmp(temp->file_data,filename)==0)
	{
	    return DUPLICATE;
	}
	temp=temp->link;
    }
    Slist *new=malloc(sizeof(Slist));
    if(new==NULL)
    {
	return FAILURE;
    }
    //Storing filename to linked list
    strcpy(new->file_data, filename);
    new->link=NULL;
    if(*head==NULL)
    {
	*head=new;
	return SUCCESS;
    }
    temp=*head;
    //Establishing link with new node
    while(temp->link!=NULL)
    {
	temp=temp->link;
    }
    temp->link=new;
    return SUCCESS;
}
