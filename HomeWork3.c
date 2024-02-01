#include <stdio.h>
#include <string.h>
#define SIZE 1000

void input2(char* str_in)
{
    FILE* in;
    in = fopen("input.txt","r");
    while(fscanf(in, "%[^\n]", str_in) == 1);
    fclose(in);
}

void buf_numbers(char *buffer,char* string_in)
{
    int size_in = strlen(string_in);
    int index = 0;
    for (int i = 0; i < size_in; i++)
    {
        if (string_in[i] >='0' && string_in[i] <= '9')  
            buffer[index++] = string_in[i];        
    }
}

void sortirovka (char* buffer)
{
    int size_buf = strlen(buffer);
    for (int i = 0; i < size_buf; i++)
    {
        for (int j = i; j < size_buf ; j++)
        {
            if (buffer[i]>buffer[j])
            {
                int temp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = temp;
            }
            
        }
        
    }
    
}
void print_result(char* buffer)
{
    int size_buf = strlen(buffer);
    FILE*out;
    out = fopen("output.txt","w");
    fprintf(out,"%s",buffer);
    fclose(out);
}
int main()
{
    char str_out[SIZE]={0};
    char str_in[SIZE]={0};
    input2(str_in);
    buf_numbers(str_out,str_in);
    sortirovka(str_out);
    print_result(str_out);
}