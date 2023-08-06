#ifndef ATOM_LIB
#define ATOM_LIB    

typedef struct atom atom;

extern unsigned long atom_hash(const char *str);
extern int atom_length(const char *str);
const char *atom_new(const char *str, int len);
extern const char *atom_string(const char *str);
extern const char *atom_int(long n);
extern void atom_reset(void);

#endif
