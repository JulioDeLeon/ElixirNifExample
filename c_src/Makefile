ERL_INCLUDE_PATH=/usr/lib/erlang/usr/include/
all: fast_compare.c
	gcc -fPIC -I$(ERL_INCLUDE_PATH) -shared -o fast_compare.so fast_compare.c

clean: 
	rm *.so 
