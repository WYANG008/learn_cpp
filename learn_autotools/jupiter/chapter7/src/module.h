#ifndef MODULE_H_INCLUDED
#define MODULE_H_INCLUDED
// This string represents the name of the function you need to import from the plug-in module
#define GET_SALUTATION_SYM "get_salutation"
typedef const char * get_salutation_t(void);
const char * get_salutation(void);
#endif /* MODULE_H_INCLUDED */