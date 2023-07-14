#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaVectorTest, "Beluga.Vector", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaVectorTest::RunTest(const FString& Parameters)
{
	FVector vec;
	FVector vec2 = vec;

	vec2 = FVector::UpVector;

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaMatrixTest, "Beluga.Matrix", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaMatrixTest::RunTest(const FString& Parameters)
{
	FMatrix mat = FMatrix::Identity;

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaTransformTest, "Beluga.Transform", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaTransformTest::RunTest(const FString& Parameters)
{
	FTransform trans;
	return true;
}