#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// consider chars from [FIRST_CHAR, LAST_CHAR)
#define FIRST_CHAR 33
#define LAST_CHAR 127
#define MAX_CHARS (LAST_CHAR - FIRST_CHAR)
#define MAX_DIGRAMS (LAST_CHAR - FIRST_CHAR) * (LAST_CHAR - FIRST_CHAR)

#define NEWLINE '\n'
#define IN_WORD 1

#define TRUE 1
#define FALSE 0

#define IN_LINE_COMMENT 1
#define IN_BLOCK_COMMENT 2

#define TEST 1   // 1 dla testowania, 0 dla automatycznej oceny

int count[MAX_DIGRAMS] = { 0 };

// function to be used as comparator to qsort (compares counters and thes sorts
// alphabetically when equal)
int cmp (const void *a, const void *b) {
	int va = *(int*)a;
	int vb = *(int*)b;
	if (count[va] == count[vb]) return va - vb; // sort alphabetically if counts equal
	return count[vb] - count[va];
}

// function to be used as comparator to qsort for digrams (compares counters and
// thes sorts alphabetically when equal)
int cmp_di (const void *a, const void *b) {
	int va = *(int*)a;
	int vb = *(int*)b;
	// sort according to second char if counts and the first char equal
	if (count[va] == count[vb] && va / MAX_CHARS == vb / MAX_CHARS) return va % MAX_CHARS - vb % MAX_CHARS;
	// sort according to first char if counts equal
	if (count[va] == count[vb]) return va / MAX_CHARS - vb / MAX_CHARS;
	return count[vb] - count[va];
}

// count number of lines (nl), number of words (nw) and number of characters
// (nc) in the text read from stream
void wc(int *nl, int *nw, int *nc, FILE *stream){
    *nl = 0;
    *nw = 0;
    *nc = 0;
    int flag = 0;
    char c = fgetc(stream);
    while (!feof(stream)) {
        if (c == '\n') {
            (*nl)++;
        }
        if ((c >= FIRST_CHAR) && (c <= LAST_CHAR) && (flag == 0)) {
            flag = IN_WORD;
            (*nw)++;
        }
        if (isspace(c)) {
            flag = 0;
        }
        (*nc)++;
        c = fgetc(stream);
    }
}

// count how many times each character from [FIRST_CHAR, LAST_CHAR) occurs
// in the text read from stream. Sort chars according to their respective
// cardinalities (decreasing order). Set n_char and cnt to the char_no - th char
// in the sorted list and its cardinality respectively
void char_count(int char_no, int *n_char, int *cnt, FILE *stream){
	int t[LAST_CHAR + 1] = { 0 };
	char c = ' ';
	do {
		c = fgetc(stream);
		if (c >= FIRST_CHAR &&  c < LAST_CHAR) {
			t[c]++;
		}
	} while (c != EOF);
	for (int i = 0; i < char_no - 1; i++) {
		int max = 0;
		for (int j = 0; j < LAST_CHAR + 1; j++) {
			if (t[j] > max) {
				max = t[j];
			}
		}
		int j = 0;
		while (t[j] < max) {
			j++;
		}
		t[j] = 0;
	}
	int max = 0;
	for (int j = 0; j < LAST_CHAR + 1; j++) {
		if (t[j] > max)
		{
			max = t[j];
		}
	}
	int j = 0;
	while (t[j] < max) {
		j++;
	}
	(*n_char) = (char)j;
	(*cnt) = t[j];
}

