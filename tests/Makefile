# we don’t want to use relative paths, so we set these variables
PROJECT_DIR=/home/toshio/eclipse-cdt-workspace/circBuffer
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/tests
# specify where the source code and includes are located
INCLUDE_DIRS=$(SRC_DIR)/code
SRC_DIRS=$(SRC_DIR)/code

# specify where the test code is located
TEST_SRC_DIRS = $(TEST_DIR)

# what to call the test binary
TEST_TARGET=circBuffer

# where the cpputest library is located
CPPUTEST_HOME=/usr/local

CPPFLAGS += -I$(CPPUTEST_HOME)/include

LD_LIBRARIES = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

CPPUTEST_USE_GCOV=Y
# run MakefileWorker.mk with the variables defined here
include MakefileWorker.mk
