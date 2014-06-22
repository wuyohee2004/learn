
OBJS_ASM = at91sam926x.o 
SRCS_ASM := $(OBJS_ASM:.o=.S)

OBJS_C = pio_at91sam926x.o
SRCS_C := $(OBJS_C:.o=.c)

all: $(BUILT_IN_OBJ)

$(BUILT_IN_OBJ): $(OBJS_C) $(OBJS_ASM)
	$(LD) $(LDFLAGS) -r $^ -o $@ 

$(OBJS_C): $(SRCS_C)
	$(CC) $(CFLAGS) -c $(SRCS_C)

$(OBJS_ASM): $(SRCS_ASM)
	$(CC) $(ASFLAGS) -c $<

clean :
	@rm -vf *.o

