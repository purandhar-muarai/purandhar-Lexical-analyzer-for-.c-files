#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <string.h>
#include <vector>

#define KEYWORD   8
#define OPERATOR  1
#define LITERAL   2
#define IDENTIFIER 3

using namespace std;
class tokens
{
    public :
    string token;
    string token_type;
    tokens()
    {
        token = '\0';
        token_type = '\0';
    }
};



void store_data(char *value, vector<tokens> &data, int type);
void tokenising(FILE * );
char *mystrtok(char *arr, const char *delim);
void print_data(vector<tokens> &data);

#endif
