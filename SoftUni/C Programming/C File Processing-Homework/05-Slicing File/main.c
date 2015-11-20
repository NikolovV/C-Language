/* 
 Write a program that takes any file and slices it to n parts. 
 Write the following functions:
 * slice(const char *sourceFile, const char *destination File, size_t parts)-
 slices the given source file into n parts and saves them in 
 destination Directory.
 * assemble(const char **parts, const char *destinationDirectory)-combines all 
 part sinto one, in the order they are passed, and saves the result in 
 destination Directory.
 The input file names, destination directory and parts should be passed to the 
 program as arguments.The program should produce proper error messages 
 in case of errors.Use buffered reading.
 */

#include "Slicing_File.h"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        error("Usage: ./program [sourceFile] [destinationDirectory] [parts]\n");
    }

    char *srcFileName = argv[1];
    char *destDirPath = argv[2];
    size_t parts = atoi(argv[3]);
        
    parts_global = parts;

    char *filePartsName[parts];
    set_names(filePartsName, parts, destDirPath);

    slice(srcFileName, destDirPath, parts);
    assemble(filePartsName, destDirPath);

    free_array(filePartsName, parts);
        
    return (EXIT_SUCCESS);
}