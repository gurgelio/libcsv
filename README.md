# LibCsv

This project aims to expose a simple Api to process csv files:

```c
/**
 * Process the CSV data by applying filters and selecting columns.
 *
 * @param csv The CSV data to be processed.
 * @param selectedColumns The columns to be selected from the CSV data.
 * @param rowFilterDefinitions The filters to be applied to the CSV data.
 *
 * @return void
 */
void processCsv(const char[], const char[], const char[]);

/**
 * Process the CSV file by applying filters and selecting columns.
 *
 * @param csvFilePath The path to the CSV file to be processed.
 * @param selectedColumns The columns to be selected from the CSV data.
 * @param rowFilterDefinitions The filters to be applied to the CSV data.
 *
 * @return void
 */
void processCsvFile(const char[], const char[], const char[]);
```

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
