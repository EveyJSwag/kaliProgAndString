objects    := src/kaliSock.o src/main.o src/wackString.o

GCC        := gcc
FLAGS      := -c
FLAGS_LINK := -o


KALI_SNIFF : $(objects)
	$(GCC) -g $(FLAGS_LINK) $@ $? 

%.o : %.c
	$(GCC) -g $(FLAGS) $< $(FLAGS_LINK) $@

.PHONY: clean
clean :
	rm src/*.o
	rm KALI_SNIFF
