This repository holds files for submission of the final exam assignment of MPCS - 51100 : Advanced Programming.

Author: Shobhit Verma
Date: 12/12/2021

Directory structure:
    - build/ : Holds Makefile and compiled object files, executable.
    - res/ : Holds sample text files for encoding and decoding.
    - src/ : Holds .c files and main.c
    - include/ : Holds include files (.h)

Compilation instructions:
    - Please use tha makefile in build/ to build the executable (runsim).
    - Running this executable will invoke an interactive prompt. Commands are follows:
        - import <file-name> : Build a code from the frequencies of the characters in file-name and store it internally.
        - encode <file-name> : Encode file-name using the internally-stored code and print the encoded stream of 0’s and 1’s to stdout and print the number of bits in the stream.
        - decode <file-name> : Decode file-name containing a single line/stream of 0’s and 1’s using the internally-stored code and print the decoded ASCII stream to stdout.
        - dump               : Dump the dictionary to stdout

Findings and closing remarks:
    - Compression of sample_text.txt (originally 3349 bytes) is done into 1811 bytes (14488 bits) - a compression ratio of 1.85
    - Compression is tolerant of missing letters in key - taking care by gracefully failing.
    - All ASCII characters from 0 to 127 are handled - however, dump command only prints encodings for visible ascii codes from 32 to 127.
