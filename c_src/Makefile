ERL_INCLUDE_PATH=/usr/lib/erlang/usr/include/

fast_compare.so: fast_compare.c
	gcc -fPIC -I$(ERL_INCLUDE_PATH) -shared -o fast_compare.so fast_compare.c

all: fast_compare.so

clean: 
	rm *.so 
