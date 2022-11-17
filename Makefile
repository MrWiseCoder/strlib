utils_dir=$(scr_dir)/lng/cdev/mylibs/utils
utils_src=$(utils_dir)/utils.c

str_dir=$(scr_dir)/lng/cdev/mylibs/stringlib
str_src=$(str_dir)/str.c
str_obj=$(str_dir)/str.o


all:
	gcc -I $(utils_dir) -o main main.c test_str.c str.c $(utils_src)

libo:
	gcc -I $(utils_dir) -c -o str.o main.c test_str.c str.c $(utils_src)
