#include "cdata0.h"
#include "cdata1.h"
#include <stdint.h>


int main()
{
    CData0 data0(10);
    printf("data 0:  \n");
    data0.print();
    data0.sort();
    printf("data 0 sorted:  \n");
    data0.print();

    printf("\n");
    CData1 data1(10);
    printf("data 1:  \n");
    data1.print();
    data1.sort();
    printf("data 1 sorted:  \n");
    data1.print();

    printf("\n data 0 = data 1:  \n");
    data0 = data1;
    data0.print();


    printf("\n");
    CData0 data2(7);
    printf("data 2:  \n");
    data2.print();
    //data2 = data0;
    printf("data 2 equals to data 0:  \n");
    data2.print();

    printf("\n");
    CData0 data3(5);
    printf("data 3:  \n");
    data3.print();
    data3 = data0 + data2;
    printf("data 0 is data 0 + data 2:  \n");
    data3.print();

    printf("\n");
    CData1 data4(5);
    printf("data 4:  \n");
    data4.print();
    data4 = data1 + data4;
    printf("data 4 += data 1:  \n");
    data4.print();

    printf("\n");
    int len = 4;
    CData **temp = new CData*[len];
    temp[0] = &data0;
    temp[1] = &data2;
    temp[2] = &data3;
    temp[3] = &data1;

    printf("temp 1 2 3 = data 0 + data 2 + data 3 :  \n");
    for(int i = 0; i < len; i ++)
    {
        temp[i]->print();
    }

    printf("\n\n");
    //CData0 sum(0);
    CData0 buff(1);
    buff = *(temp[len-1]);

    for(int i = len - 1; i > 0; i --)
    {
        *temp[i] = *temp[i - 1];
    }
    *temp[0] = buff;

    printf("temp 3 2 1 :  \n");
    for(int i = 0; i < len; i ++)
    {
        temp[i]->print();
    }


    //printf("\n");
    //printf("temp 3 + temp 2 + temp 1 :  \n");
    //(*temp[0] + *temp[1] + *temp[2] + *temp[3]).print();



    //delete [] temp;
    return 0;
}
