NAME = vector
OBJ_FILES = test_ft_vector.o
OBJ_CMP_FILES = test_std_vector.o
HEADER_FILES = Vector.hpp VectorIterator.hpp ../utils/iteratorUtils.hpp
CFLAGS = -Wall -Wextra -Werror
CXX	= clang++
all: $(NAME) cmp

$(NAME): $(OBJ_FILES)
	$(CXX) -o $@ $^

cmp: $(OBJ_CMP_FILES)
	$(CXX) -o $@ $^


%.o: %.c $(HEADER_FILES)
	$(CXX) -c $(CFLAGS) -o %@ $<

clean:
	rm -f $(OBJ_FILES) $(OBJ_CMP_FILES)

fclean: clean
	rm -f $(NAME)
	rm -f cmp

re:	fclean all

.PHONY: all clean fclean re
