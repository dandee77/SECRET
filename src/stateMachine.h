#pragma once
#include <memory>
#include <unordered_map>
#include <functional>

template <typename T>
class State {
public:
    virtual ~State() = default;

    virtual void onEnter(T* owner) = 0;
    virtual void onUpdate(T* owner, float deltaTime) = 0;
    virtual void onExit(T* owner) = 0;
};

template <typename T>
class StateMachine {
public:
    using StatePtr = std::shared_ptr<State<T>>;
    using StateFactory = std::function<StatePtr()>;

    StateMachine() = default;
    virtual ~StateMachine() = default;

    void registerState(int stateID, StateFactory factory) {
        stateFactories[stateID] = factory;
    }

    void changeState(int stateID, T* owner) {
        if (currentState) {
            currentState->onExit(owner);
        }
        auto it = stateFactories.find(stateID);
        if (it != stateFactories.end()) {
            currentState = it->second();
            if (currentState) {
                currentState->onEnter(owner);
                currentStateID = stateID;
            }
        }
    }

    void update(T* owner, float deltaTime) {
        if (currentState) {
            currentState->onUpdate(owner, deltaTime);
        }
    }

    int getCurrentStateID() const { return currentStateID; }

protected:
    int currentStateID = -1;
    StatePtr currentState = nullptr;
    std::unordered_map<int, StateFactory> stateFactories;
};