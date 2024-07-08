filename = libcsv.so
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g -fPIC -Wall

$(filename): $(objects)
	gcc $(objects) $(flags) -shared -o $(filename)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

test: $(objects)
	gcc $(objects) $(flags) -o libcsv.out

clean:
	-rm ./*.so
	-rm ./**/*.o