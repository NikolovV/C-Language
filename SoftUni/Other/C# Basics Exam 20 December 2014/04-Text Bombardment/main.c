#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 1001
#define COLUMN_BOMB 202

void alloc_2D_arr_memory(char ***str, int ROW, int COL);
void free_2D_memory(void **str, size_t size);
size_t remove_new_line(char *str);
void copy_to_2D_array(int ROW, int COL, char **matrix,
                      const char *src, size_t size);
void drop_the_bomb(int ROW, int COL, char **matrix);
void start_mission(int ROW, int COL, char **matrix, char *coordinate);
void print_the_field(int ROW, int COL, char **matrix, size_t lenght);

int main()
{
    char text[TEXT_SIZE];
    fgets(text, TEXT_SIZE, stdin);
    size_t textLenght = remove_new_line(text);

    int lineLenght;
    scanf("%3d%*c", &lineLenght);
    float rows = textLenght / ((float) lineLenght);
    int rowLenght = (int) rows + 1;

    char bomb[COLUMN_BOMB];
    fgets(bomb, TEXT_SIZE, stdin);
    remove_new_line(bomb);

    char **field = NULL;
    alloc_2D_arr_memory(&field, rowLenght, lineLenght);

    copy_to_2D_array(rowLenght, lineLenght, field, text, textLenght);

    start_mission(rowLenght, lineLenght, field, bomb);

    print_the_field(rowLenght, lineLenght, field, textLenght);

    free_2D_memory((void **) field, rowLenght);

    return (EXIT_SUCCESS);
}

void print_the_field(int ROW, int COL, char **matrix, size_t lenght)
{
    int row, col, ctr = 0;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++, ctr++)
        {
            printf("%c", matrix[row][col]);
            if (ctr == lenght)
            {
                break;
            }
        }
    }
}

void drop_the_bomb(int ROW, int COL, char **matrix)
{
    int row, col = COL;
    for (row = 0; row < ROW;)
    {
        if (matrix[row][col] != ' ')
        {
            matrix[row][col] = ' ';
            row++;
            if (row < ROW - 1)
            {
                if (matrix[row][col] == ' ')
                {
                    break;
                }
            }
        }
        else
        {
            if (matrix[row][col] == ' ')
            {
                row++;
            }
        }
    }
}

void start_mission(int ROW, int COL, char **matrix, char *coordinate)
{
    char *token = strtok(coordinate, " ");
    while (token)
    {
        int currentCoordinate = atoi(token);
        drop_the_bomb(ROW, currentCoordinate, matrix);
        token = strtok(NULL, " ");
    }
}

void copy_to_2D_array(int ROW, int COL, char **matrix, const char *src, size_t size)
{
    int row, col, j = 0;
    for (row = 0; row < ROW; row++)
    {
        for (col = 0; col < COL; col++)
        {
            if (j < size)
            {
                matrix[row][col] = src[j];
                j++;
            }
            else
            {
                matrix[row][col] = ' ';
            }
        }
    }
}

size_t remove_new_line(char *str)
{
    int lenght = strlen(str);
    if (str[lenght - 1] == '\n')
    {
        str[lenght - 1] = '\0';
    }
    return lenght - 1;
}

void alloc_2D_arr_memory(char ***str, int ROW, int COL)
{
    *str = (char **) malloc(ROW * sizeof (char *));
    if (!(*str))
    {
        fprintf(stderr, "Can't allocate memory!");
        exit(1);
    }
    int i;
    for (i = 0; i < ROW; i++)
    {
        (*str)[i] =(char *) calloc(COL, sizeof (char));
        if (!(*str)[i])
        {
            fprintf(stderr, "Can't allocate memory!\n");
            free((*str));
            exit(1);
        }
    }
}

void free_2D_memory(void **str, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(str[i]);
    }
    free(str);
}