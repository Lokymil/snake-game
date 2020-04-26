CXX = g++

CXXFLAGS = -g -Wall -Wformat
CXXFLAGS += -std=c++17
LIBS = -lSDL2
EXE = out/snake
BUILDDIR = build
SRCDIR = src

SOURCES = $(shell find . -type f -wholename "**/*.cpp" | grep -v main.cpp | sed -e 's/\.\/$(SRCDIR)\///')
OBJS = $(addprefix $(BUILDDIR)/, $(addsuffix .o, $(basename $(SOURCES))))

.PHONY: start build buildir clear
##----------------------------------------------------

start: build
	@echo "Start $(EXE)"
	./$(EXE)

build: buildir $(EXE)
	@echo "Build completed"

buildir:
	mkdir -p build

$(EXE): $(BUILDDIR)/main.o $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(BUILDDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clear:
	rm -rf $(dir $(EXE))
	rm -rf build