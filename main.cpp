#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

#define BIAS 7

using namespace std;

string floatToBin(float n){
    double backupNum;
    double num = n;
    string numStr = "";

    if(num==0){
        return "0000000000000000";

    } else if (num < 0){
        numStr+='1';
        num = -num;
    }
    else{
        numStr+='0';
    }

    backupNum = num;
    int exp = 0;
    //cout << numStr << endl;

    if(num >= 1){
        while ( (int)num > 1 ) {
            num = num / 2;
            exp++;
        }

    }
    else{
        while (  (int) num < 1 ){
            num = num * 2;
            exp --;
        }
    }

    //printf("Unbiased Exp = %d\n", exp);
    exp += BIAS;
    //printf("Biased Exp = %d\n", exp);

    for(int i=3; i>=0; i--){
        if( (exp & (1<<i) ) == 0 ){
            numStr += '0';
        }
        else{
            numStr += '1';
        }
    }

    for(int i=0; i<11; i++){
        num*=2;

        if ( ( ( (int)num ) & 1 ) ==0  ){
            numStr += '0';
        }
        else{
            numStr += '1';
        }

    }


    return numStr;
}


float binToFloat(char *str){

}



int main() {
    int ch=0;
    float num;
    string binStr;

    char *str = new char[20];

    while(true){

        //printf("1. Float to Binary\t2. Binary to float\t3. Exit\n");
        //scanf("%d", &ch);
        if(1){
            printf("Give a float number :");

            scanf("%f", &num);
            binStr = floatToBin(num);

            cout << binStr << endl;

        }
        else if(ch==2){
            printf("Give a binary string :");

            scanf("%s", &str);

            num = binToFloat(str);

            cout << num << endl;


        }
        else if(ch==3){
            break;
        }
        else{
            printf("Invalid choice");
        }

    }








    return  0;
}
