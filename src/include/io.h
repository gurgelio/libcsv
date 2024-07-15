#ifndef IO_H
#define IO_H

/**
 * Reads an entire file to a string
 *
 * @param filepath The path to the file to be read
 *
 * @throw When it fails to read the file
 * @returns The file contents as a string
 */
char *getFileContents(const char *filepath);

#endif