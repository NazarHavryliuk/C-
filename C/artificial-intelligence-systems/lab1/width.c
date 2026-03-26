#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RESULTS 80
#define MAX_QUEUE 500000
#define SEARCH_DEPTH 22
typedef struct Matrix
{
    int data[3][3];
    struct Matrix *parent;
    struct Matrix *ptr[4];
    char matrix_way[SEARCH_DEPTH];
    int level;
}Matrix;


Matrix* matrix_create(Matrix *parent);
void matrix_create_childs(Matrix *m);
void matrix_destructor(Matrix *m);
int matrix_equal(const Matrix *a, const Matrix *b);
void matrix_overwrite_create_relationship(Matrix *a, Matrix *b,int p);
void matrix_print(Matrix *m);
int matrix_swap(Matrix *m,int i,int j,int c);
int matrix_is_correct(Matrix *m);
int matrix_cheack_history(const Matrix *m, const Matrix *ptr);
void bfs();

Matrix* queue1[MAX_QUEUE];
Matrix* queue2[MAX_QUEUE];
int counter_queue1=0,counter_queue2=0, lvl_search=1;
int counter_matrixs=0;
int counter_rejected=0;
int arr[4]={4,2,1,3};
int start_arr[3][3]={{5,6,7},{8,1,2},{0,3,4}};

char results[MAX_RESULTS][100];
int counter_results=0;
char way [100];
int counter_way=0;






void bfs()
{
    for(int  k=0;k<counter_queue1;k++)
    {
        int a,b;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(queue1[k]->data[i][j]==0)
                {
                    a=i;
                    b=j;
                    break;
                }
            }
        }


            for(int i=0;i<4;i++)
            {

                queue1[k]->ptr[i]=(Matrix*)malloc(sizeof(Matrix));
                matrix_overwrite_create_relationship(queue1[k],queue1[k]->ptr[i],i);
                if(!matrix_swap(queue1[k]->ptr[i],a,b,arr[i]))
                {
                    //free(queue1[k]->ptr[i]);
                    queue1[k]->ptr[i]=NULL;
                }
                else{
                    queue2[counter_queue2]=queue1[k]->ptr[i];
                    counter_queue2++;
                    way[counter_way]='\0';
                    counter_way--;

                }
            }

        
    }
    for(int i=0;i<counter_queue2;i++)
    {
        queue1[i]=queue2[i];
        queue2[i]=0;
    }
    counter_queue1=counter_queue2;
    counter_queue2=0;
    if(lvl_search<SEARCH_DEPTH)
    {
        lvl_search++;
        bfs();
    }

}


int matrix_cheack_history(const Matrix *m, const Matrix *ptr)
{
    if(ptr==NULL)
    {
        return 1;
    }
    if(matrix_equal(m,ptr))
    {
        return 0;
    }
    if(!matrix_cheack_history(m,ptr->parent))
    {
        return 0;
    }
    return 1;
}

int matrix_is_correct(Matrix *m)
{
    int c=1;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m->data[i][j]!=c)
            {
                return 0;
            }
            c++;
            c%=9;
        }
    }
    return 1;
}

