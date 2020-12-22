TARGET=IRC

SDIR=Source/
HDIR=Include/
ODIR=Object/
DDIR=Dependency/

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
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ODIR)%.o: $(SDIR)%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -I $(HDIR) -c $< $(DEPFLAGS) $(patsubst $(ODIR)%.o, $(DDIR)%.dep, $@)

# Deletes all dependency and object files that aren't needed anymore
# After deleting a cpp file that has been compiled before, run this before compiling the main target
delete_garbage:
	find $(ODIR)*.o $(patsubst $(ODIR)%,! -name %, $(OBJECTS)) -type f -delete
	find $(DDIR)*.dep $(patsubst $(DDIR)%,! -name %, $(DEPENDENCIES)) -type f -delete

clean:
	rm -f $(TARGET) $(ODIR)*.o $(DDIR)*.dep