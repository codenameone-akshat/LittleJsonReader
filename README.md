# LittleJsonReader

A simplistic Json Reader in C++.
Build will C++ 11 and uses STL features to read a Json File.

## Getting Started

To use the Json Reader, Clone the repository or just download the Source folder and copy in your Project.
You can also just cpoy the JsonParser Folder (Source/src/Json Parser) in src or lib folders of your project.

### Usage:

Include the JsonParser.h file in your project wherever you want to use the Reader.

**Everything is included in the _JsonReader_ namespace.**
```
#include "JsonParser.h"
.
.
```
## Examples

Following are some basic examples.

### Loading the Document

Create an instance of the _**JsonDocument**_ class.

```
JsonReader::JsonDocument doc;
```
And call the _**LoadDocument()**_ function which takes the full path of the file as an input.

```
doc.LoadDocument("C:\Project1\file.json");
```
This will store the Info of the Json file in the _JsonDocument_ object.

### Parsing the File

Create a _pointer_ to the _**JsonItem**_ class. The parsed data will be stored in that pointer as a hierarchy.

Call the _**Parse()**_ function to give data to the _JsonItem*_ variable.

```
JsonReader::JsonItem* root;
root = doc.Parse();
```
**Important:** Every Node/Child/Leaf/Object/Array in the Json Document is a _**JsonItem**_ for this parser.

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
