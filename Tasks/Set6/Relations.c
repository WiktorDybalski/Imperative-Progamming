#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REL_SIZE 100
#define MAX_RANGE 100

typedef struct {
    int first;
    int second;
} pair;

int find(int* tab, int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i]==x)
        {
            return 1;
        }
    }
    return 0;
}

int add_relation (pair *tab, int n, pair new_pair)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i].first==new_pair.first && tab[i].second==new_pair.second)
        {
            return 0;
        }
    }
    if(n==MAX_REL_SIZE)
    {
        return 0;
    }
    tab[n]=new_pair;
    return 1;
}
int read_relation(pair *relation)
{
    int n,f,s;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&f);
        scanf("%d",&s);
        relation[i].first=f;
        relation[i].second=s;
    }
    return n;
}
void print_int_array(int *array, int n)
{
    printf("%d\n",n);
    for(int i=0; i<n; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

// Case 1:
int make_tmp(pair* tab, int *tmp, int n)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(!find(tmp,j,tab[i].first))
        {
            tmp[j]=tab[i].first;
            j++;
        }
        if(!find(tmp,j,tab[i].second))
        {
            tmp[j]=tab[i].second;
            j++;
        }
    }
    return j;
}
int is_reflexive(pair* tab, int n)
{
    int tmp[2*n];
    int j=make_tmp(tab,tmp,n);
    for(int i=0; i<j; i++)
    {
        int k=0;
        for(k; k<n; k++)
        {
            if(tab[k].first==tab[k].second && tab[k].first==tmp[i])
            {
                break;
            }
        }
        if(k==n)
        {
            return 0;
        }
    }
    return 1;
}
int is_irreflexive(pair* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i].first==tab[i].second)
        {
            return 0;
        }
    }
    return 1;
}
int is_symmetric(pair* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        int j=0;
        for(j; j<n; j++)
        {
            if(tab[i].first==tab[j].second && tab[j].first==tab[i].second)
            {
                break;
            }
        }
        if(j==n)
        {
            return 0;
        }
    }
    return 1;
}
int is_antisymmetric(pair* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tab[i].first==tab[j].second && tab[j].first==tab[i].second && tab[i].first!=tab[i].second)
            {
                return 0;
            }
        }
    }
    return 1;
}
int is_asymmetric(pair* tab, int n)
{
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(tab[i].first==tab[j].second && tab[j].first==tab[i].second)
                {
                    return 0;
                }
            }
        }
        return 1;
    }
}
int is_transitive(pair* tab, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(tab[i].second==tab[j].first)
            {
                int flag=1;
                for(int k=0; k<n; k++)
                {
                    if(tab[k].first==tab[i].first && tab[k].second==tab[j].second)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
int is_connected(pair* tab, int n)
{
    int tmp[2*n];
    int number_of_diff=make_tmp(tab,tmp,n);
    for(int i=0; i<number_of_diff; i++)
    {
        pair arr[n];
        int temp[2*n];
        int l=0;
        for(int k=0; k<n; k++)
        {
            if(tmp[i]==tab[k].first || tmp[i]==tab[k].second)
            {
                arr[l]=tab[k];
                l++;
            }
        }
        if(number_of_diff!=make_tmp(arr,temp,l))
        {
            return 0;
        }
    }
    return 1;
}

// Case 2:
void bubblesort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int is_partial_order(pair* tab, int n)
{
    return is_reflexive(tab,n)* is_transitive(tab,n)* is_antisymmetric(tab,n);
}
int is_total_order(pair* tab, int n)
{
    return is_partial_order(tab,n)* is_connected(tab,n);
}
int is_max_element(pair* tab, int n, int max)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i].first==max && tab[i].second>max)
        {
            return 0;
        }
    }
    return 1;
}
int find_max_elements(pair* tab, int n, int* max_elements)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(is_max_element(tab,n,tab[i].first) && !find(max_elements,j,tab[i].first))
        {
            max_elements[j++]=tab[i].first;
        }
    }
    bubblesort(max_elements,j);
    return j;
}
int is_min_element(pair* tab, int n, int min)
{
    for(int i=0; i<n; i++)
    {
        if(tab[i].second==min && tab[i].first<min)
        {
            return 0;
        }
    }
    return 1;
}
int find_min_elements(pair* tab, int n, int* min_elements)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(is_min_element(tab,n,tab[i].first) && !find(min_elements,j,tab[i].first))
        {
            min_elements[j++]=tab[i].first;
        }
    }
    bubblesort(min_elements,j);
    return j;
}
int get_domain(pair* tab, int n, int* domain)
{
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(!find(domain,j,tab[i].first))
        {
            domain[j++]=tab[i].first;
        }
        if(!find(domain,j,tab[i].second))
        {
            domain[j++]=tab[i].second;
        }
    }
    bubblesort(domain,j);
    return j;
}

// Case 3:
int find_r(pair * S,int n, int x)
{
    for(int i=0; i<n; i++)
    {
        if(S[i].first==x)
        {
            return i;
        }
    }
    return -1;
}
int composition (pair* R, int n1, pair* S, int n2, pair* C)
{
    int j=0;
    for(int i=0; i<n1; i++)
    {
        int index=find_r(S,n2,R[i].second);
        if(index>-1)
        {
            C[j].first=R[i].first;
            C[j++].second=S[index].first;
        }
    }
    return j;
}

int main(void) {
    int to_do;
    pair relation[MAX_REL_SIZE];
    pair relation_2[MAX_REL_SIZE];
    pair comp_relation[MAX_REL_SIZE];
    int domain[MAX_REL_SIZE];
    int max_elements[MAX_REL_SIZE];
    int min_elements[MAX_REL_SIZE];

    scanf("%d",&to_do);
    int size = read_relation(relation);
    int ordered, size_2, n_domain;

    switch (to_do) {
        case 1:
            printf("%d ", is_reflexive(relation, size));
            printf("%d ", is_irreflexive(relation, size));
            printf("%d ", is_symmetric(relation, size));
            printf("%d ", is_antisymmetric(relation, size));
            printf("%d ", is_asymmetric(relation, size));
            printf("%d\n", is_transitive(relation, size));
            break;
        case 2:
            ordered = is_partial_order(relation, size);
            n_domain = get_domain(relation, size, domain);
            printf("%d %d\n", ordered, is_total_order(relation, size));
            print_int_array(domain, n_domain);
            if (!ordered) break;
            int no_max_elements = find_max_elements(relation, size, max_elements);
            int no_min_elements = find_min_elements(relation, size, min_elements);
            print_int_array(max_elements, no_max_elements);
            print_int_array(min_elements, no_min_elements);
            break;
        case 3:
            size_2 = read_relation(relation_2);
            printf("%d\n", composition(relation, size, relation_2, size_2, comp_relation));
            break;
        default:
            printf("NOTHING TO DO FOR %d\n", to_do);
            break;
    }
    return 0;
}