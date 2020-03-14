SRC_DIR=./src
CODE_DIR=$(SRC_DIR)/code
OUT=circBuffer
TEST_DIR=tests
 
test:
	make -C $(TEST_DIR)
 
test_clean:
	make -C $(TEST_DIR) clean
 
circbuffer.o:
	gcc -c -I$(CODE_DIR) $(CODE_DIR)/circBuffer.c -o $(CODE_DIR)/circBuffer.o
 
main: circbuffer.o
	gcc -I$(CODE_DIR) $(CODE_DIR)/circBuffer.o $(SRC_DIR)/main.cpp -o $(OUT)
 
all: test main
 
clean: test_clean
	rm $(SRC_DIR)/*.o $(CODE_DIR)/*.o $(OUT)
