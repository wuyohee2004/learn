objs-$(CONF_S3C2410) += nand_s3c24x0.o
objs-$(CONF_S3C2440) += nand_s3c24x0.o

OBJS_ASM = 
SRCS_ASM := $(OBJS_ASM:.o=.S)

OBJS_C = s3c24xx.o uart_s3c24xx.o $(objs-y)
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

