#pragma once

// -------------Element Used------------

#include "EE_API.h"

// -------------------------------------

namespace Element
{
	class ENGINE_API ElementEditor
	{
	public:
		ElementEditor();
		virtual ~ElementEditor();

		virtual void Run();
	};

	ENGINE_API ElementEditor* CreateApplication();
}
