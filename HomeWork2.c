#include <stdio.h>
#include <string.h>
#define SIZE 1000

void input(char* str_in)
{
    FILE *in;
    in = fopen("input.txt","r");
    while(fscanf(in, "%[^\n]", str_in) == 1);
    fclose(in);
    
}
void change_variables(char* str_in, char* str_out)
{
 int size = strlen(str_in);
 int line = 0;
 int line1 = 0;
    FILE*out;
    out = fopen("output.txt","w");
    for (int i = 0; i < size; i++)
    {  
        if (str_in[i] == ' ')
            str_out[i] = ' ';
        else
        {
            if(str_in[i] == 'a')
                str_out[i] = 'b';
            if(str_in[i] == 'A')
                str_out[i] = 'B'; 
            if (str_in[i] == 'b')
                str_out[i] = 'a';
            if(str_in[i] == 'B')
                str_out[i] = 'A';          
        }
    }
    fprintf(out,"%s",str_out);
    fclose(out);
}

int main()
{
    char str_out[SIZE]={0};
    char str_in[SIZE]={0};
    input(str_in);
    change_variables(str_in, str_out);


}
