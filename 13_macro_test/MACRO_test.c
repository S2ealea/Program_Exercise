/*Macro test*/
#include <stdio.h>

int main(int argc, char* argv[])
{

    printf("%d\n",__LINE__);    // print the line number
    printf("%s\n",__FILE__);    // print the file name
    printf("%s\n",__DATE__);    // print the date
    printf("%s\n",__TIME__);    // print the time
    printf("%s\n",__func__);    // print the outer function name

    return 0;
}
