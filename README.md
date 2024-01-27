# Dokumentacja projektu Coffe Anril
- [Dokumentacja projektu Coffe Anril](#dokumentacja-projektu-coffe-anril)
  - [Analiza wymagań](#analiza-wymagań)
  - [Konstrukcja systemu](#konstrukcja-systemu)
    - [Opis wybranej technologii/specyfikacja projektu](#opis-wybranej-technologiispecyfikacja-projektu)
    - [Blueprinty](#blueprinty)
  - [Dokumentacja kodu](#dokumentacja-kodu)
    - [InteractionComponent.cpp](#interactioncomponentcpp)
      - [Zawartość pliku](#zawartość-pliku)
      - [Opis poszczególnych metod](#opis-poszczególnych-metod)
        - [1. `UInteractionComponent::UInteractionComponent()`](#1-uinteractioncomponentuinteractioncomponent)
        - [2. `void UInteractionComponent::InitComponnent(ACharacter* PlayerCharacter, APlayerController* PlayerController)`](#2-void-uinteractioncomponentinitcomponnentacharacter-playercharacter-aplayercontroller-playercontroller)
        - [3. `void UInteractionComponent::SetCanCheckInteraction(bool CanCheck)`](#3-void-uinteractioncomponentsetcancheckinteractionbool-cancheck)
        - [4. `void UInteractionComponent::TryToInteract()`](#4-void-uinteractioncomponenttrytointeract)
        - [5. `void UInteractionComponent::BeginPlay()`](#5-void-uinteractioncomponentbeginplay)
        - [6. `void UInteractionComponent::CheckCurrentActor()`](#6-void-uinteractioncomponentcheckcurrentactor)
        - [7. `void UInteractionComponent::OnLoseActor()`](#7-void-uinteractioncomponentonloseactor)
        - [8. `void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)`](#8-void-uinteractioncomponenttickcomponentfloat-deltatime-eleveltick-ticktype-factorcomponenttickfunction-thistickfunction)
    - [1. Uruchomienie aplikacji](#1-uruchomienie-aplikacji)


## Analiza wymagań


## Konstrukcja systemu

### Opis wybranej technologii/specyfikacja projektu

### Blueprinty

## Dokumentacja kodu

Na istniejący kod programistyczny składają się następujące pliki:
- CharacterBase.cpp
- CoffeGroundsActor.cpp
- CoffeMachineBase.cpp
- ContainsersComponent.cpp
- HandItem.cpp
- InteractionComponent.cpp
- InteractionInterface.cpp

Zawarte w nich metody slużą do obsługi interakcji użytkownika z otoczeniem i obsługi kamery/widoku.

Z punktu widzenia projektu najważniejszy jest plik InteractionComponent.cpp, w który rozszerza klasę UInteractionComponent o metody odpowiedzialne za obslugę ekspresu do kawy.


### InteractionComponent.cpp

W pliku znajdują się następujące metody:

#### Zawartość pliku
```cpp
{
1. `UInteractionComponent::UInteractionComponent()`
2. `void UInteractionComponent::InitComponnent(ACharacter* PlayerCharacter, APlayerController* PlayerController)`
3. `void UInteractionComponent::SetCanCheckInteraction(bool CanCheck)`
4. `void UInteractionComponent::TryToInteract()`
5. `void UInteractionComponent::BeginPlay()`
6. `void UInteractionComponent::CheckCurrentActor()`
7. `void UInteractionComponent::OnLoseActor()`
8. `void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)`
}
```
#### Opis poszczególnych metod

##### 1. `UInteractionComponent::UInteractionComponent()`

##### 2. `void UInteractionComponent::InitComponnent(ACharacter* PlayerCharacter, APlayerController* PlayerController)`

##### 3. `void UInteractionComponent::SetCanCheckInteraction(bool CanCheck)`

##### 4. `void UInteractionComponent::TryToInteract()`

##### 5. `void UInteractionComponent::BeginPlay()`

##### 6. `void UInteractionComponent::CheckCurrentActor()`

##### 7. `void UInteractionComponent::OnLoseActor()`

##### 8. `void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)`


##Samouczek obslugi aplikacji

Urządzenie na, którym ma zostać uruchomiona aplikacja musi spełniać następujące wymagania:
[] - System operacyjny Windows 10
[] - Dedykowana karta graficzna zgodna z DirectX 11 min. 4GB VRAM (NVIDIA GTX 1060)
[] - Karta dźwiękowa zgodna z DirectX 11
[] - Klawiatura i mysz

### 1. Uruchomienie aplikacji

Należy uruchomić uzyskany plik `CoffeAnril.exe`.

