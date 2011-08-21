#ifndef TOKEN_H
#define	TOKEN_H

#include "headers/utils/Object.h"

/**
 * The Token class is used by the OBJLexicalAnalyser to store individual tokens
 * found in a .OBJ file.
 *
 * Each Token object holds the actual data, the length of the data and the type
 * of the token found. It provides functions to convert the data into either
 * floating point or integer format, and also to return a deep copy of the
 * token data in char array.
 *
 * Token Types are as follows:
 * 
 *  - 0 = v
 *  - 1 = vt
 *  - 2 = vn
 *  - 3 = f
 *  - 4 = g
 *  - 5 = usemtl
 *  - 6 = mtllib
 *  - 7 = unsigned number
 *  - 8 = negative number
 *  - 9 = positive number
 *  - 10 = map_
 *  - 11 = newmtl
 *  - 12 = Ns
 *  - 13 = string
 *  - 14 = Ka
 *  - 15 = Kd
 *  - 16 = Ks
 *  - 17 = d
 *  - 18 = Tr
 * 
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Resource
 */
class Token: public Object {

public:

    char* data; ///< the actual data held by this Token
    int type; ///< the type of this Token
    int length; ///< the length of this Token

    /**
     * Default constructor. Create a new Token with the given data, length
     * and type.
     *
     * @param cData Token Data
     * @param l Token Length
     * @param cType Token Type
     */
    Token(char* cData, int l, int cType);
    /**
     * Destructor.
     */
    ~Token();

    /**
     * Return this Token's data in integer format. If this Token's data is not
     * an integer in the form of a char array, then 0 will be returned, or
     * the integer value up to the point at which a non-integer value is found
     * in the char data array.
     *
     * Integer values contain the characters 0 to 9, and may also have a 
     * leading positive (+) or negative (-) symbol.
     *
     * @return integer formatted version of this Token's data
     */
    int toInt();
    /**
     * Return this Token's data in float format. If this Token's data is not
     * a float in the form of a char array, then NAN will be returned.
     *
     * Float values contain the characters 0 to 9, and may also have a
     * leading positive (+) or negative (-) symbol. They may also have a decimal
     * section and an exponent, dictated respectively by '.' and 'E'/'e'.
     * 
     * @return floating point formatted version of this Token's data
     */
    float toFloat();
    /**
     * Return a deep copy of this Token's data.
     *
     * @return deep copy of this Token's data.
     */
    char* copyData();
};


#endif	/* TOKEN_H */

