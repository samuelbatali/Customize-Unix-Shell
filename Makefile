#
# 	Samuel Batali
#	
#	A Makefile speeds up the execution of C/C++ programs
#
shell:	shell.o
	gcc -o shell shell.o

shell.o:	shell.c
	gcc -c -Wall shell.c

clean:
	rm shell
	rm *.o 
