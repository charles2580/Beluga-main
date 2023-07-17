#include "BelugaMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

UCLASS()
class AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMyGameMode();

	UPROPERTY()
	int32 Number;

	UFUNCTION()
	bool HongikUniv();

};
