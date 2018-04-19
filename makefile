CC := g++
CF := $(shell pkg-config --cflags Qt5Widgets) -Wall -O3
LF := $(shell pkg-config --libs Qt5Widgets) -fPIC -lm -s

all: moc dialogs bin/tracer
bin/tracer: $(shell find src/ -name "*.cc")
	$(CC) $(CF) $^ $(LF) -o $@

.PHONY: moc
moc: src/moc_tracer.hh

src/moc_%.hh: src/%.hh
	moc $^ -o $@

.PHONY: dialogs
dialogs: src/dialog_main.hh src/dialog_properties.hh src/dialog_about.hh src/dialog_camera.hh

src/dialog_%.hh: ui/%.ui
	uic $^ -o $@

.PHONY: clean
clean:
	-rm bin/tracer src/dialog_*.hh src/moc_*.hh src/resources.cc 2> /dev/null
