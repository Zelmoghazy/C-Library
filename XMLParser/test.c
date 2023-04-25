#include "xmlparser.h"

int main()
{
    // new document object
    XMLDocument doc;
    // check if document loads correctly and completely parse the XML
    if (!XMLDocument_load(&doc, "G1.xml"))
    {
        exit(0);
    }
    XMLDocument_write(&doc, "out.json", 'j'); //'f' : format , 'm' : minify , 'j' : json
    XMLDocument_free(&doc);                   // destructor

    system("pause");
    return 0;
}