#include "BelugaMinimal.h"
DEFINE_LOG_CATEGORY(LogBeluga);

class FBelugaModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		UE_LOG(LogBeluga, Display, TEXT("BelugaModule::StartupModule"));
	}
	virtual void ShutdownModule() override
	{
		UE_LOG(LogBeluga, Display, TEXT("BelugaModule::ShutdownModule"));
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FBelugaModule, Beluga, "Beluga");