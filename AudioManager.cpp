// Copyright © 2025 Reverse-A. All Rights Reserved.


#include "Audio/AudioManager.h"


#pragma region AudioManager

#pragma region Constructor

UAudioManager::UAudioManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

#pragma endregion

#pragma region WorldContext

void UAudioManager::SetWorldContext(TObjectPtr<UObject> InWorld)
{
	if (WorldContext != nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_WARNING("Attempted to set WorldContext, but it's already set. Ignoring assignment");
#else 
		LOG_FATAL_USER();
#endif
		return;
	}

	// Assign the provided world context
	WorldContext = InWorld;

#if DEV_DEBUG_MODE
	LOG_INFO("WorldContext has been successfully set");
#else 
	LOG_FATAL_USER();
#endif

}

TObjectPtr<UObject> UAudioManager::GetWorldContext() const
{
	if (WorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("WorldContext is null. Returning nullptr.");
#else 
		LOG_FATAL_USER();
#endif
		return nullptr;
	}

#if DEV_DEBUG_MODE
	LOG_INFO("WorldContext successfully retrieved.");
#endif

	return WorldContext;
}

#pragma endregion

#pragma region PlaySound

void UAudioManager::PlaySound(UObject* WorldContextObject, USoundBase* Sound)
{
    if (!WorldContextObject)
    {
#if DEV_DEBUG_MODE
        LOG_ERROR("PlaySound: WorldContextObject is NULL!");
#endif
    }
    if (!Sound)
    {
#if DEV_DEBUG_MODE
        LOG_ERROR("PlaySound: Sound is NULL!");
#endif
    }

    UGameplayStatics::PlaySound2D(WorldContextObject, Sound);

}

void UAudioManager::PlaySoundAtLocation(UObject* WorldContextObject, USoundBase* Sound, FVector Location)
{
	if (!WorldContextObject)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("PlaySoundAtLocation: WorldContextObject is NULL!");
#endif
	}
	if (!Sound)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("PlaySoundAtLocation: Sound is NULL!");
#endif
	}
	UGameplayStatics::PlaySoundAtLocation(WorldContextObject, Sound, Location);
}

#pragma endregion

#pragma endregion

#pragma region UI

#pragma region Constructor

UUIAudioManager::UUIAudioManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

#pragma endregion

#pragma region PlayUIAudio

void UUIAudioManager::PlayHoveredSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
		#if DEV_DEBUG_MODE
			LOG_ERROR("World context is null. Cannot play hovered sound.");
		#endif
	}

	// Ensure a hovered sound is set in the UI audio data.
	if (UIAudioData.GetHoveredSound() == nullptr)
	{
		#if DEV_DEBUG_MODE
			LOG_INVALID("Hovered sound is not assigned in UIAudioData.");
		#else
			LOG_FATAL_USER();
		#endif
	}

	// Play the assigned hovered sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetHoveredSound());
}

void UUIAudioManager::PlayPressedSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play pressed sound.");
#endif
		return;
	}

	// Ensure a pressed sound is set in the UI audio data.
	if (UIAudioData.GetPressedSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Pressed sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned pressed sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetPressedSound());
}

void UUIAudioManager::PlaySelectSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play select sound.");
#endif
		return;
	}

	// Ensure a select sound is set in the UI audio data.
	if (UIAudioData.GetSelectSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Select sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned select sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetSelectSound());
}

void UUIAudioManager::PlayExitSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play exit sound.");
#endif
		return;
	}

	// Ensure an exit sound is set in the UI audio data.
	if (UIAudioData.GetExitSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Exit sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned exit sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetExitSound());
}

void UUIAudioManager::PlaySliderIncreaseSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play slider increase sound.");
#endif
		return;
	}

	// Ensure a slider increase sound is set in the UI audio data.
	if (UIAudioData.GetSliderIncreaseSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Slider increase sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned slider increase sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetSliderIncreaseSound());
}

void UUIAudioManager::PlaySliderDecreaseSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play slider decrease sound.");
#endif
		return;
	}

	// Ensure a slider decrease sound is set in the UI audio data.
	if (UIAudioData.GetSliderDecreaseSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Slider decrease sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned slider decrease sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetSliderDecreaseSound());
}

