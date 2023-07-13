#include "BelugaMinimal.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaStringTest, "Beluga.String", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaStringTest::RunTest(const FString& Parameters)
{
	// 생성, 대입
	{
		FString strChar("char");
		FString strWChar(L"wchar");
		FString strTChar(TEXT("wchar"));

		strChar = "1234";
		strWChar = "wchar";
		strTChar = TEXT("wchar");
	}

	// Printf
	{
		TestEqual(TEXT("Printf"), FString::Printf(TEXT("%d %f %s"), 123, 1.0f, TEXT("string")), TEXT("123 1.000000 string"));
	}

	// Format
	{
		{
			FStringFormatNamedArguments NamedArgs;
			NamedArgs.Add(TEXT("First"), 123);
			NamedArgs.Add(TEXT("Second"), 1.0f);
			NamedArgs.Add(TEXT("Third"), TEXT("string"));

			TestEqual(TEXT("FormatNamedArguments"), FString::Format(TEXT("{First} {Second} {Third}"), NamedArgs), TEXT("123 1.000000 string"));
		}
		
		{
			FStringFormatOrderedArguments OrderedArgs;
			OrderedArgs.Add(123);
			OrderedArgs.Add(1.0f);
			OrderedArgs.Add(TEXT("string"));
			
			TestEqual(TEXT("FormatOrderedArgs"), FString::Format(TEXT("{0} {1} {2}"), OrderedArgs), TEXT("123 1.000000 string"));
		}
	}

	FString strApple(TEXT("Apple"));
	FString strBanana(TEXT("Banana"));

	// Operators
	{
		// []
		{
			TestEqual(TEXT("Operator []"), strApple[0], L'A');
		}

		// < >
		{
			TestTrue(TEXT("Operator <"), strApple < strBanana);
		}
		//*
		{
			TestEqual(TEXT("Check FString addresses"), *strApple, strApple.operator*());
		}
	}

	//TChar*
	{
		FString fsChar(TEXT("ABCD"));
		const TCHAR* ad = *fsChar;
		TestEqual(TEXT("Check FString and TCHAR* addresses"), ad, *fsChar);
		TestEqual(TEXT("Check FString and TCHAR* values"), fsChar, FString(ad));
		fsChar.Reset();
		TestEqual(TEXT("Check FString and TCHAR* values"), fsChar, FString(ad));

	}

	//Shrink()
	{
		FString MyString = TEXT("ABCD EFG HI JK LMNOP");
		int Size = MyString.GetAllocatedSize();
		MyString = MyString.Left(8);
		MyString.Shrink();
		int Size2 = MyString.GetAllocatedSize();
		//TestEqual(TEXT("Check FString and TCHAR* addresses"), Size, Size2);
	}

	FString MrRue(TEXT("GOOD"));
	//길이 구하기
	{
		int a = MrRue.Len();
		TestEqual(TEXT("Check again"), MrRue.Len(), 4);
	}

	//replace()
	{
		MrRue = MrRue.Replace(TEXT("G"), TEXT("F"));
		FString food(TEXT("FOOD"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), MrRue, food);
	}

	//Insert()
	{
		MrRue.InsertAt(5, TEXT(" FIGHTER"));
		FString SeonWoo(TEXT("FOOD FIGHTER"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), MrRue, SeonWoo);
	}

	//Split()
	{
		FString Mr("");
		FString Rue("");
		MrRue.Split(TEXT(" "), &Mr, &Rue);
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), Mr, TEXT("FOOD"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), Rue, TEXT("FIGHTER"));
	}

	//RemoveAt()
	{
		FString Bong(TEXT("I REALLY WANT TO SLEEP NOW"));
		Bong.RemoveAt(22, 3, true);
	}

	//Clear()
	{
		while (MrRue.IsEmpty())
		{
			MrRue.RemoveAt(0, 1, true);
		}
	}

	return true;
}

//IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)
//
//bool FBelugaNameTest::RunTest(const FString& Parameters)
//{
//	return true;
//}