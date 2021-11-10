#test2.o:test2.c
#	gcc -c -o test2.o test2.c
#test1.o:test1.c
#	gcc -c -o test1.o test1.c

#objfiles是自定义的参数

##更改：
%.o:%.c
	gcc -c -o $@ $^
objfiles =  test1.o test2.o

test.bin:test1.o test2.o
#	gcc -o test.bin $(objfiles)
	gcc -o $@ $^
all:test.bin
	@echo "compile done!"



