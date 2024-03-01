BUILD := -kb dz60 -km khang

f:
	qmk flash $(BUILD)

c: lsp
	qmk compile -j 4 $(BUILD)

lsp:
	qmk generate-compilation-database $(BUILD)
