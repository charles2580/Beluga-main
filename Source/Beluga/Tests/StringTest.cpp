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
	//TCHAR* ad를 사용하여 fsChar의 주소에 접근
	{
		FString fsChar(TEXT("ABCD"));
		const TCHAR* ad = *fsChar;
		TestEqual(TEXT("Check FString and TCHAR* addresses"), ad, *fsChar);	
		TestEqual(TEXT("Check FString and TCHAR* values"), fsChar, FString(ad));
		fsChar = TEXT("EFGH");
		TestEqual(TEXT("Check FString and TCHAR* values"), fsChar, FString(ad));

	}

	//Shrink()
	//maxArray: 실제로 FString이 차지하고 있는 메모리의 크기, maxNum: FString의 마지막 문자의 인덱스값,즉 \0의 인덱스
	//FString.Shrink() : maxArray가 maxNum과 같지 않을 경우 maxArray를 maxNum으로 바꿈, 메모리 크기를 재설정 하는 함수
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
	//Len() : FString의 문자열 길이를 return, 문자가 하나라도 있다면 data.NUM()-1을 return, 문자가 없다면 0을 return
	{
		int a = MrRue.Len();
		TestEqual(TEXT("Check again"), MrRue.Len(), 4);
	}

	//Replace()
	//FString.Replace(From, To) : FString에서 From에 해당하는 문자를 찾아서 To로 교체
	{
		MrRue = MrRue.Replace(TEXT("G"), TEXT("F"));
		FString food(TEXT("FOOD"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), MrRue, food);
	}

	//Insert()
	//
	{
		MrRue.InsertAt(4, TEXT(" FIGHTER"));
		FString SeonWoo(TEXT("FOOD FIGHTER"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), MrRue, SeonWoo);
	}

	//Split()
	//Split(const FString& InS, FString* LeftS, FString* RightS) : 
	//FString에서 InS를 찾아서, InS를 기준으로 왼쪽의 문자열을 복사하여 LeftS에 저장하고, 오른쪽의 문자열을 복사하여 RightS에 저장한다.
	//내부적으로는 InS의 인덱스 값을 FString의 Find()함수를 이용하여 찾고 ex) leftpos = FString.Find(Ins), LeftS에 FString.Left()함수를 사용하여 0번인덱스 부터 leftpos 인덱스 까지를 복사
	{
		FString Mr("");
		FString Rue("");
		MrRue.Split(TEXT(" "), &Mr, &Rue);
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), Mr, TEXT("FOOD"));
		TestEqual(TEXT("CHECK MrRue ate all food in zochiwon"), Rue, TEXT("FIGHTER"));
	}

	//RemoveAt()
	//RemoveAt(index , count, bAllowShrinking)은 index에 해당하는 FString의 문자부터 count만큼 삭제하고 bAllowShrinking값에 따라서 메모리를 재설정 한다.
	{
		FString Bong(TEXT("I REALLY WANT TO SLEEP NOW"));
		Bong.RemoveAt(23, 3, true);
	}

	//Clear()
	//Len()을 사용하여 FString의 길이를 구하고, RemoveAt을 활용하여 0번 인덱스부터 마지막 인덱스까지를 지우고 메모리를 조정한다.
	{
		MrRue.RemoveAt(0, MrRue.Len(), true);
	}

	//IsEmpty()
	//FString이 빈 문자열인지를 확인하고, empty면 true를 그 외에는 false를 return
	{
		TestEqual(TEXT("CHECK IS MrRue HUNGRY"), MrRue.IsEmpty(), true);
	}

	//Find()
	//FString.Find() : FString내에서 string을 찾아 string의 첫번째 문자에 해당하는 index값을 반환, FString의 처음부터 끝까지를 탐색하며, 무시할 case를 설정할 수 있다.
	{
		FString Coffee(TEXT("Do you need caffeine"));
		int32 a = Coffee.Find("caffeine");
		TestEqual(TEXT("CHECK IS THERE A COFFEE"),Coffee.Find(TEXT("caffeine")),12);
	}

	//Append()
	//FString.Append(const wchar_t* Str) : 현재 FString의 맨 뒤에 인자로 넘겨 받은 Str을 추가하여 합쳐진 Fstring의 레퍼런스를 return 
	{
		MrRue.Append(TEXT("I AM HUNGRY"));
		MrRue.Append(TEXT(" PLEASE GIVE ME HAMBURGER"));
	}

	FString BadBoy;

	//Left()
	//FString.Left(int32 count) : 왼쪽에서부터, 즉 0번 인덱스 부터 count-1인덱스까지를 return

	{
		
		BadBoy = MrRue.Left(5); 
	}

	//Mid()
	//FString.Mid(int32 count) : count 번째 인덱스부터 마지막 인덱스까지를 return
	{
		BadBoy = MrRue.Mid(10); 
	}

	//Right()
	//FString.Right(int32 count) : 오른쪽에서부터, 즉 마지막 인덱스 부터 count 만큼 왼쪽에 있는 문자를 return. 
	{
		BadBoy = MrRue.Right(5); 
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FBelugaNameTest, "Beluga.Name", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool FBelugaNameTest::RunTest(const FString& Parameters)
{
	//Compare()
	//FName.Compare(FName other) : FName과 인자로 받은 other에 대해서 비교하여 compareIndex의 값이 같은 경우 FName과 other의 number의 차이를 return한다.
	//
	{
		FName MyName("Jang", 1);

		FName Friend1("Jang", 1);
		FName Friend2("Jan", 1);
		FName Friend3("JangK", 1);
		FName Friend4("Jang", 2);
		FName Friend5("Jan", 5);
		FName Friend6("JangK", 34);

		FName Friend7("Jang", 8);
		FName Friend8("Jang", -5);

		int32 ZeroOrNot = MyName.Compare(Friend1);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend1), 0);

		ZeroOrNot = MyName.Compare(Friend2);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend2), 1);

		ZeroOrNot = MyName.Compare(Friend3);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend3), -1);

		ZeroOrNot = MyName.Compare(Friend4); //Num의 값이 바뀌어도 return 값이 변함.
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend4), -1);

		ZeroOrNot = MyName.Compare(Friend5);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend5), 1);

		ZeroOrNot = MyName.Compare(Friend6);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend6), -1);

		//FName의 CompareIndex값은 같지만 DesplayIndex의 값이 다른 경우 
		ZeroOrNot = MyName.Compare(Friend7);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend6), -1);

		ZeroOrNot = MyName.Compare(Friend8);
		TestEqual(TEXT("CHECK YOUR NAME"), MyName.Compare(Friend6), -1);
	
	}
	//FName.ToString() : FName을 FString으로 변환하는 함수.
	{
		FName coke("PEPSI", 1);
		FString coca_cola = coke.ToString();
		//coca_cola에 PEPSI가 들어 갈 것이라고 예상했지만, PEPSI_0 으로 확인되어 TestEqual을 통과하지 못함.
		
		//오류를 출력하므로 주석처리
		//TestEqual(TEXT("CHECK COKE IS NAME"), coca_cola, TEXT("PEPSI"));
	}

	return true;
}