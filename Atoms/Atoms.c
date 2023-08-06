/**
 * An atom is a pointer to a unique, immutable sequence of zero or more arbitrary bytes.
 * Most atoms are pointers to null-terminated strings, but a pointer to any sequence of bytes can be an atom.
 * There is only a single occurrence of any atom, which is why it’s called an atom.
 * Two atoms are identical if they point to the same location.
 * Comparing two byte sequences for equality by simply comparing pointers is one of the advantages of atoms.
 * Another advantage is that using atoms saves space because there’s only one occurrence of each sequence.
 * Atoms are often used as keys in data structures that are indexed by sequences of arbitrary bytes
 * instead of by integers like tables and sets.  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "assert.h"
#include "Atoms.h"

#define MAXDECCHAR 43
#define num_elements(x) ((sizeof(x))/(sizeof((x)[0])))

typedef struct atom {
    struct atom *next;
    int len;
    char *str;
}atom;

atom *buckets[2039];

/**
 * Atom_string is similar to Atom_new; 
 * it caters to the common use of character strings as atoms.
 * It accepts a null-terminated string, 
 * adds a copy of that string to the atom table, if necessary,
 * and returns the atom. 
 */

/* djb2 hash function (magic numbers no explanation) */
unsigned long atom_hash(const char *str) {
    unsigned long hash = 5381;
    for (; *str != '\0'; str++) {
        unsigned char c = *str;
        hash = ((hash << 5) + hash) ^ c;
    }
    return hash;
}

const char *atom_string(const char *str)
{
    assert(str);
    return atom_new(str,strlen(str));
}

const char* atom_int(long n){
    /**
     * str has 43 characters, which is enough to hold the decimal
     * representation of any integer on any conceivable machine.
     * Suppose, for example, that longs are 128 bits.
     * The string representation of any 128-bit signed integer
     * in octal — base 8 — fits in 128/3 + 1 = 43 characters. 
     * The decimal representation can take no more digits than
     * the octal representation, so 43 characters are enough.
     **/
    char str[MAXDECCHAR];

    // pointer initialized to the end of str
    // used to iterate over the array in reverse order
    char *s = str + sizeof(str); 
    unsigned long m; // store absolute value of n

    // LONG_MIN has no corresponding positive value -2^{31} -> 2^{31}-1
    if (n == LONG_MIN){
        m = LONG_MAX + 1UL; //
    }else if( n < 0){
        m = - n;
    }else{
        m = n;
    }

    // Convert Number to String
    do{
        s--;
        *s = m%10 + '0'; // int + '0' = char equivalent
    }while((m /= 10) > 0);

    if (n < 0){
        s--;
        *s = '-'; //add minus sign
    }
    return atom_new(s,(str+sizeof(str))-s);
}


/**
 * Atom_new computes a hash number for the sequence given by
 * str[0..len-1], reduces this hash number modulo the number of elements in buckets,
 * and searches the list pointed to by that element of buckets.
 * If it finds that str[0..len-1] is already in the table, it simply returns the atom:
 **/
const char *atom_new(const char *str, int len){
    assert(str);
    assert(len >= 0);

    /**
     * Simple lookup table Hashing 
     * Casting str[i] to an unsigned character avoids C’s ambiguity about “plain” characters:
     * they can be signed or unsigned. Without the cast, values of str[i] that exceed 127 would
     * yield negative indices on machines that use signed characters.
     **/

    unsigned long hash = atom_hash(str);
    hash %= num_elements(buckets);

    atom *p = buckets[hash];

    //If str is already in the table, return it
    while (p != NULL){
        if (len == p->len){
            int i = 0;
            while ((i < len) && (p->str[i] == str[i])){
                i++;
            }
            if (i == len){     
                return p->str;
            }
        }
        p = p->next;
    }
    /* If its not : Allocate new entry */
    p = malloc(sizeof(*p) + len + 1);
    p->len = len;
    p->str = (char*)(p+1);
    if(len > 0){
        memcpy(p->str, str, len);
    }
    p->str[len] = '\0';
    p->next = buckets[hash];
    buckets[hash] = p;
    
    return p->str;
}

int atom_length(const char* str){
    assert(str);
    
    unsigned long hash = atom_hash(str);
    hash %= num_elements(buckets);

    atom *p = buckets[hash];

    while(p!= NULL){
        /* simply compare pointers */
        if (p->str == str){
            return p->len;
        }
        p = p->next;
    }
    assert(0); //check atom_length must be called only with an atom
    return(0);
}

void atom_reset(void){
    int n = num_elements(buckets);
    atom *p;
    for (int i = 0; i < n; i++){
        p = buckets[i];
        while (p != NULL){
            atom *temp = p;
            p = p->next;
            free(temp);
        }
    }
}