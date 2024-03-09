#include "main.h"

using namespace std;
extern vector<tokens> data;
int main(int argc, char **argv)
{

    if(argc == 1)
    {
        cout << "Error : Pass file name as command line argument\n";
        cout << " Usage : ./a.out test.c " << endl;
        return 0;
    }

    char *ret = strchr(argv[1], '.');
    if(ret != NULL)
    {
        if(strcmp(ret, ".c") == 0)
        { 
            FILE *fptr = fopen(argv[1], "r");
            if(fptr == NULL)
            {

                cout << "Error in file opening" << endl;
                return 0;
            }
            cout << "open    : " << argv[1] << ": Success" << endl;
            cout << "parsing : " << argv[1] << ": Started" << endl << endl;
            tokenising(fptr);
            print_data(data);

            cout << endl << "parsing  : " << argv[1] << ": Done " << endl;
        }


        else { cout << "Error : pass only .c file as input" << endl; return 0; }
    }
    else { cout << "Error : pass valid file name " << endl; return 0;}

}
