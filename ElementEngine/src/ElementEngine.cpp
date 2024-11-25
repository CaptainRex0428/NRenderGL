#include "ElementEditor.h"

#include <iostream>

class ElementEngine : public Element::ElementEditor
{
public:
	ElementEngine() {};
	virtual ~ElementEngine() {};
};

Element::ElementEditor* Element::CreateApplication()
{
	return new ElementEngine();
}