#include"invert_search.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
/*
Name:Shekhar Verma
Date: 02/10/2023
Title: PROJECT INVERTED SEARCH
*/
int main(int argc,char*argv[])
{
    if(argc == 1)
    {
	printf("ERROR : please enter valid command line agruments\nUsage : ./a.out file1.txt file.txt\n");
	return 1;
    }
    Slist *head=NULL;

    if(file_validation(&head ,argv)==FAILURE)
    {
	printf("PROGRAM TERMINATED\n");
	return 1;
    }
    int option;
    char ch;
    char word[30];
    Wlist *hash[27] = {NULL};
    do
    {
	printf("Select your choice\n");
	printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search\n5. Save Database\nEnter your choice : ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		//Case for create database
		create_data(head,hash);
		break;
	    case 2:
		//Case for display database
		display_data(hash);
		break;
	    case 3:
		//Case for update database
		if(update_data(hash,&head)==SUCCESS)
		{
		    printf("Updation database successfully\n");
		}
		break;
	    case 4:
		//Case for search database
		printf("Enter the word do you want to search : ");
		scanf("%s",word);
		search_data(hash[tolower(word[0]%97)],word);
		break;
	    case 5:
		//Case for save database
		save_data(hash);
		break;

	}
	printf("Do you want to continue (y/n) : ");
	getchar();
	scanf("%c",&ch);
    }
    while(ch=='Y' || ch=='y');
    return 0;
}
