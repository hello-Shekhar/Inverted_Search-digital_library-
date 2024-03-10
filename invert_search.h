#ifndef invert_search_H
#define invertsearch_H
//header
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
//macros
#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3
#define DUPLICATE -4
#define FILE_NOTPRESENT -5
#define FILE_EMPTY -6
//structure
typedef struct node 
{
    char file_data[30];
    struct node *link;
}Slist;

typedef struct hash_node
{
    int nword;
    char file_data[30];
    struct hash_node *hlink;
}Hlist;

typedef struct word_node
{
    int nfile;
    char word [30];
    struct word_node*link;
    Hlist *wlink;
}Wlist;

int file_validation(Slist **fhead,char *argv[]);
int insert_at_last(Slist **head, char *file_data);
void create_data(Slist *fhead , Wlist**head);
void display_data(Wlist *head[]);
int search_data(Wlist*head ,char *word);
int save_data(Wlist**head);
int update_data(Wlist *head[],Slist **f_head);

int word_count_update(Wlist **head , char *file_name);
Wlist scan_filedata(Slist*file,Wlist**head,char *filename);
int insert_last(Wlist **head , char*file_data);
int update_link(Wlist **head);
int file_empty(char *filename);
int update(char*filename ,Wlist *head[]);
#endif
