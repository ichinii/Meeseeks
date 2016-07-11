#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

#include <tuple>
#include <util/traits.h>

template <typename ...Ts>
class Provider {
	template <typename T, typename Void>
	friend T* Get();

public:
	using SubSystemPtrs = std::tuple<Ts*...>;

private:
	static Provider *s_pInstance;
	SubSystemPtrs m_SubSystems;

public:
	Provider() { s_pInstance = this; }
	~Provider() { if(s_pInstance == this); s_pInstance = nullptr; }

	template <typename T>
	T* Get();

	template <typename T>
	void Register(T* service);

	template <typename T>
	void UnRegister(T* service = nullptr);

	// Switching on multiple Providers was not yet thought about
	// void MakeCurrent();
};

template <typename ...Ts>
Provider<Ts...> *Provider<Ts...>::s_pInstance = nullptr;

template <typename ...Ts>
template <typename T>
T* Provider<Ts...>::Get()
{
	return std::get<T*>(m_SubSystems);
}

template <typename ...Ts>
template <typename T>
void Provider<Ts...>::Register(T* service)
{
	std::get<T*>(m_SubSystems) = service;
}

template <typename ...Ts>
template <typename T>
void Provider<Ts...>::UnRegister(T* service)
{
	std::get<T*>(m_SubSystems) = nullptr;
}

// global declaration
template <typename T, typename Void = void>
inline T* Get();

#define MACRO_REGISTER_PROVIDER(provider)                                                                     \
template <typename T, typename = typename std::enable_if<has_type<T*, provider::SubSystemPtrs>::value>::type> \
inline T* Get()                                                                                               \
{                                                                                                             \
  if(provider::s_pInstance)                                                                                   \
    return std::get<T*>(provider::s_pInstance->m_SubSystems);                                                 \
  return nullptr;                                                                                             \
}

// instantiate provider shared between client and server
using SharedProvider = Provider<int>;
MACRO_REGISTER_PROVIDER(SharedProvider)

#endif
