// Copyright © 2025 Reverse-A. All Rights Reserved.

#pragma once

#include "DevelopmentUtility/DiagnosticSystem.h"
#include "Kismet/GameplayStatics.h"
#include "AudioManager.generated.h"

#pragma region ForwardDeclaration

class USoundBase;
class USoundCue;

#pragma endregion

#pragma region AudioManager

UCLASS()
class AGEOFREVERSE_API UAudioManager : public UObject
{
    GENERATED_BODY()

#pragma region Constructor 

public:
    UAudioManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

#pragma region World

protected:
    /**
     * Context object representing the world.
     * Note: Currently not in use, reserved for future functionality.
     */
    TObjectPtr<UObject> WorldContext;

public:
    /**
     * Sets the world context object.
     * Note: Currently not in use, reserved for future functionality.
     */
    void SetWorldContext(TObjectPtr<UObject> InWorld);

    /**
     * Gets the current world context object.
     * Note: Currently not in use, reserved for future functionality.
     */
    TObjectPtr<UObject> GetWorldContext() const;

#pragma endregion

#pragma region PlaySound

public:
	// Plays the specified sound in the game world using the given context.
	static void PlaySound(UObject* WorldContextObject, USoundBase* Sound);	

	static void PlaySoundAtLocation(UObject* WorldContextObject, USoundBase* Sound, FVector Location);

#pragma endregion

};

#pragma endregion

#pragma region UI

#pragma region Data

USTRUCT()
struct FUIAudioData
{
	GENERATED_BODY()

#pragma region DataEntry

private:
	// Sound to play when an action is confirmed or accepted
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> AcceptSound;

	// Sound to play when navigating back in menus
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> BackSound;

	// Sound to play when cancelling an action
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> CancelSound;

	// Sound to play when closing a window or panel
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> CloseSound;

	// Sound to play when crafting items
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> CraftSound;

	// Sound to play when a disabled button is hovered over or pressed
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> DisableSound;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> DragSound;

	// Sound to play when dropping an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> DropSound;

	// Sound to play when equipping an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> EquipSound;

	// Sound to play when unequipping an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> UnequipSound;

	// Sound to play when an invalid or error action occurs
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> ErrorSound;

	// Sound to play when exiting or closing a UI element
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> ExitSound;

	// Sound to play when the button is hovered
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> HoverSound;

	// Sound to play when opening a window or panel
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> OpenSound;

	// Sound to play when picking up an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> PickupSound;

	// Sound to play when pressing a button
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> PressSound;

	// Sound to play when purchasing an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> PurchaseSound;

	// Sound to play for generic notifications or popups
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> NotificationSound;

	// Sound to play when scrolling lists or inventories
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> ScrollSound;

	// Sound to play when the button is selected or focused
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> SelectSound;

	// Sound to play when selling an item
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> SellSound;

	// Sound to play when decreasing a slider or value
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> SliderDecreaseSound;

	// Sound to play when increasing a slider or value
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> SliderIncreaseSound;

	// Sound to play when switching tabs
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> SwitchSound;

	// Sound to play when upgrading or leveling up
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> UpgradeSound;

#pragma endregion 

#pragma region Constructor

public:
	FUIAudioData()
	: AcceptSound(nullptr)
	, BackSound(nullptr)
	, CancelSound(nullptr)
	, CloseSound(nullptr)
	, CraftSound(nullptr)
	, DisableSound(nullptr)
	, DragSound(nullptr)
	, DropSound(nullptr)
	, EquipSound(nullptr)
	, UnequipSound(nullptr)
	, ErrorSound(nullptr)
	, ExitSound(nullptr)
	, HoverSound(nullptr)
	, OpenSound(nullptr)
	, PickupSound(nullptr)
	, PressSound(nullptr)
	, PurchaseSound(nullptr)
	, NotificationSound(nullptr)
	, ScrollSound(nullptr)
	, SelectSound(nullptr)
	, SellSound(nullptr)
	, SliderDecreaseSound(nullptr)
	, SliderIncreaseSound(nullptr)
	, SwitchSound(nullptr)
	, UpgradeSound(nullptr)
	{
		LoadUIAudioAssets();
	}

#pragma endregion 

#pragma region Load

