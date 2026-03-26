#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct Matrix
{
    int data[3][3];
    char way[30];
    int g;
    float f;
}Matrix;

typedef struct Node
{
    struct Node *child;
    struct Matrix *matrix;
}Node;

void add_to_list_sort_2(Node* head, Matrix* matrix);
void add_to_list_sort(Node* head, Matrix* matrix);
int matrix_equal(const Matrix *a, const Matrix *b);
void matrix_print(Matrix *m);
int matrix_is_correct(Matrix *m);
void create_child(Matrix * parent,int a,int b,int q);
int matrix_swap(Matrix *m,int i, int j, int c);
void search_f(Matrix* matrix);
void evclid_cycle();
void evclid();
Matrix* matrix_create(Matrix *parent);
void destructor_list(Node* head);
Node * delete_node(Node *head);
int check_history(Matrix* matrix);
int node_equal(Node* a, Matrix *matrix);
void add_to_list_sort(Node* head, Matrix* matrix);
Node* create_head_list(Matrix* matrix);
void matrix_copy(Matrix *a, Matrix *b);
int counter_length_list(Node* ptr);
void quarter();
void chebyshev();



int created_marix=0, added_open_list_matrix=0, added_closed_list_matrix=0,doubles=0;
int start_arr[3][3]={{5,6,7},{8,1,2},{0,3,4}};
int corect_matrix[3][3]={{1,2,3},{4,5,6},{7,8,0}};
char priority[4]={4,2,1,3};
int mode;


Node* opened_list;
Node* closed_list;


Node* create_head_list(Matrix* matrix)
{
    Node * head=(Node*)malloc(sizeof(Node));
    head->child=NULL;
    head->matrix=matrix;
    return head;
}

void add_to_list_sort(Node* head, Matrix* matrix)
{
    if(opened_list==NULL)
    {
        opened_list=(Node*)malloc(sizeof(Node));
        opened_list->matrix=matrix;
        opened_list->child=NULL;
        return;
    }
    if(head->matrix->f>matrix->f)
    {
        Node *child=(Node*)malloc(sizeof(Node));
        child->child=head->child;
        child->matrix=head->matrix;
        head->child=child;
        head->matrix=matrix;
    }
    else
    {
        add_to_list_sort_2(head,matrix);
    }
    
}

void add_to_list_sort_2(Node* head, Matrix* matrix)
{

    if(head->child!=NULL)
    {
        if(matrix->f<head->child->matrix->f)
        {
            Node *current=(Node*)malloc(sizeof(Node));
            current->child=head->child;
            current->matrix=matrix;
            head->child=current;
        }
        else
        {
            add_to_list_sort_2(head->child,matrix);
        }
    }
    else
    {
        Node *tail=(Node*)malloc(sizeof(Node));
        tail->child=NULL;
        tail->matrix=matrix;
        head->child = tail;
    }
}

int node_equal(Node* a, Matrix *matrix)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a->matrix->data[i][j]!=matrix->data[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int check_history(Matrix* matrix)
{
    created_marix++;
    Node *current=closed_list;
    while(current!=NULL)
    {
        if(node_equal(current,matrix))
        {
            doubles++;
            return 0;
        }
        else{
            current=current->child;
        }
    }
    added_open_list_matrix++;
    return 1;
}

Node * delete_node(Node *head)
{
    Node* child=head->child;
    free(head->matrix);
    free(head);
    if(child==NULL)
    {
        return NULL;
    }
    return child;
}

void destructor_list(Node* head)
{
    if(head==NULL)
    {
        return;
    }
    while(head->child!=NULL)
    {
        head=delete_node(head);
    }

    free(head->matrix);
    free(head);
    head=NULL;
}

int counter_length_list(Node* ptr)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else{
        return counter_length_list(ptr->child)+1;
    }
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

void matrix_copy(Matrix *a, Matrix *b)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a->data[i][j]=b->data[i][j];
        }
    }
    a->g=b->g;
    strcpy(a->way,b->way);
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

Matrix* matrix_create(Matrix *parent)
{
    Matrix *m= (Matrix*)malloc(sizeof(Matrix));
    if(m==NULL)
    {
        printf("Memory allocation error\n");
    }
    if(parent==NULL)
    {
        //заповнення початкового стану
        m->g=0;
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
        m->g=parent->g+1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                m->data[i][j]=0;
            }
        }
    }
/*     printf("\nCreated matrix:\n");
    matrix_print(m);
    printf("\n"); */
    return m;
}

void chebyshev()
{
    mode=3;
    printf("Chebyshev metod:\n");
    Matrix *matrix=matrix_create(NULL);
    opened_list=create_head_list(matrix);
    closed_list=create_head_list(matrix);
    evclid_cycle();
    added_closed_list_matrix=counter_length_list(closed_list);
    destructor_list(opened_list);
    destructor_list(closed_list);
    printf("Created matrix: %d\n",created_marix);
    printf("Aproved matrix: %d\n",added_open_list_matrix);
    printf("Disaproved matrix: %d\n",doubles);
    printf("Count matrix in closed list: %d\n\n\n",added_closed_list_matrix);
    added_open_list_matrix=0;
    added_closed_list_matrix=0;
    created_marix=0;
    doubles=0;
}

