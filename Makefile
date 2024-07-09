filename = libcsv.so
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -fPIC -Wall -Wextra -ggdb3

$(filename): $(objects)
	gcc $(flags) -shared $^ -o $@

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

test: $(objects)
	-gcc $(objects) $(flags) -o libcsv.out
	-./libcsv.out

clean:
	-rm ./*.so
	-rm ./**/*.o