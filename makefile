CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -Iinclude
LDFLAGS = -lsqlite3 -lgtest -lgtest_main -pthread

GTEST_FLAGS = $(shell pkg-config --cflags --libs gtest)

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test

TARG = $(BIN_DIR)/cfb-dynasty-tool
TEST_TARG = $(BIN_DIR)/test

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

APP_SRCS = $(filter-out $(SRC_DIR)/main.cpp, $(SRCS))
APP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(APP_SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.test.o,$(TEST_SRCS))

# Build app
all: $(TARG)

$(TARG): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build test
test: $(TEST_TARG)
	./$(TEST_TARG)

$(TEST_TARG): $(TEST_OBJS) $(APP_OBJS) | $(BIN_DIR)
	$(CXX) -o $@ $(TEST_OBJS) $(APP_OBJS) $(GTEST_FLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.test.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR) 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: all clean test
