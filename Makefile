filename = libcsv.so
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -fPIC -Wall -Werror

$(filename): $(objects)
	gcc $(objects) $(flags) -shared -o $(filename)


%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm ./*.so
	-rm ./**/*.o