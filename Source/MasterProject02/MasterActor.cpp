#include "MasterActor.h"

AMasterActor::AMasterActor()
{
	PrimaryActorTick.bCanEverTick = false;

	
}
void AMasterActor::BeginPlay()
{
	Super::BeginPlay();
	// 칭호
	Title.Add(TEXT("모험가"));

	// 아이템 등록
	FItemData SwordInfo;
	SwordInfo.Info = TEXT("일반 검");
	SwordInfo.Price = 500;
	SwordInfo.TitleRequired = TEXT("모험가");
	Item.Add(TEXT("검"), SwordInfo);

	FInventorySlot NewSlot;
	NewSlot.ItemName = TEXT("검");
	NewSlot.Count = 1;
	Inventory.Add(NewSlot);

	FItemData ExcaliburInfo;
	ExcaliburInfo.Info = TEXT("전설의 엑스칼리버");
	ExcaliburInfo.Price = 1000000;
	ExcaliburInfo.TitleRequired = TEXT("용사");
	Item.Add(TEXT("엑스칼리버"), ExcaliburInfo);

	FInventorySlot NewSlot2;
	NewSlot2.ItemName = TEXT("엑스칼리버");
	NewSlot2.Count = 1;
	Inventory.Add(NewSlot2);

	UseItem(0);
	UseItem(1);
}

void AMasterActor::UseItem(int32 Index)
{
	// 가방 인덱스 확인
	if (!Inventory.IsValidIndex(Index)) return;

	// 해당 인덱스의 아이템 이름 가져오기
	FString UseItemName = Inventory[Index].ItemName;

	// TMap 이름으로 아이템 정보 가져오기
	FItemData* ItemData = Item.Find(UseItemName);

	// 정보가 있으면
	if (ItemData)
	{
		// 칭호 확인
		// 칭호가 필요없거나, 칭호가 있을 경우
		if (ItemData->TitleRequired.IsNone() || Title.Contains(ItemData->TitleRequired))
		{
			UE_LOG(LogTemp, Warning, TEXT("%s 아이템 사용"), *UseItemName);
			UE_LOG(LogTemp, Warning, TEXT("%s 칭호 확인 - %s 아이템 사용 가능"), *ItemData->TitleRequired.ToString(), *UseItemName);

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s 아이템 사용"), *UseItemName);
			UE_LOG(LogTemp, Warning, TEXT("%s 칭호 없음 - %s 아이템 사용 불가"), *ItemData->TitleRequired.ToString(), *UseItemName);
		}
	}
}