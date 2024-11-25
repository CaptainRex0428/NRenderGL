#pragma once

#ifdef _WINDOWS

// extern Element::ElementEditor* Element::CreateApplication();

int main(int argc, char ** argv)
{
	auto app = Element::CreateApplication();
	app->Run();
	delete app;
}

#endif //_WINDOWS