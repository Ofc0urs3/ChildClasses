all: clean build

CPP_LINKER_FLAGS = --param=inline-unit-growth=1000000 --param=max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC $*

CPP_COMPILE_FLAGS = -c -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \

build: main.o 
	g++ $^ $(CPP_LINKER_FLAGS)

main.o: main.cpp
	g++ $< $(CPP_COMPILE_FLAGS)

clean:
	rm -f *.o *.out
