#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


#define COUNT_TOUR 20
#define ALPHA 1
#define BETHA 1
#define EVAPORATION 0.5
#define COUNT_ANTS 10
#define COUNT_CYCLES 10


void print_dist();
void ant_alqoritm();
int search_best_way(int a);
int search_best_transition();
int check_history(int a);
void print_dist();
void print_feromons();
void print_feromons_1_ant();


int tours[COUNT_TOUR][2]={{75,16},{46,22},{56,73},{55,78},{88,94},{52,91},{56,71},{83,41},{87,76},{86,36},{70,100},{98,25},{63,24},{5,5},{22,26},{12,67},{94,22},{47,40},{45,71},{49,35}};
float distances[COUNT_TOUR][COUNT_TOUR][2];
float feromon_add[COUNT_TOUR][COUNT_TOUR]={0};
int visited_tours[COUNT_TOUR]={0};
float arr_for_searched_way[COUNT_TOUR];
int distance_1_way=0;
int best_way[COUNT_TOUR];
int length_best_way=1000;
float arr_for_solver[COUNT_TOUR]={0};
int counter_arr_for_solver=0;
int mode=0;

float prioryti_ants[5]={1, 2.2, 1.2, 0.3, 2.5};
int g=0;

void ant_alqoritm()
{
    printf("Alpha: %d\n",ALPHA);
    printf("Betha: %d\n",BETHA);
    printf("Count tours: %d\n",COUNT_TOUR);
    printf("Evaporation: %f\n",EVAPORATION);
    printf("Count ants: %d\n",COUNT_ANTS);
    printf("Count cycles: %d\n",COUNT_CYCLES);
    for(int i=0;i<COUNT_TOUR;i++)
    {
        for(int j=0;j<COUNT_TOUR;j++)
        {
            if(j<=i)
            {
                distances[i][j][0]=0;
                distances[i][j][1]=0;
            }
            else
            {
                distances[i][j][0]=sqrt(pow(tours[i][0]-tours[j][0],2)+pow(tours[i][1]-tours[j][1],2));
                distances[i][j][1]=1;
            }
        }
    }
    print_dist();
    for(int i=0;i<COUNT_CYCLES;i++)
    {
        for(int j=0;j<COUNT_ANTS;j++)
        {
            search_best_way(j);
            for(int q=0;q<COUNT_TOUR;q++)
            {
                if(q==COUNT_TOUR-1)
                {
                    if(visited_tours[q]<visited_tours[q+1])
                    {
                        feromon_add[visited_tours[q]][visited_tours[0]]+=distance_1_way/COUNT_TOUR;
                    }
                    else{
                         feromon_add[visited_tours[0]][visited_tours[q]]+=distance_1_way/COUNT_TOUR;
                    }
                }
                else{
                    g++;
                    g%5;
                    if(visited_tours[q]<visited_tours[q+1])
                    {
                        if(mode==1)
                        {
                            feromon_add[visited_tours[q]][visited_tours[q+1]]+=distance_1_way/COUNT_TOUR*prioryti_ants[g];
                        }
                        else{
                            feromon_add[visited_tours[q]][visited_tours[q+1]]+=distance_1_way/COUNT_TOUR;
                        }
                    }
                    else{
                        if(mode==1)
                        {
                            feromon_add[visited_tours[q+1]][visited_tours[q]]+=distance_1_way/COUNT_TOUR*prioryti_ants[g];
                        }
                        else{
                            feromon_add[visited_tours[q+1]][visited_tours[q]]+=distance_1_way/COUNT_TOUR;
                        }
                    }
                }
            }
            //print_feromons_1_ant();
            
        }
        for(int q=0;q<COUNT_TOUR;q++)
        {
            for(int j=q+1;j<COUNT_TOUR;j++)
            {
                distances[q][j][1]/=2;
                distances[q][j][1]+=feromon_add[q][j];
                feromon_add[q][j]=0;
            }
        }
    }
    print_feromons();
    printf("Best way has length: %d\n",length_best_way);
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d-",best_way[i]+1);
    }
    printf("C%d",best_way[0]+1);
    printf("\n");
}

int search_best_way(int a)
{


    distance_1_way=0;
    for(int i=0;i<COUNT_TOUR;i++)
    {
        visited_tours[i]=-1;
    }
    visited_tours[0]=a;
    //переходи
    for(int i=1;i<COUNT_TOUR;i++)
    {
        //вибір наступного міста
        for(int j=0;j<COUNT_TOUR;j++)
        {
            if(visited_tours[i-1]==j || !check_history(j))
            {
                arr_for_solver[j]=0;
                continue;
            }
            if(j<visited_tours[i-1])
            {
                arr_for_solver[j]=pow(distances[j][visited_tours[i-1]][1],ALPHA)*pow(1/distances[j][visited_tours[i-1]][0],BETHA);
            }
            else
            {
                arr_for_solver[j]=pow(distances[visited_tours[i-1]][j][1],ALPHA)*pow(1/distances[visited_tours[i-1]][j][0],BETHA);
            }
        }
        visited_tours[i]=search_best_transition();
        if(visited_tours[i-1]>visited_tours[i])
        {
            distance_1_way+=distances[visited_tours[i]][visited_tours[i-1]][0];
        }
        else{
            distance_1_way+=distances[visited_tours[i-1]][visited_tours[i]][0];
        }
    }
    distance_1_way+=distances[0][visited_tours[COUNT_TOUR-2]][0];

    if(length_best_way>distance_1_way)
    {
        for(int i=0;i<COUNT_TOUR;i++)
        {
            length_best_way=distance_1_way;
            best_way[i]=visited_tours[i];
        }
    }
}

int search_best_transition()
{
    
    float sum=0;
    for(int i=0;i<COUNT_TOUR;i++)
    {
        sum+=arr_for_solver[i];
    }
    float arr[COUNT_TOUR];
    for(int i=0;i<COUNT_TOUR;i++)
    {
        if(i==0)
        {
            arr[i]=arr_for_solver[i]/sum;
        }
        else
        {
            arr[i]=arr[i-1]+arr_for_solver[i]/sum;
        }
    }
    float r = (float)rand() / RAND_MAX;

    for(int i=0;i<COUNT_TOUR;i++)
    {
        if(arr[i]>=r)
        {
            return i;
        }
    }
}

int check_history(int a)
{
    for(int i=0;i<COUNT_TOUR;i++)
    {
        if(visited_tours[i]==a)
        {
            return 0;
        }
    }
    return 1;
}


void print_dist()
{
    printf("Distance matrix:\n");
    printf("\t");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
    }
    printf("\n");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
        for(int j=0;j<COUNT_TOUR;j++)
        {
            printf("%2.2f\t",distances[i][j][0]);
        }
        printf("\n");
    }
}

void print_feromons()
{
    printf("Feromons matrix:\n");
    printf("\t");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
    }
    printf("\n");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
        for(int j=0;j<COUNT_TOUR;j++)
        {
            printf("%2.0f\t",distances[i][j][1]);
        }
        printf("\n");
    }
}

void print_feromons_1_ant()
{
    printf("\t");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
    }
    printf("\n");
    for(int i=0;i<COUNT_TOUR;i++)
    {
        printf("C%d\t",i+1);
        for(int j=0;j<COUNT_TOUR;j++)
        {
            printf("%2.0f\t",feromon_add[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    mode=0;
    srand(time(NULL));
    ant_alqoritm();
}