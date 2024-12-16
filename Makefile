override NAME := livectorc.a

BASENAME := vector_add vector_delone vector_foreach vector_free \
			vector_init vector_realloc vector_search

override SRCS := $(addsuffix .c, $(BASENAME))

override BUILDDIR := .build/

override OBJDIR := $(addprefix $(BUILDDIR), objs/)

override DEPDIR := $(addprefix $(BUILDDIR), deps/)

override OBJS := $(addprefix $(OBJDIR), $(addsuffix .o, $(BASENAME)))

override DEPS := $(addprefix $(DEPDIR), $(addsuffix .d, $(BASENAME)))

override CC := cc

INCS := includes

CFLAGS := -Wall -Wextra -Werror

DEPSFLAGS := -MD -MP -MF

CPPFLAGS := -I$(INCS)

override AR := ar rcs

MAKEFLAGS += --no-print-directory

all:
	@$(MAKE) $(NAME)

-include $(DEPS)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo ""
	@echo "libvectorc.a created."

$(OBJDIR)%.o: %.c | $(DEPDIR) $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPSFLAGS) $(DEPDIR)$*.d -o $@ -c $^

$(DEPDIR) $(OBJDIR):
	mkdir -p $@

clean:
	rm -rf .build

fclean: clean
	rm -f $(NAME)

re: fclean all
