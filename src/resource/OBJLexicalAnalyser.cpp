#include "headers/resource/OBJLexicalAnalyser.h"
#include <string.h>

OBJLexicalAnalyser::OBJLexicalAnalyser(char* cData)
:tokenLength(0),
 data(cData),
 pos(0)
{
    lookAhead = data[pos];
}


OBJLexicalAnalyser::~OBJLexicalAnalyser() {

    delete [] tokenValue;
    delete [] data;
}


void OBJLexicalAnalyser::appendChar(char c) {

    tokenLength++;
    //Create a new array, of 1 more length than previous
    newTokenValue = new char[tokenLength+1];
    //Ensure last token is a '\0', so strncpy works
    newTokenValue[tokenLength] = '\0';
    //Copy old token value into new token value
    if(tokenLength > 1) {
        strncpy(newTokenValue,tokenValue,tokenLength);
    }
    //Add new character
    newTokenValue[tokenLength-1] = c;
    //Delete old token value
    if(tokenLength > 1) {
        delete [] tokenValue;
    }
    //Assign new token value
    tokenValue = new char[tokenLength+1];
    strcpy(tokenValue,newTokenValue);
    //Delete temp
    delete [] newTokenValue;
}


void OBJLexicalAnalyser::updatePointers() {

    pos++;
    current = lookAhead;
    lookAhead = data[pos];
}


void OBJLexicalAnalyser::reversePointers() {

    pos--;
    lookAhead = data[pos];
    current = data[pos-1];
}


void OBJLexicalAnalyser::nextLine() {

    while(current != '\n') {
        updatePointers();
    }
    updatePointers();
}


bool OBJLexicalAnalyser::isWhiteSpace() {

    return current == ' ' || current == '\n' || current == '\r';
}


bool OBJLexicalAnalyser::isForwardSlash() {

    return current == '/';
}


bool OBJLexicalAnalyser::isDigit() {

    return current == '0' ||
           current == '1' ||
           current == '2' ||
           current == '3' ||
           current == '4' ||
           current == '5' ||
           current == '6' ||
           current == '7' ||
           current == '8' ||
           current == '9';
}


Token OBJLexicalAnalyser::getNextTokenOBJ() {

    //Reset the current token value.
    if(pos != 0) {
        delete [] tokenValue;
        tokenLength = 0;
    }
    
    //Move to the next character.
    updatePointers();
    
    //Ignore comments.
    while(current == '#') {
        nextLine();
    }

    //Ignore whitespace.
    while(isWhiteSpace()) {
        updatePointers();
    }

    //Ignore forward slash characters.
    while(isForwardSlash()) {
        updatePointers();
    }

    //Get next token. Always check for special characters first, before assuming
    //Token is just a simple string e.g for a file name
    if(current == 'v') {
        appendChar(current);
        if(lookAhead == ' ') {
            return Token(tokenValue,tokenLength,0);
        }
        else if (lookAhead == 't') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,1);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else if (lookAhead == 'n') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,2);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
                appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'f') {
        appendChar(current);
        if(lookAhead == ' ') {
            return Token(tokenValue,tokenLength,3);
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
                appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'g') {
        appendChar(current);
        if(lookAhead == ' ') {
            return Token(tokenValue,tokenLength,4);
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
                appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'u') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        if(!strcmp(tokenValue,"usemtl")) {
            return Token(tokenValue,tokenLength,5);
        }
        else {
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'm') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        if(!strcmp(tokenValue,"mtllib")) {
            return Token(tokenValue,tokenLength,6);
        }
        else {
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(isDigit()) {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace() && !isForwardSlash()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,7);
    }
    else if(current == '-') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace() && !isForwardSlash()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,8);
    }
    else if(current == '+') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace() && !isForwardSlash()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,9);
    }
    else {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,13);
    }
}


Token OBJLexicalAnalyser::getNextTokenMTL() {

    //Reset the current token value.
    if(pos != 0) {
        delete [] tokenValue;
        tokenLength = 0;
    }

    //Move to the next character.
    updatePointers();

    //Ignore comments.
    while(current == '#') {
        nextLine();
    }

    //Ignore whitespace.
    while(isWhiteSpace()) {
        updatePointers();
    }

    //Get next token. Always check for special characters first, before assuming
    //Token is just a simple string e.g for a file name
    if(current == 'm') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        if(!strcmp(tokenValue,"map_Ka") ||
           !strcmp(tokenValue,"map_Kd") ||
           !strcmp(tokenValue,"map_Ks") ||
           !strcmp(tokenValue,"map_d")  ||
           !strcmp(tokenValue,"map_bump")) {

            return Token(tokenValue,tokenLength,10);
        }
        else {
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'n') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        if(!strcmp(tokenValue,"newmtl")) {
            return Token(tokenValue,tokenLength,11);
        }
        else {
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'N') {
        appendChar(current);
        if(lookAhead == 's') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,12);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
                appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'K') {
        appendChar(current);
        if(lookAhead == 'a') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,14);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else if(lookAhead == 'd') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,15);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else if(lookAhead == 's') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,16);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                    appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
                appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'd') {
        appendChar(current);
        if(lookAhead == ' ') {
            return Token(tokenValue,tokenLength,17);
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
               appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(current == 'T') {
        appendChar(current);
        if(lookAhead == 'r') {
            updatePointers();
            appendChar(current);
            if(lookAhead == ' ') {
                return Token(tokenValue,tokenLength,18);
            }
            else {
                updatePointers();
                while(!isWhiteSpace()) {
                   appendChar(current);
                    updatePointers();
                }
                return Token(tokenValue,tokenLength,13);
            }
        }
        else {
            updatePointers();
            while(!isWhiteSpace()) {
               appendChar(current);
                updatePointers();
            }
            return Token(tokenValue,tokenLength,13);
        }
    }
    else if(isDigit()) {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,7);
    }
    else if(current == '-') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,8);
    }
    else if(current == '+') {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,9);
    }
    else {
        appendChar(current);
        updatePointers();
        while(!isWhiteSpace()) {
            appendChar(current);
            updatePointers();
        }
        return Token(tokenValue,tokenLength,13);
    }
}


int OBJLexicalAnalyser::getPos() {

    return pos;
}
