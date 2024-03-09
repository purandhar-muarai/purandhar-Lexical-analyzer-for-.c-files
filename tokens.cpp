#include "main.h"

vector<tokens> data;
int flag = 0;

void tokenising(FILE *fptr)
{
    string keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};


    // finding the file to get the size of the given file
    fseek(fptr, 0, SEEK_END);
    int fsize = ftell(fptr);
    // setting fptr back to index 0
    fseek(fptr, 0, SEEK_SET);

    char delim[] = "\n\r+-*/=,;{}[]()&  ";

    int ksize = sizeof(keywords)/sizeof(keywords[0]); // finding size of the keywords array

    char *buf = new char[fsize];
    if(fread(buf, 1, fsize, fptr) != 0) // reading from the file
    {
        char op;
        cout << "Do you want operators in the list (y/n): ";
        cin >> op ;
        cout << endl;
        if(op == 'y' || op == 'Y') {
            //finding operators in the buf/file
            for(int i = 0; i < fsize; i++) {
                if (strchr("+-*/=,;{}[]()&>><<", buf[i]) != NULL)
                {
                    char op[2] = {buf[i], '\0'};
                    store_data(op, data, OPERATOR);
                }
            }
        }

        char *token = strtok(buf, " ");
        while(token != NULL)
        {
            flag = 0;
            //checking for keywords
            for(int i = 0; i < ksize; i++)
            { 
                if(token == keywords[i])
                {
                    flag = 1;
                    store_data(token, data, KEYWORD);
                    break;
                }
            }
            // checking for literals
            if(flag == 0)
            {
                if(*token == '\'' || (*token >= '0' && *token <= '9'))
                {
                    store_data(token, data, LITERAL);
                }
                else if(*token == '"')
                {
                    char data1[1000];
                    strcpy(data1, token);
                    token = strtok(NULL, "\"");
                    strcat(data1,token);
                    strcat(data1,"\""); 
                    store_data(data1, data, LITERAL);

                }
                //storing as identifier
                else
                    store_data(token, data, IDENTIFIER);
            }
            token = strtok(NULL, delim);
        }
        delete[] buf;
    }
    else
    {
        cout << "Reading from file is failed" << endl;
    }
}
