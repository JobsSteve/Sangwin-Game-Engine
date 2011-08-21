#ifndef OBJLEXICALANALYSER_H
#define	OBJLEXICALANALYSER_H

#include "headers/resource/Token.h"

/**
 * The OBJLexicalAnalyser class parses .OBJ and .MTL files into individual
 * Tokens. These individual Tokens can then be handled depending on their type
 * by the OBJLoader.
 *
 * To get the next Token from the OBJLexicalAnalyser, the getNextTokenOBJ() or
 * getNextTokenMTL() function must be called, depending on the file size.
 *
 * The OBJLexicalAnalyser does not alert to EOF, so the file size should be
 * known in advance in order to avoid overrunning. The current position in the
 * file can be checked with the getPos() function.
 *
 * @see Token
 * @see OBJLoader
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Resource
 */
class OBJLexicalAnalyser: public Object {

public:

    /**
     * Default constructor. Takes file data to get each Token from.
     *
     * @param cData file data
     */
    OBJLexicalAnalyser(char * cData);
    /**
     * Destructor.
     */
    ~OBJLexicalAnalyser();

    /**
     * Append the given char to the current Token value. The Token value is
     * always terminated by the '\0' character.
     *
     * @param c char to append
     */
    void appendChar(char c);
    /**
     * Update the file pointers by moving them both along the file by 1
     * character.
     */
    void updatePointers();
    /**
     * Move the file pointers back one step.
     */
    void reversePointers();
    /**
     * Move to the next line in the file. Checks for the newline character.
     */
    void nextLine();
    /**
     * Checks if the current character is whitespace. Whitespace is described by
     * " ", newline characters or carriage returns.
     *
     * @return true if current character is whitespace, false if not
     */
    bool isWhiteSpace();
    /**
     * Check if the current character is a forward slash. These are used in .OBJ
     * files to break up indices, so it is useful to known when one is found.
     *
     * @return true if current character is a forward slash, false if not
     */
    bool isForwardSlash();
    /**
     * Check if the current character is a digit (0 to 9).
     *
     * @return true if current character is a digit, false if not
     */
    bool isDigit();
    /**
     * Check if the lookahead character is a digit (0 to 9).
     * 
     * @return true if lookahead character is a digit, false if not
     */
    bool lookAheadIsDigit();
    /**
     * Get the next Token from an .OBJ file.
     *
     * @return next Token
     */
    Token getNextTokenOBJ();
    /**
     * Get the next Token from an .MTL file.
     *
     * @return next Token
     */
    Token getNextTokenMTL();
    /**
     * Get the position of the current pointer into the file.
     *
     * @return position in the file
     */
    int getPos();

private:

    char current; ///< current character being examined
    char lookAhead; ///< 1 character lookahead
    char* tokenValue; ///< current Token data
    char* newTokenValue; ///< convenience variable, used for speed
    int tokenLength; ///< length of the current Token
    char* data; ///< file data
    int pos; ///< current position in the file

    /**
     * Copying is not supported.
     *
     * @param rhs
     */
    OBJLexicalAnalyser(const OBJLexicalAnalyser& rhs);
    /**
     * Copying is not supported.
     */
    OBJLexicalAnalyser& operator=(const OBJLexicalAnalyser& rhs);
};

#endif	/* OBJLEXICALANALYSER_H */

