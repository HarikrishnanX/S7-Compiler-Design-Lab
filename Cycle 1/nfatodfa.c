#include<stdio.h>
#include<stdlib.h>

struct node
{
    int st;
    struct node *link;
};

struct node1
{
    int nst[20];
};

static int set[20],nostate,noalpha,s,notransition,nofinal,start,finalstate[20],c,r,buffer[20];
int complete=-1;
char alphabet[20];
static int eclosure[20][20]={0};
struct node1 hash[20];
struct node * transition[20][20]={NULL};

int compare(struct node1 a,struct node1 b)
{
    int i;
    for (i = 1; i <= nostate; i++)
    {
        if (a.nst[i]!=b.nst[i])
        {
            return 0;
        }
    }
    return 1;
}

int insertdfastate(struct node1 newstate)
{
    int i;
    for (i = 0; i <= complete; i++)
    {
        if (compare(hash[i],newstate))
        {
            return 0;
        }
    }
    complete++;
    hash[complete]=newstate;
    return 1;
}

int findalpha(char c)
{
    int i;
    for (i = 0; i < noalpha; i++)
    {
        if (alphabet[i]==c)
        {
            return i;
        }
    }
    return(-1);
}

void insert(int r,char c,int s)
{
    int j;
    struct node *temp;
    j=findalpha(c);
    if (j==-1)
    {
        printf("\nError!!");
        exit(0);
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->st=s;
    temp->link=transition[r][j];
    transition[r][j]=temp;
}

void printnewstate(struct node1 state)
{
    int j;
    printf("{");
    for (j = 1; j <= nostate; j++)
    {
        if (state.nst[j]!=0)
        {
            printf("q%d,",state.nst[j]);
        }
    }
    printf("}\t");
}

void findfinalstate()
{
    int i,j,k,t;
    for (i = 0; i <= complete; i++)
    {
        for (j = 1; j <= nostate; j++)
        {
            for (k = 0; k < nofinal; k++)
            {
                if (hash[i].nst[j]==finalstate[k])
                {
                    printnewstate(hash[i]);
                    printf("\t");
                    j=nostate;
                    break;
                }
            }
        }
    }
}

void main()
{
    int i,j,k,m,t,n,l;
    struct node *temp;
    struct node1 newstate={0},tmpstate={0};
    printf("Enter the Number of Alphabets:");
    scanf("%d",&noalpha);
    getchar();
    printf("\nEnter the Alphabets:\n");
    for (i = 0; i < noalpha; i++)
    {
        alphabet[i]=getchar();
        getchar();
    }
    printf("\nEnter the Number of States:");
    scanf("%d",&nostate);
    printf("\nEnter the Initial State:");
    scanf("%d",&start);
    printf("\nEnter the Number of Final State(s):");
    scanf("%d",&nofinal);
    printf("\nEnter the Final State(s):");
    for (i = 0; i < nofinal; i++)
    {
        scanf("%d",&finalstate[i]);
    }
    printf("\nEnter the Number of Transitions:");
    scanf("%d",&notransition);
    printf("\nNOTE:-Input Transitions in the form:State Alphabet State");
    printf("\nNOTE:-State numbers must be greater than Zero");
    printf("\nEnter the Transitions:\n");
    for (i = 0; i < notransition; i++)
    {
        scanf("%d %c %d",&r,&c,&s);
        insert(r,c,s);
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            hash[i].nst[j]=0;
        }
    }
    complete=-1;
    i=-1;
    printf("\nEquivalent DFA:");
    printf("\n**************");
    printf("\nTransitions of DFA:\n");
    newstate.nst[start]=start;
    insertdfastate(newstate);
    while (i!=complete)
    {
        i++;
        newstate=hash[i];
        for (k = 0; k < noalpha; k++)
        {
            c=0;
            for (j = 1; j <= nostate; j++)
            {
                l=newstate.nst[j];
                if (l!=0)
                {
                    temp=transition[l][k];
                    while (temp!=NULL)
                    {
                        if (set[temp->st]==0)
                        {
                            c++;
                            set[temp->st]=temp->st;
                        }
                        temp=temp->link;
                    }
                }
            }
            printf("\n");
            if (c!=0)
            {
                for (m = 1; m <= nostate; m++)
                {
                    tmpstate.nst[m]=set[m];
                }
                insertdfastate(tmpstate);
                printnewstate(newstate);
                printf("%c\t",alphabet[k]);
                printnewstate(tmpstate);
                printf("\n");
            }
            else
            {
                printnewstate(newstate);
                printf("%c\t",alphabet[k]);
                printf("NULL\n");
            }
        }
    }
    printf("\nStates of DFA:");
    printf("\n*************\n");
    for (i = 0; i <= complete; i++)
    {
        printnewstate(hash[i]);
    }
    printf("\nAlphabets:\n");
    for (i = 0; i < noalpha; i++)
    {
        printf("%c\t",alphabet[i]);
    }
    printf("\nStart State:q%d",start);
    printf("\nFinal States:\n");
    findfinalstate();
}