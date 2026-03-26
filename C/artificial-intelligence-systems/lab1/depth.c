#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RESULTS 17
typedef struct Matrix
{
    int data[3][3];
    struct Matrix *parent;
    struct Matrix *ptr[4];

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

int counter_matrrixs=0;
int arr[4]={1,3,4,2};
int start_arr[3][3]={{5,6,7},{8,0,1},{2,3,4}};

char results[MAX_RESULTS][100];
int counter_results=0;
char way [100];
int counter_way=0;







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
                return 0;
            }
            else
            {
                way[counter_way]='t';
                counter_way++;
                int current=m->data[i-1][j];
                m->data[i-1][j]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 2:
            if(j==2)
            {
                return 0;
            }
            else
            {
                way[counter_way]='r';
                counter_way++;
                int current=m->data[i][j+1];
                m->data[i][j+1]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 3:
            if(i==2)
            {
                return 0;
            }
            else
            {
                way[counter_way]='d';
                counter_way++;
                int current=m->data[i+1][j];
                m->data[i+1][j]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        case 4:
            if(j==0)
            {
                return 0;
            }
            else
            {
                way[counter_way]='l';
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
        return 0;
    }
    counter_matrrixs++;
    //printf("\nCreated matrix:\n");
    way[counter_way]='\0';
    //printf("%s\n",way);
    //matrix_print(m);
    //printf("\n");

    if(matrix_is_correct(m))
    {
        //printf("Searched correct matrix:\n");
        //matrix_print(m);
        printf("Way is: %s",way);
        if(counter_results<MAX_RESULTS)
        {
            strcpy(results[counter_results],way);            
        }

        counter_results++;
    }
    return 1;
}
void matrix_create_childs(Matrix *m)
{

    int a,b;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m->data[i][j]==0)
            {
                a=i;
                b=j;
                break;
            }
        }
    }

    if(m->level<30)
    {
        for(int i=0;i<4;i++)
        {
m->ptr[i]=(Matrix*)malloc(sizeof(Matrix));
            matrix_overwrite_create_relationship(m,m->ptr[i],i);
            if(!matrix_swap(m->ptr[i],a,b,arr[i]))
            {
                free(m->ptr[i]);
                m->ptr[i]=NULL;
            }
            else{
                matrix_create_childs(m->ptr[i]);
                way[counter_way]='\0';
                counter_way--;
                matrix_destructor(m->ptr[i]);
                m->ptr[i]=NULL;
            }
            

        }


    }

}

Matrix* matrix_create(Matrix *parent)
{
    Matrix *m= (Matrix*)malloc(sizeof(Matrix));
    if(m==NULL)
    {
        //printf("Memory allocation error\n");
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
    counter_matrrixs++;
    //printf("\nCreated matrix:\n");
    //matrix_print(m);
    //printf("\n");
    matrix_create_childs(m);
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
    counter_matrrixs--;
    //printf("\nDestructor for matrix:\n");
    //matrix_print(m);
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
        //printf("Matrixs don`t exist\n");
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
}

void matrix_print(Matrix *m)
{
    if(m==NULL)
    {
        //printf("Matrix doesn`t exist");
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
    printf("\nCounter matrixs: %d\n\n",counter_matrrixs);
    printf("Results:\n");
    for(int i=0;i<counter_results;i++)
    {
        printf("%d-th result: %s\n",i+1,results[i]);
    }
}