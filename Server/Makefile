TARGET=IRCServer

SDIR=Source/
HDIR=Include/
ODIR=Object/
DDIR=Dependency/

LIBS=-lpthread

CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -pedantic -ggdb -O0 -std=c++17 -Iproduct -g
DEPFLAGS=-MMD -MF

SOURCES=$(wildcard $(SDIR)*.cpp)
OBJECTS=$(patsubst $(SDIR)%.cpp, $(ODIR)%.o, $(SOURCES))
DEPENDENCIES=$(patsubst $(SDIR)%.cpp, $(DDIR)%.dep, $(SOURCES))



.PHONY: all delete_garbage clean

all: $(TARGET)

-include $(DEPENDENCIES)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(ODIR)%.o: $(SDIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -I $(HDIR) -c $< $(DEPFLAGS) $(patsubst $(ODIR)%.o, $(DDIR)%.dep, $@)


delete_garbage:
	find $(ODIR)*.o $(patsubst $(ODIR)%,! -name %, $(OBJECTS)) -type f -delete
	find $(DDIR)*.dep $(patsubst $(DDIR)%,! -name %, $(DEPENDENCIES)) -type f -delete

clean:
	rm -f $(TARGET) $(ODIR)*.o $(DDIR)*.dep
