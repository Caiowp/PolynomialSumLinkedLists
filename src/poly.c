#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "poly.h"
#include "listADT.h"
//#define MAXC       1024   /* if you need a constant, #define one (or more) */
//#define MAXCOEF     256
#define _GNU_SOURCE
#define TERM_COUNT 100

//#define MAXEXP  MAXCOEF
//#define MAXPOLY 5
//#define DELIM    "x^\n"

unsigned char skip_spaces(char *p, char **pp) {
    unsigned char c;
    while (isspace(c = *p))
        p++;
    *pp = p;
    return c;
}

void show_error(const char *error, const char *str, const char *p) {
    fprintf(stderr, "error: %s\n%s%*s^\n", error, str, (int)(p - str), "");
}



void polyFile(char* file){
//	char line[100];
	char *p;
    int coef[TERM_COUNT][TERM_COUNT] = { 0 };
    int expo[TERM_COUNT][TERM_COUNT] = { 0 };
    int counter;
    int checkNodeAdded;
    int checkNodeRemoved;
    LIST* l = createList(compare);
    FILE * fp;
    char * line = NULL;
//    int poly=0;
    size_t len = 0;
    ssize_t read;
    int j=0;
//    char tmp[MAXC];              /* input & reformat buffers */
//    int coef[j][MAXCOEF] = {0},                /* coefficient array */
//        expo[j][MAXEXP] = {0},                 /* exponent array */
//        n = 0, ndx = 0;                     /* counter and index */
//    int ctmp[MAXPOLY], etmp[MAXPOLY];   /* temp values for coefficient and exponent */

    fp = fopen(file,"r");
    if (fp == NULL)
        exit(1);

    while ((read = getline(&line, &len, fp)) != -1) {
//        printf("Retrieved line of length %zu:\n", read);
//        printf("%s", line);

		p = line;

		for (counter = 0; counter < TERM_COUNT; counter++) {
			int sign = 1;
			unsigned char c = skip_spaces(p, &p);
			if (c == '\0')
				break;
			if (c == '+') {
				c = skip_spaces(p + 1, &p);
			} else
			if (c == '-') {
				sign = -1;
				c = skip_spaces(p + 1, &p);
			}
			if (c == '\0') {
				show_error("missing term", line, p);
				break;
			}
			if (isdigit(c)) {
				coef[j][counter] = sign * strtol(p, &p, 10);
				c = skip_spaces(p, &p);
			} else {
				coef[j][counter] = sign;
			}
			if (c == 'x') {
				c = skip_spaces(p + 1, &p);
				if (c == '^') {
					c = skip_spaces(p + 1, &p);
					if (isdigit(c)) {
						expo[j][counter] = strtol(p, &p, 10);
						c = skip_spaces(p, &p);
					} else {
						show_error("missing exponent", line, p);
						break;
					}
				} else {
					expo[j][counter] = 1;
				}
			} else {
				expo[j][counter] = 0;
			}
			if (c != '\0' && c != '+' && c != '-') {
				show_error("syntax error", line, p);
				break;
			}
		}

		for (int i = 0; i < counter; i++){
			printf("%+dx^%d", coef[j][i], expo[j][i]);
			checkNodeAdded = addNode(l, (int*)&coef[j][i], (int*)&expo[j][i]);

		}



		printf("\n");
		j++;
    }

    fclose(fp);

    if (line)
        free(line);

   removeNodesByCoef(l, 0);

   printList(l);
   destroyList(l);

}


