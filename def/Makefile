DEF = def
CC = clang-4.0
CFLAGS = -O3

TARGET = transaction_test

DEFSRC = TASLock.def software_tran.def 
CSRC = transaction_test.c

OBJ = $(DEFSRC:.def=.o) $(CSRC:.c=.o) cuckoo.o
HFILES = $(DEFSRC:.def=.h)

all:	$(TARGET)

clean:
	rm -f $(HFILES) $(OBJ) $(TARGET)

$(TARGET): $(HFILES) $(OBJ)
	$(DEF) -o $@ $(OBJ)

%.h: %.def
	$(DEF) -gh $<

%.o: %.def
	$(DEF) -o $@ $(CFLAGS) -c $<

%.o: %.c
	$(CC) -o $@ -mrtm $(CFLAGS) -c $<

cuckoo.o: cuckoo/cuckoo.o
	cp $< $@
