# LibCsv

This project aims to expose a simple Api to process csv files
It was built as a code challenge during a selection process

## Building

### Dependencies

This project only depends on gcc, make and the header files for glibc
Install the dependencies with your distribution repo:

- Ubuntu/Debian and derivatives: `apt install gcc make`
- Fedora, RHEL and derivatives: `dnf install gcc make`
- Arch and derivatives: `pacman -S base gcc make`
- Alpine: `apk add gcc make musl-dev`

To build this project, simply run:

```bash
make
```

The libcsv.so file will be placed on the root folder

## Testing

No extra dependencies are needed!
Simply run:

```bash
  make runtest
```

The result will the placed in *test.log*
