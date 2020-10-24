add_library(
	pdfwriter
	src/pdfwritersrc/PDFWriter.cpp
	src/pdfwriter/PDFWriterStructs.hpp
	src/pdfwriter/PDFWriter.hpp
	)

target_include_directories(pdfwriter PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
