mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
work_dir := $(dir $(mkfile_path))

flags :=  -Wall -Wextra -Wpedantic -Werror
NAME := matrix_rain

all: clean $(NAME)

$(NAME): 
	clang $(flags) -I $(work_dir)inc -lncurses $(work_dir)src/*.c       -o $(work_dir)$(NAME)

uninstall:
	rm -rf $(work_dir)$(NAME) 

clean:
	rm -rf $(work_dir)$(NAME) 

reinstall:
	make uninstall
	make all
