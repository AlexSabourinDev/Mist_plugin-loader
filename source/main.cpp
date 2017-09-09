#include "../include/Plugin.h"

int main() {

	Mist::Plugin::Handle handle = Mist::Plugin::Load("SomeDll");
	MIST_ASSERT(handle == nullptr);
}