	void LoadSound(TObjectPtr<USoundBase>& SoundVar, const TCHAR* Path, const TCHAR* Name)
	{
		USoundBase* LoadedSound = Cast<USoundBase>(StaticLoadObject(USoundBase::StaticClass(), nullptr, Path));
		if (LoadedSound)
		{
			SoundVar = LoadedSound;
			UE_LOG(LogTemp, Log, TEXT("%s loaded successfully using StaticLoadObject!"), Name);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load %s using StaticLoadObject! Final Path: %s"), Name, Path);
		}
	}


	void LoadUIAudioAssets()
	{
		LoadSound(AcceptSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Accept/SC_UI_Accept.SC_UI_Accept"), TEXT("AcceptSound"));
		LoadSound(BackSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Back/SC_UI_Back.SC_UI_Back"), TEXT("BackSound"));
		LoadSound(CancelSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Cancel/SC_UI_Cancel.SC_UI_Cancel"), TEXT("CancelSound"));
		LoadSound(CraftSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Craft/SC_UI_Craft.SC_UI_Craft"), TEXT("CraftSound"));
		LoadSound(CloseSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Close/SC_UI_Close.SC_UI_Close"), TEXT("CloseSound"));
		LoadSound(DisableSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Disabled/SC_UI_Disabled.SC_UI_Disabled"), TEXT("DisableSound"));
		LoadSound(DragSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Drag/SC_UI_Drag.SC_UI_Drag"), TEXT("DragSound")); // if needed, else remove
		LoadSound(DropSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Drop/SC_UI_Drop.SC_UI_Drop"), TEXT("DropSound"));
		LoadSound(EquipSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Equip/SC_UI_Equip.SC_UI_Equip"), TEXT("EquipSound"));
		LoadSound(ErrorSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Error/SC_UI_Error.SC_UI_Error"), TEXT("ErrorSound"));
		LoadSound(HoverSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Hovered/SC_UI_Hovered.SC_UI_Hovered"), TEXT("HoverSound"));
		LoadSound(OpenSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Open/SC_UI_Open.SC_UI_Open"), TEXT("OpenSound"));
		LoadSound(PickupSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Pickup/SC_UI_Pickup.SC_UI_Pickup"), TEXT("PickupSound"));
		LoadSound(PressSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Pressed/SC_UI_Pressed.SC_UI_Pressed"), TEXT("PressSound"));
		LoadSound(PurchaseSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Purchase/SC_UI_Purchase.SC_UI_Purchase"), TEXT("PurchaseSound"));
		LoadSound(ScrollSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Scroll/SC_UI_Scroll.SC_UI_Scroll"), TEXT("ScrollSound"));
		LoadSound(SellSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Sell/SC_UI_Sell.SC_UI_Sell"), TEXT("SellSound"));
		LoadSound(SelectSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Select/SC_UI_Select.SC_UI_Select"), TEXT("SelectSound"));
		LoadSound(SliderDecreaseSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Slider/Decrease/SC_UI_SliderDecrease.SC_UI_SliderDecrease"), TEXT("SliderDecreaseSound"));
		LoadSound(SliderIncreaseSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Slider/Increase/SC_UI_SliderIncrease.SC_UI_SliderIncrease"), TEXT("SliderIncreaseSound"));
		LoadSound(SwitchSound, TEXT("/Game/Blueprint/Auido/UI/Assets/TabSwitch/SC_UI_TabSwitch.SC_UI_TabSwitch"), TEXT("SwitchSound"));
		LoadSound(UnequipSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Unequip/SC_UI_Unequip.SC_UI_Unequip"), TEXT("UnequipSound"));
		LoadSound(UpgradeSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Upgrade/SC_UI_Upgrade.SC_UI_Upgrade"), TEXT("UpgradeSound"));
		LoadSound(ExitSound, TEXT("/Game/Blueprint/Auido/UI/Assets/Exit/SC_UI_Exit.SC_UI_Exit"), TEXT("ExitSound"));
	}

#pragma endregion

#pragma region Accessors

	USoundBase* GetHoveredSound() const
	{
		if (HoverSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(HoverSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return HoverSound;
	}

	USoundBase* GetPressedSound() const
	{
		if (PressSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(PressSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return PressSound;
	}

	USoundBase* GetSelectSound() const
	{
		if (SelectSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(SelectSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return SelectSound;
	}

	USoundBase* GetExitSound() const
	{
		if (ExitSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(ExitSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return ExitSound;
	}

	USoundBase* GetSliderIncreaseSound() const
	{
		if (SliderIncreaseSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(SliderIncreaseSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return SliderIncreaseSound;
	}

	USoundBase* GetSliderDecreaseSound() const
	{
		if (SliderDecreaseSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(SliderDecreaseSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return SliderDecreaseSound;
	}

	USoundBase* GetErrorSound() const
	{
		if (ErrorSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(ErrorSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return ErrorSound;
	}

	USoundBase* GetAcceptSound() const
	{
		if (AcceptSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(AcceptSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return AcceptSound;
	}

	USoundBase* GetDisabledSound() const
	{
		if (DisableSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(DisableSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return DisableSound;
	}

	USoundBase* GetNotificationSound() const
	{
		if (NotificationSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(NotificationSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return NotificationSound;
	}

	USoundBase* GetCancelSound() const
	{
		if (CancelSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(CancelSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return CancelSound;
	}

	USoundBase* GetBackSound() const
	{
		if (BackSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(BackSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return BackSound;
	}

	USoundBase* GetOpenSound() const
	{
		if (OpenSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(OpenSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return OpenSound;
	}

	USoundBase* GetCloseSound() const
	{
		if (CloseSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(CloseSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return CloseSound;
	}

	USoundBase* GetTabSwitchSound() const
	{
		if (SwitchSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(SwitchSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return SwitchSound;
	}

	USoundBase* GetScrollSound() const
	{
		if (ScrollSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(ScrollSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return ScrollSound;
	}

	USoundBase* GetEquipSound() const
	{
		if (EquipSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(EquipSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return EquipSound;
	}

	USoundBase* GetUnequipSound() const
	{
		if (UnequipSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(UnequipSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return UnequipSound;
	}

	USoundBase* GetDropSound() const
	{
		if (DropSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(DropSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return DropSound;
	}

	USoundBase* GetPickupSound() const
	{
		if (PickupSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(PickupSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return PickupSound;
	}

	USoundBase* GetPurchaseSound() const
	{
		if (PurchaseSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(PurchaseSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return PurchaseSound;
	}

	USoundBase* GetSellSound() const
	{
		if (SellSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(SellSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return SellSound;
	}

	USoundBase* GetCraftSound() const
	{
		if (CraftSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(CraftSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return CraftSound;
	}

	USoundBase* GetUpgradeSound() const
	{
		if (UpgradeSound == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_INVALID(UpgradeSound);
#else
			LOG_FATAL_USER();
#endif
		}
		return UpgradeSound;
	}

#pragma endregion

};

#pragma endregion

#pragma region UIAudioManager

UCLASS(BlueprintType, Blueprintable)
class AGEOFREVERSE_API UUIAudioManager : public UAudioManager
{
	GENERATED_BODY()

#pragma region Constructor 

public:
	/** Default constructor */
	UUIAudioManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

#pragma region UIAudioData

private:
    /** UI audio data container holding various sound assets */
    UPROPERTY(VisibleAnywhere)
    FUIAudioData UIAudioData;

public:
    /** Returns the UI audio data container */
    FUIAudioData GetUIAudioData() const
    {
        return UIAudioData;
    }

#pragma endregion

#pragma region Play

public:
    /** Play sound for UI hover event */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlayHoveredSound(UWorld* InWorldContext);

    /** Play sound for UI button press */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlayPressedSound(UWorld* InWorldContext);

    /** Play sound for UI select */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlaySelectSound(UWorld* InWorldContext);

    /** Play sound when exiting UI */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlayExitSound(UWorld* InWorldContext);

    /** Play sound for slider increase */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlaySliderIncreaseSound(UWorld* InWorldContext);

    /** Play sound for slider decrease */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlaySliderDecreaseSound(UWorld* InWorldContext);

    /** Play error notification sound */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlayErrorSound(UWorld* InWorldContext);

    /** Play sound for UI accept/confirm action */
    UFUNCTION(BlueprintCallable, Category = "Sound")
    void PlayAcceptSound(UWorld* InWorldContext);

#pragma endregion

};

#pragma endregion

#pragma region UI-Namespace

namespace UIAudio
{

#pragma region Data

    /** Global UI audio data container */
    inline FUIAudioData UIAudioData;

#pragma endregion

#pragma region Helper 

    /**
     * Plays the given UI sound with context and validity checks.
     * @param InWorldContext - The world context for playing sound.
     * @param Sound - The sound asset to play.
    */
    inline void PlayUISound(UWorld* InWorldContext, USoundBase* Sound)
    {
        if (!InWorldContext || !Sound)
        {
            #if DEV_DEBUG_MODE
                if (!InWorldContext)
                {
                    LOG_ERROR("PlayUISound: InWorldContext is nullptr");
                }
                if (!Sound)
                {
                    LOG_ERROR("PlayUISound: Sound is nullptr");
                }
            #else 
                LOG_FATAL_USER();
            #endif

            return;
        }

        #if DEV_DEBUG_MODE
            LOG_INFO("PlayUISound: Playing UI sound");
        #endif

        UGameplayStatics::PlaySound2D(InWorldContext, Sound);
    }

#pragma endregion

#pragma region Play

    inline void PlayHoveredSound(UWorld* InWorldContext)         { PlayUISound(InWorldContext, UIAudioData.GetHoveredSound()); }
    inline void PlayPressedSound(UWorld* InWorldContext)         { PlayUISound(InWorldContext, UIAudioData.GetPressedSound()); }
    inline void PlaySelectSound(UWorld* InWorldContext)          { PlayUISound(InWorldContext, UIAudioData.GetSelectSound()); }
    inline void PlayExitSound(UWorld* InWorldContext)            { PlayUISound(InWorldContext, UIAudioData.GetExitSound()); }
    inline void PlaySliderIncreaseSound(UWorld* InWorldContext)  { PlayUISound(InWorldContext, UIAudioData.GetSliderIncreaseSound()); }
    inline void PlaySliderDecreaseSound(UWorld* InWorldContext)  { PlayUISound(InWorldContext, UIAudioData.GetSliderDecreaseSound()); }
    inline void PlayErrorSound(UWorld* InWorldContext)           { PlayUISound(InWorldContext, UIAudioData.GetErrorSound()); }
    inline void PlayAcceptSound(UWorld* InWorldContext)          { PlayUISound(InWorldContext, UIAudioData.GetAcceptSound()); }
    inline void PlayDisabledSound(UWorld* InWorldContext)        { PlayUISound(InWorldContext, UIAudioData.GetDisabledSound()); }
    inline void PlayNotificationSound(UWorld* InWorldContext)    { PlayUISound(InWorldContext, UIAudioData.GetNotificationSound()); }
    inline void PlayCancelSound(UWorld* InWorldContext)          { PlayUISound(InWorldContext, UIAudioData.GetCancelSound()); }
    inline void PlayBackSound(UWorld* InWorldContext)            { PlayUISound(InWorldContext, UIAudioData.GetBackSound()); }
    inline void PlayOpenSound(UWorld* InWorldContext)            { PlayUISound(InWorldContext, UIAudioData.GetOpenSound()); }
    inline void PlayCloseSound(UWorld* InWorldContext)           { PlayUISound(InWorldContext, UIAudioData.GetCloseSound()); }
    inline void PlayTabSwitchSound(UWorld* InWorldContext)       { PlayUISound(InWorldContext, UIAudioData.GetTabSwitchSound()); }
    inline void PlayScrollSound(UWorld* InWorldContext)          { PlayUISound(InWorldContext, UIAudioData.GetScrollSound()); }
    inline void PlayEquipSound(UWorld* InWorldContext)           { PlayUISound(InWorldContext, UIAudioData.GetEquipSound()); }
    inline void PlayUnequipSound(UWorld* InWorldContext)         { PlayUISound(InWorldContext, UIAudioData.GetUnequipSound()); }
    inline void PlayDropSound(UWorld* InWorldContext)            { PlayUISound(InWorldContext, UIAudioData.GetDropSound()); }
    inline void PlayPickupSound(UWorld* InWorldContext)          { PlayUISound(InWorldContext, UIAudioData.GetPickupSound()); }
    inline void PlayPurchaseSound(UWorld* InWorldContext)        { PlayUISound(InWorldContext, UIAudioData.GetPurchaseSound()); }
    inline void PlaySellSound(UWorld* InWorldContext)            { PlayUISound(InWorldContext, UIAudioData.GetSellSound()); }
    inline void PlayCraftSound(UWorld* InWorldContext)           { PlayUISound(InWorldContext, UIAudioData.GetCraftSound()); }
    inline void PlayUpgradeSound(UWorld* InWorldContext)         { PlayUISound(InWorldContext, UIAudioData.GetUpgradeSound()); }

#pragma endregion

}

#pragma endregion

#pragma endregion

#pragma region Utility

#pragma region Data

USTRUCT()
struct FUtilityAudioData
{
	GENERATED_BODY()

#pragma region DataEntry

#pragma endregion

#pragma region Weapon

#pragma region Rifle

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> RifleFire;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> RifleReloadStart;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> RifleReloadEnd;

#pragma endregion

#pragma endregion

#pragma region Constructor

public:
	FUtilityAudioData()
	{
		LoadUtilityAudioAssets();
	}

	void LoadUtilityAudioAssets()
	{
		LoadWeaponAudioAssets();
	}

	void LoadWeaponAudioAssets()
	{
		// Rifle Audio Assets
		// TODO: 
	}

#pragma endregion

#pragma region Accessors

	TObjectPtr<USoundBase> GetRifleFire() const
	{
		if (RifleFire == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_ERROR("RifleFire sound is not assigned.");
#endif
			return nullptr;
		}

#if DEV_DEBUG_MODE
		LOG_INFO("RifleFire sound retrieved successfully.");
#endif

		return RifleFire;
	}

	TObjectPtr<USoundBase> GetRifleReloadStart() const
	{
		if (RifleReloadStart == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_ERROR("RifleReloadStart sound is not assigned.");
#endif
			return nullptr;
		}

#if DEV_DEBUG_MODE
		LOG_INFO("RifleReloadStart sound retrieved successfully.");
#endif

		return RifleReloadStart;
	}

	TObjectPtr<USoundBase> GetRifleReloadEnd() const
	{
		if (RifleReloadEnd == nullptr)
		{
#if DEV_DEBUG_MODE
			LOG_ERROR("RifleReloadEnd sound is not assigned.");
#endif
			return nullptr;
		}

#if DEV_DEBUG_MODE
		LOG_INFO("RifleReloadEnd sound retrieved successfully.");
#endif

		return RifleReloadEnd;
	}

#pragma endregion

};

#pragma endregion

#pragma region Manager

UCLASS(BlueprintType, Blueprintable)
class AGEOFREVERSE_API UUtilityAudioManager : public UAudioManager
{
    GENERATED_BODY()

#pragma region Constructor

public:
    UUtilityAudioManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

#pragma region Data

protected:
    UPROPERTY(VisibleAnywhere)
    FUtilityAudioData UtilityAudioData;

public:
    FUtilityAudioData GetUtilityAudioData() const
    {
        return UtilityAudioData;
    }

#pragma endregion

#pragma region Play

    UFUNCTION(BlueprintCallable)
    void PlayRifleFire(UWorld* InWorldContext);

    UFUNCTION(BlueprintCallable)
    void PlayRifleReloadStart(UWorld* InWorldContext);

    UFUNCTION(BlueprintCallable)
    void PlayRifleReloadStop(UWorld* InWorldContext);

#pragma endregion

}; 

#pragma endregion

#pragma region Namespace

namespace UtilityAudio
{
#pragma region Data 

    inline FUtilityAudioData UtilityAudioData;

#pragma endregion

#pragma region Play

#pragma region Weapon

#pragma region Rifle

    inline void PlayRifleFire(UWorld* InWorldContext)
    {
        if (!InWorldContext)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("InWorldContext is nullptr");
#endif
            return;
        }

        USoundBase* Sound = UtilityAudioData.GetRifleFire();
        if (Sound == nullptr)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("RifleFire is nullptr");
#endif
            return;
        }

#if DEV_DEBUG_MODE
        LOG_INFO("Playing RifleFire");
#endif

        UGameplayStatics::PlaySound2D(InWorldContext, Sound);
    }

    inline void PlayRifleReloadStart(UWorld* InWorldContext)
    {
        if (!InWorldContext)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("InWorldContext is nullptr");
#endif
            return;
        }

        USoundBase* Sound = UtilityAudioData.GetRifleReloadStart();
        if (Sound == nullptr)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("RifleReloadStart sound is nullptr");
#endif
            return;
        }

#if DEV_DEBUG_MODE
        LOG_INFO("Playing RifleReloadStart sound");
#endif

        UGameplayStatics::PlaySound2D(InWorldContext, Sound);
    }

    inline void PlayRifleReloadEnd(UWorld* InWorldContext)
    {
        if (!InWorldContext)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("InWorldContext is nullptr");
#endif
            return;
        }

        USoundBase* Sound = UtilityAudioData.GetRifleReloadEnd();
        if (Sound == nullptr)
        {
#if DEV_DEBUG_MODE
            LOG_ERROR("RifleReloadEnd sound is nullptr");
#endif
            return;
        }

#if DEV_DEBUG_MODE
        LOG_INFO("Playing RifleReloadEnd sound");
#endif

        UGameplayStatics::PlaySound2D(InWorldContext, Sound);
    }

#pragma endregion

#pragma endregion

#pragma endregion


}

#pragma endregion

#pragma endregion

#pragma region Character

#pragma region Data

USTRUCT()
struct FCharacterAudioData
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TMap<EPhysicalSurfaceType, TObjectPtr<USoundBase>> FootstepSounds;

	UPROPERTY(VisibleAnywhere)
	TMap<EPhysicalSurfaceType, TObjectPtr<USoundBase>> JumpSounds;

	UPROPERTY(VisibleAnywhere)
	TMap<EPhysicalSurfaceType, TObjectPtr<USoundBase>> LandSounds;

public:
	FCharacterAudioData()
		: FootstepSounds()
		, JumpSounds()
		, LandSounds()
	{
	};

};

#pragma endregion

#pragma region Manager

UCLASS(BlueprintType, Blueprintable)
class AGEOFREVERSE_API UCharacterAudioManager : public UAudioManager
{
    GENERATED_BODY()

#pragma region Constructor 

public:
    UCharacterAudioManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

};

#pragma endregion

#pragma region Namespace

namespace CharacterAudio
{

}

#pragma endregion

#pragma endregion

#pragma region Enviroment

#pragma region Data

USTRUCT()
struct FEnvironmentAudioData
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> WindSound;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> RainSound;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> ThunderSound;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> ForestAmbientSound;

public:
	FEnvironmentAudioData()
		: WindSound(nullptr)
		, RainSound(nullptr)
		, ThunderSound(nullptr)
		, ForestAmbientSound(nullptr)
	{
		LoadEnvironmentAudioAssets();
	}

	void LoadEnvironmentAudioAssets()
	{
		auto LoadSound = [](TObjectPtr<USoundBase>& SoundVar, const TCHAR* Path, const TCHAR* Name)
		{
			if (SoundVar = LoadObject<USoundBase>(nullptr, Path))
			{
				UE_LOG(LogTemp, Log, TEXT("[FEnvironmentAudioData] %s loaded successfully."), Name);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("[FEnvironmentAudioData] Failed to load %s."), Name);
			}
		};

		LoadSound(WindSound, TEXT("/Game/Blueprint/Audio/Environment/Wind/Wave_Env_Wind"), TEXT("WindSound"));
		LoadSound(RainSound, TEXT("/Game/Blueprint/Audio/Environment/Rain/Wave_Env_Rain"), TEXT("RainSound"));
		LoadSound(ThunderSound, TEXT("/Game/Blueprint/Audio/Environment/Thunder/Wave_Env_Thunder"), TEXT("ThunderSound"));
		LoadSound(ForestAmbientSound, TEXT("/Game/Blueprint/Audio/Environment/Forest/Wave_Env_ForestAmbient"), TEXT("ForestAmbientSound"));
	}

	// Accessors
	USoundBase* GetWindSound() const { return WindSound; }
	USoundBase* GetRainSound() const { return RainSound; }
	USoundBase* GetThunderSound() const { return ThunderSound; }
	USoundBase* GetForestAmbientSound() const { return ForestAmbientSound; }
};
#pragma endregion

#pragma region Manager

UCLASS(BlueprintType, Blueprintable)
class AGEOFREVERSE_API UEnvironmentAudioManager : public UAudioManager
{
    GENERATED_BODY()

#pragma region Constructor

public:
    UEnvironmentAudioManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

};

#pragma endregion

#pragma region Namespace



#pragma endregion

#pragma endregion

#pragma region Music

#pragma region Data

USTRUCT(BlueprintType)
struct FAmbientMusic
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> PeacefulTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> NaturalTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> FuturisticTracks;

public:
	FAmbientMusic()
	{
		LoadAmbientMusicAssets();
	}

	void LoadAmbientMusicAssets() {}
};

USTRUCT(BlueprintType)
struct FElectroAtmosphereMusic
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> SynthwaveTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> DarkWaveTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> FutureBassTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> CyberpunkTracks;

public:
	FElectroAtmosphereMusic()
	{
		LoadElectroAtmosphereMusicAssets();
	}

	void LoadElectroAtmosphereMusicAssets()
	{

	}
};

USTRUCT(BlueprintType)
struct FCalmMusic
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> SoftTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> LofiTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> ChillTracks;

public:
	FCalmMusic() { LoadCalmMusicAssets(); }
	void LoadCalmMusicAssets() {}
};

USTRUCT(BlueprintType)
struct FIntenseMusic
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> TechnoTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> TranceTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> DubstepTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> IndustrialTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> DrumAndBassTracks;

	UPROPERTY(VisibleAnywhere)
	TArray<USoundWave*> GlitchHopTracks;

public:
	FIntenseMusic() { LoadIntenseMusicAssets(); }
	void LoadIntenseMusicAssets() {}
};

USTRUCT(BlueprintType)
struct FBackgroundMusic
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	FAmbientMusic AmbientMusic;

	UPROPERTY(VisibleAnywhere)
	FElectroAtmosphereMusic ElectroAtmosphereMusic;

	UPROPERTY(VisibleAnywhere)
	FCalmMusic CalmMusic;

	UPROPERTY(VisibleAnywhere)
	FIntenseMusic IntenseMusic;

	FBackgroundMusic()
		: AmbientMusic()
		, ElectroAtmosphereMusic()
		, CalmMusic()
		, IntenseMusic()
	{
	}
};

USTRUCT()
struct FMusicAudioData
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USoundBase> MainMenuMusic;

	UPROPERTY(VisibleAnywhere)
	FBackgroundMusic BackgroundMusic;

public:
	FMusicAudioData()
		: MainMenuMusic(nullptr)
		, BackgroundMusic()
	{
		LoadMusicAssets();
	}

	void LoadMusicAssets()
	{

	}

};

#pragma endregion

#pragma region Manager

UCLASS(BlueprintType, Blueprintable)
class AGEOFREVERSE_API UMusicManager : public UAudioManager
{
    GENERATED_BODY()

#pragma region Constructor

public:
    UMusicManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

#pragma endregion

};

#pragma endregion

#pragma region Namespace

namespace MusicManager
{

}

#pragma endregion

#pragma endregion
