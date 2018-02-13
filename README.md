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

- Create an instance of the _**JsonDocument**_ class.

```
    JsonReader::JsonDocument doc;
```

- And call the _**LoadDocument()**_ function which takes the full path of the file as an input.

```
    doc.LoadDocument("C:\Project1\file.json");
```

This will store the Info of the Json file in the _JsonDocument_ object.

### Parsing the File
**IMPORTANT:** Every Node/Child/Leaf/Object/Array in the Json Document is a _**JsonItem**_ for this parser.

- Create a _pointer_ to the _**JsonItem**_ class. The parsed data will be stored in that pointer as a hierarchy.

```
    JsonReader::JsonItem* root;
```

- Call the _**Parse()**_ function to give data to the _JsonItem*_ variable.

```
    root = doc.Parse();
```

### Accessing the Elements
- Create a _**JsonItem**_ object to store the _first child_ in the object and call _**GetFirstChild()**_.
```
    JsonReader::JsonItem* item = root->GetFirstChild();
```
- To get the next element or object, call _**GetNextChild()**_ from the parent item.

```
    item = root->GetNextChild();
```
**IMPORTANT:** If the Item has no further childs, to prevent the assert, fuunction will return the same child over and over again.

### Getting the Values
You can get the value using the _**GetValue()**_ function which returns the object of the value. 

To get the value as an DataType and not a Location, use the following functions:-
- **asString()**: Returns the value as a string. If no conversion possible, returns null.

- **asInt()**: Returns value as an integer. If no conversions possible, returns 0.

- **asBool()**: Returns value as an boolean. If no conversions possible, returns false.

- **asDouble**: Returns value as an floating point number. If no conversions possible, returns 0.0f.

```
     item->GetValue()->asString();
```
**IMPORTANT:** If no value found (for example if the value is an Array), it will return an empty string "";

- **size()**: Returns the number of elements in that particular object.

```
    root->size()
```

- **GetChildAt(int index)**: Returns the child object on the given index. If not present, returns nullptr. Actual value can be accessed further.

```
    root->GetChildAt(2)->GetValue()->asBool();
```

For Further Implementation, see the [Test.cpp](Source/Test.cpp) file.

_Test.cpp soon to be updates showing full functionality._

## License
This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details
