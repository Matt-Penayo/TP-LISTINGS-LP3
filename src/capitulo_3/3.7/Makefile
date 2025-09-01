# ----------------------
# Compiler settings
CXX := g++
CC  := gcc
CXXFLAGS := -Wall -Wextra -O2 -MMD -MP -w
CFLAGS   := -Wall -Wextra -O2 -MMD -MP -w
LDLIBS :=

# ----------------------
# Detect current location
CURDIR  := $(abspath .)
CHAPTER := $(notdir $(patsubst %/,%,$(dir $(CURDIR))))
SECTION := $(notdir $(CURDIR))
BINDIR  := $(CURDIR)/../../../bin/$(CHAPTER)/$(SECTION)

# ----------------------
# Set the final executable name here
EXE_NAME := sigchld.exe   # <--- change this to whatever you want
EXEEXT  :=                     # optionally add .exe if needed for Windows
OUT := $(BINDIR)/$(EXE_NAME)$(EXEEXT)

# ----------------------
# Sources
SRCS := $(wildcard *.c *.cpp)
OBJS := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SRCS)))

# ----------------------
.PHONY: all clean
all: $(OUT)

$(OUT): $(OBJS)
	@mkdir -p "$(BINDIR)"
	@$(CXX) -o $@ $^ $(LDLIBS)
	@echo "Built $@"

# ----------------------
# Compilation rules (generate .d files)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# include dependency files
-include $(OBJS:.o=.d)

# ----------------------
clean:
	-rm -f $(OBJS) $(OUT) *.d
	@echo "Cleaned $(CURDIR)"