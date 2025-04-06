CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -fstack-protector

DEBUG_FLAGS = -O0 -ggdb3 -D_DEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

CXXFLAGS += $(DEBUG_FLAGS)
##CXXFLAGS = $(RELEASE_FLAGS)

CXX = g++

run:       ./bin/main.o ./bin/copy_tree.o ./bin/def_oper.o ./bin/tree.o ./bin/diff.o ./bin/dump.o ./bin/to_tex.o ./bin/fillbuf.o ./bin/opt.o
	$(CXX) ./bin/main.o ./bin/copy_tree.o ./bin/def_oper.o ./bin/tree.o ./bin/diff.o ./bin/dump.o ./bin/to_tex.o ./bin/fillbuf.o ./bin/opt.o $(CXXFLAGS) -o main

./bin/main.o:      src/main.cpp h/copy_tree.h h/dump.h h/tree.h
	$(CXX) -c    ./src/main.cpp $(CXXFLAGS) -o ./bin/main.o

./bin/copy_tree.o: src/copy_tree.cpp h/copy_tree.h h/tree.h
	$(CXX) -c    ./src/copy_tree.cpp $(CXXFLAGS) -o ./bin/copy_tree.o

./bin/def_oper.o:  src/def_oper.cpp h/def_oper.h h/oper.h
	$(CXX) -c    ./src/def_oper.cpp $(CXXFLAGS) -o ./bin/def_oper.o

./bin/tree.o:      src/tree.cpp h/tree.h h/def_oper.h
	$(CXX) -c    ./src/tree.cpp $(CXXFLAGS) -o ./bin/tree.o

./bin/diff.o:      src/diff.cpp h/diff.h h/tree.h h/def_oper.h h/oper.h h/copy_tree.h h/dump.h
	$(CXX) -c    ./src/diff.cpp $(CXXFLAGS) -o ./bin/diff.o

./bin/dump.o:      src/dump.cpp h/dump.h h/tree.h h/def_oper.h
	$(CXX) -c    ./src/dump.cpp $(CXXFLAGS) -o ./bin/dump.o

./bin/to_tex.o:    src/to_tex.cpp h/to_tex.h h/tree.h h/def_oper.h h/opt.h h/macros.h
	$(CXX) -c    ./src/to_tex.cpp $(CXXFLAGS) -o ./bin/to_tex.o

./bin/fillbuf.o:   src/fillbuf.cpp h/fillbuf.h h/tree.h
	$(CXX) -c    ./src/fillbuf.cpp $(CXXFLAGS) -o ./bin/fillbuf.o

./bin/opt.o:       src/opt.cpp h/opt.h h/dump.h h/macros.h
	$(CXX) -c    ./src/opt.cpp $(CXXFLAGS) -o ./bin/opt.o

clean:
	rm -f main ./bin/*.o ./bin/png/*.png