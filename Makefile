TARGET:=foo
INCLUDES="-Ilib -Iglfw/include/GLFW"
LIBS=lib/shlinkle.cpp

$(TARGET): src/main.cpp
	clang -I $(INCLUDE_PATH) src/main.cpp $(LIBS) -o bin/$(TARGET)

clean: 
	rm bin/$(TARGET)

.default: $(TARGET)
