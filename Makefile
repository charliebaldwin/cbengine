TARGET:=foo
INCLUDE_PATH="lib"
LIBS=lib/shlinkle.cpp

$(TARGET): src/main.cpp
	clang -I $(INCLUDE_PATH) src/main.cpp $(LIBS) -o bin/$(TARGET)

clean: 
	rm bin/$(TARGET)
