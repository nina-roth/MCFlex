CC = gcc
CFLAGS ?= -g

all: MCFLEX

    MCFLEX: MC_flex.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

    clean: FRC
	rm -f MCFLEX MC_flex.o

    # This is an explicit suffix rule. It may be omitted on systems
    # that handle simple rules like this automatically.
    .cpp.o:
	$(CC) $(CFLAGS) -c $<

    FRC:
    .SUFFIXES: .cpp
