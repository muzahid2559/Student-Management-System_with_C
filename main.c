#include<stdio.h>
#include<stdlib.h>
struct node
{
    int id;
    char name[100];
    float CGPA;
    struct node *next;
}*head;

void append()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->id);
    scanf("%s",temp->name);
    scanf("%f",&temp->CGPA);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node *p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
void search()
{
    struct node *temp;
    int sid,flag=0;
    scanf("%d",&sid);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->id==sid)
        {
            printf("%d\t",temp->id);
            printf("%s\t",temp->name);
            printf("%.2f\t",temp->CGPA);
            flag=1;
            break;
        }
        temp=temp->next;

    }
    if(flag==0)
    {
        printf("Not found\n");
    }

}
void delete_info()
{
    struct node *prev,*tem;
    tem = head;
    prev = head;
    int ID;
    scanf("%d",&ID);

    while(tem->id != ID)
    {
        prev =tem;
        tem = tem->next;
    }
    if(prev==tem){
        head = head->next;
        return;
    }
    prev->next = tem->next;
    free(tem);
}
void display()
{
    printf("ID\tNAME\tCGPA\n");
    struct node *p;
    p=head;
    while(p!=NULL)
    {
        printf("%d\t%s\t%.2f\t\n ",p->id,p->name,p->CGPA);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    while(1)
    {
       printf("\t\t\tStudent Management System:\t\t\t\n ");
       printf("1.Insert a record\n");
       printf("2.Display all record\n");
       printf("3.Search a record\n");
       printf("4.Delete Record\n");
       printf("5.Update a record\n");

    printf("Inter any number:");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
             append();
             break;
        case 2:
            display();
            break;
        case 3:
             search();
            break;
       case 4:
            delete_info();
            break;
        default:
            printf("########\n");
    }
    }
    return 0;
}
