
CFLAGS += -DGB_TOPHALF

OBJS_C = init.o nand.o stdio.o kermit.o
SRCS_C := $(OBJS_C:.o=.c)

SUBDIRS = $(ARCH)
SUB_BUILT_IN_OBJS := $(foreach n, $(SUBDIRS), $(n)/$(BUILT_IN_OBJ))

all: g-bios-th.bin g-bios-th.dis $(IMAGE_OUT_DIR)/g-bios-th.bin

$(OBJS_C): $(SRCS_C)
	$(CC) $(CFLAGS) -c $^

$(SUB_BUILT_IN_OBJS): $(SUBDIRS)

$(SUBDIRS):
	@make -C $@ all

g-bios-th.elf: $(SUB_BUILT_IN_OBJS) $(OBJS_C)
	$(LD) $(LDFLAGS) -T $(ARCH)/$(SOC_VENDOR)/g-bios-th.lds $^ -o $@	

g-bios-th.bin: g-bios-th.elf
	$(CROSS_COMPILE)objcopy -O binary -S $< $@
	@cp -v $@ $(IMAGE_OUT_DIR)

g-bios-th.dis: g-bios-th.elf
	$(CROSS_COMPILE)objdump -d $< > $@

$(IMAGE_OUT_DIR)/g-bios-th.bin:
	@cp -v g-bios-th.bin $(IMAGE_OUT_DIR)

kermit.c:
	@ln -sf $(TOP_DIR)/lib/$@ $@

clean:
	@for dir in $(SUBDIRS); do \
		make -C $$dir clean; \
	 done	
	@rm -vf *.o g-bios-th.*

.PHONY: $(SUBDIRS)