void quarter()
{
    mode=2;
    printf("Quarter metod:\n");
    Matrix *matrix=matrix_create(NULL);
    opened_list=create_head_list(matrix);
    closed_list=create_head_list(matrix);
    evclid_cycle();
    added_closed_list_matrix=counter_length_list(closed_list);
    destructor_list(opened_list);
    destructor_list(closed_list);
    printf("Created matrix: %d\n",created_marix);
    printf("Aproved matrix: %d\n",added_open_list_matrix);
    printf("Disaproved matrix: %d\n",doubles);
    printf("Count matrix in closed list: %d\n\n\n",added_closed_list_matrix);
    added_open_list_matrix=0;
    added_closed_list_matrix=0;
    created_marix=0;
    doubles=0;
}

void evclid()
{
    mode=1;
    printf("Evclid metod:\n");
    Matrix *matrix=matrix_create(NULL);
    opened_list=create_head_list(matrix);
    closed_list=create_head_list(matrix);
    evclid_cycle();
    added_closed_list_matrix=counter_length_list(closed_list);
    destructor_list(opened_list);
    destructor_list(closed_list);
    printf("Created matrix: %d\n",created_marix);
    printf("Aproved matrix: %d\n",added_open_list_matrix);
    printf("Disaproved matrix: %d\n",doubles);
    printf("Count matrix in closed list: %d\n\n\n",added_closed_list_matrix);
    added_open_list_matrix=0;
    added_closed_list_matrix=0;
    created_marix=0;
    doubles=0;

}

void evclid_cycle()
{
    int a,b;
    Matrix *current_matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix_copy(current_matrix, opened_list->matrix);
    while(!matrix_is_correct(opened_list->matrix))
    {
        matrix_copy(current_matrix,opened_list->matrix);
        opened_list=delete_node(opened_list);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(current_matrix->data[i][j]==0)
                {
                    a=i;
                    b=j;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++)
        {
            create_child(current_matrix,a,b,priority[i]);
        }

        Node * new=(Node*)malloc(sizeof(Node));
        new->matrix = (Matrix*)malloc(sizeof(Matrix));
        matrix_copy(new->matrix,  current_matrix);
        new->child=closed_list;
        closed_list=new;
    }
    if(matrix_is_correct(opened_list->matrix))
    {
        printf("Searched right matrix:\n");
        matrix_print(opened_list->matrix);
        printf("Way: %s\n",opened_list->matrix->way);
    }
    free(current_matrix);
}

void search_f(Matrix* matrix)
{
    int x,y;
    float f=0;;
    switch (mode)
    {
    case 1:
            for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int q=0;q<3;q++)
                {
                    for(int w=0;w<3;w++)
                    {
                        if(matrix->data[i][j]==corect_matrix[q][w])
                        {
                            f+=sqrt(pow(i-q,2)+pow(j-w,2));
                        }
                    }
                }
            }
        }
        break;
    case 2:
            for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int q=0;q<3;q++)
                {
                    for(int w=0;w<3;w++)
                    {
                        if(matrix->data[i][j]==corect_matrix[q][w])
                        {
                            f+=abs(i-q)+abs(j-w);
                        }
                    }
                }
            }
        }
        break;
    case 3:
            for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int q=0;q<3;q++)
                {
                    for(int w=0;w<3;w++)
                    {
                        if(matrix->data[i][j]==corect_matrix[q][w])
                        {
                            if(i-q>=j-w)
                            {
                                f+=abs(i-q);
                            }
                            else{
                                f+=abs(j-w);
                            }
                        }
                    }
                }
            }
        }
        break;
    
    default:
        break;
    }
    
    matrix->f=f+matrix->g;
    //printf("%f\n",matrix->f);
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
                m->way[m->g]='t';
                m->g++;
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
                m->way[m->g]='r';
                m->g++;
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
                m->way[m->g]='d';
                m->g++;
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
                m->way[m->g]='l';
                m->g++;
                int current=m->data[i][j-1];
                m->data[i][j-1]=m->data[i][j];
                m->data[i][j]=current;
            }
            break;
        default:
            break;
    }

    if(!check_history(m))
    {
        return 0;
    }


    search_f(m);

/*     printf("\n\n");
    matrix_print(m);
    printf("f:%f\n\n",m->f); */
    add_to_list_sort(opened_list,m);
    return 1;
}

void create_child(Matrix * parent,int a,int b,int q)
{
    Matrix * child=(Matrix*)malloc(sizeof(Matrix));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            child->data[i][j]=parent->data[i][j];
        }
    }
    child->g=parent->g;
    strcpy(child->way, parent->way);
    child->g=parent->g;
    matrix_swap(child,a,b,q);
}



int main()
{
    evclid();
    quarter();
    chebyshev();
}