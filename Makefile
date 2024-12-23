TARGET:=foo
INCLUDES=-Ilib -Iglfw/include -Iglad/include
LIBS=lib/shlinkle.cpp -Lglfw/lib-arm64 -lglfw3 glad/src/glad.c 

$(TARGET): src/main.cpp
	clang $(INCLUDES) src/main.cpp $(LIBS) -o bin/$(TARGET)

clean: 
	rm bin/$(TARGET)

.default: $(TARGET)
