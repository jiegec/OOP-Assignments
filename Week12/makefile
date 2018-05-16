lSOURCES=$(wildcard *.cxx)
sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
lOBJECTS=$(lSOURCES:%.cxx=%.o)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=match.exe
LIB=KMP.a

all: $(TARGET) $(LIB)
$(TARGET): $(sOBJECTS) $(HEADERS) $(LIB)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) $(LIB) -o $(TARGET)
$(LIB): $(lOBJECTS) $(HEADERS)
	@echo "Now Generating $(LIB) ..."
	ar -rv $(LIB) $(lOBJECTS)
	ranlib $(LIB)
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -I. --std=c++11 -c $< -o $@
%.o: %.cxx $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -I. --std=c++11 -c $< -o $@
clean:
	del *.o *.exe *.bak || true
	rm *.o *.exe *.bak || true
explain:
	@echo "Headers: $(HEADERS)"
#	@echo "Lib Sources: $(lSOURCES)"
#	@echo "Lib Objects: $(lOBJECTS)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
