ERL_INCLUDE_PATH=/usr/lib/erlang/usr/include/
C_SRC=./c_src
fast_compare.so: $(C_SRC)/fast_compare.c
	gcc -fPIC -I$(ERL_INCLUDE_PATH) -shared -o $(C_SRC)/fast_compare.so $(C_SRC)/fast_compare.c

all: fast_compare.so

clean: 
	rm $(C_SRC)*.so 
