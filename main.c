#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "struct.h"
#define MAX 131

int HashIndex(char *str)
{
	int sum=0;
	int i;
	for(i=0;str[i];i++)
		sum=sum+str[i];
	return sum%MAX;
}

void InitHash(HashTable hash[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		hash[i].count=0;
		hash[i].next=NULL;
	}
}

void insert(char *str)
{
	int flag=0;
	int index;
	HashTable *p,*q;
	index=HashIndex(str);
	if(hash[index].count==0||strcmp(hash[index].word,str)==0)
	{
		hash[index].count++;
		strcpy(hash[index].word,str);
	}
	else
	{
		if(hash[index].next==NULL)
		{
			p=(HashTable *)malloc(sizeof(HashTable));
			p->count=1;
			p->next=NULL;
			strcpy(p->word,str);
			hash[index].next=p;
		}
		else
		{
			q=hash[index].next;
			while(q!=NULL)
			{
				if(strcmp(q->word,str)==0)
				{
					q->count++;
					flag=1;
					break;
				}
				else
					q=q->next;
			}
			if(flag==0)
			{
				q=(HashTable *)malloc(sizeof(HashTable));
				q->count=1;
				q->next=NULL;
				strcpy(q->word,str);
				q->next=hash[index].next;
				hash[index].next=q;
			}
		}
	}
}

void delet(char *str)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(strcmp(hash[i].word,str)==0&&hash[i].count>0)
        {
            hash[i].count--;
        }
    }
}

//void OutPut(HashTable hash[],FILE *fp)
void OutPut(HashTable hash[])
{
	int i;
	for(i=0;i<MAX;i++)
	{
		if(hash[i].count!=0)
			printf("%4d %s\n",hash[i].count ,hash[i].word);
	}
}

void find(char *str)
{
    int i,flag=0;
    for(i=0;i<MAX;i++)
    {
        if(strcmp(hash[i].word,str)==0)
        {
            printf("%s\t%d\n",hash[i].word,hash[i].count);
            flag=1;
        }
    }
    if(flag==0)
        printf("Not found!\n");
}

int main()
{
	char w[MAX];
	InitHash(hash,MAX);
	while(EOF!=scanf("%s",w))
    {
        if(strcmp(w,"insert")==0)
        {
            scanf("%s",w);
            insert(w);
        }
        else if(strcmp(w,"delete")==0)
        {
            scanf("%s",w);
            delet(w);
        }
        else if(strcmp(w,"find")==0)
        {
            scanf("%s",w);
            printf("----------\n");
            find(w);
            printf("----------\n");
        }
    }
	//OutPut(hash);
	return 0;
}
