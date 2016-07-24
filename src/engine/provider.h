#ifndef ENGINE_SYSTEM_H
#define ENGINE_SYSTEM_H

#include <tuple>
#include <util/traits.h>
#include <assert.h>

#define MACRO_DECLARE_PROVIDER_ACCESS(provider)                                       \
template <typename T>                                                                 \
inline                                                                                \
typename std::enable_if< has_type< T*, provider::SubSystemPtrs >::value, T* >::type   \
Get();                                                                                \
                                                                                      \
template <typename T>                                                                 \
inline                                                                                \
typename std::enable_if< has_type< T*, provider::SubSystemPtrs >::value, bool >::type \
Set(T* ptr);

#define MACRO_DEFINE_PROVIDER_ACCESS(provider)                                        \
template <typename T>                                                                 \
inline                                                                                \
typename std::enable_if< has_type< T*, provider::SubSystemPtrs >::value, T* >::type   \
Get()                                                                                 \
{                                                                                     \
  if(provider::s_pInstance)                                                           \
    return std::get<T*>(provider::s_pInstance->m_SubSystems);                         \
  return nullptr;                                                                     \
}                                                                                     \
                                                                                      \
template <typename T>                                                                 \
inline                                                                                \
typename std::enable_if< has_type< T*, provider::SubSystemPtrs >::value, bool >::type \
Set(T *ptr)                                                                           \
{                                                                                     \
  if(provider::s_pInstance)                                                           \
  {                                                                                   \
    std::get<T*>(provider::s_pInstance->m_SubSystems) = ptr;                          \
    return true;                                                                      \
  }                                                                                   \
  return false;                                                                       \
}

template <typename ...Ts>
class Provider {
private:
	using thisType = Provider<Ts...>;
	using SubSystemPtrs = std::tuple<Ts*...>;

	template <typename T>
	friend
	typename std::enable_if< has_type< T*, thisType::SubSystemPtrs >::value, T* >::type
	Get();

	template <typename T>
	friend
	typename std::enable_if< has_type< T*, thisType::SubSystemPtrs >::value, bool >::type
	Set(T* ptr);

	static Provider *s_pInstance;
	SubSystemPtrs m_SubSystems;

public:
	Provider() { s_pInstance = this; }
	~Provider() { if(s_pInstance == this) s_pInstance = nullptr; }

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

#endif
