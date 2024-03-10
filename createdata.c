#include"invert_search.h"

void create_data(Slist *fhead,Wlist*head[])
{
   /*1.one by one read file data .
     2.open file in read mode.
     3.using fscanf storing a fptr file to word      
     4.check 1st character is alphabet or not.
     5.if not then special character.
     6.compare the word at each node with a new node.
     7.if wordare not repeated then insert_at_last
      */
    while(fhead)
    {
	scan_filedata(fhead,head,fhead->file_data);
	fhead = fhead ->link;
    }
}

char *f_name;
Wlist scan_filedata(Slist *file,Wlist**head,char *filename)
{
    int flag;
    f_name=filename;
    //Open file in read mode
    FILE *fptr=fopen(f_name, "r");
    char word[30];
    flag=1;
    if(fptr==NULL)
    {
	printf("Error: In opening %s file",f_name);
    }
    while(fscanf(fptr,"%s",word)!=EOF)
    {
	//Taking index for alphabet
	int index=(tolower(word[0]))%97;
	//Checking index other than alphabet
	if(!(index>=0 && index<=25))
	{
	    index=26;
	}
	if(head[index]!=NULL)
	{
	    Wlist *temp=head[index];
	    //Compare the word at each node with a new word
	    while(temp)
	    {
		if(!strcmp(temp->word, word))
		{
		    word_count_update(&temp, filename);
		    flag=0;
		    break;
		}
		temp=temp->link;
	    }
	}
	if(flag==1)
	{
	    //Calling function if words is not repeated
	    insert_last(&head[index], word);
	}
    }
    printf("Database created for %s file successfully\n",filename);
}
//Function to update the word count
int word_count_update(Wlist **head, char *file_name)
{
    Hlist *h_temp=(*head)->wlink;
    Hlist *prev=NULL;
    while(h_temp)
    {
	//Check filenames are same or not
	if(!strcmp(h_temp->file_data, file_name))
	{
	    //Updating word count
	    h_temp->nword++;
	    return SUCCESS;
	}
	prev=h_temp;
	h_temp=h_temp->hlink;
    }
    //Updating file count
    (*head)->nfile++;
    Hlist *new_node=malloc(sizeof(Hlist));
    if(new_node==NULL)
    {
	return FAILURE;
    }
    //Update subnode link
    strcpy(new_node->file_data, file_name);
    new_node->nword=1;
    new_node->hlink=NULL;
    prev->hlink=new_node;
    return SUCCESS;
}

extern char *f_name;
int insert_last(Wlist **head, char *data)
{
    /*
     */
    //Creating main nade
    Wlist *new=malloc(sizeof(Wlist));
    if(new==NULL)
    {
	return FAILURE;
    }
    //Storing data to main nade
    new->nfile=1;
    strcpy(new->word, data);
    new->wlink=NULL;
    new->link=NULL;
    //Calling function to create sub node and establishing link
    update_link(&new);
    if(*head==NULL)
    {
	*head=new; 
	return SUCCESS;
    }
    //Traversing through list if node is present
    Wlist *temp=*head;
    while(temp->link)
    {
	temp=temp->link;
    }
    temp->link=new;
    return SUCCESS;
}
//Function to create sub node
int update_link(Wlist **head)
{
    Hlist *new=malloc(sizeof(Hlist));
    if(new==NULL)
    {
	return FAILURE;
    }
    new->nword=1;
    strcpy(new->file_data, f_name);
    new->hlink=NULL;
    (*head)->wlink=new;
    return SUCCESS;
}
