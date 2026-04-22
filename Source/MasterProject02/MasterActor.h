#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MasterActor.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Count;
};

USTRUCT(BlueprintType)
struct FItemData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Info;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Price;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TitleRequired;
};

UCLASS()
class MASTERPROJECT02_API AMasterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMasterActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<FInventorySlot> Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TMap<FString, FItemData> Item;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TSet<FName> Title;

	void UseItem(int32 Index);

protected:
	virtual void BeginPlay() override;
};
