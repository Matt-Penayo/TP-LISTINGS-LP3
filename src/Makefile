# Find all subdirectories under src/ that contain a Makefile
SUBDIRS := $(dir $(wildcard capitulo_*/*/Makefile))

all:
	@for dir in $(SUBDIRS); do \
		echo ">>> Building in $$dir"; \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		echo ">>> Cleaning in $$dir"; \
		$(MAKE) -C $$dir clean; \
	done

# Allow "make listing-X.Y"
listing-%:
	@chapter=$$(echo $* | cut -d. -f1); \
	section=$$(echo $* | cut -d. -f2); \
	dir="capitulo_$${chapter}/$${chapter}.$${section}"; \
	if [ -d "$$dir" ]; then \
		echo ">>> Building in $$dir"; \
		$(MAKE) -C $$dir; \
	else \
		echo "No such listing: $*"; \
		exit 1; \
	fi