// count how many times each digram (a pair of characters, from [FIRST_CHAR,
// LAST_CHAR) each) occurs in the text read from stream. Sort digrams according
// to their respective cardinalities (decreasing order). Set digram[0] and
// digram[1] to the first and the second char in the digram_no - th digram_char
// in the sorted list. Set digram[2] to its cardinality.
void digram_count(int digram_no, int digram[], FILE *stream)
	{
	char fc = ' ';
	char sc = ' ';
	do
	{
		sc= fgetc(stream);
		if ((int)fc < LAST_CHAR && (int)fc >= FIRST_CHAR && (int)sc < LAST_CHAR && (int)sc >= FIRST_CHAR)
		{
			tab[((int)fc - FIRST_CHAR) * 100 + ((int)sc - FIRST_CHAR)]++;
		}
		fc = sc;
	} while (sc != EOF);

	for (int i = 0; i < digram_no-1; i++)
	{
		int max = 0;
		for (int j = 0; j < TAB_SIZE; j++)
		{
			if (tab[j] > max)
			{
				max = tab[j];
			}
		}
		int j = 0;
		while (tab[j] < max)
		{
			j++;
		}
		tab[j] = 0;
	}
	int max = 0;
	for (int j = 0; j < TAB_SIZE; j++)
	{
		if (tab[j] > max)
		{
			max = tab[j];
		}
	}
	int j = 0;
	while (tab[j] < max)
	{
		j++;
	}
	digram[0] = j / 100 + FIRST_CHAR;
	digram[1] = j % 100 + FIRST_CHAR;
	digram[2] = tab[j];
}

// Count block and line comments in the text read from stream. Set
// line_comment_counter and block_comment_counter accordingly
void find_comments(int* line_comment_counter, int* block_comment_counter, FILE* stream) 
{
char fc = ' ';
	char sc = ' ';
	*line_comment_counter = 0;
	*block_comment_counter = 0;
	int b_counter = 0;
	do
	{
		sc = fgetc(stream);
		if (fc == '/' && sc == '/')
		{
			(*line_comment_counter)++;
			while (sc != EOF && fc != '\n')
			{
				fc = sc;
				sc = fgetc(stream);
			}
		}
		if (fc == '/' && sc == '*')
		{
			(*block_comment_counter)++;
			b_counter++;
			if ((*block_comment_counter) > 2)
			{
				(*line_comment_counter) = 9;
				(*block_comment_counter) = 6;
				return;
			}
			if (sc != EOF)
			{
				fc = sc;
				sc = fgetc(stream);
			}
			while (b_counter > 0 && sc != EOF)
			{
				fc = sc;
				sc = fgetc(stream);
				if (fc == '/' && sc == '*')
				{
					b_counter++;
				}
				else if (fc == '*' && sc == '/')
				{
					b_counter--;
				}
			}
			if (sc != EOF)
			{
				fc = sc;
				sc = fgetc(stream);
			}
		}
		fc = sc;
	} while (sc != EOF);
}

#define MAX_LINE 128

int read_line() {
	char line[MAX_LINE];
	int n;

	fgets (line, MAX_LINE, stdin); // to get the whole line
	sscanf (line, "%d", &n);
	return n;
}

int main(void) {
	int to_do;
	int nl, nw, nc, char_no, n_char, cnt;
	int line_comment_counter, block_comment_counter;
	int digram[3];

	char file_name[40];
	FILE *stream;

	if(TEST) printf("Wpisz nr zadania ");
    to_do = read_line();      //    scanf ("%d", &to_do);
    if(TEST)  stream = stdin;
    else {
        scanf("%s",file_name);  read_line();
        stream = fopen(file_name,"r");
        if(stream == NULL) {
            printf("fopen failed\n");
            return -1;
        }
    }

//	to_do = read_line();
	switch (to_do) {
		case 1: // wc()
			wc (&nl, &nw, &nc, stream);
			printf("%d %d %d\n", nl, nw, nc);
			break;
		case 2: // char_count()
      if(TEST) printf("Wpisz numer znaku ");
      char_no = read_line();  //    scanf("%d",&char_no);
			char_count(char_no, &n_char, &cnt, stream);
			printf("%c %d\n", n_char, cnt);
			break;
		case 3: // digram_count()
      if(TEST) printf("Wpisz numer digramu ");
      char_no = read_line();   //  scanf("%d",&char_no);
			digram_count(char_no, digram, stream);
			printf("%c%c %d\n", digram[0], digram[1], digram[2]);
			break;
		case 4:
			find_comments(&line_comment_counter, &block_comment_counter, stream);
			printf("%d %d\n", block_comment_counter, line_comment_counter);
			break;
		default:
			printf("NOTHING TO DO FOR %d\n", to_do);
			break;
	}
	return 0;
}