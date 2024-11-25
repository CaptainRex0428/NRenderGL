#include "EE_Program.h"

#include "ScrewExtend.h"
#include "EE_Micro.h"

namespace Element
{
	ElementEditor::ElementEditor()
	{
	}

	ElementEditor::~ElementEditor()
	{
	}

	void ElementEditor::Run()
	{

		ScrewExtend::Init();

		ELMG_TERMINAL_INFO("Termianl Logger LINKED!");
		ELMG_CLIENT_WARN("Client Logger LINKED!");

		ScrewExtend::Trace::Start();
	}
}
