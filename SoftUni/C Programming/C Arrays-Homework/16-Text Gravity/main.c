/* 
 Write  a  program  that  takes  as  input  a line  length and text and  formats
 the  text  so  that  it  fits  inside  several  rows, each  with  length  equal
 to  the  given  line  length.  Once  the  text  is  fitted,  each  character  
 starts  dropping  as  long  as there is an empty space below it.
 The input will come from the console. It will consist of two lines.
 * The first line will hold the line length.
 * The second input line will hold a string.
 Output
 * The  output  consists  of lines,  enclosed  in  pipe  characters  ('|'). 
 Print space"  "  in  all  empty  cells.  See  the  example below.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Text_Gravity.h"

int main()
{
    int row, col;

    printf("Enter col length: ");
    check_intInput(&col);
    
    char text[BUFFER];
    fgets(text, BUFFER, stdin);
    int textLength = remove_new_line(text);
    
    double maxRow = textLength / (double)col;
    row = (int)maxRow + 1;
    
    char matrixText[row][col];
    fill_D_array(row, col, matrixText, text, textLength);
    
    print_matrix(row, col, matrixText);
    
    text_gravity(row, col, matrixText);
    
    printf("\n");
    print_matrix(row, col, matrixText);
 
    return (EXIT_SUCCESS);
}