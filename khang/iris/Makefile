BUILD := -kb keebio/iris/rev4 -km khang

c: lsp
	qmk compile -j 4 $(BUILD)

f:
	qmk flash $(BUILD)

lsp:
	qmk generate-compilation-database $(BUILD)
