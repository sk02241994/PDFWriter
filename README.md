# PDFWriter lib

This is a simple library written in C++ for creating a simple pdf file.

PDFWriter library allows you to generate pdf files. 

The features supported by library are:
* Creation of page
* Adding content to page
* Setting fonts and their sizes

## Building the file
Need cmake to build the file
```bash
mkdir build
cd build
cmake ..
make
```
## Running the test files
```bash
cd build
./test/pdfTest
```
## Running the example file
```bash
cd build
./PDFWriterExecutable/PdfWrite
```
On running example.pdf file will be generated.

## Example
```c++
#include <iostream>
#include <pdfwriter/PDFWriter.hpp>

int main()
{
    std::string err;
    pdfwrite::PDFWriter pdf;
    pdf.setWidthHeight(1000, 1000);
    pdf.pdfSetFont(pdfwrite::COURIER, 18);

    std::string s = "  \t\t   fee \r\nxxxxxxxxxxxxx\r\n\"fi\"fo fum";

    s += " a aa aaa aaaa bbb bb b c cc ccc dddd eeeee ";
    s += " foo bar baz foo bar baz ";
    s += " mairzy doats and doazy doats and little lambsey divey";
    s += " a kiddley divey too, wouldn't you? ";
    s += " a b c d e f g h i jj kkk llll mmmmmm nnnnnnn oooooooooooo ";
    s += "----------------------- -------------------------- ";
    s += "$$$ $$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ ";
    s += "******************** ************************ ***** ";

    pdf.pdfSetContent(s);
    pdf.warpText(700, true);
    pdf.setXY(100, 800);
    pdf.pdfAddToPage();

    pdf.pdfAddNewPage();
    pdf.pdfSetFont(pdfwrite::HELVETICA, 12);

    std::string st = "3.141592653589793238462643383279502884197169399375105820974944592307816406286 ";
    st += "208998628034825342117067982148086513282306647093844609550582231725359408128481 ";
    st += "117450284102701938521105559644622948954930381964428810975665933446128475648233 ";
    st += "786783165271201909145648566923460348610454326648213393607260249141273724587006 ";
    pdf.pdfSetContent(st);
    pdf.warpText(700, true);
    pdf.setXY(20, 800);
    pdf.pdfAddToPage();

    if (!pdf.writeToFile("example.pdf", err))
    {
        std::cout << err;
    }
    return 0;
}
```