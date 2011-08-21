#include "headers/resource/Token.h"
#include <math.h>
#include <string.h>

Token::Token(char* cData, int l, int cType)
:data(new char[l+1]),
 type(cType),
 length(l)
{
    strcpy(data,cData);
}


Token::~Token() {

    delete [] data;
}


int Token::toInt() {

    //Result
    int result = 0;
    //Current digit
    int digit = 0;

    //Check for negativity
    bool isNegative = data[0] == '-';
    //Check if number has a positive or negative sign to find the start index
    int i = isNegative || data[0] == '+' ? 1 : 0;
    //Iterate over each number in the arrya
    while(i < length) {
        //Get the number value of the current char
        if(data[i] >= '0' && data[i] <= '9') {
            digit = data[i] - '0';
        }
        else {
            //Handled by returning the current value of result.
            return result;
        }
        //Update the result
        result = 10*result + digit;
        i++;
    }

    //Return result, with or without negative results
    return isNegative ? -result : result;
}


float Token::toFloat() {

    //Result
    float result = 0.0f;
    //Current digit
    int digit = 0;

    //Check for negativity
    bool isNegative = data[0] == '-';
    //Check if number has a positive or negative sign to find the start index
    int i = isNegative || data[0] == '+' ? 1 : 0;

    bool hasFraction = false;
    bool hasExponent = false;

    //Read Integer part
    while(i < length) {
        //Get the number value of the current char
        if(data[i] >= '0' && data[i] <= '9') {
            digit = data[i] - '0';
        }
        //If decimal point is found, break the loop
        else if(data[i] == '.') {
            hasFraction = true;
            i++;
            break;
        }
        //If exponent sign is found, break the loop
        else if(data[i] == 'e' || data[i] == 'E') {
            hasExponent = true;
            i++;
            break;
        }
        //Return a NAN value if this is not a floating point number
        else {
            return FP_NAN;
        }
        //Update result
        result = 10*result + digit;
        i++;
    }

    //Read Decimal part
    if(hasFraction) {
        //Number of decimal places
        int decPlaces = 0;
        while(i < length) {
            //Get the number value of the current char
            if(data[i] >= '0' && data[i] <= '9') {
                digit = data[i] - '0';
                decPlaces++;
            }
            //If exponent size is found, break the loop
            else if(data[i] == 'e' || data[i] == 'E') {
                hasExponent = true;
                i++;
                break;
            }
            //Return a NAN value if this is not a floating point number
            else {
                return FP_NAN;
            }
            //Update result
            result = 10*result + digit;
            i++;
        }
        //Convert result to decimal
        result = result / pow(10,decPlaces);
    }

    //Read Exponent part
    if(hasExponent) {
        //Exponent
        int E = 0;
        //Check for negative exponent
        bool isNegativeE = data[i] == '-';
        i = isNegative || data[i] == '+' ? i+1 : i;
        while(i < length) {
            //Get the number value of the current char
            if(data[i] >= '0' && data[i] <= '9') {
                digit = data[i] - '0';
            }
            //Return a NAN value if this is not a floating point number
            else {
                return FP_NAN;
            }
            //Update exponent
            E = 10*E + digit;
            i++;
        }
        //Convert exponent to negative if needed, and add to result
        E = isNegativeE ? -E : E;
        result = pow(result,E);
    }

    //Convert result to negative if needed
    result = isNegative ? -result : result;

    //Check if result is value, and return it or not NAN
    return result != result ? FP_NAN : result;
}


char* Token::copyData() {

    char* dataCopy = new char[length+1];
    strcpy(dataCopy,data);
    return dataCopy;
}
