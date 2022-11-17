#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils.h>

#include "str.h"

/** extern void print_stars(); */

Mod str = {
    .len = &str_len,
    .find = &str_str,
    .replace = &str_replace,
    .print = &str_print,
    .destroy = &str_destroy,
    .copy = &str_copy
};

string str_str(const string s1, const string s2) {
    string s3 = strstr(s1, s2);
    return s3;
}

size_t str_len(const string s) {
    size_t l = strlen(s);
    return l;
}

string str_replace(const string text, const string search, const string replace_with) {
    string s2 = str.find(text, search);
    int initial_text_lenth = str.len(text);
    int searched_index_text_length = str.len(s2);
    int search_text_length = str.len(search);
    int replace_text_length = str.len(replace_with);
    int index1 = initial_text_lenth - searched_index_text_length;
    int index2 = index1 + search_text_length;
    int index3 = index1 + replace_text_length;
    int remaining_part_length = searched_index_text_length - search_text_length;
    int new_remaining_part_length = remaining_part_length + replace_text_length;
    int new_full_length = initial_text_lenth - search_text_length + replace_text_length;
    string after_search = &text[index2];
    string s3 = (string) malloc(sizeof(char) * new_full_length);
    printf("after_search: '%s'\n", after_search);
    strncpy(s3, text, index1);
    strcat(s3, replace_with);
    strcat(s3, after_search);
    return s3;
}

void str_print(string s) {
    printf("String: '%s'\n", s);
}

void str_destroy(string s) {
    free(s);
}

string str_copy(string s1, string s2) {
    strcpy(s1, s2);
    return s1;
}

void str_obj_init(const string s, Str* so) {
    // TODO: No need for this.
    so->text = (string) malloc(STR_SIZE * sizeof(char));
    strcpy(so->text, s);
}

void str_obj_from(Str* so, const string s) {
    size_t l = str_len(s);
    so->size = l;
    so->text = malloc(sizeof(s) * l);
    strcpy(so->text, s);
}

lenptr str_obj_len(Str* o) {
    auto size_t _str_len();
    size_t _str_len() {
        return strlen(o->text);
    }
    return &_str_len;
}

printptr str_obj_print(Str* so) {
    auto void _str_obj_print();
    void _str_obj_print() {
        printf("\t string => '%s'\n", so->text);
    }
    return &_str_obj_print;
}

void str_obj_print_len(Str* so) {
    int l0 = strlen(so->text);
    printf("\t length => #%d\n", l0);
}

void str_test() {
    print_stars();
    printf("\t *** String Object *** \n");
    newStr(sobj0, "my string");
    sobj0.print();
    int l0 = sobj0.len();
    printf("l0 => %d\n", l0);
    print_stars();
    printf("\t *** Length *** \n");
    int l = str.len("adam");
    printf("adam len: %d\n", l);
    print_stars();
    printf("\t *** Find *** \n");
    string s0 = "da";
    string s1 = "hayda dur bakam";
    string s2 = str.find(s1, s0);
    printf("Find '%s' in '%s' => '%s'\n", s0, s1, s2);
    print_stars();
    printf("\t *** Replace *** \n");
    string s3 = "adam ol la";
    string s4 = "ol";
    string s5 = "yok";
    printf("Replace '%s' with '%s' in '%s' \n", s4, s5, s3);
    string heyt = str.replace(s3, s4, s5);
    str.print(heyt);
    str.destroy(heyt);
    print_stars();
    printf("\t *** Copy *** \n");
    string s7 = "but that is second";
    string s6 = (string) malloc(sizeof(char) * str.len(s7));
    printf("Copying '%s' onto '%s' \n", s6, s7);
    string s8 = str.copy(s6, s7);
    str.print(s8);
    str.destroy(s8);
}