int matrix_swap(Matrix *m,int i, int j, int c)
{
    switch (c)
    {
        case 1:
            if(i==0)
            {
                counter_rejected++;
                return 0;
            }
            else
            {
                m->matrix_way[m->level-2]='t';
                counter_way++;
                int current=m->data[i-1][j];
                m->data[i-1][j]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 2:
            if(j==2)
            {
                counter_rejected++;
                return 0;
            }
            else
            {
                m->matrix_way[m->level-2]='r';
                counter_way++;
                int current=m->data[i][j+1];
                m->data[i][j+1]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 3:
            if(i==2)
            {
                counter_rejected++;
                return 0;
            }
            else
            {
                m->matrix_way[m->level-2]='d';
                counter_way++;
                int current=m->data[i+1][j];
                m->data[i+1][j]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 4:
            if(j==0)
            {
                counter_rejected++;
                return 0;
            }
            else
            {
                m->matrix_way[m->level-2]='l';
                counter_way++;
                int current=m->data[i][j-1];
                m->data[i][j-1]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        default:
            break;
    }

    if(!matrix_cheack_history(m,m->parent))
    {
        way[counter_way]='\0';
        counter_way--;
        counter_rejected++;
        return 0;
    }
    counter_matrixs++;
    printf("\nCreated matrix:\n");
    way[counter_way]='\0';
    printf("%s\n",m->matrix_way);
    matrix_print(m);
    printf("\n");

    if(matrix_is_correct(m))
    {
        printf("Searched correct matrix:\n");
        matrix_print(m);
        printf("Way is: %s",m->matrix_way);
        if(counter_results<MAX_RESULTS)
        {
            strcpy(results[counter_results],m->matrix_way);            
        }

        counter_results++;
    }
    return 1;
}

Matrix* matrix_create(Matrix *parent)
{
    Matrix *m= (Matrix*)malloc(sizeof(Matrix));
    if(m==NULL)
    {
        printf("Memory allocation error\n");
    }

    m->parent=parent;


    if(parent==NULL)
    {
        //заповнення початкового стану
        m->level=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                m->data[i][j]=start_arr[i][j];
            }
        }
    }
    else
    {
        m->level=parent->level+1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                m->data[i][j]=0;
            }
        }
    }
    queue1[counter_queue1]=m;
    counter_queue1++;
    counter_matrixs++;
    printf("\nCreated matrix:\n");
    matrix_print(m);
    printf("\n");
    bfs();
    //matrix_create_childs(m);
    return m;
}

void matrix_destructor(Matrix *m)
{
    if(m==NULL)
    {
        return;
    }
    for(int i=0;i<4;i++)
    {
        matrix_destructor(m->ptr[i]);
    }
    //counter_matrixs--;
    printf("\nDestructor for matrix:\n");
    matrix_print(m);
    free(m);
}

int matrix_equal(const Matrix *a, const Matrix *b)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a->data[i][j]!=b->data[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

void matrix_overwrite_create_relationship(Matrix *father, Matrix *child,int p)
{
    if(father==NULL || child==NULL)
    {
        printf("Matrixs don`t exist\n");
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            child->data[i][j]=father->data[i][j];
        }
    }
    for(int i=0;i<4;i++)
    {
        child->ptr[i]=NULL;
    }
    father->ptr[p]=child;
    child->parent=father;
    child->level=father->level+1;

    for(int i=0;i<father->level-1;i++)
    {
        child->matrix_way[i]=father->matrix_way[i];
    }
}

void matrix_print(Matrix *m)
{
    if(m==NULL)
    {
        printf("Matrix doesn`t exist");
        return;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",m->data[i][j]);
        }
        printf("\n");
    }
}



int main()
{
    Matrix *head=matrix_create(NULL);

    matrix_destructor(head);
    printf("\nCounter created matrixs: %d\n\n",counter_matrixs+counter_rejected);
    printf("\nCounter confirm matrixs: %d\n\n",counter_matrixs);
    printf("\nCounter rejected matrixs: %d\n\n",counter_rejected);
    printf("Results:\n");
    int f=0;
    int arrr[MAX_RESULTS];
    int frequency[MAX_RESULTS][2]={0};
    int count=0;
    for(int i=0;i<counter_results;i++)
    {
        while(results[i][f]!='\0')
        {
            f++;
        }
        arrr[i]=f;
        printf("\n%d-th result: %s\nLenght:%d\n",i+1,results[i],f);
        f=0;
    }
/*     int flag=0;
    for(int i=0;i<counter_results;i++)
    {
        flag=0;
        for(int j=0;j<count;j++)
        {
            if(arrr[i]==frequency[j][0])
            {
                flag=1;
                frequency[j][1]++;
                break;
            }
        }
        if(!flag)
        {
            frequency[count][0]=arrr[i];
            frequency[count][1]=1;
            count++;
        }
    }

    for(int i=0;i<count;i++)
    {
        printf("%d:\t%d\n",frequency[i][0],frequency[i][1]);
    } */
}