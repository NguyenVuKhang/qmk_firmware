USER := khang

KEEB := keebio/iris/rev4
KEEB := dz60

CONTEXT := -kb $(KEEB) -km $(USER)

c: lsp
	qmk compile -j 4 $(CONTEXT)

f:
	qmk flash $(CONTEXT)

lsp:
	qmk generate-compilation-database $(CONTEXT)
