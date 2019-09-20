#####################
TARGET= main
TARGETs = s
TARGETbh= bh
TARGETgh= gh
TARGETph= ph
TARGETo= o
TARGETsn = 4
TARGETbhn= 5
TARGETghn= 3
TARGETphn= 3
TARGETon= 1
TARGETPATH = branch-trace-gcc.trace.gz


CC       = g++
# compiling flags here
CFLAGS   = -g -Wall -I.

LINKER   = g++
# linking flags here
LFLAGS   = -Wall -I. -lm


SRCDIR   = ./src
OBJDIR   = ./obj
BINDIR   = ./build
INCDIR   = ./include


SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f



$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "Compiled "$<" successfully!"


	
gunzipp:
	gunzip -c hola.zip |$(BINDIR)/$(TARGET) $(TARGETs) $(TARGETsn) $(TARGETbh) $(TARGETbhn) $(TARGETgh) $(TARGETghn) $(TARGETph) $(TARGETphn) $(TARGETo) $(TARGETon)


run args:
	$(BINDIR)/$(TARGET) $(TARGETs) $(TARGETsn) $(TARGETbh) $(TARGETbhn) $(TARGETgh) $(TARGETghn) $(TARGETph) $(TARGETphn) $(TARGETo) $(TARGETon) 
	



.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@$(rm) $(OBJDIR)/*.o
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Cleanup complete!"
	@$(rm) -r ./docs/html
	@$(rm) -r ./docs/latex

doxygen:
	@doxygen ./docs/Doxyfile

gunzip:
	gunzip -c $(TARGETPATH)|$(BINDIR)/$(TARGET) $(TARGETs) $(TARGETsn) $(TARGETbh) $(TARGETbhn) $(TARGETgh) $(TARGETghn) $(TARGETph) $(TARGETphn) $(TARGETo) $(TARGETon)
