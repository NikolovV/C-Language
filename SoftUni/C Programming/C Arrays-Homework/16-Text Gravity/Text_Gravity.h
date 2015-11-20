#ifndef TEXT_GRAVITY_H
#define	TEXT_GRAVITY_H

#define BUFFER 1000

void check_intInput(int *a);
void fill_D_array(int ROW, int COL, char strTwoD[][COL], char str[], int size);
int remove_new_line(char *str);
void print_matrix(int ROW, int COL, char a[][COL]);
void text_gravity(int ROW, int COL, char a[][COL]);

#endif	/* TEXT_GRAVITY_H */

