#ifndef STR_H
#define STR_H

#define STR_SIZE 128
#define newStr(o, s) Str o = { \
    .text = s, \
    .len = str_obj_len(&o), \
    .print = str_obj_print(&o) \
}

// Func ptrs
typedef char* string;
typedef int (*Get_size)(string a);
typedef void (*fromptr) (string s);
typedef size_t (*lenptr) ();
typedef void (*printptr) ();

// Module or Library Struct
typedef struct _mod {
    size_t (*len)(const string);
    string (*find) (const string, const string);
    string (*replace) (string, string, string);
    void (*print) (string);
    void (*destroy) (string);
    string (*copy) (string, string);
} Mod;

// String Object struct
typedef struct {
    string text;
    int size;
    size_t (*len)();
    // void (*from)(string s);
    fromptr from;
    printptr print;
    string (*find) (string search);
    void (*replace) (string text, string search, string replace_with);
} Str;

// Module funcs
size_t str_len(const string);
string str_str(const string, const string);
string str_replace(const string, const string, const string);
void str_print(string);
void str_destroy(string);
string str_copy(string, string);

// String Object funcs
void str_obj_init(const string, Str*);
printptr str_obj_print(Str*);
void str_obj_from(Str*, const string);
lenptr str_obj_len(Str*);
void str_obj_print_len(Str*);

// Utils
void str_test();


#endif
