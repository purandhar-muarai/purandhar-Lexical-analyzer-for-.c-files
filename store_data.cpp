#include "main.h"

void store_data(char *value, vector<tokens> &data, int type)
{
    //cout << "store data" << endl;
    tokens t1;
    switch(type)
    {
        case OPERATOR:
            t1.token = value;
            t1.token_type = "operator  ";
            break;
        case KEYWORD: 
            t1.token_type = "keyword   ";
            t1.token = value;
            break;
        case IDENTIFIER:
            t1.token_type = "identifier";
            t1.token = value;
            break;
        case LITERAL:
            t1.token_type = "literal   ";
            t1.token = value;
            break;
    }
    data.push_back(t1);

   // cout <<t1.token_type << "   :   " << t1.token << endl;
    //cout << data.front().token << data.front().token_type << endl;
}
void print_data(vector<tokens> &data)
{

    for(auto &it : data)
    {
        cout << it.token_type << " : " << it.token << endl;
    }
}

