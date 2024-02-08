#include <stdio.h>
#include <string.h>
const int SIZE = 100;
void change_symbols(int size, char * line)
{
    int i = 0, j;
    char b;
    while (i < size)
    {
       while (line[i] == ' ')
           i++;
       j = i + 1;
       while (line[j] == ' ')
           j++;
       if (j >= size) 
           break;
       b = line[i];
       line[i] = line[j];
       line[j] = b;        
       i = j + 1;
    }
}
void main(void)
{   
    FILE* f_in;
    if(!f_in)
        f_in = fopen("input.txt", "r"); 
    char str_in[SIZE];
    fscanf(f_in, "%[^\n]",str_in);
    fclose(f_in);
    FILE * f_out;
    if(!f_out)
        f_out = fopen("output.txt","w");
    change_symbols(strlen(str_in),str_in);
    fprintf(f_out, "%s", str_in);
    fclose(f_out);
}
