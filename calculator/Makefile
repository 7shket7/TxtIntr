.PHONY: all debug release clean

RELEASE_FLAGS = -O2 -Wall -DNDEBUG
DEBUG_FLAGS   = -g -O0 -Wall
RELEASE_EXEC  = trig_calc
DEBUG_EXEC    = trig_calc-dbg
SOURCE        = trig_calc.cpp

all: debug release

debug: $(DEBUG_EXEC)

$(DEBUG_EXEC): trig_calc.cpp
	g++ $(DEBUG_FLAGS) trig_calc.cpp -o $(DEBUG_EXEC) 

release: $(RELEASE_EXEC)

$(RELEASE_EXEC): trig_calc.cpp
	g++ $(RELEASE_FLAGS) trig_calc -o $(RELEASE_EXEC)

clean:
	rm -f $(RELEASE_EXEC) $(DEBUG_EXEC)
