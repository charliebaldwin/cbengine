TARGET:=foo
INCLUDES=-Ilib -Iglfw/include -Iglad/include
LIBS=lib/shlinkle.cpp -Lglfw/lib-universal -lglfw3 glad/src/glad.c 

$(TARGET): src/main.cpp
	clang $(INCLUDES) src/main.cpp $(LIBS) -o bin/$(TARGET)

clean: 
	rm bin/$(TARGET)

.default: $(TARGET)
