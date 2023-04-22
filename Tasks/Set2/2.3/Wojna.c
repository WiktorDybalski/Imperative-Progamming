#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NUMBERS_OF_CONFLICTS 100
#define CBUFF_SIZE  52
#define N 52

int karty[N];
int Gracz_A[CBUFF_SIZE];
int Gracz_B[CBUFF_SIZE];
int out1=0, len1=0, out2=0, len2=0;
int cardA=0, cardB=0;

void swap(int tab[], int a, int b)
{
    int temp = tab[a];
    tab[a] = tab[b];
    tab[b] = temp;
}

int rand_from_interval(int a, int b)
{
    if (a > b) return INT_MIN;
    if (b - a >  RAND_MAX) return RAND_MAX;
    if (a == b) return a;
    int randomNum = (rand() % (b - a + 1)) + a;
    return randomNum;
}

void rand_permutation(int n, int tab[]) {
    if (n <= 0 || n > 100) return;
    for(int i = 0; i < n; i++) {
        tab[i] = i;    
    }
    for(int j = 0; j < n - 1; j++) {
        int random = rand_from_interval(j, n - 1);
        swap(tab, j, random);
    }
}

void create_deck(int karty[]) {
    rand_permutation(N, karty);
}

void give_cards(int karty[], int cbuff1[], int cbuff2[]) {
    for(int i = 0; i < 26; i++) {
        Gracz_A[i] = karty[i];
        len1++;
    }
    
    for(int j = 0; j < 26; j++) {
        Gracz_B[j] = karty[j + 26];
        len2++;
    }
}

void print_array(int n, int array[]) {
    printf("Cards: ");
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        printf(" ");
    }
    printf("\n");
}

void cbuff1_print() {
    if (len1 == 0) {
        printf("The cbuff is empty\n");
        return;
    }
    for(int i = 0; i < len1; i++) {
        if (Gracz_A[(out1 + i) % 52] < 10) {
            printf("  ");
            printf("%d", Gracz_A[(out1 + i) % 52]);
        } else {
            printf(" ");
            printf("%d", Gracz_A[(out1 + i) % 52]);
        }
    }
    printf("\n");
}

void cbuff2_print() {
    if (len2 == 0) {
        printf("The cbuff is empty\n");
        return;
    }
    int i = 0;
    if (i == 0) {
            printf("");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        }
    for(int i = 1; i < len2; i++) {
        if (Gracz_B[(out2 + i) % 52] == 49) {
            printf("   ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
            continue;
        }
        if (Gracz_B[(out2 + i) % 52] < 10) {
            printf("  ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        } else {
            printf(" ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        }
    }
    printf("\n");
}

void cbuff2_print_game() {
    if (len2 == 0) {
        printf("The cbuff is empty\n");
        return;
    }
    int i = 0;
    if (i == 0) {
            printf("");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        }
    for(int i = 1; i < len2; i++) {
        if (Gracz_B[(out2 + i) % 52] == 28) {
            printf("   ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
            continue;
        }
        if (Gracz_B[(out2 + i) % 52] < 10) {
            printf("  ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        } else {
            printf(" ");
            printf("%d", Gracz_B[(out2 + i) % 52]);
        }
    }
    printf("\n");
}

int Gracz_A_pop() {
    if (len1 == 0) {
        return -1;
    }
    int x = Gracz_A[out1];
    out1 = (out1 + 1) % 52;
    len1--;
    return x;
}

int Gracz_B_pop() {
    if (len2 == 0) {
        return -1;
    }
    int z = Gracz_B[out2];
    out2 = (out2 + 1) % 52;
    len2--;
    return z;
}

double Gracz_A_push(int cli_nr) {
    if (len1 >= CBUFF_SIZE) {
        return INFINITY;
    }
    Gracz_A[(out1 + len1) % 52] = cli_nr;
    len1++;
    return 0.0;
}

double Gracz_B_push(int cli_nr) {
    if (len2 >= CBUFF_SIZE) {
        return INFINITY;
    }
    Gracz_B[(out2 + len2) % 52] = cli_nr;
    len2++;
    return 0.0;
}

int type_of_card(int card) {
    int temp = (card / 4) + 2;
    return temp;
}

int who_is_better() {
    cardA = type_of_card(Gracz_A[out1]);
    cardB = type_of_card(Gracz_B[out2]);
    if (cardA > cardB) return 1;
    if (cardA < cardB) return -1;
    return 0;
}

void Game(int range) {
    int fight = 0;
    int round = 0;
    while ((len1 != N) && (len2 != N) && (round < range)) { 
        round++;
        int meeting = who_is_better();
        if (meeting == 1) {
            Gracz_A_push(Gracz_A_pop());
            Gracz_A_push(Gracz_B_pop());
            fight++;

        } else if (meeting == -1) {
            Gracz_B_push(Gracz_B_pop());
            Gracz_B_push(Gracz_A_pop());
            fight++;

        } else if (meeting == 0) {
            int war = 1;
            int temp1 = out1;
            int temp2 = out2;
            while (meeting == 0) {
                if ((len1 <= 2) || (len2 <= 2)) {
                    printf("1 ");
                    printf("%d ", len1);
                    printf("%d ", len2);
                    return;
                }
                war = war + 2;
                out1 = out1 + 2;
                out2 = out2 + 2;
                meeting = who_is_better();
                if (meeting == 1) {
                    out1 = temp1;
                    out2 = temp2;
                    for(int i = 0; i < war; i++) {
                         Gracz_A_push(Gracz_A_pop());
                    }
                    for(int i = 0; i < war; i++) {
                         Gracz_A_push(Gracz_B_pop());
                    }
                } else if (meeting == -1) {
                    out1 = temp1;
                    out2 = temp2;
                    for(int i = 0; i < war; i++) {
                         Gracz_B_push(Gracz_B_pop());
                    }
                    for(int i = 0; i < war; i++) {
                         Gracz_B_push(Gracz_A_pop());
                    }
                }
            }

        } else printf("ERROR: Wrong meeting in Game_simplified");
    }
    if (len1 == N) {
        printf("2 %d", fight + 2);
    } else if (len2 == N) {
        printf("3\n");
        cbuff2_print_game();
    } else {
        printf("0 ");
        printf("%d ", len1);
        printf("%d ", len2);
    }
}

void Game_simplified(int range) {
    int fight = 0;
    int round = 0;
    while ((len1 != N) && (len2 != N) && (round <= range)) { 
        round++;
        int meeting = who_is_better();
        if (meeting == 1) {
            Gracz_A_push(Gracz_A_pop());
            Gracz_A_push(Gracz_B_pop());
            fight++;

        } else if (meeting == -1) {
            Gracz_B_push(Gracz_B_pop());
            Gracz_B_push(Gracz_A_pop());
            fight++;

        } else if (meeting == 0) {
            int x = Gracz_A_pop();
            int y = Gracz_B_pop();
            Gracz_A_push(x);
            Gracz_B_push(y);

        } else printf("ERROR: Wrong meeting in Game_simplified");

    }
    if (len1 == N) {
        printf("2 %d", fight + 1);
    } else if (len2 == N) {
        printf("3\n");
        cbuff2_print();
    } else {
        printf("0 ");
        printf("%d ", len1);
        printf("%d ", len2);
    }

}
int main() {
    int Version;
    int seed;
    int range;
    scanf("%d %d %d", &seed, &Version, &range);
    srand(seed);
    create_deck(karty);
    give_cards(karty, Gracz_A, Gracz_B);
    if (Version == 0) {
        Game(range);
    }   else {
        Game_simplified(range);
    }
    return 0;
}