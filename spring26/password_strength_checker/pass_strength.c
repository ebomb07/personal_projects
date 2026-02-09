#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


void clear(){
    printf("\033[H\033[J");
    fflush(stdout);
}

double entro(char word[], int length){
    /* 
    

    E = log2(SIZE OF CHARACTER SET) * Length 
    
    Character sets (They can combine):

    0-9 = 10
    a-z = 26
    A-Z = 26
    symbols = 32

    ###########

    Ascii table (inclusive-inclusive) (assuming chars are between 33-126, inclusive):

    0-9 = 48-57 
    a-z = 97-122
    A-Z = 65-90
    symbol = 33-47 & 58-64 & 91-96 & 123-126

    ###########

    Example:

        Password: aB3!
        char set = 94
        length = 4

        log2(94) * 4 = ~26.22 bits of entropy (Very weak)

    */

    bool check_num = false;
    bool check_lower = false;
    bool check_upper = false;
    bool check_symbol = false;
    uint8_t total = 0; // 0-255
    double entropy = 0.0;

    for(int i=0; i < length; i++){
        //translates to ascii numbers
        uint8_t temp = (int)word[i];

        if (temp >= 48 && temp <= 57 && check_num == false){
            check_num = true;
            total = total + 10;
        }else if (temp >= 97 && temp <= 122 && check_lower == false){
            check_lower = true;
            total = total + 26;
        }else if (temp >= 65 && temp <= 90 && check_upper == false){
            check_upper = true;
            total = total + 26;
        }else if (((temp >= 33 && temp <= 47) || (temp >= 58 && temp <= 64) || (temp >= 91 && temp <= 96) || (temp >=123 && temp <= 126)) && check_symbol == false){
            check_symbol = true;
            total = total + 32;
        }
    }

    entropy = log((double)total) / log(2.0);
    entropy = entropy * (double)length;
    return entropy;
}

void output_password_check(double result,char word[],int len){
    printf("Your password: %s\nHas the length of: %d\nHas an entropy of: %f\nIt ",word, len, result);

    if (result > 0 && result <=35){
        printf("Is a Very weak password");
    }else if (result>=36 && result <= 59){
        printf("Is a Weak password");
    }else if (result >= 60 && result <= 119){
        printf("Is a strong password");
    }else if (result >= 120){
        printf("Is a very strong password");
    }else{
        printf("How did you get an entropy below 0");
    }
    printf("\n");
}

int main(){
    clear();
    int len = 31; 
    /* 
    Theoritical max of length for the entropy formula (until it reaches 1 || 100%)
    L = (1/log2(10)) * 100
    L = 30.103 (rounded)
    assuming lowest value of R = 10
    */
    char word[len];

    printf("What is the password (Max characters 30): ");

    if(fgets(word,len,stdin)){
        word[strcspn(word,"\n")] = '\0';
    }

    clear();
    double result = entro(word,strlen(word));



    output_password_check(result,word,strlen(word));
    return 0;
}