CC=gcc
SRC_PATH=../src
INC_PATH=../include

override CFLAGS+=-Wall -I$(INC_PATH) -O3

all: runsim

runsim: $(SRC_PATH)/main.c priority_queue.o binary_tree.o utils.o trie.o
	$(CC) $(CFLAGS) $(SRC_PATH)/main.c -o runsim priority_queue.o binary_tree.o utils.o trie.o

priority_queue.o: $(SRC_PATH)/priority_queue.c $(INC_PATH)/priority_queue.h
	$(CC) $(CFLAGS) $(SRC_PATH)/priority_queue.c -c

binary_tree.o: $(SRC_PATH)/binary_tree.c $(INC_PATH)/binary_tree.h
	$(CC) $(CFLAGS) $(SRC_PATH)/binary_tree.c -c

trie.o: $(SRC_PATH)/trie.c $(INC_PATH)/trie.h
	$(CC) $(CFLAGS) $(SRC_PATH)/trie.c -c

utils.o: $(SRC_PATH)/utils.c $(INC_PATH)/utils.h
	$(CC) $(CFLAGS) $(SRC_PATH)/utils.c -c

clean:
	rm -rf *.o runsim
