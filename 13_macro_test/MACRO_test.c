/*Macro test*/
#include <stdio.h>

int main(int argc, char* argv[])
{

    printf("%d\n",__LINE__);    // print the line number
    printf("%s\n",__FILE__);    // print the file name
    printf("%s\n",__DATE__);    // print the date
    printf("%s\n",__TIME__);    // print the time
    printf("%s\n",__func__);    // print the outer function name
    printf("%d\n",__STDC__);    // exam whether the compiler 
                                // support c iso, 1 for supoort
    printf("%d\n",__STDC_VERSION__);    // print the supported standers
                                        // Note:compile with -std=c99


    return 0;
}