void UUIAudioManager::PlayErrorSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play error sound.");
#endif
		return;
	}

	// Ensure an error sound is set in the UI audio data.
	if (UIAudioData.GetErrorSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Error sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned error sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetErrorSound());
}

void UUIAudioManager::PlayAcceptSound(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_ERROR("World context is null. Cannot play accept sound.");
#endif
		return;
	}

	// Ensure an accept sound is set in the UI audio data.
	if (UIAudioData.GetAcceptSound() == nullptr)
	{
#if DEV_DEBUG_MODE
		LOG_INVALID("Accept sound is not assigned in UIAudioData.");
#else
		LOG_FATAL_USER();
#endif
		return;
	}

	// Play the assigned accept sound using the provided world context.
	PlaySound(InWorldContext, UIAudioData.GetAcceptSound());

}

#pragma endregion

#pragma endregion

#pragma region Utility

#pragma region Constructor

UUtilityAudioManager::UUtilityAudioManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
}

#pragma endregion

#pragma region PlayUtilityAudio

#pragma region Weapon

#pragma region Rifle 

void UUtilityAudioManager::PlayRifleFire(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
		#if DEV_DEBUG_MODE
			LOG_ERROR("World context is null. Cannot play rifle fire sound.");
		#endif
		return;
	}

	// Ensure rifle fire sound is set in the utility audio data.
	if (UtilityAudioData.GetRifleFire() == nullptr)
	{
		#if DEV_DEBUG_MODE
			LOG_ERROR("Rifle fire sound is not assigned in UtilityAudioData.");
		#else
			LOG_FATAL_USER();
		#endif
		return;
	}

	#if DEV_DEBUG_MODE
		LOG_INFO("Rifle fire sound has been played successfully.");
	#endif

	// Play the assigned rifle fire sound using the provided world context.
	PlaySound(InWorldContext, UtilityAudioData.GetRifleFire());
}

void UUtilityAudioManager::PlayRifleReloadStart(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
		#if DEV_DEBUG_MODE
				LOG_ERROR("World context is null. Cannot play rifle reload start sound.");
		#endif
		return;
	}

	// Ensure rifle reload start sound is set in the utility audio data.
	if (UtilityAudioData.GetRifleReloadStart() == nullptr)
	{
		#if DEV_DEBUG_MODE
				LOG_ERROR("Rifle reload start sound is not assigned in UtilityAudioData.");
		#else
				LOG_FATAL_USER();
		#endif
		return;
	}

	#if DEV_DEBUG_MODE
		LOG_INFO("Rifle reload start sound has been played successfully.");
	#endif

	// Play the assigned rifle reload start sound using the provided world context.
	PlaySound(InWorldContext, UtilityAudioData.GetRifleReloadStart());
}

void UUtilityAudioManager::PlayRifleReloadStop(UWorld* InWorldContext)
{
	// Check if the world context is valid before proceeding.
	if (InWorldContext == nullptr)
	{
		#if DEV_DEBUG_MODE
				LOG_ERROR("World context is null. Cannot play rifle reload stop sound.");
		#endif
		return;
	}

	// Ensure rifle reload stop sound is set in the utility audio data.
	if (UtilityAudioData.GetRifleReloadEnd() == nullptr)
	{
		#if DEV_DEBUG_MODE
			LOG_ERROR("Rifle reload stop sound is not assigned in UtilityAudioData.");
		#else
			LOG_FATAL_USER();
		#endif
		return;
	}

	#if DEV_DEBUG_MODE
		LOG_INFO("Rifle reload stop sound has been played successfully.");
	#endif

	// Play the assigned rifle reload stop sound using the provided world context.
	PlaySound(InWorldContext, UtilityAudioData.GetRifleReloadEnd());
}



#pragma endregion

#pragma endregion

#pragma endregion

#pragma endregion

#pragma region Character

UCharacterAudioManager::UCharacterAudioManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

#pragma endregion

#pragma region Environment


UEnvironmentAudioManager::UEnvironmentAudioManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

#pragma endregion

#pragma region Music

UMusicManager::UMusicManager(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

#pragma endregion
