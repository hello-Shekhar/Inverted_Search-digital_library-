#include"invert_search.h"
#include"string.h"
/*1.Check CLA files are .txt file or not.(using strstr it will return NULL if not present.)
  2.Check file is present or not.(means failed to open)
  3.Check file is empty or not.(using fseek traverse in file if ftell value is NULL means file empty)
  4.Check file is Duplicate file or not.(insert at last)
*/
int file_validation(Slist **head,char*argv[])
{
    int i,ret;
    for(i=1;argv[i]!=NULL;i++)
    {
    if(!strstr(argv[i],".txt"))
    {
	printf("%s is not .txt file\n",argv[i]);
	return FAILURE;
    }
    printf("%s .txt FILE VALIDATION \t<SUCCESS>\n",argv[i]);
    FILE *fptr;
    fptr = fopen(argv[i],"r");
    if(fptr == NULL)
    {
	printf("%s file is not present\n",argv[i]);
	return FAILURE;
    }
    fseek(fptr,0L,SEEK_END);
    if(!ftell(fptr))
    {
	printf("%s file is empty\n",argv[i]);
	return FAILURE;
    }
    printf("%s FILE NOT EMPTY VALIDATION \t<SUCCESS>\n",argv[i]);
    if(ret =(insert_at_last(head,argv[i])==SUCCESS)) 
    {
    printf("%s FILE INSERTION \t<SUCCESS>\n",argv[i]);
    }
    else if(ret = DUPLICATE)
    {
	printf("%s is duplicate file.\nUsage : ./.aout file1.txt file2.txt file.txt\n",argv[i]);
	return FAILURE;
    }
    else 
    {
	printf("%s is failed to add file in linked list\n",argv[i]);
	return FAILURE;
    }
    printf("\n");
    }
}
