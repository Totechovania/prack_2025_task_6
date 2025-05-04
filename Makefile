.PHOENY: all clean

COMP_OPT = -m32 -std=c99 -c -o

all: program

program: main.o integral.o root.o f1.o f2.o f3.o
	 gcc  $^ -m32 -o $@ -lm


main.o: main.c
	 gcc  $^ $(COMP_OPT) $@

main.c: integral.h root.h


root.o: root.c
	 gcc  $^ $(COMP_OPT) $@ 


integral.o: integral.c
	 gcc  $^ $(COMP_OPT) $@


test_functions.o: test_functions.c
	gcc $^ $(COMP_OPT) $@

f1.o: f1.asm
	nasm $^ -f elf32 -o $@

f2.o: f2.asm
	nasm $^ -f elf32 -o $@

f3.o: f3.asm
	nasm $^ -f elf32 -o $@

clean:
	rm *.o