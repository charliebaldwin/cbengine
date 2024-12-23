TARGET:=foo
BREW:=$(shell brew --prefix)
INCLUDES=-I$(BREW)/include
LIBS=-L$(BREW)/lib -lglfw -framework OpenGL

$(TARGET): src/main.cpp
	clang -o bin/$(TARGET) $(INCLUDES) src/main.cpp  $(LIBS) 

clean: 
	rm bin/$(TARGET)

.default: $(TARGET)
