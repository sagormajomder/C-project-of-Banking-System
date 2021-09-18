/**
****This is a Banking System project to submit MR. A.K.M Mashuqur Rahman Mazumder
****This project is Done by Sagor Majomder   */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node Node;
struct node
{
    int account;
    char name[50];
    double balance;
    Node *link;
};

Node *head;

Node* unique(Node *mul,Node *start)
{
    int found=0;
    while(mul->link!=NULL)
    {
        if(mul->account==start->account)
        {
            found++;
            break;
        }
        else
        {
            found=0;
        }
        mul=mul->link;
    }

    if(found!=0)
    {
        printf("Account Number is Already Used! \nEnter Different Account Number:");
        scanf("%d",&start->account);
        unique(mul,start);
    }
    else
    {

        printf("\n\nCongratulation!!Account Number is Unique!\n\n");
    }
}

void create(Node *start)
{
    while(start->link!=NULL)
    {
        start = start->link;
    }
    Node *newnode;
    newnode=(Node*)malloc(sizeof(Node));
    start->link=newnode;

    printf("Enter Account Number:");
    scanf("%d",&newnode->account);
    printf("Enter Account Name:");
    fflush(stdin);
    gets(newnode->name);
    printf("Enter Initial Balance:");
    scanf("%lf",&newnode->balance);
    newnode->link=NULL;
    unique(head,newnode);
}


void sort(Node *first)
{
    Node *p,*q;
    char swap2[50];
    int swap1;
    double swap3;
    for(p=first;p->link!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {
            if(p->account > q->account)
            {
                swap1=p->account;
                strcpy(swap2,p->name);
                swap3=p->balance;

                p->account=q->account;
                strcpy(p->name,q->name);
                p->balance=q->balance;

                q->account=swap1;
                strcpy(q->name,swap2);
                q->balance=swap3;

            }

        }
    }
}

int search(Node *first, int value)
{
    Node *p;
    p=first;
    while(p!=NULL && p->account>value)
    {
        p=p->link;
    }
    if(p->account==value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void deposit(Node* d)
{
    int n,found;
    double sum;
    printf("Please Enter Deposit Account Number:");
    scanf("%d",&n);

    while(d->link!=NULL)
    {
        if(d->account==n)
        {
            found++;
            break;
        }
        else
        {
            found=0;
        }
        d=d->link;
    }

    if(d->account==n)
    {
        found++;
    }

    if(found!=0)
    {
        printf("Please Enter the Deposit amount:");
        scanf("%lf",&sum);
        d->balance=d->balance+sum;
        printf("Now Account NO. %d has Total %lf Taka",d->account,d->balance);
    }
    else
    {
        printf("\nAccount is not Found!\n");
    }
}

void show(Node* s)
{
    int n,found;
    printf("Enter Account Number which information want to show:");
    scanf("%d",&n);
    sort(s);

    while(s->link!=NULL)
    {
        if(n==s->account)
        {
            found++;
            break;
        }
        else
        {
            found=0;
        }
        s=s->link;
    }
    if(n==s->account)
    {
        found++;
    }


    if(found!=0)
    {
        printf("+------------------+ \n");
        printf("| Showing Balance: |\n");
        printf("+------------------+ \n");

        printf("Account Number : %d\n", s->account);
        printf("Account Name : %s\n", s->name);
        printf("Account Balance : %lf Taka\n", s->balance);
        printf("____________________\n");
    }
    else
    {
        printf("\nAccount is not Found!!");
    }

}

void showall(Node *sa)
{
    int i=0;
    printf("+-----------------------+ \n");
    printf("| Showing All Accounts: |\n");
    printf("+-----------------------+ \n");
    sort(sa);
    while(sa->link!=NULL)
    {
        i++;
        printf("%d. Account no : %d | ",i,sa->account);
        printf("Account Name : %s | ",sa->name);
        printf("Account Balance : %lf Taka.\n",sa->balance);
        sa=sa->link;
    }
    i++;
    printf("%d. Account no : %d | ",i,sa->account);
    printf("Account Name : %s | ",sa->name);
    printf("Account Balance : %lf Taka.\n",sa->balance);
}
int main()
{
    Node *start,*d,*s,*sa;
    head=(Node*)malloc(sizeof(Node));
    printf("+-----------------------+ \n");
    printf("| Welcome To Bank \n");
    printf("+-----------------------+ \n");
    printf("For Creating A New Account,You Need to Enter Some Infomation\n");
    printf("Enter Account Number:");
    scanf("%d",&head->account);
    printf("Enter Account Name:");
    fflush(stdin);
    gets(head->name);
    printf("Enter Initial Balance:");
    scanf("%lf",&head->balance);
    head->link=NULL;
    start=head;

    int choice;
    while(true)
    {
        printf("\n\n+-----------------------+ \n");
        printf("| Welcome To Bank \n");
        printf("+-----------------------+ \n");
        printf("\nWhat operation you want to do?\n\n");

        printf("+--------------------------+\n");
        printf("| 1. Create a new account. |\n");
        printf("+--------------------------+\n");
        printf("| 2. Deposit.              |\n");
        printf("+--------------------------+\n");
        printf("| 3. Show balance.         |\n");
        printf("+--------------------------+\n");
        printf("| 4. Show all accounts.    |\n");
        printf("+--------------------------+\n");
        printf("| 0. Exit.                 |\n");
        printf("+--------------------------+\n");

        printf("Enter Your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 0:
        {
            free(head);
            free(start);
            free(sa);
            free(s);
            free(d);
            exit(0);
            break;
        }
        case 1:
        {
            create(start);
            break;
        }


        case 2:
        {
            d=head;
            deposit(d);
            break;
        }

        case 3:
        {
            s=head;
            show(s);
            break;
        }
        case 4:
        {
            sa=head;
            showall(sa);
            break;
        }
        default:
            printf("You Enter Wrong Choice\n");
            break;
        }

    }
}
