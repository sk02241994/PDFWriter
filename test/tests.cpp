#include <iostream>
#include <pdfwriter/PDFWriter.hpp>
#include <gtest/gtest.h>


TEST(PDFCONSTS, pdfMmToPoint)
{
	ASSERT_EQ(28, PDF_MM_TO_POINT(10));
	ASSERT_EQ(48, PDF_MM_TO_POINT(17));
	ASSERT_EQ(37, PDF_MM_TO_POINT(13.234));
}

TEST(PDFCLASS, pdfConstructors)
{
	pdfwrite::PDFWriter *pdf = new pdfwrite::PDFWriter();
	delete pdf;
}

TEST(PDFCLASSMETHOD, pdfGetWidth)
{
	pdfwrite::PDFWriter pdf(12, 13);
	ASSERT_EQ(12, pdf.pdfGetWidth());
}

TEST(PDFCLASSMETHOD, pdfGetHeight)
{
	pdfwrite::PDFWriter pdf(12, 13);
	ASSERT_EQ(13, pdf.pdfGetHeight());
}

TEST(PDFCLASSMETHOD, pdfGetContent)
{
	pdfwrite::PDFWriter pdf;
	pdf.pdfSetContent("Hello world");
	ASSERT_EQ("Hello world", pdf.pdfGetContent());
}

TEST(PDFCLASSMETHOD, warpText)
{
	pdfwrite::PDFWriter pdf;
	std::vector<std::string> expectedWords = {"This     is", "barnabus", "of       the", "great", "spainyard"};
	std::string s = "This is barnabus of the great spainyard";
	pdf.pdfSetFont(pdfwrite::HELVETICA, 12);
	pdf.pdfSetContent(s);
	pdf.warpText(50, true);
	std::vector<std::string> words = pdf.pdfGetWrappedText();
	ASSERT_EQ(expectedWords.size(), words.size());
	for (int i = 0; i < expectedWords.size(); i++)
	{
		ASSERT_EQ(expectedWords[i], words[i]);
	}
}

TEST (PDFCLASSMETHOD, pdfGetFont){
	pdfwrite::PDFWriter pdf;
	pdf.pdfSetFont(pdfwrite::Font::COURIER_OBLIQUE, 12);
	ASSERT_EQ(3, pdf.pdfGetFont());
}

TEST(PDFCLASSMETHOD, pdfAddNewPage){
	pdfwrite::PDFWriter pdf;
	pdf.pdfSetContent("21, 12");
	pdf.pdfAddNewPage();
	ASSERT_EQ("", pdf.pdfGetContent());
}

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
